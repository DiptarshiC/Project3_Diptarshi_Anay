/*
 * cirbuf2.c
 *
 *  Created on: Dec 6, 2017
 *      Author: USER
 */


#include<stdint.h>
#include "cirbuf2.h"

/*****************************************************************************************************************************************
*@file:cirbuf.c
*@brief:this file contains all the function definitions of the circular buffer functions.It inherits all the global variables of cirbuf.h
*@Author:Diptarshi Chakraborty
*@Date:10/22/2017
********************************************************************************************************************************************/
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"cirbuf2.h"


/*****************************************************************************************************************************************
*@function name:CB_buffer_add_item(CB_t *q,	uint8_t data)
*@brief:Function to add item to buffer
*The function takes a buffer pointer and the data to be added and completes the operarion returning the result of the operation.It checks
*whether the buffer is full or not.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message saying the operation is a success.
*@param:CB_t *q,uint8_t data which is a circular buffer pointer and a unsigned integer type data
*@return:CB_status, an enum which returns the data type.
*******************************************************************************************************************************************/

CB_status1 CB_buffer_add_item1(CB_t1 *q,uint8_t data){

    if((q->head==(NULL))||(q->tail==(NULL))||(q->buff_point==(NULL)))/*This first if else condition checks whether there
							               is any NULL pointer error present in the CB
								       If there is, it will return a null pointer error*/
	error_message=NULL_Error;




      if(CB_is_full(q)==buff_full)
						       /*condition to check to check whether the buffer is full or not.
						         when the buffer is full head coincides with tail and the size is equal to the count
							 the buffer is said to be full
							 the error message of buff_full.*/
	{
		error_message=buff_full;
	}





	else if(((q->head)==(q->tail))&&((q->count)!=(q->size)))/*condition to check to check when the buffer is empty*/
	{


	error_message=success;
	*(q->head)=data;
	if((q->head)==(q->buff_point+q->size-1))		/*if the circular buffer reaches the tip of the allocated memory, it,should
								warp around and reach the base of the allocated memory.Otherwise it may just
								increment towards the limit*/
		{
			 (q->head)=(q->buff_point);
		}
	else
		{
			q->head=q->head+1;			//simply increment
		}
       	 q->count=q->count+1;				//count of the CB is incremented by 1
	}

	else
	{
		error_message=success;
      	        *(q->head)=data;
		if((q->head)==(q->buff_point+q->size-1))/*if the circular buffers head pointer reaches the tip of the allocated memory,itshould
						       warp around and reach the base of the allocated memory.Otherwise it may just
						       increment towards the limit*/
		{
			 (q->head)=(q->buff_point);
		}
		else
		{
			q->head=q->head+1;			//simply increment
		}
		q->count=q->count+1;				//increment the count
	}


	return error_message;


}
/*********************************************************************************************************************************************
*@function name:CB_buffer_remove_item(CB_t *q,	uint8_t data)
*@brief:Function to remove item to buffer
*The function takes a buffer pointer and the data to be removed and completes the operarion returning the result of the operation.It checks
*whether the buffer is empty.If it is empty it shall return an error message saying the circular buffer is empty.In all other cases the
*function returns a message saying the operation is a success.
*@param:CB_t *q,uint8_t data which is a circular buffer pointer and a unsigned integer type variable named data to store the removed item
*@return:CB_status, an enum which returns the data type.
**********************************************************************************************************************************************/
CB_status1 CB_buffer_remove_item1(CB_t1 *q,uint8_t *data){

    if((q->head==(NULL))||(q->tail==(NULL))||(q->buff_point==(NULL)))/*This first if else condition checks whether there
										     is any NULL pointer error present in the CB
										     If there is, it will return a null pointer error*/
	error_message=NULL_Error;





       if(CB_is_empty(q)==buff_empty)
							/*condition to check to check whether the buffer is empty
						        when the buffer is full head coincides with tail and the size is not equal to the count
							the buffer is said to be full
							the error message of buff_full.*/
	{error_message=buff_empty;}




	else if(((q->head)==(q->tail))&&((q->count)==(q->size)))	/*condition to check to check when the buffer is full*/
	{


	error_message=success;
	*data=*(q->tail);
//	*q->tail=(uint8_t)"EMPTY";
	if((q->tail)==(q->buff_point+q->size-1))/*if the circular buffers tail pointer reaches the tip of the allocated memory, it,should
						warp around and reach the base of the allocated memory.Otherwise it may just
						increment towards the limit*/
		{
			 (q->tail)=(q->buff_point);
		}
	else
		{
			(q->tail)=(q->tail)+1;			//simply increment the tail
		}
       	 (q->count)=(q->count)-1;				//count of the CB is decremented by 1
	}

	else
	{
	error_message=success;
       	*data=*(q->tail);
//	*q->tail=(uint8_t)"EMPTY";
		if((q->tail)==(q->buff_point+q->size-1))	/*if the circular buffer reaches the tip of the allocated memory,itshould
								warp around and reach the base of the allocated memory.Otherwise it may just
								increment towards the limit*/
		{
		 	(q->tail)=(q->buff_point);
		}
		else
		{
			(q->tail)=(q->tail)+1;			//simply increment
		}
		(q->count)=(q->count)-1;				//count is decremented by 1
	}


	return error_message;


}

/*********************************************************************************************************************************************
*@function name:CB_is_full(CB_t *q)
*@brief:Function to remove item to check whether the function is full
*The function takes a buffer pointer.It checks
*whether the buffer is full.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message or an error code.
*@param:CB_t *q
*@return:CB_status, an enum which returns the data type.
**********************************************************************************************************************************************/
CB_status1 CB_is_full1(CB_t1 *q){

	if(((q->count)==(q->size))&&((q->head)==(q->tail)))
		error_message=buff_full;

	else if(((q->count)!=(q->size))&&((q->head)==(q->tail)))
		error_message=buff_empty;

	else if((q->head==NULL)||(q->tail==NULL)||(q->buff_point==NULL))
		error_message=NULL_Error;

	else
		error_message=success;


	return error_message;
}

/*********************************************************************************************************************************************
*@function name:CB_is_full(CB_t *q)
*@brief:Function to remove item to check whether the function is empty
*The function takes a buffer pointer.It checks
*whether the buffer is empty.If it is full it shall return an error message saying the circular buffer is full.In all other cases the
*function returns a message or an error code.
*@param:CB_t *q
*@return:CB_status, an enum which returns the data type.
**********************************************************************************************************************************************/
CB_status1 CB_is_empty1(CB_t1 *q){

	if(((q->count)==(q->size))&&((q->head)==(q->tail)))
		error_message=buff_full;

	else if(((q->count)!=(q->size))&&((q->head)==(q->tail)))
		error_message=buff_empty;

	else if((q->head==NULL)||(q->tail==NULL)||(q->buff_point==NULL))
		error_message=NULL_Error;

	else
		error_message=success;


	return error_message;
}

/*********************************************************************************************************************************************
*@function name:CB_init(CB_t *q,size_t size)
*@brief:Function to initalize a Circular buffer
*The function takes a buffer pointer and the size of the buffer
*function returns a message or an error code.
*@param:CB_t *q
*@return:CB_status, an enum which returns the data type.
*
**********************************************************************************************************************************************/
CB_status1 CB_init1(CB_t1 *q,size_t size){


	q->size=size;
	q->buff_point=(uint8_t*)malloc(sizeof(uint8_t)*size);
	q->head=q->buff_point;
	q->tail=q->buff_point;
	q->count=0;
	error_message=buff_empty;
	uint8_t* i;
	i=q->buff_point;
	while(i< q->buff_point+q->size){
		if(i==NULL)
		{
			error_message=NULL_Error;
			break;
		}
		i++;
	}


	return error_message;
}

/*********************************************************************************************************************************************
*@function name:CB_destroy(CB_t *q,size_t size)
*@brief:Function to destroy a Circular buffer
*The function takes a buffer pointer.
*function returns a message or an error code.
*@param:CB_t *q
*@return:CB_status, an enum which returns the data type.
*
**********************************************************************************************************************************************/
CB_status1 CB_destroy1(CB_t1 *q){

	uint8_t *p;
	p=q->buff_point;

	while(p!=NULL){

		p=NULL;
		p=p+1;
	}
	error_message=NULL_Error;
	return error_message;
}
/*********************************************************************************************************************************************
*@function name:CB_peek(CB_t *q,size_t pos,size_t *point)
*@brief:Function to peek into a position in a circular buffer
*The function takes a buffer pointer, the position from the head and a pointer to return that position
*function returns a message or an error code.
*@param:CB_t *q,size_t pos, size_t *point
*@return:CB_status, an enum which returns the data type.
*
********************************************************************************************************************************************/
CB_status1 CB_peek1(CB_t1 *q,uint8_t pos,uint8_t *point){


	uint8_t i;
	point=q->head;
	uint8_t *rel1,*rel2;
	rel1=(q->head)+pos;
	rel2=q->buff_point+q->size-1;


	uint8_t rel=rel1-rel2;
	if((rel1)>(rel2))
		point=q->buff_point+rel-1;

	else
		point=rel1;



/*	uint8_t i=1;
	while(i<=pos){
	point=q->head+i;
	i++;
	}*/
//	for(i=1;i<=pos;i++){
//       if((point)==(q->buff_point+q->size-1))
//		point=q->buff_point;
//	else
		point=point+1;
//	}

	error_message=success;

	return error_message;

}


