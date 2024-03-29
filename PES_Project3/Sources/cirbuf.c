/*****************************************************************************************************************************************
*@file:cirbuf.c
*@brief:this file contains all the function definitions of the circular buffer functions.It inherits all the global variables of cirbuf.h
*@Author:Diptarshi Chakraborty
*@Date:10/22/2017
********************************************************************************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include "cirbuf.h"
#include <stdint.h>

CB_status CB_init(CB_t * ptr , int8_t length)
{
	CB_status status;
	if (ptr ->buffer == NULL || length <= 0)
    	{
        	status = FAIL;
    	}
 	else
    	{
		    ptr -> buffer = (int8_t *)malloc(sizeof(int8_t)* length);
        	ptr -> head = ptr->buffer;
        	ptr -> tail = ptr->buffer;
        	ptr -> count = 0;
        	ptr -> size = length;
        	ptr -> peek = 0;
        	status = Allocate_Free;
    	}
 	return status;
}


CB_status CB_is_full(CB_t * ptr)
{
	CB_status status;
	if(ptr == NULL)
	{
		status = FAIL;
	}
	else if(ptr -> count == ptr -> size)
    	{
        	status = Buffer_Full;
    	}
    	else
    	{
        	status = Buffer_Not_Full;
    	}
 	return status;
}

CB_status CB_is_empty(CB_t * ptr)
{
	CB_status status;
	if(ptr == NULL)
		{
			status = FAIL;
		}
	else if(ptr -> count == 0)
    	{
        	status = Buffer_Empty;
    	}
    	else
    	{
        	status = Buffer_Not_Empty;
    	}
 	return status;
}

CB_status CB_buffer_add_item(CB_t * ptr,int8_t add)
{
	CB_status status;
	if(ptr == NULL)
		{
			status = FAIL;
		}
	else if(ptr -> count == ptr -> size)
    	{
        status = Over_Fill;
		return status;
    	}
 	else if(ptr -> head == ptr-> buffer + ptr-> size -1)
 	{
   		*ptr-> head = add;
   		ptr-> head = ptr-> buffer;
   		ptr-> count++;
   		status = Wrap_Add;
 	}
 	else
 	{
		*ptr-> head = add;
 		ptr -> head++;
		ptr -> count++;
   		status = Added;
 	}
 	return status;
}

CB_status CB_buffer_remove_item(CB_t * ptr,int8_t remove)
{
	CB_status status;
	if(ptr == NULL)
		{
			status = FAIL;
		}
	else if(CB_is_empty(ptr) == Buffer_Empty)
    	{
		status = Over_Empty;
        	return status;
    	}
 	else if(ptr -> tail == ptr-> buffer + ptr-> size -1)
 	{
		remove = *ptr-> tail;
  		ptr -> tail = ptr->buffer;
   		ptr->count--;
   		status = Wrap_Remove;
 	}
 	else
 	{
   		remove = *ptr->tail;
   		ptr->tail++;
   		ptr->count--;
   		status = Removed;
 	}
 	return status;
}

CB_status CB_peek(CB_t *ptr ,int8_t position, int8_t * src)
{
	CB_status status;
	if(ptr == NULL)
		{
			status = FAIL;
		}
	else if(position <= 0 || position >= ptr-> size)
	{
   		status = FAIL;
	}
	else
	{
  		ptr-> peek = *( ptr-> buffer + position );
  		status = SUCCESS;
	}
	return status;
}

CB_status CB_Destroy(CB_t * ptr)
{

  	CB_status status;
  	if(ptr == NULL)
  			{
  				status = FAIL;
  			}
  	else{
 	free( ptr-> buffer );
 	status = SUCCESS;
  	}
 	return status;
}







