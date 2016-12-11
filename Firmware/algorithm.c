/*
 * algorithm.c
 *
 *  Created on: 26 de nov de 2016
 *      Author: Wenderson
 */

#include "algorithm.h"

void Ad_interrupt(void)
{
	volatile int16_t  normalizedRef;
	volatile int16_t  normalizedErr;
	volatile int16_t  lmsResult;
	volatile uint16_t unsignedResult;
	volatile uint8_t  output;

	// Normalize the sample to Q0.15 (the original ad resolution was unsigned 12 bits)
	// unsigned Q12 << 3 = unsigned Q15
	// unsigned Q15 - (Q15MAX / 2) = signed Q15
	normalizedRef = (int16_t)((REFERENCE_MICROPHONE << 3) - 16384);
	normalizedErr = (int16_t)((ERROR_MICROPHONE 	<< 3) - 16384);

	// Adaptative filtering
	lmsResult = Lms_update(normalizedRef, normalizedErr);

	// Remove the signal of lms result by inserting a DC level of 50%
	// Signed Q15 + Q(15MAX / 2) = unsigned Q15
	unsignedResult = (uint16_t)(lmsResult + (int16_t)16384);

	// Normalize the output data to Q8 (unsigned 8 bits)
	output = (uint8_t)(unsignedResult >> 7);

	// Output the resulting data into 8 bits DAC
	AUDIO_OUTPUT(output);
}
