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
#ifndef INCLUDES_LOGGER_QUEUE_H_
#define INCLUDES_LOGGER_QUEUE_H_

#include <stdint.h>
#include "MKL25Z4.h"
#include "cirbuf2.h"

typedef enum{
	LOGGER_INITIALZED,
	GPIO_INITIALZED,
	SYSTEM_INITIALIZED,
	SYSTEM_HALTED,
	INFO,
	WARNING,
	ERROR,
	PROFILING_STARTED,
	PROFILING_RESULT,
	PROFILING_COMPLETED,
	DATA_RECEIVED,
	DATA_ANALYSIS_STARTED,
	DATA_ALPHA_COUNT,
	DATA_NUMERIC_COUNT,
	DATA_PUNCTUATION_COUNT,
	DATA_MISC_COUNT,
	DATA_ANALYSIS_COMPLETED
}LOG_ID;

typedef struct{

	uint8_t LOG_ID;
	uint32_t TIME_STAMP;
	uint8_t LOG_LENGTH;
	uint8_t CHECKSUM;
	uint8_t PAYLOAD_LENGTH[23];
}LOG;

CB_t1 logger_buffer;

 LOG LOG1[17];
LOG_ID ID;


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

void log_item(LOG_ID ID);


#endif /* INCLUDES_LOGGER_QUEUE_H_ */
