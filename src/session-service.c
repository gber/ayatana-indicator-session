
#include <glib/gi18n.h>

#include <dbus/dbus-glib.h>
#include <dbus/dbus-glib-bindings.h>

#include <libdbusmenu-glib/server.h>
#include <libdbusmenu-glib/menuitem.h>

#include "dbus-shared-names.h"

static DbusmenuMenuitem * root_menuitem = NULL;
static GMainLoop * mainloop = NULL;

static void
show_dialog (DbusmenuMenuitem * mi, gchar * type)
{
	gchar * helper = g_build_path(LIBEXECDIR, "gtk-logout-helper", NULL);
	gchar * dialog_line = g_strdup_printf("%s --%s", helper, type);
	g_free(helper);

	g_debug("Showing dialog '%s'", dialog_line);

	GError * error = NULL;
	if (!g_spawn_command_line_async(dialog_line, &error)) {
		g_warning("Unable to show dialog: %s", error->message);
		g_error_free(error);
	}

	g_free(dialog_line);

	return;
}

static void
create_items (DbusmenuMenuitem * root) {
	DbusmenuMenuitem * mi = NULL;

	mi = dbusmenu_menuitem_new();
	dbusmenu_menuitem_property_set(mi, "label", _("Log Out"));
	dbusmenu_menuitem_child_append(root, mi);
	g_signal_connect(G_OBJECT(mi), DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED, G_CALLBACK(show_dialog), "logout");

	mi = dbusmenu_menuitem_new();
	dbusmenu_menuitem_property_set(mi, "label", _("Suspend"));
	dbusmenu_menuitem_child_append(root, mi);
	g_signal_connect(G_OBJECT(mi), DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED, G_CALLBACK(show_dialog), "suspend");

	mi = dbusmenu_menuitem_new();
	dbusmenu_menuitem_property_set(mi, "label", _("Hibernate"));
	dbusmenu_menuitem_child_append(root, mi);
	g_signal_connect(G_OBJECT(mi), DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED, G_CALLBACK(show_dialog), "hibernate");

	mi = dbusmenu_menuitem_new();
	dbusmenu_menuitem_property_set(mi, "label", _("Restart"));
	dbusmenu_menuitem_child_append(root, mi);
	g_signal_connect(G_OBJECT(mi), DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED, G_CALLBACK(show_dialog), "restart");

	mi = dbusmenu_menuitem_new();
	dbusmenu_menuitem_property_set(mi, "label", _("Shutdown"));
	dbusmenu_menuitem_child_append(root, mi);
	g_signal_connect(G_OBJECT(mi), DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED, G_CALLBACK(show_dialog), "shutdown");

	return;
}

int
main (int argc, char ** argv)
{
    g_type_init();

    DBusGConnection * connection = dbus_g_bus_get(DBUS_BUS_SESSION, NULL);
    DBusGProxy * bus_proxy = dbus_g_proxy_new_for_name(connection, DBUS_SERVICE_DBUS, DBUS_PATH_DBUS, DBUS_INTERFACE_DBUS);
    GError * error = NULL;
    guint nameret = 0;

    if (!org_freedesktop_DBus_request_name(bus_proxy, INDICATOR_SESSION_DBUS_NAME, 0, &nameret, &error)) {
        g_error("Unable to call to request name");
        return 1;
    }   

    if (nameret != DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER) {
        g_error("Unable to get name");
        return 1;
    }   

    root_menuitem = dbusmenu_menuitem_new();
	g_debug("Root ID: %d", dbusmenu_menuitem_get_id(root_menuitem));

	create_items(root_menuitem);

    DbusmenuServer * server = dbusmenu_server_new(INDICATOR_SESSION_DBUS_OBJECT);
    dbusmenu_server_set_root(server, root_menuitem);

    mainloop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(mainloop);

    return 0;
}

