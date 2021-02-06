#include <config.h>
/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "lxc_monitor_protocol.h"
#include "virxdrdefs.h"

bool_t
xdr_virLXCMonitorExitStatus (XDR *xdrs, virLXCMonitorExitStatus *objp)
{

         if (!xdr_enum (xdrs, (enum_t *) objp))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLXCMonitorExitEventMsg (XDR *xdrs, virLXCMonitorExitEventMsg *objp)
{

         if (!xdr_virLXCMonitorExitStatus (xdrs, &objp->status))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLXCMonitorInitEventMsg (XDR *xdrs, virLXCMonitorInitEventMsg *objp)
{

         if (!xdr_uint64_t (xdrs, &objp->initpid))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLXCMonitorProcedure (XDR *xdrs, virLXCMonitorProcedure *objp)
{

         if (!xdr_enum (xdrs, (enum_t *) objp))
                 return FALSE;
        return TRUE;
}
