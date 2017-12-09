/*
 * dma.h
 *
 *  Created on: Dec 4, 2017
 *      Author: Anay
 */
/**
* @file dma.c
* @brief This file is used to manipulate data in dma as well as direct memory and allocate
* space in memory
* @author Anay Gondhalekar & Diptarshi Chakraborty
* @date 12/8/2017
**/

#include<stdio.h>
#include<stdint.h>

#ifndef INCLUDES_DMA_H_
#define INCLUDES_DMA_H_

uint8_t* my_memmove(uint8_t* src,uint8_t* dst,size_t length);
/*This is a function that copies the data in the source pointer to the destination
* pointer.It does takes care of overlap.The inputs are the source pointer,the destination
* pointer and the length of both the pointer arrays.Both the pointers are first incremented
* till the end of the pointer array then the source and the destination
* pointer is dereferenced where one is copied to the other.Both the pointers are then
* decremented till the length of the pointers.*/

int8_t* my_memset(uint8_t* src,size_t length,uint8_t value);
/*This function sets all the indices of a given pointer array to a given value
* It takes the source pointer and the value as the input and fills it with the values at every index*/

uint8_t* memmove_dma(uint8_t *src, uint8_t *dst, uint32_t length);
/* This function uses dma to copy data from source to destination handling the overlap*/

uint8_t* memset_dma(uint8_t* src,size_t length,uint8_t value);
/* Sets the given data at source to the desired value using dma transfer.*/

#endif /* INCLUDES_DMA_H_ */
