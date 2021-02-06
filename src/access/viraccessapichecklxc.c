/* Automatically generated from ./remote/lxc_protocol.x by gendispatch.pl.
 * Do not edit this file.  Any changes you make will be lost.
 */
#include <config.h>
#include "access/viraccessapichecklxc.h"
#include "access/viraccessmanager.h"
#include "datatypes.h"
#include "virerror.h"

#define VIR_FROM_THIS VIR_FROM_ACCESS

/* Returns: -1 on error/denied, 0 on allowed */
int virDomainLxcOpenNamespaceEnsureACL(virConnectPtr conn, virDomainDefPtr domain)
{
    virAccessManagerPtr mgr;
    int rv;

    if (!(mgr = virAccessManagerGetDefault())) {
        return -1;
    }

    if ((rv = virAccessManagerCheckDomain(mgr, conn->driver->name, domain, VIR_ACCESS_PERM_DOMAIN_OPEN_NAMESPACE)) <= 0) {
        virObjectUnref(mgr);
        if (rv == 0)
            virReportError(VIR_ERR_ACCESS_DENIED,
                            _("'%s' denied access"), conn->driver->name);
        return -1;
    }
    virObjectUnref(mgr);
    return 0;
}
