/*
 * fir.h
 *
 *  Created on: 27 de nov de 2016
 *      Author: Wenderson
 */

#ifndef FIR_H_
#define FIR_H_

// Common definitions
#include "algorithm.h"

// Configuration parameters
#define FIR_N_COEF				ALG_N_COEF 	// Use the number of coefficients defined by algorithm.h

// External function prototype
int16_t Fir_filter(int16_t *input, int16_t *filter);

#endif /* FIR_H_ */
