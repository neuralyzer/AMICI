#ifndef _MY_TDATA
#define _MY_TDATA

#include <nvector/nvector_serial.h>  /* defs. of serial NVECTOR fcts. and macros  */
#include <sundials/sundials_klu_impl.h> /* def. of type klu solver */
#include <sundials/sundials_sparse.h> /* def. of type sparse stuff */
#include <sundials/sundials_types.h> /* def. of type realtype */
#include <sundials/sundials_math.h>  /* definition of ABS */
#include <sundials/sundials_config.h>

#include <include/udata.h>

/** @brief struct that provides temporary storage for different variables */
class TempData {
    
public:
    
    /**
     * @brief Default constructor
     */
    TempData(const UserData *udata);
    ~TempData();
    
    /** current time */
    realtype t;
    
    /** state vector */
    N_Vector x; 
    /** old state vector */
    N_Vector x_old;
    /** array of state vectors at discontinuities*/
    N_Vector *x_disc;
    /** array of differential state vectors at discontinuities*/
    N_Vector *xdot_disc;
    /** array of old differential state vectors at discontinuities*/
    N_Vector *xdot_old_disc;
    /** differential state vector */
    N_Vector dx;
    /** old differential state vector */
    N_Vector dx_old;
    /** time derivative state vector */
    N_Vector xdot;
    /** old time derivative state vector */
    N_Vector xdot_old;
    /** adjoint state vector */
    N_Vector xB;
    /** old adjoint state vector */
    N_Vector xB_old;
    /** differential adjoint state vector */
    N_Vector dxB; 
    /** quadrature state vector */
    N_Vector xQB;
    /** old quadrature state vector */
    N_Vector xQB_old;
    /** sensitivity state vector array */
    N_Vector *sx; 
    /** differential sensitivity state vector array */
    N_Vector *sdx; 
    /** Jacobian */
    DlsMat Jtmp;
    
    /** parameter derivative of likelihood array */
    realtype *llhS0;
    /** data likelihood */
    realtype *Jy;
    /** parameter derivative of data likelihood */
    realtype *dJydp;
    /** observable derivative of data likelihood */
    realtype *dJydy;
    /** state derivative of data likelihood */
    realtype *dJydx;
    /** event likelihood */
    realtype *Jz;
    /** parameter derivative of event likelihood */
    realtype *dJzdp;
    /** state derivative of event likelihood */
    realtype *dJzdx;
    /** state derivative of event */
    realtype *dzdx;
    /** parameter derivative of event */
    realtype *dzdp;
    /** parameter derivative of observable */
    realtype *dydp;
    /** state derivative of observable */
    realtype *dydx;
    /** initial sensitivity of observable */
    realtype *yS0;
    /** data standard deviation */
    realtype *sigmay;
    /** parameter derivative of data standard deviation */
    realtype *dsigmaydp;
    /** event standard deviation */
    realtype *sigmaz;
    /** parameter derivative of event standard deviation */
    realtype *dsigmazdp;

    /** array of flags indicating which root has beend found */
    /*!
    array of length nr with the indices of the user functions gi found to have a root. For i = 0, . . . ,nr 1 if gi has a root, and = 0 if not.
    */
    int *rootsfound;
    /** array of index which root has been found */
    int *rootidx;
    /** array of number of found roots for a certain event type */
    int *nroots;
    /** array of values of the root function */
    realtype *rootvals;
    /** temporary rootval storage to check crossing in secondary event */
    realtype *h;

    /** change in x */
    realtype *deltax;
    /** change in sx */
    realtype *deltasx;
    /** change in xB */
    realtype *deltaxB;
    /** change in qB */
    realtype *deltaqB;
    
    /** integer for indexing of backwards problems */
    int which;
    
    /** array containing the time-points of discontinuities*/
    realtype *discs; 
    /** array containing the index of discontinuities */
    realtype *irdiscs; 
    
    /** number of parameters, copied from udata, necessary for deallocation */
    int nplist;
    
	};

#endif /* _MY_TDATA */
