/*
 * Filename: dft.c
 * Author: Volkan Salma
 * Created: 16.11.2015
 */

#include <math.h>

#include "dft.h"

/*
  Discrete Fourier Transform
*/
void dft(const float *samples, const int sample_size,
		 float *ret_reel_coeffs, float *ret_img_coeffs)
{
	float i, r;
	int n, k;
	
	for(k = 0; k < sample_size; k++){
		i = 0;
		r = 0;

		for(n = 0; n < sample_size; n++){
			r += samples[n] * cos(-2 * M_PI * k * n / sample_size);
			i += samples[n] * sin(-2 * M_PI * k * n / sample_size);
		}

		ret_reel_coeffs[k] = r;
		ret_img_coeffs[k] = i;
	}
}

/*
  Inverse Discrete Fourier Transform
*/
void inv_dft(const float *reel_coeffs, const float *img_coeffs, 
			 const int sample_size, float *ret_reel_samples)
{
	float r;
	int n, k;

	for(k = 0; k < sample_size; k++){
		r = 0;

		for(n = 0; n < sample_size; n++){
			r += reel_coeffs[n] * cos(2 * M_PI * k * n / sample_size);
			r -= img_coeffs[n] * sin(2 * M_PI * k * n / sample_size);
		}

		ret_reel_samples[k] = r / sample_size;
	}
}
