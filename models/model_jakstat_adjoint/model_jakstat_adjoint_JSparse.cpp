
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include "model_jakstat_adjoint_dwdx.h"
#include "model_jakstat_adjoint_w.h"

int JSparse_model_jakstat_adjoint(realtype t, N_Vector x, N_Vector xdot, SlsMat J, void *user_data, N_Vector tmp1, N_Vector tmp2, N_Vector tmp3) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *xdot_tmp = N_VGetArrayPointer(xdot);
int inz;
SparseSetMatToZero(J);
J->indexvals[0] = 0;
J->indexvals[1] = 1;
J->indexvals[2] = 1;
J->indexvals[3] = 2;
J->indexvals[4] = 2;
J->indexvals[5] = 3;
J->indexvals[6] = 3;
J->indexvals[7] = 4;
J->indexvals[8] = 4;
J->indexvals[9] = 5;
J->indexvals[10] = 5;
J->indexvals[11] = 6;
J->indexvals[12] = 6;
J->indexvals[13] = 7;
J->indexvals[14] = 7;
J->indexvals[15] = 8;
J->indexvals[16] = 0;
J->indexvals[17] = 8;
J->indexptrs[0] = 0;
J->indexptrs[1] = 2;
J->indexptrs[2] = 4;
J->indexptrs[3] = 6;
J->indexptrs[4] = 8;
J->indexptrs[5] = 10;
J->indexptrs[6] = 12;
J->indexptrs[7] = 14;
J->indexptrs[8] = 16;
J->indexptrs[9] = 18;
status = w_model_jakstat_adjoint(t,x,NULL,user_data);
status = dwdx_model_jakstat_adjoint(t,x,NULL,user_data);
  J->data[0] = -udata->p[0]*udata->w[0];
  J->data[1] = udata->p[0]*udata->w[0];
  J->data[2] = udata->dwdx[0]*udata->p[1]*-2.0;
  J->data[3] = udata->dwdx[0]*udata->p[1];
  J->data[4] = -udata->p[2];
  J->data[5] = (udata->k[0]*udata->p[2])/udata->k[1];
  J->data[6] = -udata->p[3];
  J->data[7] = udata->p[3]*2.0;
  J->data[8] = -udata->p[3];
  J->data[9] = udata->p[3];
  J->data[10] = -udata->p[3];
  J->data[11] = udata->p[3];
  J->data[12] = -udata->p[3];
  J->data[13] = udata->p[3];
  J->data[14] = -udata->p[3];
  J->data[15] = udata->p[3];
  J->data[16] = (udata->k[1]*udata->p[3])/udata->k[0];
  J->data[17] = -udata->p[3];
for(inz = 0; inz<18; inz++) {
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


