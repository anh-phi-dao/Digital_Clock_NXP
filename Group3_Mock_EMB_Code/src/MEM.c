#include "MEM.h"

void flash_ready(void)
{
	while(!(FTFC->FSTAT & (1u << 7u)));
	if (FTFC->FSTAT & (1u << 5u))
	{
		FTFC->FSTAT |= (1u << 5u);
	}
	if (FTFC->FSTAT & (1u << 4u))
	{
		FTFC->FSTAT |= (1u << 4u);
	}
}

void flash_launch_command(void)
{
	while(!(FTFC->FSTAT & (1u << 7u)));
	FTFC->FSTAT |= (1u << 7u);
}

void program_partition_command(void)
{
	flash_ready();
	FTFC->FCCOB0 = 0x80u;
	FTFC->FCCOB1 = 0u;
	FTFC->FCCOB2 = 0u;
	FTFC->FCCOB3 = 0u;
	FTFC->FCCOB4 = 0x02u;
	FTFC->FCCOB5 = 0x04u;
	flash_launch_command();
}

void flexram_normal_eeprom(void)
{
	flash_ready();
	FTFC->FCCOB0 = 0x81;
	FTFC->FCCOB1 = 0x00;
	flash_launch_command();
	while(!(FTFC->FCNFG & (1u << 0u)));
}

void writeEEPROM(uint32_t *address, uint32_t data)
{
	while(!(FTFC->FSTAT & (1u << 7u)));
	*address = data;
}

uint32_t readEEPROM(uint32_t *address)
{
	while(!(FTFC->FSTAT & (1u << 7u)));
	uint32_t data = *address;
	return data;
}