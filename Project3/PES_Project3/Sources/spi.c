/**
 * @file spi.c
 *
 * @brief file containing the function definition of all spi functions
 *
 * @date Nov 25, 2017
 *
 * @author: Diptarshi Chakraborty
 *
 */

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

void SPI_init(){
	SIM_SCGC5|=SIM_SCGC5_PORTD_MASK;// TURNS ON CLOCK TO D MODULE
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;//ENABLES THE SPIO CLOCK

	PORTD_PCR0|=PORT_PCR_MUX(0x2);// MUX FOR SPI0_PCS0 PIN
	PORTD_PCR1|=PORT_PCR_MUX(0x2);// MUX FOR SPI0_SCK PIN
	PORTD_PCR2|=PORT_PCR_MUX(0x2);// MUX FOR SPI0_MOSI PIN
	PORTD_PCR3|=PORT_PCR_MUX(0x2);// MUX FOR SPI0_MISO PIN

	SPI0_C1|=SPI_C1_MSTR_MASK;//SPI0 IS SET TO MASTER MODE
	SPI0_C1|=SPI_C1_SSOE_MASK;//SS pin function is automatic SS output
	SPI0_C2|=SPI_C2_MODFEN_MASK; //IN THE MASTER MODE THE SS PIN SERVES AS THE SLAVE SELECT INPUT
	SPI0_BR|=SPI_BR_SPPR(0x02);//BAUD PRESCALER DIVISOR TO 3
	SPI0_BR|=SPI_BR_SPR(0x08);//BAUD RATE DIVISOR TO 64

	SPI0_C1 |= SPI_C1_SPE_MASK;//THIS ENABLES SPI0 MODULE

}

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

void SPI_read_byte(uint8_t byte){

	while(!(SPI_S_SPRF_MASK&SPI0_S));

		byte=SPI0_D;//SENDS CHARACTER TO SPI0_D REGISTER


}

/**
 * @brief writes a single byte from the SPI bus
 *
 * The function should write a byte in the SPI data register with the help of the SPTEF bit in the SPI0_S register
 *
 *
 * @param byte of data
 *
 * @return void
 *
 */

void SPI_write_byte(uint8_t byte){

	while(!(SPI_S_SPTEF_MASK&SPI0_S));

	SPI0_D=byte;//SENDS CHARACTER TO SPI0_D REGISTER

}

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

void SPI_send_packet(uint8_* p, size_t length){

		int i;
		if(p != NULL)
		{
			for(i=0;i<length;i++)
			{
				while(!(SPI_S_SPTEF_MASK&SPI0_S));    // Wait until transmit buffer is empty
				SPI0_D = *p;                                                // Send the data
				p++;
			}
		}

}

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

void SPI_flush(){

	while(!(SPI_S_SPTEF_MASK&SPI0_S));    // Wait until transmit buffer is empty
}





