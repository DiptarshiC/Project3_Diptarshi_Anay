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

#include <stdint.h>
#include "nordic.h"

/**
 * @brief a function that Read the register and return the value
 *
 *
 *
 * @param uint8_t
 *
 * @return uint8_t
 *
 */
uint8_t nrf_read_register(uint8_t register1){


	uint8_t a,b;

	SPI_write_byte(0x00|(register1));//read command
	b=SPI_read_byte(a);
	/*Sending one dummy byte*/
	SPI_write_byte(0xFF);//1st dummy byte
	a= SPI_read_byte(a);//reading STATUS register
	//a= SPI_read_byte(a);//reading STATUS register
	return a;

}


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
void nrf_write_register(uint8_t register1,uint8_t value){
	uint8_t a;

	SPI_write_byte((0x20)|(register1)); //write command
	a=SPI_read_byte(a);
	SPI_write_byte(value);
	a=SPI_read_byte(a);



}

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
uint8_t nrf_read_status(){

	uint8_t a;

	nrf_chip_enable();

	a= nrf_read_register(NORDIC_STATUS_REG);

	nrf_chip_disable();

	return a;
}

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
uint8_t nrf_read_config(){

	uint8_t a;
	nrf_chip_enable();
	a= nrf_read_register(NORDIC_CONFIG_REG);
	nrf_chip_disable();
	return a;

}

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
void nrf_write_config(uint8_t config){
	nrf_chip_enable();
	nrf_write_register(NORDIC_CONFIG_REG,config);
	nrf_chip_disable();
}

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
uint8_t nrf_read_rf_setup(){

	uint8_t a;
	nrf_chip_enable();
	a=nrf_read_register(NORDIC_RF_SETUP_REG);
	nrf_chip_disable();
	return a;

}

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
void nrf_write_rf_setup(uint8_t config){
	nrf_chip_enable();
	nrf_write_register(NORDIC_RF_SETUP_REG,config);
	nrf_chip_disable();
}

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
uint8_t nrf_read_rf_ch(){

	uint8_t a;
	nrf_chip_enable();
	a=nrf_read_rf_ch(NORDIC_RF_CH_REG);
	nrf_chip_disable();
	return a;
}

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
void nrf_write_rf_ch(uint8_t channel){

	nrf_chip_enable();
	nrf_write_register(NORDIC_RF_CH_REG,channel);
	nrf_chip_disable();
}

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
void nrf_read_TX_ADDR(uint8_t * address){

		int i;
		uint8_t a;
		nrf_chip_enable();
		SPI_write_byte(0x00|(NORDIC_TXADDR_REG));//read command
		a= SPI_read_byte(a);//reading STATUS register*/
		/*Sending  dummy bytes*/
		/*SPI_write_byte(0x00);//1st dummy byte
		SPI_write_byte(0x00);//2nd dummy byte
		SPI_write_byte(0x00);//3rd dummy byte
		SPI_write_byte(0x00);//4th dummy byte
		SPI_write_byte(0x00);//5th dummy byte
		a= SPI_read_byte(a);//reading STATUS register*/
		for(i=0;i<5;i++){

			SPI_write_byte(0x00);//writing dummy byte
			*(address+i)=SPI_read_byte(a);


		}

		nrf_chip_disable();

}

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
void nrf_write_TX_ADDR(uint8_t * tx_addr){

			int i;
			uint8_t a;
			nrf_chip_enable();
			SPI_write_byte(0x20|(NORDIC_TXADDR_REG));//write command
			a= SPI_read_byte(a);//reading STATUS register*/
			/*Sending one dummy byte*/
			/*SPI_write_byte(0x00);//1st dummy byte
			SPI_write_byte(0x00);//2nd dummy byte
			SPI_write_byte(0x00);//3rd dummy byte
			SPI_write_byte(0x00);//4th dummy byte
			SPI_write_byte(0x00);//5th dummy byte
			a= SPI_read_byte(a);//reading STATUS register*/
			for(i=0;i<5;i++){
				SPI_write_byte(*(tx_addr+i));
				a= SPI_read_byte(a);

			}

			nrf_chip_disable();
}

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
uint8_t nrf_read_fifo_status(){

	uint8_t a;
	nrf_chip_enable();
	a=nrf_read_rf_ch(FIFO_STATUS_REG);
	nrf_chip_disable();
	return a;

}


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
void nrf_flush_tx_fifo(){

	uint8_t a;
	nrf_chip_enable();

	SPI_write_byte(0xE1);
	a= SPI_read_byte(a);

	nrf_chip_disable();

}

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
void nrf_flush_rx_fifo(){

	uint8_t a;
	nrf_chip_enable();

	SPI_write_byte(0xE2);
	a= SPI_read_byte(a);
	nrf_chip_disable();

}
