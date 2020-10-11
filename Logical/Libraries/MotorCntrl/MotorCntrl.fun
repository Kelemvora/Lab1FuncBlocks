
{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FB_Motor (*Motor Model*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u : {REDUND_UNREPLICABLE} REAL; (*input voltage*)
	END_VAR
	VAR_OUTPUT
		w : {REDUND_UNREPLICABLE} REAL; (*rotation speed*)
		phi : {REDUND_UNREPLICABLE} REAL; (*position*)
	END_VAR
	VAR
		integrator : {REDUND_UNREPLICABLE} FB_Integrator; (*integrator*)
		Tm : {REDUND_UNREPLICABLE} REAL; (*Tm*)
		Ke : {REDUND_UNREPLICABLE} REAL; (*Ke*)
		dt : {REDUND_UNREPLICABLE} REAL; (*calc step*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK FB_Integrator (*Integrator*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		in : {REDUND_UNREPLICABLE} REAL; (*inp_integrator*)
	END_VAR
	VAR_OUTPUT
		out : {REDUND_UNREPLICABLE} REAL; (*out_integrator*)
	END_VAR
	VAR
		dt : {REDUND_UNREPLICABLE} REAL; (*calc_step*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK FB_Regulator (*PI regulator*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		e : {REDUND_UNREPLICABLE} REAL; (*Disagreement*)
	END_VAR
	VAR_OUTPUT
		u : {REDUND_UNREPLICABLE} REAL; (*voltage *)
	END_VAR
	VAR
		K_p : {REDUND_UNREPLICABLE} REAL; (*K_p*)
		K_i : {REDUND_UNREPLICABLE} REAL; (*K_i*)
		integrator : {REDUND_UNREPLICABLE} FB_Integrator; (*integrator*)
		iyOld : {REDUND_UNREPLICABLE} REAL; (*storing the value*)
		max_abs_value : {REDUND_UNREPLICABLE} REAL; (*edge of restriction block*)
		dt : {REDUND_UNREPLICABLE} REAL; (*calc_step*)
	END_VAR
END_FUNCTION_BLOCK
