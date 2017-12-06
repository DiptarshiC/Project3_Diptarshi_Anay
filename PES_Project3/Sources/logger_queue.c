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
							CB_buffer_add_item1(&logger_buffer,ID);
	}


	else if(ID==1){

							LOG1[ID].LOG_LENGTH=16;
							LOG1[ID].PAYLOAD_LENGTH[23]="GPIO_INITIALZED";
							CB_buffer_add_item1(&logger_buffer,ID);
		}

	else if(ID==2){

							LOG1[ID].LOG_LENGTH=18;
							LOG1[ID].PAYLOAD_LENGTH[23]="SYSTEM_INITIALIZED";
							CB_buffer_add_item1(&logger_buffer,ID);
			}

	else if(ID==3){

							LOG1[ID].LOG_LENGTH=13;
							LOG1[ID].PAYLOAD_LENGTH[23]="SYSTEM_HALTED";
							CB_buffer_add_item1(&logger_buffer,ID);
			}

	 else if(ID==4){

							LOG1[ID].LOG_LENGTH=4;
							LOG1[ID].PAYLOAD_LENGTH[23]="INFO";
							CB_buffer_add_item1(&logger_buffer,ID);
				}

	 else if(ID==5){

								LOG1[ID].LOG_LENGTH=7;
								LOG1[ID].PAYLOAD_LENGTH[23]="WARNING";
								CB_buffer_add_item1(&logger_buffer,ID);
					}
	 else if(ID==6){

								LOG1[ID].LOG_LENGTH=5;
								LOG1[ID].PAYLOAD_LENGTH[23]="ERROR";
								CB_buffer_add_item1(&logger_buffer,ID);
						}

	 else if(ID==7){

								LOG1[ID].LOG_LENGTH=17;
								LOG1[ID].PAYLOAD_LENGTH[23]="PROFILING_STARTED";
								CB_buffer_add_item1(&logger_buffer,ID);
							}

	 else if(ID==8){

								LOG1[ID].LOG_LENGTH=16;
								LOG1[ID].PAYLOAD_LENGTH[23]="PROFILING_RESULT";
								CB_buffer_add_item1(&logger_buffer,ID);
								}

	 else if(ID==9){

								LOG1[ID].LOG_LENGTH=19;
								LOG1[ID].PAYLOAD_LENGTH[23]="PROFILING_COMPLETED";
								CB_buffer_add_item1(&logger_buffer,ID);
									}

	 else if(ID==10){

								LOG1[ID].LOG_LENGTH=13;
								LOG1[ID].PAYLOAD_LENGTH[23]="DATA_RECEIVED";
								CB_buffer_add_item1(&logger_buffer,ID);
									}

	 else if(ID==11){

								LOG1[ID].LOG_LENGTH=21;
								LOG1[ID].PAYLOAD_LENGTH[23]="DATA_ANALYSIS_STARTED";
								CB_buffer_add_item1(&logger_buffer,ID);
									}

	 else if(ID==12){

									LOG1[ID].LOG_LENGTH=1;
									LOG1[ID].PAYLOAD_LENGTH[23]=1;
									CB_buffer_add_item1(&logger_buffer,ID);
									}//DATA_ALPHA_COUNT

	 else if(ID==13){

	 									LOG1[ID].LOG_LENGTH=1;
	 									LOG1[ID].PAYLOAD_LENGTH[23]=1;
	 									CB_buffer_add_item1(&logger_buffer,ID);

	 								}//DATA_NUMERIC_COUNT

	 else if(ID==14){

	 	 									LOG1[ID].LOG_LENGTH=1;
	 	 									LOG1[ID].PAYLOAD_LENGTH[23]=1;
	 	 									CB_buffer_add_item1(&logger_buffer,ID);

	 	 								}//DATA_PUNCTUATION_COUNT

	 else if(ID==15){

	 	 	 									LOG1[ID].LOG_LENGTH=1;
	 	 	 									LOG1[ID].PAYLOAD_LENGTH[23]=1;
	 	 	 									CB_buffer_add_item1(&logger_buffer,ID);

	 	 	 								}//DATA_MISC_COUNT

	 else if(ID==16){

	 	 	 	 									LOG1[ID].LOG_LENGTH=23;
	 	 	 	 									LOG1[ID].PAYLOAD_LENGTH[23]="DATA_ANALYSIS_COMPLETED";
	 	 	 	 									CB_buffer_add_item1(&logger_buffer,ID);

	 	 	 	 								}//DATA_ANALYSIS_COMPLETED

}

