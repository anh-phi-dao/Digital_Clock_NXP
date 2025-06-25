#ifndef LPSPI_H
#define LPSPI_H

#include <stdint.h>

#define LPSPI0_BASE 0x4002C000u
#define LPSPI1_BASE 0x4002D000u
#define LPSPI2_BASE 0x4002E000u

#define LPSPI0 ((LPSPI_REG*)LPSPI0_BASE)
#define LPSPI1 ((LPSPI_REG*)LPSPI1_BASE)
#define LPSPI2 ((LPSPI_REG*)LPSPI2_BASE)

typedef struct
{
    uint32_t VERID;
    uint32_t PARAM;
    uint32_t RES_1[2];
    uint32_t CR;
    uint32_t SR;
    uint32_t IER;
    uint32_t DER;
    uint32_t CFGR0;
    uint32_t CFGR1;
    uint32_t RES_2[2];
    uint32_t DMR0;
    uint32_t DMR1;
    uint32_t RES_3[2];
    uint32_t CCR;
		uint32_t RES_4[5];
    uint32_t FCR;
    uint32_t FSR;
    uint32_t TCR;
    uint32_t TDR;
    uint32_t RES_5[2];
    uint32_t RSR;
    uint32_t RDR;
} LPSPI_REG;

void lpspi1_init_master(void);
void LPSPI1_transmit(uint16_t data);
uint16_t LPSPI1_receive(void);
void lpspi1_transmit_start(void);

#endif