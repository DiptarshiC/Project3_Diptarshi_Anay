/**
* @file logger.h
 *
 * @brief file containing the function definitions of all the logger functions
 *
 * @date Nov 26, 2017
 *
 * @author: Diptarshi Chakraborty
 *
 */
#include<stdlib.h>
#include<stdint.h>
#include "logger.h"
#include "uart.h"
#include "MKL25Z4.h"
#include "conversion.h"




/**
 * @brief a function that Takes a pointer to a sequence of bytes and length of bytes to log
 *
 *
 *
 * @param uint8_t* src, uint8_t length
 *
 * @return void
 *
 */

void log_data(uint8_t* src, uint8_t length){

	UART_send_n( src,length);
}

/**
 * @brief a function that takes a C-string and logs that to the terminal
 *
 *
 * @param uint8_t
 *
 * @return uint8_t
 *
 */

void log_string(uint8_t* src,uint8_t length){

	UART_send_n( src,length);


}


/**
 * @brief a function that Takes an integer and logs that to the terminal (use itoa())
 *
 *
 * @param uint8_t
 *
 * @return uint8_t
 *
 */

void log_integer(uint8_t integer){

			uint8_t a2[10];
			uint8_t * ptr2;
			ptr2 = &a2[0];
			ptr2 = my_itoa(integer,ptr2,10);
			uint8_t length2;
			while(*ptr2!='\0')
					{
						UART_send(ptr2);
						ptr2++;
					}
			//UART_send_n( ptr3,length2);

}

/**
 * @brief a function that blocks until the current logger buffer is empty
 *
 *
 * @param uint8_t
 *
 * @return uint8_t
 *
 */

void log_flush(uint8_t integer){
	START_CRITICAL();




	EDN_CRITICAL();
}

