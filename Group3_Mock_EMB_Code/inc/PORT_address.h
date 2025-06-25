/**
  * @file    Port_address.h
  * @author  Dao Anh Phi
  * @brief   GPIO config
  *          This file provides firmware functions to manage the register, define 
  *          register address,mask for GPIO registers.
**/
#ifndef PORT_ADDRESS_H
#define PORT_ADDRESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct
{
	volatile uint32_t PCR[32];
	volatile uint32_t GPCLR;
	volatile uint32_t GPCHR;
	volatile uint32_t GICLR;
	volatile uint32_t GICHR;

	uint32_t Reserve[4];

	volatile uint32_t ISFR;
	volatile uint32_t DFER;
	volatile uint32_t DFCR;
	volatile uint32_t DFWR;
	
}Port;

#define PORTA ((Port*)0x40049000UL)
#define PORTB ((Port*)0x4004A000UL)
#define PORTC ((Port*)0x4004B000UL)
#define PORTD ((Port*)0x4004C000UL)
#define PORTE ((Port*)0x4004D000UL)

#ifdef __cplusplus
}
#endif


#endif 

