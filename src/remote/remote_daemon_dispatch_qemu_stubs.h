/* Automatically generated from ./remote/qemu_protocol.x by gendispatch.pl.
 * Do not edit this file.  Any changes you make will be lost.
 */
static int qemuDispatchConnectDomainMonitorEventDeregister(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    qemu_connect_domain_monitor_event_deregister_args *args);
static int qemuDispatchConnectDomainMonitorEventDeregisterHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("qemuDispatchConnectDomainMonitorEventDeregister");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = qemuDispatchConnectDomainMonitorEventDeregister(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* qemuDispatchConnectDomainMonitorEventDeregister body has to be implemented manually */



static int qemuDispatchConnectDomainMonitorEventRegister(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    qemu_connect_domain_monitor_event_register_args *args,
    qemu_connect_domain_monitor_event_register_ret *ret);
static int qemuDispatchConnectDomainMonitorEventRegisterHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("qemuDispatchConnectDomainMonitorEventRegister");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = qemuDispatchConnectDomainMonitorEventRegister(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
/* qemuDispatchConnectDomainMonitorEventRegister body has to be implemented manually */



static int qemuDispatchDomainAgentCommand(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    qemu_domain_agent_command_args *args,
    qemu_domain_agent_command_ret *ret);
static int qemuDispatchDomainAgentCommandHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("qemuDispatchDomainAgentCommand");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = qemuDispatchDomainAgentCommand(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
static int qemuDispatchDomainAgentCommand(
    virNetServerPtr server ATTRIBUTE_UNUSED,
    virNetServerClientPtr client,
    virNetMessagePtr msg ATTRIBUTE_UNUSED,
    virNetMessageErrorPtr rerr,
    qemu_domain_agent_command_args *args,
    qemu_domain_agent_command_ret *ret)
{
    int rv = -1;
    virDomainPtr dom = NULL;
    char *result = NULL;
    char **result_p = NULL;
    struct daemonClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->conn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    if (!(dom = get_nonnull_domain(priv->conn, args->dom)))
        goto cleanup;

    if ((result = virDomainQemuAgentCommand(dom, args->cmd, args->timeout, args->flags)) == NULL)
        goto cleanup;

    if (VIR_ALLOC(result_p) < 0)
        goto cleanup;

    if (VIR_STRDUP(*result_p, result) < 0)
        goto cleanup;

    ret->result = result_p;
    rv = 0;

cleanup:
    if (rv < 0) {
        virNetMessageSaveError(rerr);
        VIR_FREE(result_p);
    }
    virObjectUnref(dom);
    VIR_FREE(result);
    return rv;
}



static int qemuDispatchDomainAttach(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    qemu_domain_attach_args *args,
    qemu_domain_attach_ret *ret);
static int qemuDispatchDomainAttachHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("qemuDispatchDomainAttach");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = qemuDispatchDomainAttach(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
static int qemuDispatchDomainAttach(
    virNetServerPtr server ATTRIBUTE_UNUSED,
    virNetServerClientPtr client,
    virNetMessagePtr msg ATTRIBUTE_UNUSED,
    virNetMessageErrorPtr rerr,
    qemu_domain_attach_args *args,
    qemu_domain_attach_ret *ret)
{
    int rv = -1;
    virDomainPtr dom = NULL;
    struct daemonClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->conn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    if ((dom = virDomainQemuAttach(priv->conn, args->pid_value, args->flags)) == NULL)
        goto cleanup;

    if (make_nonnull_domain(&ret->dom, dom) < 0)
        goto cleanup;

    rv = 0;

cleanup:
    if (rv < 0)
        virNetMessageSaveError(rerr);
    virObjectUnref(dom);
    return rv;
}



static int qemuDispatchDomainMonitorCommand(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    qemu_domain_monitor_command_args *args,
    qemu_domain_monitor_command_ret *ret);
static int qemuDispatchDomainMonitorCommandHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("qemuDispatchDomainMonitorCommand");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = qemuDispatchDomainMonitorCommand(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
/* qemuDispatchDomainMonitorCommand body has to be implemented manually */



virNetServerProgramProc qemuProcs[] = {
{ /* Unused 0 */
   NULL,
   0,
   (xdrproc_t)xdr_void,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method DomainMonitorCommand => 1 */
   qemuDispatchDomainMonitorCommandHelper,
   sizeof(qemu_domain_monitor_command_args),
   (xdrproc_t)xdr_qemu_domain_monitor_command_args,
   sizeof(qemu_domain_monitor_command_ret),
   (xdrproc_t)xdr_qemu_domain_monitor_command_ret,
   true,
   0
},
{ /* Method DomainAttach => 2 */
   qemuDispatchDomainAttachHelper,
   sizeof(qemu_domain_attach_args),
   (xdrproc_t)xdr_qemu_domain_attach_args,
   sizeof(qemu_domain_attach_ret),
   (xdrproc_t)xdr_qemu_domain_attach_ret,
   true,
   0
},
{ /* Method DomainAgentCommand => 3 */
   qemuDispatchDomainAgentCommandHelper,
   sizeof(qemu_domain_agent_command_args),
   (xdrproc_t)xdr_qemu_domain_agent_command_args,
   sizeof(qemu_domain_agent_command_ret),
   (xdrproc_t)xdr_qemu_domain_agent_command_ret,
   true,
   0
},
{ /* Method ConnectDomainMonitorEventRegister => 4 */
   qemuDispatchConnectDomainMonitorEventRegisterHelper,
   sizeof(qemu_connect_domain_monitor_event_register_args),
   (xdrproc_t)xdr_qemu_connect_domain_monitor_event_register_args,
   sizeof(qemu_connect_domain_monitor_event_register_ret),
   (xdrproc_t)xdr_qemu_connect_domain_monitor_event_register_ret,
   true,
   1
},
{ /* Method ConnectDomainMonitorEventDeregister => 5 */
   qemuDispatchConnectDomainMonitorEventDeregisterHelper,
   sizeof(qemu_connect_domain_monitor_event_deregister_args),
   (xdrproc_t)xdr_qemu_connect_domain_monitor_event_deregister_args,
   0,
   (xdrproc_t)xdr_void,
   true,
   1
},
{ /* Async event DomainMonitorEvent => 6 */
   NULL,
   0,
   (xdrproc_t)xdr_void,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
};
size_t qemuNProcs = ARRAY_CARDINALITY(qemuProcs);
