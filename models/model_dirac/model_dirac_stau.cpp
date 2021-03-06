
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include "model_dirac_w.h"

int stau_model_dirac(realtype t, int ie, realtype *stau, N_Vector x, N_Vector *sx, void *user_data) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *sx_tmp;
int ip;
memset(stau,0,sizeof(realtype)*udata->nplist);
status = w_model_dirac(t,x,NULL,user_data);
for(ip = 0; ip<udata->nplist; ip++) {
sx_tmp = N_VGetArrayPointer(sx[ip]);
switch (udata->plist[ip]) {
  case 1: {
    switch(ie) { 
        case 0: {
  stau[ip] = 1.0;

        } break;

        case 1: {
  stau[ip] = 1.0;

        } break;

    } 

  } break;

}
}
return(status);

}


