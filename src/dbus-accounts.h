/*
 * Generated by gdbus-codegen 2.34.0. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __DBUS_ACCOUNTS_H__
#define __DBUS_ACCOUNTS_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.freedesktop.Accounts */

#define TYPE_ACCOUNTS (accounts_get_type ())
#define ACCOUNTS(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ACCOUNTS, Accounts))
#define IS_ACCOUNTS(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ACCOUNTS))
#define ACCOUNTS_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_ACCOUNTS, AccountsIface))

struct _Accounts;
typedef struct _Accounts Accounts;
typedef struct _AccountsIface AccountsIface;

struct _AccountsIface
{
  GTypeInterface parent_iface;



  gboolean (*handle_create_user) (
    Accounts *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_name,
    const gchar *arg_fullname,
    gint arg_accountType);

  gboolean (*handle_delete_user) (
    Accounts *object,
    GDBusMethodInvocation *invocation,
    gint64 arg_id,
    gboolean arg_removeFiles);

  gboolean (*handle_find_user_by_id) (
    Accounts *object,
    GDBusMethodInvocation *invocation,
    gint64 arg_id);

  gboolean (*handle_find_user_by_name) (
    Accounts *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_name);

  gboolean (*handle_list_cached_users) (
    Accounts *object,
    GDBusMethodInvocation *invocation);

  const gchar * (*get_daemon_version) (Accounts *object);

  void (*user_added) (
    Accounts *object,
    const gchar *arg_user);

  void (*user_changed) (
    Accounts *object,
    const gchar *arg_user);

  void (*user_deleted) (
    Accounts *object,
    const gchar *arg_user);

};

GType accounts_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *accounts_interface_info (void);
guint accounts_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void accounts_complete_list_cached_users (
    Accounts *object,
    GDBusMethodInvocation *invocation,
    const gchar *const *users);

void accounts_complete_find_user_by_id (
    Accounts *object,
    GDBusMethodInvocation *invocation,
    const gchar *user);

void accounts_complete_find_user_by_name (
    Accounts *object,
    GDBusMethodInvocation *invocation,
    const gchar *user);

void accounts_complete_create_user (
    Accounts *object,
    GDBusMethodInvocation *invocation,
    const gchar *user);

void accounts_complete_delete_user (
    Accounts *object,
    GDBusMethodInvocation *invocation);



/* D-Bus signal emissions functions: */
void accounts_emit_user_added (
    Accounts *object,
    const gchar *arg_user);

void accounts_emit_user_deleted (
    Accounts *object,
    const gchar *arg_user);

void accounts_emit_user_changed (
    Accounts *object,
    const gchar *arg_user);



/* D-Bus method calls: */
void accounts_call_list_cached_users (
    Accounts *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_call_list_cached_users_finish (
    Accounts *proxy,
    gchar ***out_users,
    GAsyncResult *res,
    GError **error);

gboolean accounts_call_list_cached_users_sync (
    Accounts *proxy,
    gchar ***out_users,
    GCancellable *cancellable,
    GError **error);

void accounts_call_find_user_by_id (
    Accounts *proxy,
    gint64 arg_id,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_call_find_user_by_id_finish (
    Accounts *proxy,
    gchar **out_user,
    GAsyncResult *res,
    GError **error);

gboolean accounts_call_find_user_by_id_sync (
    Accounts *proxy,
    gint64 arg_id,
    gchar **out_user,
    GCancellable *cancellable,
    GError **error);

void accounts_call_find_user_by_name (
    Accounts *proxy,
    const gchar *arg_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_call_find_user_by_name_finish (
    Accounts *proxy,
    gchar **out_user,
    GAsyncResult *res,
    GError **error);

gboolean accounts_call_find_user_by_name_sync (
    Accounts *proxy,
    const gchar *arg_name,
    gchar **out_user,
    GCancellable *cancellable,
    GError **error);

void accounts_call_create_user (
    Accounts *proxy,
    const gchar *arg_name,
    const gchar *arg_fullname,
    gint arg_accountType,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_call_create_user_finish (
    Accounts *proxy,
    gchar **out_user,
    GAsyncResult *res,
    GError **error);

gboolean accounts_call_create_user_sync (
    Accounts *proxy,
    const gchar *arg_name,
    const gchar *arg_fullname,
    gint arg_accountType,
    gchar **out_user,
    GCancellable *cancellable,
    GError **error);

void accounts_call_delete_user (
    Accounts *proxy,
    gint64 arg_id,
    gboolean arg_removeFiles,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_call_delete_user_finish (
    Accounts *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_call_delete_user_sync (
    Accounts *proxy,
    gint64 arg_id,
    gboolean arg_removeFiles,
    GCancellable *cancellable,
    GError **error);



/* D-Bus property accessors: */
const gchar *accounts_get_daemon_version (Accounts *object);
gchar *accounts_dup_daemon_version (Accounts *object);
void accounts_set_daemon_version (Accounts *object, const gchar *value);


/* ---- */

#define TYPE_ACCOUNTS_PROXY (accounts_proxy_get_type ())
#define ACCOUNTS_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ACCOUNTS_PROXY, AccountsProxy))
#define ACCOUNTS_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_ACCOUNTS_PROXY, AccountsProxyClass))
#define ACCOUNTS_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_ACCOUNTS_PROXY, AccountsProxyClass))
#define IS_ACCOUNTS_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ACCOUNTS_PROXY))
#define IS_ACCOUNTS_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_ACCOUNTS_PROXY))

typedef struct _AccountsProxy AccountsProxy;
typedef struct _AccountsProxyClass AccountsProxyClass;
typedef struct _AccountsProxyPrivate AccountsProxyPrivate;

struct _AccountsProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  AccountsProxyPrivate *priv;
};

struct _AccountsProxyClass
{
  GDBusProxyClass parent_class;
};

GType accounts_proxy_get_type (void) G_GNUC_CONST;

void accounts_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
Accounts *accounts_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
Accounts *accounts_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void accounts_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
Accounts *accounts_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
Accounts *accounts_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TYPE_ACCOUNTS_SKELETON (accounts_skeleton_get_type ())
#define ACCOUNTS_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ACCOUNTS_SKELETON, AccountsSkeleton))
#define ACCOUNTS_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_ACCOUNTS_SKELETON, AccountsSkeletonClass))
#define ACCOUNTS_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_ACCOUNTS_SKELETON, AccountsSkeletonClass))
#define IS_ACCOUNTS_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ACCOUNTS_SKELETON))
#define IS_ACCOUNTS_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_ACCOUNTS_SKELETON))

typedef struct _AccountsSkeleton AccountsSkeleton;
typedef struct _AccountsSkeletonClass AccountsSkeletonClass;
typedef struct _AccountsSkeletonPrivate AccountsSkeletonPrivate;

struct _AccountsSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  AccountsSkeletonPrivate *priv;
};

struct _AccountsSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType accounts_skeleton_get_type (void) G_GNUC_CONST;

Accounts *accounts_skeleton_new (void);


G_END_DECLS

#endif /* __DBUS_ACCOUNTS_H__ */
