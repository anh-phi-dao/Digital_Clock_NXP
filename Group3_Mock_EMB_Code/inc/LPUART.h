#ifndef LPUART_H
#define LPUART_H

#include <stdint.h>

#define LPUART0_BASE 0x4006A000u
#define LPUART1_BASE 0x4006B000u
#define LPUART2_BASE 0x4006C000u

#define LPUART0 ((LPUART_REG*)LPUART0_BASE)
#define LPUART1 ((LPUART_REG*)LPUART1_BASE)
#define LPUART2 ((LPUART_REG*)LPUART2_BASE)

typedef struct
{
    uint32_t VERID;
    uint32_t PARAM;
    uint32_t GLOBAL;
    uint32_t PINCFG;
    uint32_t BAUD;
    uint32_t STAT;
    uint32_t CTRL;
    uint32_t DATA;
    uint32_t MATCH;
    uint32_t MODIR;
    uint32_t FIFO;
    uint32_t WATER;
} LPUART_REG;

void lpuartn_init(uint8_t n, uint32_t baud);
void LPUART1_transmit(uint8_t data);
void lpuart1_transmit_start(void);

#endif