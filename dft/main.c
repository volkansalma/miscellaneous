/*
 * Filename: main.c
 * Author: Volkan Salma
 * Created: 16.11.2015
 */
 
#include <stdio.h>

#include "dft.h"

int main()
{
	float samples[20] = {55, 32, 7, -18, -41, -41, -41, -41, -41, 74,
						 74, -41, -48, -48, -43, -33, -19, -5, 7, 11};
 
	float coeff_reel[20];
	float coeff_img[20]; 
	int i;

	dft(samples, 20, coeff_reel, coeff_img);

	for(i = 0; i < 20; i++){
		printf("Reel[%d]=%f Image[%d]=%f\n", (i + 1), coeff_reel[i], 
				(i + 1), coeff_img[i]);
	}

	inv_dft(coeff_reel, coeff_img, 20, samples);
	
	for(i = 0; i < 20; i++){
		printf("invDft[%d]=%f\n", (i + 1), samples[i]);
	}

	return 0;
}
