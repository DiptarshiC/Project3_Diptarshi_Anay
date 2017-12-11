/*
 * dma.c
 *
 *  Created on: Dec 4, 2017
 *      Author: Anay Gondhalekar
 */

/**
* @file dma.c
* @brief This file is used to manipulate data in dma as well as direct memory and allocate
* space in memory
* @author Anay Gondhalekar & Diptarshi Chakraborty
* @date 12/8/2017
**/
#include "MKL25Z4.h"
#include <stdint.h>
#include <stdio.h>
#include "memory.h"
#include <malloc.h>


uint8_t* memmove_dma(uint8_t *src, uint8_t *dst, uint32_t length)
{
	  uint8_t *result;
	  size_t overlap = 0;
		// Clock Gate enabled for DMA and DMAMUX
		SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
		SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;

		// Disable channel 0 before initializing
		DMAMUX0_CHCFG0 &= ~DMAMUX_CHCFG_ENBL_MASK;
		DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;

	  if (NULL == src || NULL == dst || 0 == length)
	    {
	    result = NULL;
	    }
	  else
	  {
		    if (src < dst)
		      /* Start of source is lower in memory than the destination. */
		      {
		      if (src + length > dst)
		        {
		        overlap = src + length - dst;
		        }
		      }

	DMA_SAR0 =  src + overlap;
	DMA_DAR0 =  dst + overlap;

    DMA_DSR_BCR0 |= length;  		// Total Number of Bytes to transfer
 //   DMA_DCR0 |= DMA_DCR_START_MASK;
	DMA_DCR0 |= DMA_DCR_SINC_MASK;	// Increase Source Address after every transfer
	DMA_DCR0 |= DMA_DCR_SSIZE(1);	// Transfer Size- 8 or 32 bit
	DMA_DCR0 |= DMA_DCR_DINC_MASK;	// Increase Destination Address after every transfer
	DMA_DCR0 |= DMA_DCR_DSIZE(1);	// Transfer Size- 8 or 32 bit

    //Unsure about interrupt currently
//	DMA_DCR0 |= DMA_DCR_EINT_MASK;	// Enable DMA Interrupt
//	NVIC_EnableIRQ(DMA0_IRQn);
//	__enable_irq;

	DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;
	DMA_DCR0 |= DMA_DCR_START_MASK;

	if(overlap != 0)
	    {
		DMA_SAR0 =  src ;
		DMA_DAR0 =  dst ;

	    DMA_DSR_BCR0 |= length;  		// Total Number of Bytes to transfer
	   // DMA_DCR0 |= DMA_DCR_START_MASK;
		DMA_DCR0 |= DMA_DCR_SINC_MASK;	// Increase Source Address after every transfer
		DMA_DCR0 |= DMA_DCR_SSIZE(1);	// Transfer Size- 8 or 32 bit
		DMA_DCR0 |= DMA_DCR_DINC_MASK;	// Increase Destination Address after every transfer
		DMA_DCR0 |= DMA_DCR_DSIZE(1);	// Transfer Size- 8 or 32 bit

		//Unsure about interrupt currently
		DMA_DCR0 |= DMA_DCR_EINT_MASK;	// Enable DMA Interrupt
//		NVIC_EnableIRQ(DMA0_IRQn);
//		__enable_irq;

		DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;
		DMA_DCR0 |= DMA_DCR_START_MASK;
	    }
	result = dst;
}
 return result;
}

uint8_t* memset_dma(uint8_t* src,size_t length,uint8_t value)
{
	   uint8_t *result;
	   uint8_t *val;
	   val = &value;
	// Clock Gate enabled for DMA and DMAMUX
		SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
		SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;

		// Disable channel 0 before initializing
		DMAMUX0_CHCFG0 &= ~DMAMUX_CHCFG_ENBL_MASK;
		DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;


		if (NULL == src || 0 == length)
		    {
		    result = NULL;
		    }
		else
		{
		DMA_SAR0 =  val;
		DMA_DAR0 =  src;

		DMA_DSR_BCR0 |= length;				// Number of Bytes in memset
		//DMA_DCR0 |= DMA_DCR_START_MASK;
		DMA_DCR0 &= ~DMA_DCR_SINC_MASK;		// Do not increment source address
		DMA_DCR0 |= DMA_DCR_SSIZE(1);		// 8 or 32 bit transfer at a time
		DMA_DCR0 |= DMA_DCR_DINC_MASK;		// Increment destination address after every transfer
		DMA_DCR0 |= DMA_DCR_DSIZE(1);		// 8or 32 bit transfer at a time


//		DMA_DCR0 |= DMA_DCR_EINT_MASK;		// Enable DMA Interrupt
//
//		NVIC_EnableIRQ(DMA0_IRQn);
//		__enable_irq;
		// Enable channel 0
		DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;
		DMA_DCR0 |= DMA_DCR_START_MASK;
		result = src;
		}
		return result;
}


uint8_t* my_memmove(uint8_t* src,uint8_t* dst,size_t length)
{
	size_t i=0;
	uint8_t* temp=(uint8_t*) malloc(sizeof(uint8_t)*length);


	if (NULL == src || NULL == dst || 0 == length)
	    {
	    dst = NULL;
	    }

	else
	{
	for(i=0;i<length;i++)
	{
		*(temp+i)=*(src+i);

	}
	        for(i=0;i<length;i++)
        {
                *(dst+i)=*(temp+i);

        }
	}


	return dst;
}

int8_t* my_memset(uint8_t* src,size_t length,uint8_t value)
	{
	size_t i;
    int8_t* isrc;
    if (NULL == src || 0 == length)
      {
      isrc = NULL;
      }
	for(i=0;i<length;i++){
		*(src)=value;
		src++;
	}
        isrc = (int8_t*)src;
	return isrc;
}

void DMA0_IRQHandler(){

	uint32_t i= DMA_DSR_BCR0;
	// Check source of interupt ; either done bit or CE bit
		if(DMA_DSR_BCR0 == DMA_DSR_BCR_DONE_MASK)
		{
					DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;		// CLear done bit



		}


