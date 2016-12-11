/*
 * lms.h
 *
 *  Created on: 26 de nov de 2016
 *      Author: Wenderson
 */

#ifndef LMS_H_
#define LMS_H_

// Common definitions
#include "algorithm.h"

// Configuration parameters
#define LMS_FILTER_N_COEF	ALG_N_COEF 	   	// Use the number of coefficients defined by algorithm.h
#define LMS_STEP			ALG_LMS_STEP	// Use the STEP defined by algorithm.h

// External functions prototype
int16_t Lms_update(int16_t reference, int16_t error);

#endif /* LMS_H_ */
