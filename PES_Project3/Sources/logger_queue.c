/**
 * @file logger_queue.h
 *
 * @brief file containing the function declarations of all the logger_queue functions
 *
 * @date Nov 26, 2017
 *
 * @author: Diptarshi Chakraborty
 *
 */
#include <stdint.h>
#include "MKL25Z4.h"
#include "cirbuf2.h"
#include "logger_queue.h"
#include "logger.h"
uint8_t seconds=0;
uint8_t minutes=0;

/**
 * @brief a function that logs an item to the logger buffer
 *
 *
 *
 * @param LOG_ID ID
 *
 * @return void
 *
 */

void log_item(LOG_ID ID){


	LOG1[ID].LOG_ID=ID;

	if(ID==0){

							LOG1[ID].LOG_LENGTH=17;
							LOG1[ID].PAYLOAD_LENGTH[23]="LOGGER_INITIALZED";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);

	}


	else if(ID==1){

							LOG1[ID].LOG_LENGTH=16;
							LOG1[ID].PAYLOAD_LENGTH[23]="GPIO_INITIALZED";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
		}

	else if(ID==2){

							LOG1[ID].LOG_LENGTH=18;
							LOG1[ID].PAYLOAD_LENGTH[23]="SYSTEM_INITIALIZED";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
			}

	else if(ID==3){

							LOG1[ID].LOG_LENGTH=13;
							LOG1[ID].PAYLOAD_LENGTH[23]="SYSTEM_HALTED";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
			}

	 else if(ID==4){

							LOG1[ID].LOG_LENGTH=4;
							LOG1[ID].PAYLOAD_LENGTH[23]="INFO";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
				}

	 else if(ID==5){

							LOG1[ID].LOG_LENGTH=7;
							LOG1[ID].PAYLOAD_LENGTH[23]="WARNING";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
					}
	 else if(ID==6){

							LOG1[ID].LOG_LENGTH=5;
							LOG1[ID].PAYLOAD_LENGTH[23]="ERROR";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
						}

	 else if(ID==7){

							LOG1[ID].LOG_LENGTH=17;
							LOG1[ID].PAYLOAD_LENGTH[23]="PROFILING_STARTED";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
							}

	 else if(ID==8){

							LOG1[ID].LOG_LENGTH=16;
							LOG1[ID].PAYLOAD_LENGTH[23]="PROFILING_RESULT";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
								}

	 else if(ID==9){

							LOG1[ID].LOG_LENGTH=19;
							LOG1[ID].PAYLOAD_LENGTH[23]="PROFILING_COMPLETED";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
									}

	 else if(ID==10){

							LOG1[ID].LOG_LENGTH=13;
							LOG1[ID].PAYLOAD_LENGTH[23]="DATA_RECEIVED";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
									}

	 else if(ID==11){

							LOG1[ID].LOG_LENGTH=21;
							LOG1[ID].PAYLOAD_LENGTH[23]="DATA_ANALYSIS_STARTED";
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,0);
									}

	 else if(ID==12){

							LOG1[ID].LOG_LENGTH=1;
							LOG1[ID].PAYLOAD_LENGTH[23]=1;
							LOG1[ID].DATA=alphabet;
							LOG1[ID].TIME_STAMP=seconds;
							CB_buffer_add_item1(&logger_buffer,ID);
							CB_buffer_add_item1(&logger_buffer_RTC,seconds);
							CB_buffer_add_item1(&logger_buffer_payload,alphabet);
							}//DATA_ALPHA_COUNT

	 else if(ID==13){

	 						LOG1[ID].LOG_LENGTH=1;
	 						LOG1[ID].PAYLOAD_LENGTH[23]=1;
	 						LOG1[ID].DATA=numeric;
	 						LOG1[ID].TIME_STAMP=seconds;
	 						CB_buffer_add_item1(&logger_buffer,ID);
	 						CB_buffer_add_item1(&logger_buffer_RTC,seconds);
	 						CB_buffer_add_item1(&logger_buffer_payload,numeric);

	 						}//DATA_NUMERIC_COUNT

	 else if(ID==14){

	 	 					LOG1[ID].LOG_LENGTH=1;
	 	 					LOG1[ID].PAYLOAD_LENGTH[23]=1;
	 	 					LOG1[ID].DATA=punctuations;
	 	 					LOG1[ID].TIME_STAMP=seconds;
	 	 					CB_buffer_add_item1(&logger_buffer,ID);
	 	 					CB_buffer_add_item1(&logger_buffer_RTC,seconds);
	 	 					CB_buffer_add_item1(&logger_buffer_RTC,punctuations);

	 	 					}//DATA_PUNCTUATION_COUNT

	 else if(ID==15){

	 	 	 				LOG1[ID].LOG_LENGTH=1;
	 	 	 				LOG1[ID].PAYLOAD_LENGTH[23]=1;
	 	 	 				LOG1[ID].DATA=misclleaneous;
	 	 	 				LOG1[ID].TIME_STAMP=seconds;
	 	 	 				CB_buffer_add_item1(&logger_buffer,ID);
	 	 	 				CB_buffer_add_item1(&logger_buffer_RTC,seconds);
	 	 	 				CB_buffer_add_item1(&logger_buffer_RTC,misclleaneous);

	 	 	 				}//DATA_MISC_COUNT

	 else if(ID==16){

	 	 	 	 			LOG1[ID].LOG_LENGTH=23;
	 	 	 	 			LOG1[ID].PAYLOAD_LENGTH[23]="DATA_ANALYSIS_COMPLETED";
	 	 	 	 			LOG1[ID].TIME_STAMP=seconds;
	 	 	 	 			CB_buffer_add_item1(&logger_buffer,ID);
	 	 	 	 			CB_buffer_add_item1(&logger_buffer_RTC,seconds);
	 	 	 	 			CB_buffer_add_item1(&logger_buffer_RTC,0);
	 	 	 	 			}//DATA_ANALYSIS_COMPLETED

}


/**
 * @brief a function that initializes rtc module
 *
 *
 *
 * @param LOG_ID ID
 *
 * @return void
 *
 */

void rtc_init(){

	SIM_SCGC5|=(1<<11);

	MCG_C1 |= MCG_C1_IRCLKEN_MASK;//Enable the internal reference clock. MCGIRCLK is active.
	MCG_C2 &= ~(MCG_C2_IRCS_MASK);//Select the slow internal reference clock source.


	//Set PTC1 as RTC_CLKIN and select 32 KHz clock source for the RTC module.

	PORTC_PCR1 |= (PORT_PCR_MUX(0x1));
	SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0x2);

	//Set PTC3 as CLKOUT pin and selects the MCGIRCLK clock to output on the CLKOUT pin

	SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(0x4);
	PORTC_PCR3 |= (PORT_PCR_MUX(0x5));

	//Enable software access and interrupts to the RTC module.

	SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;

	//Clear all RTC registers.

	RTC_CR = RTC_CR_SWR_MASK;
	RTC_CR &= ~RTC_CR_SWR_MASK;



	if (RTC_SR & RTC_SR_TIF_MASK){
	     RTC_TSR = 0x00000000;////  this action clears the TIF
	}

	//RTC_TCR = RTC_TCR_CIR(1) | RTC_TCR_TCR(0xFF);
	RTC_TCR =0;/*Set time compensation parameters*/

	//Enable time seconds interrupt for the module and enable its irq.

	NVIC->ISER[0]=(1<<21);
	RTC_IER |= RTC_IER_TSIE_MASK;

	//Enable time counter.

	RTC_SR |= RTC_SR_TCE_MASK;

	/*Configure the timer seconds and alarm registers*/
	//RTC_TSR = 0xFF;
}

/**
 * @brief a function that clocks every second
 *
 *
 *
 * @param LOG_ID ID
 *
 * @return void
 *
 */

void RTC_Seconds_IRQHandler()
{
//	interrupt = 1;

	seconds = RTC_TSR;

    if (seconds >59){
    	minutes++;
    	RTC_SR &= ~RTC_SR_TCE_MASK;
    	RTC_TSR = 0x00; //Reset counter
    	seconds = RTC_TSR;
    	RTC_SR |= RTC_SR_TCE_MASK;
    }
}

