/*
 * lms.c
 *
 *  Created on: 26 de nov de 2016
 *      Author: Wenderson
 */

#include "lms.h"
#include "fir.h"

int16_t filter[LMS_FILTER_N_COEF];
int16_t inputBuffer[LMS_FILTER_N_COEF];

void Lms_init(void)
{
	#if (LMS_FILTER_N_COEF <= 255)
		uint8_t i;
	#else
		uint16_t i;
	#endif

	for(i = 0; i < LMS_FILTER_N_COEF; i++)
	{
		filter[i] = 0;
		inputBuffer[i] = 0;
	}
}

int16_t Lms_update(int16_t input, int16_t error)
{
	static int16_t output = 0;

	#if (LMS_FILTER_N_COEF <= 255)
		uint8_t i;
	#else
		uint16_t i;
	#endif

	// Input data shift
	for(i = (LMS_FILTER_N_COEF - 1); i; i--)
	{
		inputBuffer[i] = inputBuffer[i - 1];
	}
	inputBuffer[0] = input;

	// LMS algorithm
	output = Fir_filter(&inputBuffer[0], &filter[0]);
	for(i = 0; i < LMS_FILTER_N_COEF; i++)
	{
		//filter = filter + ((error * buff) * u);
		filter[i] = filter[i] + (mul(mul(error, inputBuffer[i]), LMS_STEP));
	}

	return output;
}



