
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include "model_dirac_dwdp.h"
#include "model_dirac_w.h"

int dxdotdp_model_dirac(realtype t, realtype *dxdotdp, N_Vector x, N_Vector dx, void *user_data) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
int ip;
int ix;
memset(dxdotdp,0,sizeof(realtype)*2*udata->nplist);
status = dwdp_model_dirac(t,x,NULL,user_data);
for(ip = 0; ip<udata->nplist; ip++) {
switch (udata->plist[ip]) {
  case 0: {
  dxdotdp[(0+ip * udata->nx)] = -x_tmp[0];

  } break;

  case 2: {
  dxdotdp[(1+ip * udata->nx)] = x_tmp[0];

  } break;

  case 3: {
  dxdotdp[(1+ip * udata->nx)] = -x_tmp[1];

  } break;

}
}
for(ip = 0; ip<udata->nplist; ip++) {
   for(ix = 0; ix<2; ix++) {
       if(amiIsNaN(dxdotdp[ix+ip*2])) {
           dxdotdp[ix+ip*2] = 0;
           if(!udata->nan_dxdotdp) {
               warnMsgIdAndTxt("AMICI:mex:fdxdotdp:NaN","AMICI replaced a NaN value in dxdotdp and replaced it by 0.0. This will not be reported again for this simulation run.");
               udata->nan_dxdotdp = TRUE;
           }
       }
       if(amiIsInf(dxdotdp[ix+ip*2])) {
           warnMsgIdAndTxt("AMICI:mex:fdxdotdp:Inf","AMICI encountered an Inf value in dxdotdp, aborting.");
           return(-1);
       }
   }
}
return(status);

}


