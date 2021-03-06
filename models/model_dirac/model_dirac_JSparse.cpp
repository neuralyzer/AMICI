
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include "model_dirac_dwdx.h"
#include "model_dirac_w.h"

int JSparse_model_dirac(realtype t, N_Vector x, N_Vector xdot, SlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *xdot_tmp = N_VGetArrayPointer(xdot);
int inz;
SparseSetMatToZero(J);
J->indexvals[0] = 0;
J->indexvals[1] = 1;
J->indexvals[2] = 1;
J->indexptrs[0] = 0;
J->indexptrs[1] = 2;
J->indexptrs[2] = 3;
status = w_model_dirac(t,x,NULL,user_data);
status = dwdx_model_dirac(t,x,NULL,user_data);
  J->data[0] = -udata->p[0];
  J->data[1] = udata->p[2];
  J->data[2] = -udata->p[3];
for(inz = 0; inz<3; inz++) {
   if(amiIsNaN(J->data[inz])) {
       J->data[inz] = 0;
       if(!udata->nan_JSparse) {
           warnMsgIdAndTxt("AMICI:mex:fJ:NaN","AMICI replaced a NaN value in Jacobian and replaced it by 0.0. This will not be reported again for this simulation run.");
           udata->nan_JSparse = TRUE;
       }
   }
   if(amiIsInf(J->data[inz])) {
       warnMsgIdAndTxt("AMICI:mex:fJ:Inf","AMICI encountered an Inf value in Jacobian! Aborting simulation ... ");
       return(-1);
   }
}
return(status);

}


