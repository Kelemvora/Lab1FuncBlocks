
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "MotorCntrl.h"
#ifdef __cplusplus
	};
#endif
/* Integrator */
void FB_Integrator(struct FB_Integrator* inst)
{
	inst->out +=  inst->in;
}
