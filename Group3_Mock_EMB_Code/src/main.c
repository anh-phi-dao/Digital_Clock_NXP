#include <stdio.h>
#include "Cortex_M4.h"
#include "PCC_address.h"
#include "PORT_address.h"
#include "GPIO_address.h"
#include "SCG_config.h"
#include "Timer_config.h"
#include "LPUART.h"
#include "LPSPI.h"
#include "MEM.h"
#include <string.h>
#include <stdlib.h>

/* 1 to enable unit test, 0 to disable unit test */
#define UNIT_TEST 0

typedef struct
{
	uint8_t second;
	uint8_t minute;
	uint8_t hour;
	uint8_t flag;
} TIME;

typedef struct
{
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t flag;
} DATE;

typedef struct
{
	char tx[40];
	uint8_t tx_index;
	char rx[40];
	uint8_t rx_index;
} UART_BUFFER;

typedef struct
{
	uint16_t tx[40];
	uint8_t tx_size;
	uint8_t tx_index;
} SPI_BUFFER;

volatile TIME time;
volatile DATE date;
volatile UART_BUFFER uart;
volatile SPI_BUFFER spi;
volatile uint8_t ledStat = 1;
volatile uint8_t mainFlag = 0;

void button0_process(void);
void button1_process(void);
void set_time(void);
void set_date(void);
void get_time_month(void);

#if (UNIT_TEST == 1)
int test_gpio_init(void);
int test_sosc_8mhz_init(void);
int test_rccr_normal_run_init(void);
int test_nvic_init_(void);
int test_sys_tick_init(void);
int test_sys_tick_load_value(void);
int test_lpuartn_init(void);
int test_lpspi_init_master(void);
#endif

int main()
{
	/* Set up EEPROM */
	program_partition_command();
	flexram_normal_eeprom();
	
	/* Load EEPROM data */
	time.second = readEEPROM(eepromStart + 0);
	time.minute = readEEPROM(eepromStart + 1);
	time.hour = readEEPROM(eepromStart + 2);
	date.day = readEEPROM(eepromStart + 3);
	date.month = readEEPROM(eepromStart + 4);
	date.year = readEEPROM(eepromStart + 5);
	
	if (date.day > 50) date.day = 0;
	if (date.month > 100) date.month = 1;
	if (date.year > 9999) date.year = 1970;
	
	/* Configure GPIO pin */
	gpio_init(GPIOC, PORT12, INPUT, ISF_INTERRUPT_RISING_EDGE);
	gpio_init(GPIOC, PORT13, INPUT, ISF_INTERRUPT_RISING_EDGE);
	
	/* Configure system clock */
	sosc_8mhz_init(DIV_divided_by_1, DIV_divided_by_1);
	rccr_normal_run_init(System_OSC, Divide_by_1, Divide_by_1, Divide_by_1);
	
	/* Enable GPIO interrupt */
	nvic_init(PORTC_NVIC, 3);
	nvic_init(LPSPI1_NVIC, 2);
	nvic_init(LPUART1_TRANSMIT_RECIEVE_ERROR_OVERRUN_NVIC, 1);
	
	/* Enable system tick interrupt */
	sys_tick_init(INTERRUPT);
	sys_tick_load_value(4000000);
	
	/* Enable LPUART1 */
	lpuartn_init(1, 9600);
	
	/* Enable LPSPI1 */
	lpspi1_init_master();
	
	/* Set up led display */
	spi.tx[0] = 0x0C01;
	spi.tx[1] = 0x09FF;
	spi.tx[2] = 0x0B07;
	
	spi.tx_index = 0;
	spi.tx_size = 3;
	
	lpspi1_transmit_start();
	
	time.flag = 0;
	date.flag = 1;
	
	uint16_t table[25];
	uint8_t table_index = 0;
	
	#if (UNIT_TEST == 1)
	int tc1 =test_gpio_init();
	int tc2=test_sosc_8mhz_init();
	int tc3=test_rccr_normal_run_init();
	int tc4=test_nvic_init_();
	int tc5=test_sys_tick_init();
	int tc6=test_sys_tick_load_value();
	int tc7=test_lpuartn_init();
	int tc8=test_lpspi_init_master();
	#endif 
	while(1)
	{
		if (mainFlag == 2)
		{
			if (time.flag == 2)
			{
				spi.tx[0] = 0x0100 + table[table_index + 0];
				spi.tx[1] = 0x0200 + table[table_index + 1];
				spi.tx[2] = 0x0300 + table[table_index + 2];
				spi.tx[3] = 0x0400 + table[table_index + 3];
				spi.tx[4] = 0x0500 + table[table_index + 4];
				spi.tx[5] = 0x0600 + table[table_index + 5];
				spi.tx[6] = 0x0700 + table[table_index + 6];
				spi.tx[7] = 0x0800 + table[table_index + 7];
				
				spi.tx_index = 0;
				spi.tx_size = 8;
				
				lpspi1_transmit_start();
				
				table_index++;
				if (table_index > 17)
				{
					table_index = 0;
				}
			}
			
			int temp;
			switch (date.month)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
					temp = 31;
					break;
			case 4:
			case 6:
			case 9:
			case 11:
					temp = 30;
					break;
			default:
					if ((((date.year % 4) == 0) && ((date.year % 100) != 0)) || ((date.year % 400) == 0))
					{
							temp = 29;
					}
					else
					{
							temp = 28;
					}
			}
			if ((time.second + 1) >= 60)
			{
				time.second = 0;
				if ((time.minute + 1) >= 60)
				{
					time.minute = 0;
					if ((time.hour + 1) >= 24)
					{
						time.hour = 0;
						if (date.day + 1 > temp)
						{
							date.day = 1;
							if (date.month + 1 > 12)
							{
								date.month = 1;
								date.year++;
							}
							else
							{
								date.month++;
							}
						}
						else
						{
							date.day++;
						}
					}
					else
					{
						time.hour++;
					}
				}
				else
				{
					time.minute++;
				}
			}
			else
			{
				time.second++;
			}
			
			/* Update table */
			table[0] = time.second % 10;
			table[1] = time.second / 10;
			table[2] = 0x0A;
			table[3] = time.minute % 10;
			table[4] = time.minute / 10;
			table[5] = 0x0A;
			table[6] = time.hour % 10;
			table[7] = time.hour / 10;
			table[8] = 0x0F;
			table[9] = date.year % 1000 % 100 % 10;
			table[10] = date.year % 1000 % 100 / 10;
			table[11] = date.year % 1000 / 100;
			table[12] = date.year / 1000;
			table[13] = 0x80 + date.month % 10;
			table[14] = date.month / 10;
			table[15] = 0x80 + date.day % 10;
			table[16] = date.day / 10;
			table[17] = 0x0F;
			table[18] = time.second % 10;
			table[19] = time.second / 10;
			table[20] = 0x0A;
			table[21] = time.minute % 10;
			table[22] = time.minute / 10;
			table[23] = 0x0A;
			table[24] = time.hour % 10;
			
			sprintf(uart.tx, "%d:%d:%d-%d/%d/%d\n", time.hour, time.minute, time.second, date.day, date.month, date.year);
			lpuart1_transmit_start();
			
			if (time.flag == 0)
			{
				set_time();
			}
			else if (time.flag == 1)
			{
				set_date();
			}
			
			mainFlag = 0;
		}
	}
}

void SysTick_Handler (void)
{
	mainFlag += 1;
}

void PORTC_IRQHandler(void)
{
	PTC_PORT_INTERRUPT(button0_process,PORT12);
	PTC_PORT_INTERRUPT(button1_process,PORT13);
}

void button0_process(void)
{
	time.flag += 1;
	if (time.flag > 2)
	{
		time.flag = 0;
	}
}

void button1_process(void)
{
	ledStat ^= 1;
	if (ledStat == 0)
	{
		spi.tx[0] = 0x0C00;
		
		spi.tx_index = 0;
		spi.tx_size = 1;
		
		lpspi1_transmit_start();
	}
	else
	{
		spi.tx[0] = 0x0C01;
		
		spi.tx_index = 0;
		spi.tx_size = 1;
		
		lpspi1_transmit_start();
	}
}

void LPUART1_RxTx_IRQHandler(void)
{
	if (LPUART1->STAT & (1u << 23u))
	{
		if (uart.tx[uart.tx_index] != '\0')
		{
			LPUART1->DATA = uart.tx[uart.tx_index];
			uart.tx_index++;
		}
		else
		{
			LPUART1->CTRL &= ~(1u << 23u);
			uart.tx_index = 0;
		}
	}
	
	if (LPUART1->STAT & (1u << 21u))
	{
		uart.rx[uart.rx_index] = LPUART1->DATA;
		
		if (uart.rx[uart.rx_index] == '\n')
		{
			uart.rx[uart.rx_index] = '\0';
			uart.rx_index = 0;
			get_time_month();
		}
		else
		{
			uart.rx_index++;
		}
	}
}

void LPSPI1_IRQHandler(void)
{
	if (LPSPI1->SR & (1u << 0u))
	{
		if (spi.tx_index < spi.tx_size)
		{
			LPSPI1->TDR = spi.tx[spi.tx_index];
			spi.tx_index++;
		}
		else
		{
			LPSPI1->IER &= ~(1u << 0u);
			spi.tx_index = 0;
		}
	}
}

void set_time(void)
{
	spi.tx[0] = 0x0100 + time.second % 10;
	spi.tx[1] = 0x0200 + time.second / 10;
	spi.tx[2] = 0x0400 + time.minute % 10;
	spi.tx[3] = 0x0500 + time.minute / 10;
	spi.tx[4] = 0x0700 + time.hour % 10;
	spi.tx[5] = 0x0800 + time.hour / 10;
	spi.tx[6] = 0x030A;
	spi.tx[7] = 0x060A;
	
	spi.tx_index = 0;
	spi.tx_size = 8;
	
	writeEEPROM(eepromStart + 0, time.second);
	writeEEPROM(eepromStart + 1, time.minute);
	writeEEPROM(eepromStart + 2, time.hour);
		
	lpspi1_transmit_start();
}

void set_date(void)
{
	spi.tx[0] = 0x0100 + date.year % 1000 % 100 % 10;
	spi.tx[1] = 0x0200 + date.year % 1000 % 100 / 10;
	spi.tx[2] = 0x0300 + date.year % 1000 / 100;
	spi.tx[3] = 0x0400 + date.year / 1000;
	spi.tx[4] = 0x0580 + date.month % 10;
	spi.tx[5] = 0x0600 + date.month / 10;
	spi.tx[6] = 0x0780 + date.day % 10;
	spi.tx[7] = 0x0800 + date.day / 10;
	
	spi.tx_index = 0;
	spi.tx_size = 8;
	
	writeEEPROM(eepromStart + 3, date.day);
	writeEEPROM(eepromStart + 4, date.month);
	writeEEPROM(eepromStart + 5, date.year);
		
	lpspi1_transmit_start();
}

void get_time_month(void)
{
	char *temp = strtok(uart.rx, ".");
	time.hour = atoi(temp);
	temp = strtok(NULL, ".");
	time.minute = atoi(temp);
	temp = strtok(NULL, ".");
	time.second = atoi(temp);
	temp = strtok(NULL, ".");
	date.day = atoi(temp);
	temp = strtok(NULL, ".");
	date.month = atoi(temp);
	temp = strtok(NULL, ".");
	date.year = atoi(temp);
}


#if (UNIT_TEST == 1)
int test_gpio_init(void)
{
	
	if ((PCC->PCC_PORTC&(1<<30))!=(1<<30))
	{
		return 0;
	}
	if(PORTC->PCR[12]!=((1<<8)|(ISF_INTERRUPT_RISING_EDGE<<16)))
	{
		return 0;
	}
	if((GPIOC->PDDR&(1<<12))>>12!=0)
	{
		return 0;
	}
	return 1;
}

int test_sosc_8mhz_init(void)
{
	
	if(SCG->SOSCCFG!=((1<<EREFS)|(2<<RANGE)))
	{
		return 0;
	}
	if(SCG->SOSCDIV!=((DIV_divided_by_1<<DIV1)|(DIV_divided_by_1<<DIV2)))
	{
		return 0;
	}
	if(SCG->SOSCCSR&((1<<SOSCVLD)|((1<<SOSCEN)))!=((1<<SOSCVLD)|((1<<SOSCEN))))
	{
		return 0;
	}
	return 1;
}	

int test_rccr_normal_run_init(void)
{
	
	if(SCG->RCCR!=((System_OSC<<SCS)|(Divide_by_1<<DIVCORE)|( Divide_by_1<<DIVBUS)|(Divide_by_1<<DIVSLOW)))
	{
		return 0;
	}
	if(SCG->CSR!=SCG->RCCR)
	{
		return 0;
	}
	return 1;
}

int test_nvic_init_(void)
{
	
	if(((NVIC->ISER[PORTC_NVIC.NONE_IPR_NUMBER])&(1<<(PORTC_NVIC.NVIC_ID%32)))==0)
	{
		return 0;
	}
	return 1;
}

int test_sys_tick_init(void)
{
	
	if(SYST->CSR!=7)
	{
		return 0;
	}
	return 1;
}

int test_sys_tick_load_value(void)
{
	
	if(SYST->RVR!=4000000-1)
	{
		return 0;
	}		
	return 1;
}

int test_lpuartn_init(void)
{
	if(LPUART1->BAUD!=((0b01001u << 24u) | ((8000000u / 9600 / 10u) << 0u)))
	{
		return 0;
	}
	if(LPUART1->CTRL != ((1u << 21u) | (1u << 19u) | (1u << 18u)))
	{
		return 0;
	}
	return 1;
}

int test_lpspi_init_master(void)
{
	if( LPSPI1->CFGR1 != ((1u << 3u) | (1u << 0u)))
	{
		return 0;
	}
	if(LPSPI1->TCR != ((0b010u << 27u) | (0b11u << 24u) | (15u << 0u)))
	{
		return 0;
	}
	return 1;
}


#endif