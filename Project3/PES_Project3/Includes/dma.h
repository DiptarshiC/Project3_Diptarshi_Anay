/**
 * @file dma.h
 *
 * @brief file containing the function declarations of all dma functions
 *
 * @date Nov 25, 2017
 *
 * @author: Diptarshi Chakraborty
 *
 */

#ifndef INCLUDES_DMA_H_
#define INCLUDES_DMA_H_
#include <stdint.h>


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
uint8_t* memmove_dma(uint8_t *src, uint8_t *dst, uint32_t length);

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
uint8_t* memzero_dma(uint8_t *src, uint32_t length);

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
void DMA0_IRQHandler();


#endif /* INCLUDES_DMA_H_ */
