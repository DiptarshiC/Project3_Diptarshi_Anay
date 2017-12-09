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
#include "logger_queue.h"
#include "cirbuf2.h"


uint8_t alphabet=0;
uint8_t numeric=0;
uint8_t  punctuations=0;
uint8_t  misclleaneous=0;


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

void log_flush(){
	//START_CRITICAL();

	int i;

			uint8_t log_id;
			uint8_t payload_item;
			uint8_t rtc_value;
			while(CB_is_full1(&logger_buffer)!=buff_empty){

		    CB_buffer_remove_item1(&logger_buffer,&log_id);//By this statement every element from the logger buffer is removed(the buffer which stores the id)
			CB_buffer_remove_item1(&logger_buffer_payload,&payload_item);//By this statement every element from the payload logger buffer is removed(the buffer which stores the payload)
			CB_buffer_remove_item1(&logger_buffer_RTC,&rtc_value);//By this statement every element from the payload logger buffer is removed(the buffer which stores the rtc value)
			char a7[4]="RTC:";
			int l1= 4;
			char * PTR;
			PTR =&a7[0];
			for(i = 0; i < l1; i++)
			{
					UART_send(PTR);
					PTR++;
			}

			uint8_t time[10];
			uint8_t * PTR1;
			PTR1 = &time[0];
			PTR1 = my_itoa(rtc_value, PTR1, 10);
			uint8_t length2;
			while(*PTR1 != '\0')
			{
				UART_send(PTR1);
				PTR1++;
			}

			uint8_t * log_name;
			log_name=&(LOG1[log_id].PAYLOAD_LENGTH[0]);
			for(i = 0;i <LOG1[ID].LOG_LENGTH; i++)
						{
								UART_send(log_name);
								log_name++;

						}
			uint8_t * PTR2;
			PTR2 = &(LOG1[log_id].DATA);
			PTR1 = my_itoa(payload_item, PTR2, 10);

			while(*PTR2 != '\0')
			{
				UART_send(PTR2);
				PTR1++;
			}

/*
	char a1[10] = "Alphabets:";
			int length1 = 9;
			char * ptr1;
			ptr1 = &a1[0];
			for(int i = 0; i < length1; i++)
			{
				UART_send(ptr1);
				ptr1++;
			}

			uint8_t a2[10];
			uint8_t * ptr2;
			ptr2 = &a2[0];
			ptr2 = my_itoa(alphabet, ptr2, 10);

			while(*ptr2 != '\0')
			{
				UART_send(ptr2);
				ptr2++;
			}

			char a3[8] = " Digits:";
			int length3 = 8;
			char * ptr3;
			ptr3 = &a3[0];
			for(int i = 0; i < length3; i++)
			{
				UART_send(ptr3);
				ptr3++;
			}

			uint8_t a4[10];
			uint8_t * ptr4;
			ptr4 = &a4[0];
			ptr4 = my_itoa(numeric, ptr4, 10);
			while(*ptr4 != '\0')
			{
				UART_send(ptr4);
				ptr4++;
			}

			char a5[14] = " Punctuations:";
			int length5 = 12;
			char * ptr5;
			ptr5 = &a5[0];
			for(int i = 0; i < length5; i++)
			{
				UART_send(ptr5);
				ptr5++;
			}

			uint8_t a6[10];
			uint8_t * ptr6;
			ptr6 = &a6[0];
			ptr6 = my_itoa(punctuations, ptr6, 10);
			while(*ptr6 != '\0')
			{
				UART_send(ptr6);
				ptr6++;
			}

			char a71[15] = " Miscellaneous:";
			int length7 = 12;
			char * ptr7;
			ptr7 = &a71[0];
			for(int i = 0; i < length7; i++)
			{
				UART_send(ptr7);
				ptr7++;
			}

			uint8_t a8[10];
			uint8_t * ptr8;
			ptr8 = &a8[0];
			ptr8 = my_itoa(misclleaneous, ptr8, 10);
			while(*ptr8 != '\0')
			{
				UART_send(ptr8);
				ptr8++;
			}

			alphabet = 0;
			numeric = 0;
			punctuations = 0;
			misclleaneous=0;

			*/

			}
	//END_CRITICAL();
}

