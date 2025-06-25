#include "LPSPI.h"
#include "PCC_address.h"
#include "PORT_address.h"

void lpspi1_init_master(void)
{
		PCC->PCC_PORTB|=(1<<30);
		PORTB->PCR[14]= (3<<8);
		PORTB->PCR[15]=3<<8;
		PORTB->PCR[16]=3<<8;
		PORTB->PCR[17]=3<<8;
	
		/* Enable module clock and choose SPLLDIV2 as clock source */
    PCC->PCC_LPSPI1 = (1u << 30) | (0b001u << 24);

		LPSPI1->CR = 0u;
	
    LPSPI1->IER = 0u;
	
    LPSPI1->DER = 0u;
	
    LPSPI1->CFGR0 = 0u;
		
    LPSPI1->CFGR1 = (1u << 3u) | (1u << 0u);
	
		LPSPI1->TCR = (0b010u << 27u) | (0b11u << 24u) | (15u << 0u);

    LPSPI1->CCR = (4u << 24u) | (9u << 24u) | (8u << 8u) | (8u << 0u);

    LPSPI1->FCR = (0u << 0u);

    LPSPI1->CR = (1u << 3u) | (1u << 0u);
}

void LPSPI1_transmit(uint16_t data)
{
	volatile uint32_t status = LPSPI1->SR;
  while (!(status & (1u << 0u)))
	{
		status = LPSPI1->SR;
	}
  LPSPI1->TDR = data;
}

uint16_t LPSPI1_receive(void)
{
	uint16_t data;
	while (!(LPSPI1->SR & (1u << 1u)));
	data = LPSPI1->RDR;
	LPSPI1->SR |= (1u << 1u);
	return data;
}

void lpspi1_transmit_start(void)
{
	LPSPI1->IER |= (1u << 0u);
}