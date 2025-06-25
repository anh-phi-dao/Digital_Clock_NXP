/**
  * @file    PCC_address.h
  * @author  Dao Anh Phi
  * @brief   PCC config
  *          This file provides firmware functions to manage the register, define 
  *          register address,mask for PCC registers.
**/
#ifndef PCC_ADDRESS_H
#define PCC_ADDRESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct
{
	volatile uint32_t PCC_FTFC;//0x80
	volatile uint32_t PCC_DMAMUX;//0x84

	volatile uint32_t Reserve[2];

	volatile uint32_t PCC_FlexCAN0;//0x90
	volatile uint32_t PCC_FlexCAN1;//0x94
	volatile uint32_t PCC_FTM3;//0x98
	volatile uint32_t PCC_ADC1;//0x9C

	volatile uint32_t Reserve1[3];

	volatile uint32_t PCC_FlexCAN2;//0xAC
	volatile uint32_t PCC_LPSPI0;//0xB0
	volatile uint32_t PCC_LPSPI1;//0xB4
	volatile uint32_t PCC_LPSPI2;//0xB8

	volatile uint32_t Reserve2[2];

	volatile uint32_t PCC_PDB1;//0xC4
	volatile uint32_t PCC_CRC;//0xC8

	volatile uint32_t Reserve3[3];

	volatile uint32_t PCC_PDB0;//0xD8
	volatile uint32_t PCC_LPIT;//0xDC
	volatile uint32_t PCC_FTM0;//0xE0
	volatile uint32_t PCC_FTM1;//0xE4
	volatile uint32_t PCC_FTM2;//0xE8
	volatile uint32_t PCC_ADC0;//0xEC

	volatile uint32_t Reserve4[1];
	
	volatile uint32_t PCC_RTC;//0xF4
	
	volatile uint32_t Reserve5[2];
	
	volatile uint32_t PCC_LPTMR0;//0x100
	
	volatile uint32_t Reserve6[8];
	
	volatile uint32_t PCC_PORTA;//0x124
	volatile uint32_t PCC_PORTB;//0x128
	volatile uint32_t PCC_PORTC;//0x12C
	volatile uint32_t PCC_PORTD;//0x130
	volatile uint32_t PCC_PORTE;//0x134
	
	volatile uint32_t Reserve7[6];
	
	volatile uint32_t PCC_SAI0;//0x150
	volatile uint32_t PCC_SAI1;//0x154
	
	volatile uint32_t Reserve8[4];
	
	volatile uint32_t PCC_FLEXIO;//0x168
	
	volatile uint32_t Reserve9[6];
	
	volatile uint32_t PCC_EWM;//0x184
	
	volatile uint32_t Reservex[4];
	
	volatile uint32_t PCC_LPI2C0;//0x198
	volatile uint32_t PCC_LPI2C1;//0x19C
	
	volatile uint32_t Reserve10[2];
	
	volatile uint32_t PCC_LPUART0;//0x1A8
	volatile uint32_t PCC_LPUART1;//0x1AC
	volatile uint32_t PCC_LPUART2;//0x1B0
	
	volatile uint32_t Reserve11[1];
	
	volatile uint32_t PCC_FTM4;//0x1B8
	volatile uint32_t PCC_FTM5;//0x1BC
	volatile uint32_t PCC_FTM6;//0x1C0
	volatile uint32_t PCC_FTM7;//0x1C4
	
	volatile uint32_t Reserve12[1];
	
	volatile uint32_t PCC_CMP0;//0x1CC
	
	volatile uint32_t Reserve13[2];
	
	volatile uint32_t PCC_QSPI;//0x1D8
	
	volatile uint32_t Resever14[2];
	
	volatile uint32_t PCC_ENET;//0x1E4
}pcc;

enum PCC_X_PSC
{
	SOSCDIV2_CLK=1,
	SIRCDIV2_CLK,
	FIRCDIV2_CLK,
	SPLLDIV2_CLK=6
};

#define PCC ((pcc*)0x40065080)


#ifdef __cplusplus
}
#endif
#endif 