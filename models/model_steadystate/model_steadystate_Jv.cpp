
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include "model_steadystate_w.h"

int Jv_model_steadystate(N_Vector v, N_Vector Jv, realtype t, N_Vector x, N_Vector xdot, void *user_data, N_Vector tmp) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *xdot_tmp = N_VGetArrayPointer(xdot);
realtype *v_tmp = N_VGetArrayPointer(v);
realtype *Jv_tmp = N_VGetArrayPointer(Jv);
memset(Jv_tmp,0,sizeof(realtype)*3);
status = w_model_steadystate(t,x,NULL,user_data);
  Jv_tmp[0] = udata->dwdx[1]*v_tmp[2]+v_tmp[1]*(udata->p[2]*2.0-udata->p[1]*x_tmp[0])-v_tmp[0]*(udata->dwdx[0]*udata->p[0]*2.0+udata->p[1]*x_tmp[1]);
  Jv_tmp[1] = udata->dwdx[1]*v_tmp[2]+v_tmp[0]*(udata->dwdx[0]*udata->p[0]-udata->p[1]*x_tmp[1])-v_tmp[1]*(udata->p[2]+udata->p[1]*x_tmp[0]);
  Jv_tmp[2] = -v_tmp[2]*(udata->dwdx[1]+udata->k[3])+udata->p[1]*v_tmp[0]*x_tmp[1]+udata->p[1]*v_tmp[1]*x_tmp[0];
return(status);

}


