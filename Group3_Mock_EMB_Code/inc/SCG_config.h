/**
  * @file    SCG.h
  * @author  Dao Anh Phi
  * @brief   SCG config
  *          This file provides firmware functions to manage the register, define 
  *          register address,mask for SCG registers.
**/

#ifndef SCG_CONFIG_H
#define SCG_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief SCG register
**/
typedef struct 
{
   volatile uint32_t VERID;//0x00
   volatile uint32_t PARAM;//0x04

   volatile uint32_t Reserve[2];

   volatile uint32_t CSR;//0x10
   volatile uint32_t RCCR;//0x14
   volatile uint32_t VCCR;//0x18
   volatile uint32_t HCCR;//0x1C
   volatile uint32_t CLKOUTCNFG;//0x20
    
   volatile uint32_t Reserve1[55];

   volatile uint32_t SOSCCSR;//0x100
   volatile uint32_t SOSCDIV;//0x104
   volatile uint32_t SOSCCFG;//0x108

   volatile uint32_t Reserve2[61];

   volatile uint32_t SIRCCSR;//0x200
   volatile uint32_t SIRCDIV;//0x204
   volatile uint32_t SIRCCFG;//0x208

   volatile uint32_t Reserve3[61];

   volatile uint32_t FIRCCSR;//0x300
   volatile uint32_t FIRCDIV;//0x304
   volatile uint32_t FIRCCFG;//0x308

   volatile uint32_t Reserve4[189];

   volatile uint32_t SPLLCSR;//0x600
   volatile uint32_t SPLLDIV;//0x604
   volatile uint32_t SPLLCFG;//0x608

}SCG_config;


enum HCCR_RCCR_VCCR_CSR_MASK
{
    DIVSLOW,
    DIVSLOW_1,
    DIVSLOW_2,
    DIVSLOW_3,
    DIVBUS,
    DIVBUS_1,
    DIVBUS_2,
    DIVBUS_3,
    DIVCORE=16,
    DIVCORE_1,
    DIVCORE_2,
    DIVCORE_3,
    SCS=24,
    SCS_1,
    SCS_2,
    SCS_3,
};

enum HCCR_RCCR_VCCR_SCS_VALUE
{
    System_OSC=1,
    SIRC,
    FIRC,
    System_PPL=6,
};

enum HCCR_RCCR_DIVCORE_DIVBUS_DIVSLOW
{
    Divide_by_1,
    Divide_by_2,
    Divide_by_3,
    Divide_by_4,
    Divide_by_5,
    Divide_by_6,
    Divide_by_7,
    Divide_by_8,
    Divide_by_9_NO_USE_FOR_DIVSLOW,
    Divide_by_10_NO_USE_FOR_DIVSLOW,
    Divide_by_11_NO_USE_FOR_DIVSLOW,
    Divide_by_12_NO_USE_FOR_DIVSLOW,
    Divide_by_13_NO_USE_FOR_DIVSLOW,
    Divide_by_14_NO_USE_FOR_DIVSLOW,
    Divide_by_15_NO_USE_FOR_DIVSLOW,
    Divide_by_16_NO_USE_FOR_DIVSLOW,
};

enum SOSCCSR_MASK
{
    SOSCEN,
    SOSCCM=16,
    SOSCCMRE,
    SOSC_LK=23,
    SOSCVLD,
    SOSCSEL,
    SOSCELR,
};

enum SOSCDIV_SIRCDIV_FIRCDIV_SPLLDIV_MASK
{
    DIV1,
    DIV1_1,
    DIV1_2,
    DIV2=8,
    DIV2_1,
    DIV2_2,
};

typedef enum 
{
    DIV_divided_by_1=1,
    DIV_divided_by_2,
    DIV_divided_by_4,
    DIV_divided_by_8,
    DIV_divided_by_16,
    DIV_divided_by_32,
    DIV_divided_by_64,

}SOSC_SIRC_FIRC_SPLL_DIV_VAL;


enum SOSCCFG_MASK
{
    EREFS=2,
    HGO,
    RANGE,
    RANGE_1,

};

enum SIRCCSR_MASK
{
    SIRCEN,
    SIRCSTEN,
    SIRCLPEN,
    SIRC_LK=23,
    SIRCVLD,
    SIRCSEL,
};

enum FIRCCSR_MASK
{
    FIRCEN,
    FIRCREGOFT=3,
    FIRC_LK=23,
    FIRCVLD,
    FIRCSEL,
    FIRCERR,
};

enum SIRCCFG_FIRCCFG_MASK
{
    IRC_RANGE,
    IRC_RANG1,
};

enum SPLLCSR_MASK
{
    SPLLEN,
    SPLLCM=16,
    SPLLCMRE,
    SPLL_LK=23,
    SPLLVLD,
    SPLLSEL,
    SPLLERR,
};

enum SPLLDIV_MASK
{
    SPLLDIV1,
    SPLLDIV1_1,
    SPLLDIV1_2,
    SPLLDIV2=8,
    SPLLDIV2_1,
    SPLLDIV2_2,
};

enum SPLLCFG_MASK
{
    SOURCE,
    PREDIV=8,
    PREDIV_1,
    PREDIV_2,
    MULT=16,
    MULT_1,
    MULT_2,
    MULT_3,
    MULT_4,
};

typedef enum 
{
    System_Oscillator,
    Fast_Internal_Reference_Clock,    
}SPLLCFG_SOURCE;

typedef enum
{
    Multiply_factor_16,
    Multiply_factor_17,
    Multiply_factor_18,
    Multiply_factor_19,
    Multiply_factor_20,
    Multiply_factor_21,
    Multiply_factor_22,
    Multiply_factor_23,
    Multiply_factor_24,
    Multiply_factor_25,
    Multiply_factor_26,
    Multiply_factor_27,
    Multiply_factor_28,
    Multiply_factor_29,
    Multiply_factor_30,
    Multiply_factor_31,
    Multiply_factor_32,
    Multiply_factor_33,
    Multiply_factor_34,
    Multiply_factor_35,
    Multiply_factor_36,
    Multiply_factor_37,
    Multiply_factor_38,
    Multiply_factor_39,
    Multiply_factor_40,
    Multiply_factor_41,
    Multiply_factor_42,
    Multiply_factor_43,
    Multiply_factor_44,
    Multiply_factor_45,
    Multiply_factor_46,
    Multiply_factor_47,
}SPLLCFG_VCO_MULTIPLY_FACTOR;

typedef enum
{
    Divide_factor_1,
    Divide_factor_2,
    Divide_factor_3,
    Divide_factor_4,
    Divide_factor_5,
    Divide_factor_6,
    Divide_factor_7,
    Divide_factor_8,
}SPLLCFG_PREDIVIDE_FACTOR;

enum CLKOUTCNFG
{
    CLKOUTSEL=24,
};

typedef enum
{
    NORMAL_RUN,
    HIGH_RUN,
    VERY_LOW_POWER_RUN,
    VERY_LOW_POWER_SLOW,
}GENERAL_CLOCK_MODE;

#define SCG ((SCG_config*)0x40064000UL)

void sosc_8mhz_init(SOSC_SIRC_FIRC_SPLL_DIV_VAL val1,SOSC_SIRC_FIRC_SPLL_DIV_VAL val2);
void FIRC_48MHZ_INIT(SOSC_SIRC_FIRC_SPLL_DIV_VAL val1,SOSC_SIRC_FIRC_SPLL_DIV_VAL val2);
void SIRC_8MHZ_INIT(GENERAL_CLOCK_MODE mod);
void SPLL_INIT(SPLLCFG_VCO_MULTIPLY_FACTOR mutiplier,SPLLCFG_PREDIVIDE_FACTOR predivide,SPLLCFG_SOURCE source,SOSC_SIRC_FIRC_SPLL_DIV_VAL val1,SOSC_SIRC_FIRC_SPLL_DIV_VAL val2);
void rccr_normal_run_init(uint8_t source,uint8_t divcore,uint8_t divbus,uint8_t divslow);
void HCCR_High_run_init(uint8_t source,uint8_t divcore,uint8_t divbus,uint8_t divslow);
void VCCR_Very_low_power_run_init(uint8_t source,uint8_t divcore,uint8_t divbus,uint8_t divslow);
void Slow_Run_Fast_IRC();
void Normal_run_system_pll_160();
void Normal_run_system_pll_128();
void High_speed_run_pll_112();
void High_speed_run_pll_160();
void Very_low_power_run();
void CLOCK_CONFIG_FREQUENCY_FOR_NORMAL_RUN(float CORE_SYS_CLOCK,float BUS_CLOCK,float FLASH_CLOCK,SPLLCFG_SOURCE Clock_source);
void CLOCK_SIRC_CONFIG_FREQUENCY_NORMAL_RUN(float CORE_SYS_CLOCK,float BUS_CLOCK,float FLASH_CLOCK);


#ifdef __cplusplus
}
#endif

#endif