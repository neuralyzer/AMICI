
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include "model_jakstat_adjoint_dwdx.h"
#include "model_jakstat_adjoint_w.h"

int JB_model_jakstat_adjoint(long int NeqBdot, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, DlsMat JB, void *user_data, N_Vector tmp1B, N_Vector tmp2B, N_Vector tmp3B) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *xB_tmp = N_VGetArrayPointer(xB);
realtype *xBdot_tmp = N_VGetArrayPointer(xBdot);
  memset(JB->data,0,sizeof(realtype)*81);
status = w_model_jakstat_adjoint(t,x,NULL,user_data);
status = dwdx_model_jakstat_adjoint(t,x,NULL,user_data);
  JB->data[0+0*9] = udata->p[0]*udata->w[0];
  JB->data[0+1*9] = -udata->p[0]*udata->w[0];
  JB->data[1+1*9] = udata->dwdx[0]*udata->p[1]*2.0;
  JB->data[1+2*9] = -udata->dwdx[0]*udata->p[1];
  JB->data[2+2*9] = udata->p[2];
  JB->data[2+3*9] = -(udata->k[0]*udata->p[2])/udata->k[1];
  JB->data[3+3*9] = udata->p[3];
  JB->data[3+4*9] = udata->p[3]*-2.0;
  JB->data[4+4*9] = udata->p[3];
  JB->data[4+5*9] = -udata->p[3];
  JB->data[5+5*9] = udata->p[3];
  JB->data[5+6*9] = -udata->p[3];
  JB->data[6+6*9] = udata->p[3];
  JB->data[6+7*9] = -udata->p[3];
  JB->data[7+7*9] = udata->p[3];
  JB->data[7+8*9] = -udata->p[3];
  JB->data[8+0*9] = -(udata->k[1]*udata->p[3])/udata->k[0];
  JB->data[8+8*9] = udata->p[3];
return(status);

}


