/**
 * @file dma.c
 *
 * @brief file containing the function definition of all dma functions
 *
 * @date Nov 25, 2017
 *
 * @author: Diptarshi Chakraborty
 *
 */

#include <stdint.h>
#include "dma.h";
#include "MKL25Z4.h"
/**
 * @brief moves a chunk of memory from one location to another using DMA module
 *
 *
 *
 * @param pointer to the source, pointer to the destination, length of bytes to transfer
 *
 * @return pointer to the address
 *
 */

uint8_t* memmove_dma(uint8_t *src, uint8_t *dst, uint32_t length){

	// Clock Gate enabled for DMA and DMAMUX
		SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
		SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;

		// Disable channel 0 before initializing
		DMAMUX0_CHCFG0 &= ~DMAMUX_CHCFG_ENBL_MASK;
		DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;

		// Give Source and Destination address and Avoid Overlap
	    if(dst<src || dst>(src+length))
	    {
		DMA_SAR0 =  src;
		DMA_DAR0 =  dst;
	    }



	    DMA_DSR_BCR0 |= length;  		// Totoal Number of Bytes to transfer
		DMA_DCR0 |= DMA_DCR_SINC_MASK;	// Increase Source Address after every transfer
		DMA_DCR0 |= DMA_DCR_SSIZE(1);	// Transfer Size- 8 or 32 bit
		DMA_DCR0 |= DMA_DCR_DINC_MASK;	// Increase Destination Address after every transfer
		DMA_DCR0 |= DMA_DCR_DSIZE(1);	// Transfer Size- 8 or 32 bit


		DMA_DCR0 |= DMA_DCR_EINT_MASK;	// Enable DMA Interrupt
		NVIC_EnableIRQ(DMA0_IRQn);
		__enable_irq;



		// Enable channel 0
		DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;


		//Start DMA Transfer
		DMA_DCR0 |= DMA_DCR_START_MASK;
}

/**
 * @brief makes a block of memory zero using the DMA module
 *
 *
 *
 * @param pointer to byte of source data,length of bytes to be made 0
 *
 * @return void
 *
 */
uint8_t* memzero_dma(uint8_t *src, uint32_t length){
				uint8_t array[1];
				array[0]=0;
			uint32_t i=0;
			// Clock Gate enabled for DMA and DMAMUX
			SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;
			SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;

			// Disable channel 0 before initializing
			DMAMUX0_CHCFG0 &= ~DMAMUX_CHCFG_ENBL_MASK;
			DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;

			// Give Source and Destination address

			// Give source address as address of 0 and Destination as array on which memzero in being performed
			DMA_SAR0 =  array;
			DMA_DAR0 =  src;

			DMA_DSR_BCR0 |= length;				// Number of Bytes in memzero
			DMA_DCR0 &= ~DMA_DCR_SINC_MASK;		// Do not increament source address
			DMA_DCR0 |= DMA_DCR_SSIZE(1);		// 8or 32 bit transfer at a time
			DMA_DCR0 |= DMA_DCR_DINC_MASK;		// Increament destination address after every transfer
			DMA_DCR0 |= DMA_DCR_DSIZE(1);		// 8or 32 bit transfer at a time

			DMA_DCR0 |= DMA_DCR_EINT_MASK;		// Enable DMA Interrupt
			NVIC_EnableIRQ(DMA0_IRQn);
			__enable_irq;

			// Enable channel 0
			DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;

			//pit_enable();


			//Start DMA Transfer
			DMA_DCR0 |= DMA_DCR_START_MASK;

}

/**
 * @brief IRQ handler of the DMA module
 *
 *
 *
 * @param void
 *
 * @return void
 *
 */
void DMA0_IRQHandler(){

	uint32_t i= DMA_DSR_BCR0;
	// Check source of interupt ; either done bit or CE bit
		if(DMA_DSR_BCR0 == DMA_DSR_BCR_DONE_MASK)
		{
					DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE_MASK;		// CLear done bit



		}

}
