/*
 * Filename: pid.h
 * Author: Volkan Salma
 * Created: 19.11.2015
 */
 
#ifndef PID_H
#define PID_H

typedef struct
{
	/* Settings */
	float kp;
	float ki;
	float kd;
	float dt;
	float out_min;
	float out_max;

	/* Controller memory */
	float prev_err;
	float err_sum;
}PID;

void pid_init(PID *pid, float dt, float out_min, float out_max);

void pid_set(PID *pid, float kp, float ki, float kd);

float pid_calc(PID *pid, float set_point, float feedback);

#endif
