/*
 * Filename: main.c
 * Author: Volkan Salma
 * Created: 19.11.2015
 */
 
#include <stdio.h>

#include "pid.h"

/*
  Example usage for PID module 
*/
int main()
{
	PID my_pid;
	int i;
	float calc;

	/*init PID for 50 Hz, -100,100 range */
	pid_init(&my_pid, (float)(1.0 / 50), -100, 100);

	/* Set Kp = 0.7, Ki = 0.001, Kd = 0.0005 */
	pid_set(&my_pid, 0.7, 0.001, 0.0005);

	for (i = 0; i < 100; i++){
		calc = pid_calc(&my_pid, 50, (float)i);
		printf("PID controller output[%d]: %f\n", i, calc);
	}
	return 0;
}
