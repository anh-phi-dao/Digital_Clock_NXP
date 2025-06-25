#ifndef MEM_H
#define MEM_H

#include <stdint.h>

#define FTFC_BASE 0x40020000u

#define FTFC ((FTFC_REG*)FTFC_BASE)

typedef struct
{
	uint8_t FSTAT;
	uint8_t FCNFG;
	uint8_t FSEC;
	uint8_t FOPT;
	uint8_t FCCOB3;
	uint8_t FCCOB2;
	uint8_t FCCOB1;
	uint8_t FCCOB0;
	uint8_t FCCOB7;
	uint8_t FCCOB6;
	uint8_t FCCOB5;
	uint8_t FCCOB4;
	uint8_t FCCOBB;
	uint8_t FCCOBA;
	uint8_t FCCOB9;
	uint8_t FPROT8;
	uint8_t FPROT2;
	uint8_t FPROT1;
	uint8_t FPROT0;
	uint8_t RES_1[2];
	uint8_t FEPROT;
	uint8_t FDPROT;
	uint8_t RES_2[20];
	uint8_t FCSESTAT;
	uint8_t RES_3;
	uint8_t FERSTAT;
	uint8_t FERCNFG;
} FTFC_REG;

void flash_ready(void);
void flash_launch_command(void);
void program_partition_command(void);
void flexram_normal_eeprom(void);
void writeEEPROM(uint32_t *address, uint32_t data);
uint32_t readEEPROM(uint32_t *address);

#define eepromStart (uint32_t*)0x14000000u

#endif