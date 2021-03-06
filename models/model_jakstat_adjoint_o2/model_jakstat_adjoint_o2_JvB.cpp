
#include <include/symbolic_functions.h>
#include <string.h>
#include <include/udata.h>
#include "model_jakstat_adjoint_o2_w.h"

int JvB_model_jakstat_adjoint_o2(N_Vector vB, N_Vector JvB, realtype t, N_Vector x, N_Vector xB, N_Vector xBdot, void *user_data, N_Vector tmpB) {
int status = 0;
UserData *udata = (UserData*) user_data;
realtype *x_tmp = N_VGetArrayPointer(x);
realtype *xB_tmp = N_VGetArrayPointer(xB);
realtype *xBdot_tmp = N_VGetArrayPointer(xBdot);
realtype *vB_tmp = N_VGetArrayPointer(vB);
realtype *JvB_tmp = N_VGetArrayPointer(JvB);
memset(JvB_tmp,0,sizeof(realtype)*162);
status = w_model_jakstat_adjoint_o2(t,x,NULL,user_data);
  JvB_tmp[0] = -udata->p[0]*vB_tmp[1]*udata->w[0]+udata->k[0]*udata->p[0]*vB_tmp[0]*udata->w[0]*udata->w[2];
  JvB_tmp[1] = udata->dwdx[0]*udata->p[1]*vB_tmp[1]*2.0-udata->dwdx[0]*udata->p[1]*vB_tmp[2];
  JvB_tmp[2] = udata->p[2]*vB_tmp[2]-udata->k[0]*udata->p[2]*vB_tmp[3]*udata->w[3];
  JvB_tmp[3] = -udata->dwdx[1]*udata->p[3]*vB_tmp[4]+udata->k[1]*udata->p[3]*vB_tmp[3]*udata->w[3];
  JvB_tmp[4] = udata->p[3]*vB_tmp[4]-udata->p[3]*vB_tmp[5];
  JvB_tmp[5] = udata->p[3]*vB_tmp[5]-udata->p[3]*vB_tmp[6];
  JvB_tmp[6] = udata->p[3]*vB_tmp[6]-udata->p[3]*vB_tmp[7];
  JvB_tmp[7] = udata->p[3]*vB_tmp[7]-udata->p[3]*vB_tmp[8];
  JvB_tmp[8] = udata->p[3]*vB_tmp[8]-udata->k[1]*udata->p[3]*vB_tmp[0]*udata->w[2];
  JvB_tmp[9] = vB_tmp[0]*udata->w[0]-vB_tmp[1]*udata->w[0]+udata->p[0]*vB_tmp[9]*udata->w[0]-udata->p[0]*vB_tmp[10]*udata->w[0];
  JvB_tmp[10] = udata->p[1]*vB_tmp[1]*x_tmp[10]*4.0+udata->p[1]*vB_tmp[10]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[10]*2.0-udata->p[1]*vB_tmp[11]*x_tmp[1]*2.0;
  JvB_tmp[11] = udata->p[2]*vB_tmp[11]-udata->k[0]*udata->p[2]*vB_tmp[12]*udata->w[3];
  JvB_tmp[12] = udata->p[3]*vB_tmp[12]-udata->p[3]*vB_tmp[13]*2.0;
  JvB_tmp[13] = udata->p[3]*vB_tmp[13]-udata->p[3]*vB_tmp[14];
  JvB_tmp[14] = udata->p[3]*vB_tmp[14]-udata->p[3]*vB_tmp[15];
  JvB_tmp[15] = udata->p[3]*vB_tmp[15]-udata->p[3]*vB_tmp[16];
  JvB_tmp[16] = udata->p[3]*vB_tmp[16]-udata->p[3]*vB_tmp[17];
  JvB_tmp[17] = udata->p[3]*vB_tmp[17]-udata->k[1]*udata->p[3]*vB_tmp[9]*udata->w[2];
  JvB_tmp[18] = udata->p[0]*vB_tmp[18]*udata->w[0]-udata->p[0]*vB_tmp[19]*udata->w[0];
  JvB_tmp[19] = vB_tmp[1]*(udata->dwdx[0]*2.0+udata->p[1]*x_tmp[19]*4.0)-vB_tmp[2]*(udata->dwdx[0]+udata->p[1]*x_tmp[19]*2.0)+udata->p[1]*vB_tmp[19]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[20]*x_tmp[1]*2.0;
  JvB_tmp[20] = udata->p[2]*vB_tmp[20]-udata->k[0]*udata->p[2]*vB_tmp[21]*udata->w[3];
  JvB_tmp[21] = udata->p[3]*vB_tmp[21]-udata->p[3]*vB_tmp[22]*2.0;
  JvB_tmp[22] = udata->p[3]*vB_tmp[22]-udata->p[3]*vB_tmp[23];
  JvB_tmp[23] = udata->p[3]*vB_tmp[23]-udata->p[3]*vB_tmp[24];
  JvB_tmp[24] = udata->p[3]*vB_tmp[24]-udata->p[3]*vB_tmp[25];
  JvB_tmp[25] = udata->p[3]*vB_tmp[25]-udata->p[3]*vB_tmp[26];
  JvB_tmp[26] = udata->p[3]*vB_tmp[26]-udata->k[1]*udata->p[3]*vB_tmp[18]*udata->w[2];
  JvB_tmp[27] = udata->p[0]*vB_tmp[27]*udata->w[0]-udata->p[0]*vB_tmp[28]*udata->w[0];
  JvB_tmp[28] = udata->p[1]*vB_tmp[1]*x_tmp[28]*4.0+udata->p[1]*vB_tmp[28]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[28]*2.0-udata->p[1]*vB_tmp[29]*x_tmp[1]*2.0;
  JvB_tmp[29] = vB_tmp[2]+udata->p[2]*vB_tmp[29]-udata->k[0]*vB_tmp[3]*udata->w[3]-udata->k[0]*udata->p[2]*vB_tmp[30]*udata->w[3];
  JvB_tmp[30] = udata->p[3]*vB_tmp[30]-udata->p[3]*vB_tmp[31]*2.0;
  JvB_tmp[31] = udata->p[3]*vB_tmp[31]-udata->p[3]*vB_tmp[32];
  JvB_tmp[32] = udata->p[3]*vB_tmp[32]-udata->p[3]*vB_tmp[33];
  JvB_tmp[33] = udata->p[3]*vB_tmp[33]-udata->p[3]*vB_tmp[34];
  JvB_tmp[34] = udata->p[3]*vB_tmp[34]-udata->p[3]*vB_tmp[35];
  JvB_tmp[35] = udata->p[3]*vB_tmp[35]-udata->k[1]*udata->p[3]*vB_tmp[27]*udata->w[2];
  JvB_tmp[36] = udata->p[0]*vB_tmp[36]*udata->w[0]-udata->p[0]*vB_tmp[37]*udata->w[0];
  JvB_tmp[37] = udata->p[1]*vB_tmp[1]*x_tmp[37]*4.0+udata->p[1]*vB_tmp[37]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[37]*2.0-udata->p[1]*vB_tmp[38]*x_tmp[1]*2.0;
  JvB_tmp[38] = udata->p[2]*vB_tmp[38]-udata->k[0]*udata->p[2]*vB_tmp[39]*udata->w[3];
  JvB_tmp[39] = vB_tmp[3]-udata->dwdx[1]*vB_tmp[4]+udata->p[3]*vB_tmp[39]-udata->p[3]*vB_tmp[40]*2.0;
  JvB_tmp[40] = vB_tmp[4]-vB_tmp[5]+udata->p[3]*vB_tmp[40]-udata->p[3]*vB_tmp[41];
  JvB_tmp[41] = vB_tmp[5]-vB_tmp[6]+udata->p[3]*vB_tmp[41]-udata->p[3]*vB_tmp[42];
  JvB_tmp[42] = vB_tmp[6]-vB_tmp[7]+udata->p[3]*vB_tmp[42]-udata->p[3]*vB_tmp[43];
  JvB_tmp[43] = vB_tmp[7]-vB_tmp[8]+udata->p[3]*vB_tmp[43]-udata->p[3]*vB_tmp[44];
  JvB_tmp[44] = vB_tmp[8]+udata->p[3]*vB_tmp[44]-udata->k[1]*vB_tmp[0]*udata->w[2]-udata->k[1]*udata->p[3]*vB_tmp[36]*udata->w[2];
  JvB_tmp[45] = udata->p[0]*vB_tmp[45]*udata->w[0]-udata->p[0]*vB_tmp[46]*udata->w[0];
  JvB_tmp[46] = udata->p[1]*vB_tmp[1]*x_tmp[46]*4.0+udata->p[1]*vB_tmp[46]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[46]*2.0-udata->p[1]*vB_tmp[47]*x_tmp[1]*2.0;
  JvB_tmp[47] = udata->p[2]*vB_tmp[47]-udata->k[0]*udata->p[2]*vB_tmp[48]*udata->w[3];
  JvB_tmp[48] = udata->p[3]*vB_tmp[48]-udata->p[3]*vB_tmp[49]*2.0;
  JvB_tmp[49] = udata->p[3]*vB_tmp[49]-udata->p[3]*vB_tmp[50];
  JvB_tmp[50] = udata->p[3]*vB_tmp[50]-udata->p[3]*vB_tmp[51];
  JvB_tmp[51] = udata->p[3]*vB_tmp[51]-udata->p[3]*vB_tmp[52];
  JvB_tmp[52] = udata->p[3]*vB_tmp[52]-udata->p[3]*vB_tmp[53];
  JvB_tmp[53] = udata->p[3]*vB_tmp[53]-udata->k[1]*udata->p[3]*vB_tmp[45]*udata->w[2];
  JvB_tmp[54] = udata->p[0]*vB_tmp[0]*udata->w[5]-udata->p[0]*vB_tmp[1]*udata->w[5]+udata->p[0]*vB_tmp[54]*udata->w[0]-udata->p[0]*vB_tmp[55]*udata->w[0];
  JvB_tmp[55] = udata->p[1]*vB_tmp[1]*x_tmp[55]*4.0+udata->p[1]*vB_tmp[55]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[55]*2.0-udata->p[1]*vB_tmp[56]*x_tmp[1]*2.0;
  JvB_tmp[56] = udata->p[2]*vB_tmp[56]-udata->k[0]*udata->p[2]*vB_tmp[57]*udata->w[3];
  JvB_tmp[57] = udata->p[3]*vB_tmp[57]-udata->p[3]*vB_tmp[58]*2.0;
  JvB_tmp[58] = udata->p[3]*vB_tmp[58]-udata->p[3]*vB_tmp[59];
  JvB_tmp[59] = udata->p[3]*vB_tmp[59]-udata->p[3]*vB_tmp[60];
  JvB_tmp[60] = udata->p[3]*vB_tmp[60]-udata->p[3]*vB_tmp[61];
  JvB_tmp[61] = udata->p[3]*vB_tmp[61]-udata->p[3]*vB_tmp[62];
  JvB_tmp[62] = udata->p[3]*vB_tmp[62]-udata->k[1]*udata->p[3]*vB_tmp[54]*udata->w[2];
  JvB_tmp[63] = udata->p[0]*vB_tmp[0]*udata->w[6]-udata->p[0]*vB_tmp[1]*udata->w[6]+udata->p[0]*vB_tmp[63]*udata->w[0]-udata->p[0]*vB_tmp[64]*udata->w[0];
  JvB_tmp[64] = udata->p[1]*vB_tmp[1]*x_tmp[64]*4.0+udata->p[1]*vB_tmp[64]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[64]*2.0-udata->p[1]*vB_tmp[65]*x_tmp[1]*2.0;
  JvB_tmp[65] = udata->p[2]*vB_tmp[65]-udata->k[0]*udata->p[2]*vB_tmp[66]*udata->w[3];
  JvB_tmp[66] = udata->p[3]*vB_tmp[66]-udata->p[3]*vB_tmp[67]*2.0;
  JvB_tmp[67] = udata->p[3]*vB_tmp[67]-udata->p[3]*vB_tmp[68];
  JvB_tmp[68] = udata->p[3]*vB_tmp[68]-udata->p[3]*vB_tmp[69];
  JvB_tmp[69] = udata->p[3]*vB_tmp[69]-udata->p[3]*vB_tmp[70];
  JvB_tmp[70] = udata->p[3]*vB_tmp[70]-udata->p[3]*vB_tmp[71];
  JvB_tmp[71] = udata->p[3]*vB_tmp[71]-udata->k[1]*udata->p[3]*vB_tmp[63]*udata->w[2];
  JvB_tmp[72] = udata->p[0]*vB_tmp[0]*udata->w[7]-udata->p[0]*vB_tmp[1]*udata->w[7]+udata->p[0]*vB_tmp[72]*udata->w[0]-udata->p[0]*vB_tmp[73]*udata->w[0];
  JvB_tmp[73] = udata->p[1]*vB_tmp[1]*x_tmp[73]*4.0+udata->p[1]*vB_tmp[73]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[73]*2.0-udata->p[1]*vB_tmp[74]*x_tmp[1]*2.0;
  JvB_tmp[74] = udata->p[2]*vB_tmp[74]-udata->k[0]*udata->p[2]*vB_tmp[75]*udata->w[3];
  JvB_tmp[75] = udata->p[3]*vB_tmp[75]-udata->p[3]*vB_tmp[76]*2.0;
  JvB_tmp[76] = udata->p[3]*vB_tmp[76]-udata->p[3]*vB_tmp[77];
  JvB_tmp[77] = udata->p[3]*vB_tmp[77]-udata->p[3]*vB_tmp[78];
  JvB_tmp[78] = udata->p[3]*vB_tmp[78]-udata->p[3]*vB_tmp[79];
  JvB_tmp[79] = udata->p[3]*vB_tmp[79]-udata->p[3]*vB_tmp[80];
  JvB_tmp[80] = udata->p[3]*vB_tmp[80]-udata->k[1]*udata->p[3]*vB_tmp[72]*udata->w[2];
  JvB_tmp[81] = udata->p[0]*vB_tmp[0]*udata->w[8]-udata->p[0]*vB_tmp[1]*udata->w[8]+udata->p[0]*vB_tmp[81]*udata->w[0]-udata->p[0]*vB_tmp[82]*udata->w[0];
  JvB_tmp[82] = udata->p[1]*vB_tmp[1]*x_tmp[82]*4.0+udata->p[1]*vB_tmp[82]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[82]*2.0-udata->p[1]*vB_tmp[83]*x_tmp[1]*2.0;
  JvB_tmp[83] = udata->p[2]*vB_tmp[83]-udata->k[0]*udata->p[2]*vB_tmp[84]*udata->w[3];
  JvB_tmp[84] = udata->p[3]*vB_tmp[84]-udata->p[3]*vB_tmp[85]*2.0;
  JvB_tmp[85] = udata->p[3]*vB_tmp[85]-udata->p[3]*vB_tmp[86];
  JvB_tmp[86] = udata->p[3]*vB_tmp[86]-udata->p[3]*vB_tmp[87];
  JvB_tmp[87] = udata->p[3]*vB_tmp[87]-udata->p[3]*vB_tmp[88];
  JvB_tmp[88] = udata->p[3]*vB_tmp[88]-udata->p[3]*vB_tmp[89];
  JvB_tmp[89] = udata->p[3]*vB_tmp[89]-udata->k[1]*udata->p[3]*vB_tmp[81]*udata->w[2];
  JvB_tmp[90] = udata->p[0]*vB_tmp[0]*udata->w[9]-udata->p[0]*vB_tmp[1]*udata->w[9]+udata->p[0]*vB_tmp[90]*udata->w[0]-udata->p[0]*vB_tmp[91]*udata->w[0];
  JvB_tmp[91] = udata->p[1]*vB_tmp[1]*x_tmp[91]*4.0+udata->p[1]*vB_tmp[91]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[91]*2.0-udata->p[1]*vB_tmp[92]*x_tmp[1]*2.0;
  JvB_tmp[92] = udata->p[2]*vB_tmp[92]-udata->k[0]*udata->p[2]*vB_tmp[93]*udata->w[3];
  JvB_tmp[93] = udata->p[3]*vB_tmp[93]-udata->p[3]*vB_tmp[94]*2.0;
  JvB_tmp[94] = udata->p[3]*vB_tmp[94]-udata->p[3]*vB_tmp[95];
  JvB_tmp[95] = udata->p[3]*vB_tmp[95]-udata->p[3]*vB_tmp[96];
  JvB_tmp[96] = udata->p[3]*vB_tmp[96]-udata->p[3]*vB_tmp[97];
  JvB_tmp[97] = udata->p[3]*vB_tmp[97]-udata->p[3]*vB_tmp[98];
  JvB_tmp[98] = udata->p[3]*vB_tmp[98]-udata->k[1]*udata->p[3]*vB_tmp[90]*udata->w[2];
  JvB_tmp[99] = udata->p[0]*vB_tmp[99]*udata->w[0]-udata->p[0]*vB_tmp[100]*udata->w[0];
  JvB_tmp[100] = udata->p[1]*vB_tmp[1]*x_tmp[100]*4.0+udata->p[1]*vB_tmp[100]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[100]*2.0-udata->p[1]*vB_tmp[101]*x_tmp[1]*2.0;
  JvB_tmp[101] = udata->p[2]*vB_tmp[101]-udata->k[0]*udata->p[2]*vB_tmp[102]*udata->w[3];
  JvB_tmp[102] = udata->p[3]*vB_tmp[102]-udata->p[3]*vB_tmp[103]*2.0;
  JvB_tmp[103] = udata->p[3]*vB_tmp[103]-udata->p[3]*vB_tmp[104];
  JvB_tmp[104] = udata->p[3]*vB_tmp[104]-udata->p[3]*vB_tmp[105];
  JvB_tmp[105] = udata->p[3]*vB_tmp[105]-udata->p[3]*vB_tmp[106];
  JvB_tmp[106] = udata->p[3]*vB_tmp[106]-udata->p[3]*vB_tmp[107];
  JvB_tmp[107] = udata->p[3]*vB_tmp[107]-udata->k[1]*udata->p[3]*vB_tmp[99]*udata->w[2];
  JvB_tmp[108] = udata->p[0]*vB_tmp[108]*udata->w[0]-udata->p[0]*vB_tmp[109]*udata->w[0];
  JvB_tmp[109] = udata->p[1]*vB_tmp[1]*x_tmp[109]*4.0+udata->p[1]*vB_tmp[109]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[109]*2.0-udata->p[1]*vB_tmp[110]*x_tmp[1]*2.0;
  JvB_tmp[110] = udata->p[2]*vB_tmp[110]-udata->k[0]*udata->p[2]*vB_tmp[111]*udata->w[3];
  JvB_tmp[111] = udata->p[3]*vB_tmp[111]-udata->p[3]*vB_tmp[112]*2.0;
  JvB_tmp[112] = udata->p[3]*vB_tmp[112]-udata->p[3]*vB_tmp[113];
  JvB_tmp[113] = udata->p[3]*vB_tmp[113]-udata->p[3]*vB_tmp[114];
  JvB_tmp[114] = udata->p[3]*vB_tmp[114]-udata->p[3]*vB_tmp[115];
  JvB_tmp[115] = udata->p[3]*vB_tmp[115]-udata->p[3]*vB_tmp[116];
  JvB_tmp[116] = udata->p[3]*vB_tmp[116]-udata->k[1]*udata->p[3]*vB_tmp[108]*udata->w[2];
  JvB_tmp[117] = udata->p[0]*vB_tmp[117]*udata->w[0]-udata->p[0]*vB_tmp[118]*udata->w[0];
  JvB_tmp[118] = udata->p[1]*vB_tmp[1]*x_tmp[118]*4.0+udata->p[1]*vB_tmp[118]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[118]*2.0-udata->p[1]*vB_tmp[119]*x_tmp[1]*2.0;
  JvB_tmp[119] = udata->p[2]*vB_tmp[119]-udata->k[0]*udata->p[2]*vB_tmp[120]*udata->w[3];
  JvB_tmp[120] = udata->p[3]*vB_tmp[120]-udata->p[3]*vB_tmp[121]*2.0;
  JvB_tmp[121] = udata->p[3]*vB_tmp[121]-udata->p[3]*vB_tmp[122];
  JvB_tmp[122] = udata->p[3]*vB_tmp[122]-udata->p[3]*vB_tmp[123];
  JvB_tmp[123] = udata->p[3]*vB_tmp[123]-udata->p[3]*vB_tmp[124];
  JvB_tmp[124] = udata->p[3]*vB_tmp[124]-udata->p[3]*vB_tmp[125];
  JvB_tmp[125] = udata->p[3]*vB_tmp[125]-udata->k[1]*udata->p[3]*vB_tmp[117]*udata->w[2];
  JvB_tmp[126] = udata->p[0]*vB_tmp[126]*udata->w[0]-udata->p[0]*vB_tmp[127]*udata->w[0];
  JvB_tmp[127] = udata->p[1]*vB_tmp[1]*x_tmp[127]*4.0+udata->p[1]*vB_tmp[127]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[127]*2.0-udata->p[1]*vB_tmp[128]*x_tmp[1]*2.0;
  JvB_tmp[128] = udata->p[2]*vB_tmp[128]-udata->k[0]*udata->p[2]*vB_tmp[129]*udata->w[3];
  JvB_tmp[129] = udata->p[3]*vB_tmp[129]-udata->p[3]*vB_tmp[130]*2.0;
  JvB_tmp[130] = udata->p[3]*vB_tmp[130]-udata->p[3]*vB_tmp[131];
  JvB_tmp[131] = udata->p[3]*vB_tmp[131]-udata->p[3]*vB_tmp[132];
  JvB_tmp[132] = udata->p[3]*vB_tmp[132]-udata->p[3]*vB_tmp[133];
  JvB_tmp[133] = udata->p[3]*vB_tmp[133]-udata->p[3]*vB_tmp[134];
  JvB_tmp[134] = udata->p[3]*vB_tmp[134]-udata->k[1]*udata->p[3]*vB_tmp[126]*udata->w[2];
  JvB_tmp[135] = udata->p[0]*vB_tmp[135]*udata->w[0]-udata->p[0]*vB_tmp[136]*udata->w[0];
  JvB_tmp[136] = udata->p[1]*vB_tmp[1]*x_tmp[136]*4.0+udata->p[1]*vB_tmp[136]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[136]*2.0-udata->p[1]*vB_tmp[137]*x_tmp[1]*2.0;
  JvB_tmp[137] = udata->p[2]*vB_tmp[137]-udata->k[0]*udata->p[2]*vB_tmp[138]*udata->w[3];
  JvB_tmp[138] = udata->p[3]*vB_tmp[138]-udata->p[3]*vB_tmp[139]*2.0;
  JvB_tmp[139] = udata->p[3]*vB_tmp[139]-udata->p[3]*vB_tmp[140];
  JvB_tmp[140] = udata->p[3]*vB_tmp[140]-udata->p[3]*vB_tmp[141];
  JvB_tmp[141] = udata->p[3]*vB_tmp[141]-udata->p[3]*vB_tmp[142];
  JvB_tmp[142] = udata->p[3]*vB_tmp[142]-udata->p[3]*vB_tmp[143];
  JvB_tmp[143] = udata->p[3]*vB_tmp[143]-udata->k[1]*udata->p[3]*vB_tmp[135]*udata->w[2];
  JvB_tmp[144] = udata->p[0]*vB_tmp[144]*udata->w[0]-udata->p[0]*vB_tmp[145]*udata->w[0];
  JvB_tmp[145] = udata->p[1]*vB_tmp[1]*x_tmp[145]*4.0+udata->p[1]*vB_tmp[145]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[145]*2.0-udata->p[1]*vB_tmp[146]*x_tmp[1]*2.0;
  JvB_tmp[146] = udata->p[2]*vB_tmp[146]-udata->k[0]*udata->p[2]*vB_tmp[147]*udata->w[3];
  JvB_tmp[147] = udata->p[3]*vB_tmp[147]-udata->p[3]*vB_tmp[148]*2.0;
  JvB_tmp[148] = udata->p[3]*vB_tmp[148]-udata->p[3]*vB_tmp[149];
  JvB_tmp[149] = udata->p[3]*vB_tmp[149]-udata->p[3]*vB_tmp[150];
  JvB_tmp[150] = udata->p[3]*vB_tmp[150]-udata->p[3]*vB_tmp[151];
  JvB_tmp[151] = udata->p[3]*vB_tmp[151]-udata->p[3]*vB_tmp[152];
  JvB_tmp[152] = udata->p[3]*vB_tmp[152]-udata->k[1]*udata->p[3]*vB_tmp[144]*udata->w[2];
  JvB_tmp[153] = udata->p[0]*vB_tmp[153]*udata->w[0]-udata->p[0]*vB_tmp[154]*udata->w[0];
  JvB_tmp[154] = udata->p[1]*vB_tmp[1]*x_tmp[154]*4.0+udata->p[1]*vB_tmp[154]*x_tmp[1]*4.0-udata->p[1]*vB_tmp[2]*x_tmp[154]*2.0-udata->p[1]*vB_tmp[155]*x_tmp[1]*2.0;
  JvB_tmp[155] = udata->p[2]*vB_tmp[155]-udata->k[0]*udata->p[2]*vB_tmp[156]*udata->w[3];
  JvB_tmp[156] = udata->p[3]*vB_tmp[156]-udata->p[3]*vB_tmp[157]*2.0;
  JvB_tmp[157] = udata->p[3]*vB_tmp[157]-udata->p[3]*vB_tmp[158];
  JvB_tmp[158] = udata->p[3]*vB_tmp[158]-udata->p[3]*vB_tmp[159];
  JvB_tmp[159] = udata->p[3]*vB_tmp[159]-udata->p[3]*vB_tmp[160];
  JvB_tmp[160] = udata->p[3]*vB_tmp[160]-udata->p[3]*vB_tmp[161];
  JvB_tmp[161] = udata->p[3]*vB_tmp[161]-udata->k[1]*udata->p[3]*vB_tmp[153]*udata->w[2];
return(status);

}


