/*
 * algorithm.h
 *
 *  Created on: 26 de nov de 2016
 *      Author: Wenderson
 */

#ifndef CG_SRC_ALGORITHM_H_
#define CG_SRC_ALGORITHM_H_

// Compiler libraries
#include "r_cg_macrodriver.h"

// Hardware assignments
#define REFERENCE_MICROPHONE	((uint16_t)(S12AD.ADDR2))
#define ERROR_MICROPHONE		((uint16_t)(S12AD.ADDR3))
#define AUDIO_OUTPUT(X)			(DA.DADR0 = (uint16_t)((X) & 0x00FFU))

// Customization parameters
#define ALG_N_COEF				50
#define ALG_LMS_STEP			(150)	//32768 * 0.0001;

#define mul(a,b) ((int16_t)((int32_t)(a * b) / 16384))

// Code generation needs - DO NOT CHANGE!
#ifndef TRUE
	#define TRUE	1
#endif
#ifndef FALSE
	#define FALSE	0
#endif
#if (TRUE == FALSE)
	#error "TRUE definition macro can't be equals FALSE definition macro!"
#endif

// External function prototype
void Ad_interrupt(void);

#endif /* CG_SRC_ALGORITHM_H_ */
