/**
* @file profilingFxn.c
* @brief defines functions to profile standard library versions, non-DMA,
* non-DMA optimized using -o3 and DMA versions of memmove and memzero/memset.
* Setting compile time flags will choose the target specific code
* @author Anay Gondhalekar
* @date 12/08/2017
**/

#include "profiler.h"
#include "memory.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#define FRDM
#define size 10
#ifdef FRDM
#include "MKL25Z4.h"
#include "dma.h"
#endif

struct timeval initial, final;
#define CLOCKTIME 0.0477
#define RESET_VALUE (0x00)
#define PRESCALAR (0x04)
#define MCGFLLCLK_VAL (0x1)
#define LPTPM_INCREMENT (0x1)
#define LPTPM_DISABLE (0x0)
#define OVERFLOW_VAL (0xFFFF)

#ifdef FRDM

/*function to configure TPM0 counter*/
void init_TPM0(){
	/*Clock gate control for TPM0*/
	SIM->SCGC6|=SIM_SCGC6_TPM0_MASK;

	/*selecting MCGFLLCLK as TPM clock source*/
	SIM_SOPT2|=SIM_SOPT2_TPMSRC(MCGFLLCLK_VAL);

	/*Clear SC register*/
	TPM0_SC=RESET_VALUE;

	/*clear count value*/
	TPM0_CNT=RESET_VALUE;

	/*Setting modulo value*/
	TPM0_MOD=OVERFLOW_VAL;

	/*Clear timer overflow flag*/
	TPM0_SC|=TPM_SC_TOF_MASK;

	/*Enable timer overflow interrupt*/
	TPM0_SC|=TPM_SC_TOIE_MASK;
}


/*function to start timer counter*/
void TPM0_start(){

	/*set count value to 0*/
	TPM0_CNT=RESET_VALUE;

	/*Enable LPTPM counter increment*/
	TPM0_SC|= TPM_SC_CMOD(LPTPM_INCREMENT);
}


/*Function to stop timer counter*/
void TPM0_stop(){

	/*stop the counter*/
	TPM0_SC |= TPM_SC_CMOD(LPTPM_DISABLE);
}

#endif

/*function to calculate time difference in microseconds*/
uint32_t timetaken(){
	uint32_t initial_us,final_us,diff_us;
	initial_us= (uint32_t)initial.tv_sec*1000000 + (uint32_t)initial.tv_usec;
	final_us= (uint32_t)final.tv_sec*1000000 + (uint32_t)final.tv_usec;
	diff_us=final_us-initial_us;
	return diff_us;
}


/*function to start profiler to calculate timer taken by each
 * function for different transfer sizes in microseconds*/
void Profiler_run()
{

	uint8_t source[size]={0,1,2,3,4,5,6,7,8,9};
	uint8_t dest[size];
#ifdef FRDM
	init_TPM0();
	TPM0_start();

	//my_memmove((uint8_t *)&source,(uint8_t*)&dest,(uint32_t)size); //my_memmove
	TPM0_stop();

	memmove_dma((uint16_t*)&source[0],(uint16_t*)&dest[0],10); // dma-


#endif

#ifdef BBB

	struct timeval initial, final;
	gettimeofday(&initial,NULL);

	my_memmove((uint8_t*)&source,(uint8_t*)&dest,(uint32_t)size);//my_memmove
	my_memset((uint8_t *)&source,(uint32_t)size,(uint8_t) 0); //my_memset
	memmove((uint8_t*)&dest,(uint8_t*)&source,(uint32_t)size); //std memmove
	memset((uint8_t*)&source,(uint8_t) 0,(uint32_t) size); //std memset

	gettimeofday(&final,NULL);
	uint32_t diff=0;
	diff=timetaken();

	#endif

}




