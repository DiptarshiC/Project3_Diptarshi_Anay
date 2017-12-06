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

#ifndef INCLUDES_LOGGER_H_
#define INCLUDES_LOGGER_H_

#include<stdint.h>
#include "MKL25Z4.h"

#define		START_CRITICAL()	__disable_irq()
#define		END_CRITICAL()		__enable_irq()


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

void log_data(uint8_t* src, uint8_t length);

/**
 * @brief a function that takes a C-string and logs that to the terminal
 *
 *
 * @param uint8_t
 *
 * @return uint8_t
 *
 */

void log_string(uint8_t* src,uint8_t length);

/**
 * @brief a function that Takes an integer and logs that to the terminal (use itoa())
 *
 *
 * @param uint8_t
 *
 * @return uint8_t
 *
 */

void log_integer(uint8_t integer);

/**
 * @brief a function that blocks until the current logger buffer is empty
 *
 *
 * @param uint8_t
 *
 * @return uint8_t
 *
 */

void log_flush(uint8_t integer);






#endif /* INCLUDES_LOGGER_H_ */
