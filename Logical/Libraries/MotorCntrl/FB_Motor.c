
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCntrl.h"
#ifdef __cplusplus
	};
#endif
/* Motor Model */
void FB_Motor(struct FB_Motor* inst)
{
	inst->integrator.in = (inst->u / inst->Ke - inst->w) * inst->dt / inst->Tm; 
	FB_Integrator(&(inst->integrator));
	inst->w = inst->integrator.out;	
	inst->integrator.in = inst->w * inst->dt;
	FB_Integrator(&(inst->integrator));
	inst->phi = inst->integrator.out;
}
