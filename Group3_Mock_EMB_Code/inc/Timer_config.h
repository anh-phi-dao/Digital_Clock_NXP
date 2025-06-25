/**
 * @file Timer_config.h
 * @author Dao Anh Phi
 * @brief this file uses for defining the register of timer modules
 *        
**/

#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

struct FLEX_TIMER_STATUS_CONTROL_VALUe_REGISTERS
{
	volatile uint32_t CnSC;
	volatile uint32_t CnV;
};

struct FLEX_TIMER_MIRRORS
{
	volatile uint32_t CnV_MIRROR;
};

typedef struct 
{
    volatile uint32_t SC;//0x00
    volatile uint32_t CNT;//0x4
    volatile uint32_t MOD;//0x8
		/*
    volatile uint32_t C0SC;//0xC
    volatile uint32_t C0V;//0x10
    volatile uint32_t C1SC;//0x14
    volatile uint32_t C1V;//0x18
    volatile uint32_t C2SC;//0x1C
    volatile uint32_t C2V;//0x20
    volatile uint32_t C3SC;//0x24
    volatile uint32_t C3V;//0x28
    volatile uint32_t C4SC;//0x2C
    volatile uint32_t C4V;//0x30
    volatile uint32_t C5SC;//0x34
    volatile uint32_t C5V;//0x38
    volatile uint32_t C6SC;//0x3C
    volatile uint32_t C6V;//0x40
    volatile uint32_t C7SC;//0x44
    volatile uint32_t C7V;//0x48
		*/
		struct FLEX_TIMER_STATUS_CONTROL_VALUe_REGISTERS control[8];
    volatile uint32_t CNTIN;//0x4C
    volatile uint32_t STATUS;//0x50
    volatile uint32_t MODE;//0x54
    volatile uint32_t SYNC;//0x58
    volatile uint32_t OUTINIT;//0x5C
    volatile uint32_t OUTMASK;//0x60
    volatile uint32_t COMBINE;//0x64
    volatile uint32_t DEADTIME;//0x68
    volatile uint32_t EXTTRIG;//0x6C
    volatile uint32_t POL;//0x70
    volatile uint32_t FMS;//0x74
    volatile uint32_t FILTER;//0x78
    volatile uint32_t FLTCTRL;//0x7C
    volatile uint32_t QDCTRL;//0x80
    volatile uint32_t CONF;//0x84
    volatile uint32_t FLTPOL;//0x88
    volatile uint32_t SYNCONF;//0x8C
    volatile uint32_t INVCTR;//0x90
    volatile uint32_t SWOCTRL;//0x94
    volatile uint32_t PWMLOAD;//0x98
    volatile uint32_t HCR;//0x9C
    volatile uint32_t PAIR0DEADTIME;//0xA0

    volatile uint32_t Reserve;

    volatile uint32_t PAIR1DEADTIME;//0xA8

    volatile uint32_t Reserve2;

    volatile uint32_t PAIR2DEADTIME;//0xB0

    volatile uint32_t Reserve3;

    volatile uint32_t PAIR3DEADTIME;//0xB8

    volatile uint32_t Reserve4[81];

    volatile uint32_t MOD_MIRROR;//0x200
		/*
    volatile uint32_t C0V_MIRROR;//0x204
    volatile uint32_t C1V_MIRROR;//0x208
    volatile uint32_t C2V_MIRROR;//0x20C
    volatile uint32_t C3V_MIRROR;//0x210
    volatile uint32_t C4V_MIRROR;//0x214
    volatile uint32_t C5V_MIRROR;//0x218
    volatile uint32_t C6V_MIRROR;//0x21C
    volatile uint32_t C7V_MIRROR;//0x220
		*/
		struct FLEX_TIMER_MIRRORS mirrorsn[8];

}Flex_Timer;

typedef struct 
{
    volatile uint32_t CSR;
    volatile uint32_t PSR;
    volatile uint32_t CMR;
    volatile uint32_t CNR;

}Low_power_timer;


struct LPIT_TIMER_REGISTERS
{
    volatile uint32_t TVAL;//0x20
    volatile uint32_t CVAL;//0x24
    volatile uint32_t TCTRL;//0x28
    volatile uint32_t RESERVE;
};

typedef struct 
{
    volatile uint32_t VERID;//0x00
    volatile uint32_t PARAM;//0x04
    volatile uint32_t MCR;//0x08
    volatile uint32_t MSR;//0x0C
    volatile uint32_t MIER;//0x10
    volatile uint32_t SETTEN;//0x14
    volatile uint32_t CLRTEN;//0x18

    volatile uint32_t Reserve;
    /*
    volatile uint32_t TVAL0;//0x20
    volatile uint32_t CVAL0;//0x24
    volatile uint32_t TCTRL0;//0x28

    volatile uint32_t Reserve1;

    volatile uint32_t TVAL1;//0x30
    volatile uint32_t CVAL1;//0x34
    volatile uint32_t TCTRL1;//0x38

    volatile uint32_t Reserve2;

    volatile uint32_t TVAL2;//0x40
    volatile uint32_t CVAL2;//0x44
    volatile uint32_t TCTRL2;//0x48  

    volatile uint32_t Reserve3;

    volatile uint32_t TVAL3;//0x50
    volatile uint32_t CVAL3;//0x54
    volatile uint32_t TCTRL3;//0x58
    */
    struct LPIT_TIMER_REGISTERS TIMER_X[4];
    
}low_power_interrupt_timer;

typedef enum
{
    LPIT_TIMER_CHANNEL_0,
    LPIT_TIMER_CHANNEL_1,
    LPIT_TIMER_CHANNEL_2,
    LPIT_TIMER_CHANNEL_3,

}LPIT_TIMER_CHANNEL_NUMBER;

enum TCTRLn_MASK
{
    T_EN,
    CHAIN,
    MODE,
    MODE_1,
    TSOT=16,
    TSOI,
    TROT,
    TRG_SRC=23,
    TRIF_SEL,
};

typedef enum
{
    Thirty_two_bits_Periodic_Counter,
    Dual_16_bit_Periodic_Counter,
    Two_bit_Trigger_Accumulator,
    Thirty_two_bits_Trigger_Input_Capture,

}LPIT_TCTRLn_MODE;

#define NO_INTERRUPT 0
#define INTERRUPT 1

#define LPIT ((low_power_interrupt_timer*)0x40037000UL)

#define LPTMR ((Low_power_timer*)0x40040000UL)

#define FTM0 ((Flex_Timer*)0x40038000UL)
#define FTM1 ((Flex_Timer*)0x40039000UL)
#define FTM2 ((Flex_Timer*)0x4003A000UL)
#define FTM3 ((Flex_Timer*)0x40026000UL)
#define FTM4 ((Flex_Timer*)0x4006E000UL)
#define FTM5 ((Flex_Timer*)0x4006F000UL)
#define FTM6 ((Flex_Timer*)0x40070000UL)
#define FTM7 ((Flex_Timer*)0x40071000UL)


void LPIT_MODULE_ENABLE(uint8_t psc);
void LPIT_CONFIG(LPIT_TIMER_CHANNEL_NUMBER number,volatile uint32_t value,LPIT_TCTRLn_MODE mode,char TROT_Option,char TSOI_Option,char TSOT_Option,char Chain_Option);
void LPIT_ENABLE(LPIT_TIMER_CHANNEL_NUMBER number,char interrupt_option);
void LPIT_CHANGE_VALUE(LPIT_TIMER_CHANNEL_NUMBER number,uint32_t value);
void LPIT_DISABLE(LPIT_TIMER_CHANNEL_NUMBER number,char interrupt_option);
void LPIT_DISABLE_MODULE();
uint32_t LPIT_READ_CURRENT_VALUE(LPIT_TIMER_CHANNEL_NUMBER number);


#ifdef __cplusplus
}
#endif

#endif 
