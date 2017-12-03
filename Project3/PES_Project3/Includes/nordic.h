/**
 * @file nordic.h
 *
 * @brief file containing the function declarations of all nordic module functions
 *
 * @date Nov 26, 2017
 *
 * @author: Diptarshi Chakraborty
 *
 */



#ifndef INCLUDES_NORDIC_H_
#define INCLUDES_NORDIC_H_

#include <stdint.h>
#include <stdlib.h>
#include "spi.h"
#include "MKL25Z4.h"

/**MACROS DEFINED FOR THE REGISTER SET ADDRESSES OF THE NRF MODULE*/

#define 	NORDIC_CONFIG_REG 		(0x00)
#define 	NORDIC_TXADDR_REG 		(0x10)
#define 	NORDIC_POWER_UP 		(0x01)
#define 	NORDIC_POWER_UP_MASK 	(0x02)
#define 	NORDIC_POWER_DOWN_MASK 	(0x00)
#define 	NORDIC_EN_AA_REG 		(0x01)
#define 	NORDIC_EN_RXADDR_REG 	(0x02)
#define 	NORDIC_SETUP_AW_REG 	(0x03)
#define 	NORDIC_SETUP_RETR_REG 	(0x04)
#define 	NORDIC_RF_CH_REG 		(0x05)
#define 	NORDIC_RF_SETUP_REG 	(0x06)
#define 	NORDIC_STATUS_REG 		(0x07)
#define 	RX_ADDR_P0_REG 			(0x0A)
#define 	RX_ADDR_P1_REG 			(0x0B)
#define 	TX_ADDR 				(0x10)
#define 	FIFO_STATUS_REG 		(0x17)
#define 	NRF_PIPESIZE 			(0X11)
#define 	NRF_ENRXADDR 			(0x02)
#define 	W_TXPAYLOAD 			(0xA0)
#define 	R_RXPAYLOAD 			(0x61)

/*Definitions of macro functions for disabling and enabling the pins*/

#define		nrf_chip_enable()		PTD_BASE_PTR->PCOR = 1	//Chip select low
#define 	nrf_chip_disable()		PTD_BASE_PTR->PSOR = 1 //Chip select high


/**
 * @brief a function that reads the register and return the value
 *
 *
 *
 * @param uint8_t
 *
 * @return uint8_t
 *
 */
uint8_t nrf_read_register(uint8_t register1);


/**
 * @brief a function that writes to the given register with the data
 *
 *
 *
 * @param uint8_t register,uint8_t value
 *
 * @return void
 *
 */
void nrf_write_register(uint8_t register1, uint8_t value);

/**
 * @brief a function that reads the STATUS register
 *
 *
 *
 * @param void
 *
 * @return uint8_t
 *
 */
uint8_t nrf_read_status();

/**
 * @brief a function that reads the CONFIG register
 *
 *
 *
 * @param void
 *
 * @return uint8_t
 *
 */
uint8_t nrf_read_config();
/**
 * @brief a function that writes to the CONFIG register
 *
 *
 *
 * @param void
 *
 * @return uint8_t
 *
 */
void nrf_write_config(uint8_t config);

/**
 * @brief a function that reads RF_SETUP register
 *
 *
 *
 * @param void
 *
 * @return uint8_t
 *
 */
uint8_t nrf_read_rf_setup();

/**
 * @brief a function that writes to the RF_SETUP register
 *
 *
 *
 * @param uint8_t
 *
 * @return void
 *
 */
void nrf_write_rf_setup(uint8_t config);

/**
 * @brief a function that reads RF_CH register
 *
 *
 *
 * @param void
 *
 * @return uint8_t
 *
 */
uint8_t nrf_read_rf_ch();

/**
 * @brief a function that writes to the RF_CH register
 *
 *
 *
 * @param uint8_t
 *
 * @return void
 *
 */
void nrf_write_rf_ch(uint8_t channel);

/**
 * @brief a function that reads the 5 bytes of the TX_ADDR register
 *
 *
 *
 * @param uint8_t*
 *
 * @return void
 *
 */
void nrf_read_TX_ADDR(uint8_t * address);

/**
 * @brief a function that writes the 5 byte TX_ADDR register
 *
 *
 *
 * @param uint8_t*
 *
 * @return void
 *
 */
void nrf_write_TX_ADDR(uint8_t * tx_addr);

/**
 * @brief a function that reads FIFO_STATUS register
 *
 *
 *
 * @param void
 *
 * @return uint8_t
 *
 */
uint8_t nrf_read_fifo_status();



/**
 * @brief a function that sends the command FLUSH_TX
 *
 *
 *
 * @param void
 *
 * @return void
 *
 */
void nrf_flush_tx_fifo();

/**
 * @brief a function that sends the command FLUSH_RX
 *
 *
 *
 * @param void
 *
 * @return void
 *
 */
void nrf_flush_rx_fifo();





#endif /* INCLUDES_NORDIC_H_ */
