
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCntrl.h"
#ifdef __cplusplus
	};
#endif

void FB_Regulator(struct FB_Regulator* inst)
{
	
	REAL in_BON=0; REAL sum_after = 0;
	inst->integrator.in=inst->e * inst->K_i * inst->dt + inst->iyOld;
	FB_Integrator(&(inst->integrator));
	in_BON = inst-> e * inst->K_p;
	
	if(in_BON > inst->max_abs_value) 
	{in_BON = inst->max_abs_value;}
	
	sum_after = in_BON + inst->integrator.out;
	if(sum_after > inst->max_abs_value) 
	{inst->u = inst->max_abs_value;}
	else {inst->u = sum_after;}
	inst->iyOld =inst->u - sum_after;
}
