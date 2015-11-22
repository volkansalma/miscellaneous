/*
 * Filename: dft.h
 * Author: Volkan Salma
 * Created: 16.11.2015
 */
 
#ifndef DFT_H
#define DFT_H

void dft(const float *samples, const int sample_size,
		 float *ret_reel_coeffs, float *ret_img_coeffs);

void inv_dft(const float *reel_coeffs, const float *img_coeffs, 
			 const int sample_size, float *ret_reel_samples);

#endif
