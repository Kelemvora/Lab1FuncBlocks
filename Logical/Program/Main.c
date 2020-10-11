
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	enable = 1;
	speed = 0;
	count = 0;
	
	fb_motor.u = 0;
	fb_motor.phi = 0;
	fb_motor.w = 0;
	fb_motor.Ke = 0.25;
	fb_motor.Tm = 0.1;
	fb_motor.dt = 0.02;;
	
	fb_motor_2.u = 0;
	fb_motor_2.phi = 0;
	fb_motor_2.w = 0;
	fb_motor_2.Ke = 0.25;
	fb_motor_2.Tm = 0.1;
	fb_motor_2.dt = 0.02;
	
	fb_controller.iyOld = 0;
	fb_controller.u = 0;
	/*fb_controller.K_p = fb_motor.Ke *fb_motor.Tm; */
	fb_controller.K_p = 0.025;
	/*fb_controller.K_i = fb_motor.Ke; */
	fb_controller.K_i = 0.25;
	fb_controller.max_abs_value=12;
	fb_controller.dt = 0.02;
}

void _CYCLIC ProgramCyclic(void)
{
	if(enable == 1)
	{
		/*
		count += 10;
		if(count<=5000)
		{
			speed=0;
		}
		else
		{
			speed=5;
			if(count >= 10000)
			{
				count = 0;
			}
		}
		*/
		
	/*need adjustment*/
		count += 100;
		if(count<5000)
		{
			speed=0;
		}
		else if( count >= 10000 && count <= 15000)
		{
			speed=5;
		}
		else {speed=0;}
		
		/*
		count += 100;
		if( (count >= 10000) && (count <=30000))
		{
			speed =3;
		}
		else {
			speed=0;
		}
		*/
		/* С регулятором: */
		fb_controller.e = speed - fb_motor.w;
		/*fb_controller.e = speed - fb_motor.phi;*/
		FB_Regulator(&fb_controller);
		fb_motor.u= fb_controller.u;
		FB_Motor(&fb_motor);
		
		/* Без регулятора: */
		fb_motor_2.u = speed - fb_motor_2.w;
		FB_Motor(&fb_motor_2);
		
	}
	
}

void _EXIT ProgramExit(void)
{

}

