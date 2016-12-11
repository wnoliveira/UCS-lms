/*
 * fir.c
 *
 *  Created on: 27 de nov de 2016
 *      Author: Wenderson
 */

#include "fir.h"

int16_t Fir_filter(int16_t *input, int16_t *filter)
{
	int32_t acc = 0;

	// Loop index
	#if (FIR_N_COEF <= 255)
		uint8_t i;
	#else
		uint16_t i;
	#endif

	for(i = 0; i < FIR_N_COEF; i++)
	{
		// Multiplication of Q0.15 * Q0.15 = Q0.30.
		// The 'mul' function implements a pseudo floating precision,
		// resulting in a Q0.15 answer.
		acc += mul(*(input + i), *(filter + i));
	}

	// Normalize result data in original format by dividing it by number of accumulations
	return (int16_t)(acc / FIR_N_COEF);
}
