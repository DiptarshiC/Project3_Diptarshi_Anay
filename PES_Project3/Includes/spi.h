/**
 * @file spi.h
 *
 * @brief file containing the function declarations of all spi functions
 *
 * @date Nov 25, 2017
 *
 * @author: Diptarshi Chakraborty
 *
 */

#ifndef INCLUDES_SPI_H_
#define INCLUDES_SPI_H_

#include <stdint.h>

/**
 * @brief a function that initializes the spi module
 *
 * The function should initialize the spi module and set it to work
 *
 * @param void
 *
 * @return void
 *
 */

void SPI_init();

/**
 * @brief Reads a single byte from the SPI bus
 *
 * The function should read from the spi data register
 *
 * @param byte of data
 *
 * @return void
 *
 */

uint8_t SPI_read_byte(uint8_t byte);

/**
 * @brief writes a single byte from the SPI bus
 *
 * The function should write a byte in the SPI data register
 *
 * @param byte of data
 *
 * @return void
 *
 */

void SPI_write_byte(uint8_t byte);

/**
 * @brief Sends numerous SPI Bytes given a pointer to a byte array and a length of how many bytes to send
 *
 * The function should send  a length of bytes to the SPI data register
 *
 * @param array of bytes, length of how many bytes to send
 *
 * @return void
 *
 */

void SPI_send_packet(uint8_t* p,uint8_t length);

/**
 * @brief Blocks until SPI transmit buffer has completed transmitting
 *
 *
 *
 * @param void
 *
 * @return void
 *
 */

void SPI_flush();




#endif /* INCLUDES_SPI_H_ */
