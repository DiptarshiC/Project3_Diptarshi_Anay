/*
 * cirbuf2.h
 *
 *  Created on: Dec 6, 2017
 *      Author: USER
 */

#ifndef INCLUDES_CIRBUF2_H_
#define INCLUDES_CIRBUF2_H_

/*****************************************************************************************************************************************
*@file:cirbuf2.h
*@brief:this file contains all the function declarations of the circular buffer functions and also the declaration of a typedef enum for
*for a circular buffer as well as definition of a circular buffer structure.
*@Author:Diptarshi Chakraborty
*@Date:10/22/2017
********************************************************************************************************************************************/

#include<stdio.h>
#include<stdint.h>
/*******************************************************************************************************************************************
*Below the strucutre of a circular buffer has been defined
*The size of each item is of uint8_t
*
*******************************************************************************************************************************************/
typedef struct {
	uint8_t *buff_point;	//pointer to the buffer
	uint8_t *head;		//Where to add an item
	uint8_t *tail;	//Where to remove an item
	size_t  size;		//No. of items allocated to the buffer
	size_t count;	//number of items currently in the buffer
	}CB_t1;


typedef enum {
	buff_full,
	buff_empty,
	success,
	NULL_Error		//Buffer allocation failure
	}CB_status1;
CB_status1 error_message;
/*********************************************************************************************************************************************
/*********************************************************************************************************************************************
*@function name:CB_buffer_add_item(CB_t1 *q,	uint8_t data)
*@brief:Function to add item to buffer
*The function takes a buffer pointer and the data to be added and completes the operarion returning the result of the operation.It checks
*whether the buffer is full or not.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message saying the operation is a success.
*@param:CB_t *q,uint8_t data which is a circular buffer pointer and a unsigned integer type data
*@return:CB_status, an enum which returns the data type.
*
**********************************************************************************************************************************************/
CB_status1 CB_buffer_add_item1(CB_t1 *q,	uint8_t data);


/*********************************************************************************************************************************************
*@function name:CB_buffer_remove_item(CB_t *q,	uint8_t data)
*@brief:Function to remove item to buffer
*The function takes a buffer pointer and the data to be removed and completes the operarion returning the result of the operation.It checks
*whether the buffer is empty.If it is empty it shall return an error message saying the circular buffer is empty.In all other cases the
*function returns a message saying the operation is a success.
*@param:CB_t *q,uint8_t data which is a circular buffer pointer and a unsigned integer type variable named data to store the removed item
*@return:CB_status, an enum which returns the data type.
*
*
**********************************************************************************************************************************************/
CB_status1 CB_buffer_remove_item1(CB_t1 *q,uint8_t *data);


/*********************************************************************************************************************************************
*@function name:CB_is_full(CB_t *q)
*@brief:Function to remove item to check whether the function is full
*The function takes a buffer pointer.It checks
*whether the buffer is full.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message or an error code.
*@param:CB_t *q
*@return:CB_status, an enum which returns the data type.
*
**********************************************************************************************************************************************/
CB_status1 CB_is_full1(CB_t1 *q);


/*********************************************************************************************************************************************
*@function name:CB_is_full(CB_t *q)
*@brief:Function to remove item to check whether the function is empty
*The function takes a buffer pointer.It checks
*whether the buffer is empty.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message or an error code.
*@param:CB_t *q
*@return:CB_status, an enum which returns the data type.
**********************************************************************************************************************************************/
CB_status1 CB_is_empty1(CB_t1 *q);


/*********************************************************************************************************************************************
*@function name:CB_init(CB_t *q,size_t size)
*@brief:Function to initalize a Circular buffer
*The function takes a buffer pointer and the size of the buffer
*function returns a message or an error code.
*@param:CB_t *q
*@return:CB_status, an enum which returns the data type.
*
**********************************************************************************************************************************************/
CB_status1 CB_init1(CB_t1 *q,size_t size);

/*********************************************************************************************************************************************
*@function name:CB_destroy(CB_t *q,size_t size)
*@brief:Function to destroy a Circular buffer
*The function takes a buffer pointer.
*function returns a message or an error code.
*@param:CB_t *q
*@return:CB_status, an enum which returns the data type.
*
**********************************************************************************************************************************************/
CB_status1 CB_destroy1(CB_t1 *q);

/*********************************************************************************************************************************************
*@function name:CB_peek(CB_t *q,size_t pos,size_t *point)
*@brief:Function to peek into a position in a circular buffer
*The function takes a buffer pointer, the position from the head and a pointer to return that position
*function returns a message or an error code.
*@param:CB_t *q,size_t pos, size_t *point
*@return:CB_status, an enum which returns the data type.
*
**********************************************************************************************************************************************/
CB_status1 CB_peek1(CB_t1 *q,uint8_t pos,uint8_t *point);





#endif /* INCLUDES_CIRBUF2_H_ */
