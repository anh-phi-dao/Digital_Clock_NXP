#include "LPUART.h"
#include "PCC_address.h"
#include "PORT_address.h"

void lpuartn_init(uint8_t n, uint32_t baud)
{
    switch (n)
    {
        case 0:
					PCC->PCC_PORTB=(1<<30);
					PORTB->PCR[0]=(2<<8);
					PORTB->PCR[1]=(2<<8);
					PCC->PCC_LPUART0 = (1u << 30) | (0b001u << 24);
					LPUART0->BAUD = (0b01001u << 24u) | ((baud * 10 / 8000000) << 0u);
					LPUART0->CTRL = (1u << 21u) | (1u << 19u) | (1u << 18u) ;
					break;
				case 1:
					PCC->PCC_PORTC=(1<<30);
					PORTC->PCR[7]=(2<<8);
					PORTC->PCR[6]=(2<<8);
					PCC->PCC_LPUART1 = (1u << 30) | (0b001u << 24);
					LPUART1->BAUD = (0b01001u << 24u) | ((8000000u / baud / 10u) << 0u);
					LPUART1->CTRL = (1u << 21u) | (1u << 19u) | (1u << 18u);
					break;
				case 2:
					PCC->PCC_PORTA=(1<<30);
					PORTA->PCR[9]=(2<<8);
					PORTA->PCR[8]=(2<<8);
					PCC->PCC_LPUART2 = (1u << 30) | (0b001u << 24);
					LPUART2->BAUD = (0b01001u << 24u) | ((baud * 10u / 8000000u) << 0u);
					LPUART2->CTRL = (1u << 21u) | (1u << 19u) | (1u << 18u);
					break;
				default:
					break;
    }
}

void LPUART1_transmit(uint8_t data)
{
	while(!(LPUART1->STAT & (1u << 23u)));
	LPUART1->DATA = data;
}

void lpuart1_transmit_start(void)
{
	LPUART1->CTRL |= (1u << 23u);
}