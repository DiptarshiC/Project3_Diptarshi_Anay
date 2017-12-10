/*
 * profiler.h
 *
 *  Created on: Dec 8, 2017
 *      Author: Anay
 */
#include <stdio.h>
#include <stdint.h>
#ifndef INCLUDES_PROFILER_H_
#define INCLUDES_PROFILER_H_
#define FRDM

#ifdef FRDM


/******************************************************************
* init_TPM0() - This function configures TPM0 counter
******************************************************************/
void init_TPM0();


/******************************************************************
* TPM0_start() - This function starts TPM0 counter
******************************************************************/
void TPM0_start();


/******************************************************************
* TPM0_stop() - This function stops TPM0 counter
******************************************************************/
void TPM0_stop();

#endif


/**********************************************************************
* Profiler_run() - This function starts the profiler to calculate time
* taken by various function
***********************************************************************/
void Profiler_run(void);


/*********************************************************************
* timetaken() - This function calculates difference between initial
* and final time in microseconds
*********************************************************************/
uint32_t timetaken (void);

#endif /* INCLUDES_PROFILER_H_ */
