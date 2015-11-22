/*
 * Filename: pid.c
 * Author: Volkan Salma
 * Created: 19.11.2015
 */

#include "pid.h"

/*
  Init the controller with setting sampling time and output limits
*/
void pid_init(PID *pid, float dt, float out_min, float out_max)
{
	pid->dt = dt;
	pid->out_min = out_min;
	pid->out_max = out_max;
}

/*
  Set controller coefficients
*/
void pid_set(PID *pid, float kp, float ki, float kd)
{
   pid->kp = kp;
   pid->ki = ki;
   pid->kd = kd;
}

/*
  PID output calculation according to feedback
*/
float pid_calc(PID *pid, float set_point, float feedback)
{ 
	float err;
	float d_err;
	float output;

	/* Error */
	err = set_point - feedback;

	/* Derivative of the error */
	d_err = (err - pid->prev_err) / pid->dt;

	/* Integral of the error */
	pid->err_sum += (err * pid->dt);

	/* clamp the integral error in output range */
	if ((pid->ki * pid->err_sum) > pid->out_max)
		pid->err_sum = pid->out_max / pid->ki;
	else if ((pid->ki * pid->err_sum) < pid->out_min)
		pid->err_sum = pid->out_min / pid->ki;

	/* PID calculation */
	output = (pid->kp * err) + (pid->ki * pid->err_sum) + (pid->kd * d_err);

	/* clamp the output in output range */
	if (output > pid->out_max)
		output = pid->out_max;
	else if (output < pid->out_min)
		output = pid->out_min;

	/* Keep the error for the next step*/
	pid->prev_err = err;
    
    return output;
}
