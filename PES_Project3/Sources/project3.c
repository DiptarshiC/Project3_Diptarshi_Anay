#include "cirbuf.h"
#include "project3.h"
#include "uart.h"
#include "conversion.h"
#include "logger_queue.h"
#include "cirbuf2.h"
#include "logger.h"

CB_t * Tx;
CB_t * Rx;
int8_t c;
int8_t alpha = 0, num = 0, punc = 0, misc = 0;

static int i = 0;

int8_t length = 100;
extern CB_t * Tx;
extern CB_t * Rx;

void project3()
{
	rtc_init();

	Tx = malloc(sizeof(CB_t));
		Tx->buffer = malloc(sizeof(int8_t) * 10);
		Rx = malloc(sizeof(CB_t));
		Rx->buffer = malloc(sizeof(int8_t) * 10);
		CB_init(Rx, length);
		CB_init(Tx, length);

		UART_configure();
}

	void getCount(int8_t c)
	{
		log_item(DATA_ANALYSIS_STARTED);
		UART0_C2 &= ~UART0_C2_TIE_MASK;
		UART0_C2 &= ~UART0_C2_RIE_MASK;
		if(c == 13)
		{
			printStats();
			/*log_flush();*/


		}
		else if((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		{
			alpha++;
		}
		else if(c >= 48 && c <= 57)	//numeric
		{
			num++;
		}
		else if(c == 33 || c == 34 || c == 44 || c == 46 || c == 45 || c == 58 || c == 59 || c == 39 || c == 91 || c == 93 || c == 40 || c == 41 || c == 63)
		{
			punc++;
		}
		else							//miscellaneous
		{
			misc++;
		}
	}

	void printStats()
	{
		//Serial.println();

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
		ptr2 = my_itoa(alpha, ptr2, 10);
		uint8_t length2;
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
		ptr4 = my_itoa(num, ptr4, 10);
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
		ptr6 = my_itoa(punc, ptr6, 10);
		while(*ptr6 != '\0')
		{
			UART_send(ptr6);
			ptr6++;
		}

		char a7[15] = " Miscellaneous:";
		int length7 = 12;
		char * ptr7;
		ptr7 = &a7[0];
		for(int i = 0; i < length7; i++)
								{
									UART_send(ptr7);
									ptr7++;
								}

								uint8_t a8[10];
								uint8_t * ptr8;
								ptr8 = &a8[0];
								ptr8 = my_itoa(misc, ptr8, 10);
								while(*ptr8 != '\0')
								{
									UART_send(ptr8);
									ptr8++;
								}

		alpha = 0;
		num = 0;
		punc = 0;
		misc = 0;
	}





