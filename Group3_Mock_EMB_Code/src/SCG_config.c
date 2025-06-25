/**
 * **
  ******************************************************************************
  * @file    SCG.c
  * @author  Dao Anh Phi
  * @brief   SCG clock configuration.
  *          This file provides firmware functions to manage the following
  *          functionalities of System Clock Generation.
  *           + System OSCILATOR (SOSC)
  *           + system peripheral phase lock loop (PLL)
  *           + Fast Internal Reference clock(FIRC)
  *           + Slow Internal Reference clock(SIRC)
  *           + Clock option 
  
**/

#include <stdint.h>
#include "SCG_config.h"


/******************************************
 * @brief in oder to use this drive you need to understand some feature in SCG registers
 *        You can use some common default configuration or you can change the frequency as 
 *        like but not every frequency is suittable. And the function allow to modify frequency
 *        only allow to run in normal mode
 *        You can configure manually by these 2 function. Example
 *        SOSC_8MHZ_INIT();
 *        SPLL_INIT(SPLLCFG_VCO_MULTIPLY_FACTOR mutiplier,SPLLCFG_PREDIVIDE_FACTOR predivide,SPLLCFG_SOURCE source,SOSC_SIRC_FIRC_SPLL_DIV_VAL val1,SOSC_SIRC_FIRC_SPLL_DIV_VAL val2);
 *        RCCR_Normal_run_init(uint8_t source,uint8_t divcore,uint8_t divbus,uint8_t divslow)
*******************************************/


/**
 * @brief set up system_osc with 8mhz crystal oscillator
 *        
**/
 void sosc_8mhz_init(SOSC_SIRC_FIRC_SPLL_DIV_VAL val1,SOSC_SIRC_FIRC_SPLL_DIV_VAL val2)
{
    volatile uint32_t temp=0;
    SCG->SOSCCFG=0;
    SCG->SOSCDIV=0;
    SCG->SOSCCFG=0;
    SCG->SOSCDIV|=(val1<<DIV1)|(val2<<DIV2);//divided by 1//
    SCG->SOSCCFG=(1<<EREFS)|(2<<RANGE);//internal oscillator,low gain operator,medium range
    temp=SCG->SOSCCSR;
    while((temp&(1<<SOSC_LK))!=0)//wait until SOSCCSR is unlock
    {

    }
    SCG->SOSCCSR|=(1<<SOSCEN);//enable system osc
     temp=SCG->SOSCCSR;
    while ((temp&(1<<SOSCVLD))==0)//wait until system osc is valid
    {
        temp=SCG->SOSCCSR;
    }
    
}

/**
 * @brief set up FIRC 48mhz
**/
 void FIRC_48MHZ_INIT(SOSC_SIRC_FIRC_SPLL_DIV_VAL val1,SOSC_SIRC_FIRC_SPLL_DIV_VAL val2)
{
    volatile uint32_t temp=0;
    SCG->FIRCDIV=temp;
    temp=(val1<<DIV1)|(val2<<DIV2);
    SCG->FIRCDIV|=temp;//divided by 1
    SCG->FIRCCFG=0;// FIRC 48 mHZ
    //SCG->FIRCCSR=0; 
    temp=SCG->FIRCCSR;
    while((temp&(1<<FIRC_LK))!=0)//wait until FIRCCSR is unlock
    {
        temp=SCG->FIRCCSR;
    }

    SCG->FIRCCSR|=(1<<FIRCEN);//enable FIRC
    temp=SCG->FIRCCSR;
    while((temp&(1<<FIRCVLD))==0)//wait until FIRC is valid
    {
        temp=SCG->FIRCCSR;
    }
}

/**
 * @brief set up SIRC with 8mhz
**/
void SIRC_8MHZ_INIT(GENERAL_CLOCK_MODE mod)
{
    volatile uint32_t temp=0;
    SCG->SIRCCSR=0;//unlock the sirc
    SCG->SIRCDIV=0;
    SCG->SIRCCFG=0;
    if(mod==HIGH_RUN||mod==NORMAL_RUN)// divided modules for peripherals clock depend on run mode
    {
        SCG->SIRCDIV|=(DIV_divided_by_1<<DIV1)|(DIV_divided_by_1<<DIV2);//divided by 1
    }
    else if(mod==VERY_LOW_POWER_RUN||mod==VERY_LOW_POWER_SLOW)
    {
        SCG->SIRCDIV|=(DIV_divided_by_2<<DIV1)|(DIV_divided_by_2<<DIV2);
    }
    SCG->SIRCCFG|=(1<<IRC_RANGE);//SIRC 8mhz, medium range from 4mhz-8mhz
    SCG->SIRCCSR=0;
    temp=SCG->SIRCCSR;
    while((temp&(1<<SIRC_LK))!=0)//wait until SIRCCSR is unlock
    {
        temp=SCG->SIRCCSR;
    }
    SCG->SIRCCSR|=(1<<SIRCEN);//enable SIRC
    temp=SCG->SIRCCSR;
    while((temp&(1<<SIRCVLD))==0)//wait until SIRC is valid
    {
        temp=SCG->SIRCCSR;
    }
}

/**
 * @brief set up SPLL depend on source, output SPLL_CLK, output peripheral clock
 * @param mutiplier 
 * @param predivide
 * @param source could be oscillator or fast internal clock
 * @param val1
 * @param val2 
 * 
 * @note example SPLL_INIT(Multiply_factor_40,Divide_factor_1,System_Oscillator,DIV_divided_by_2,DIV_divided_by_4);
 *       This means the clock source is oscilator, so the input frequency is 8mhz, then the output spll_clk
 *       is 8*40/1/2=160mhz, SPLLDIV1=80mhz,SPLLDIV2=40mhz
**/
void SPLL_INIT(SPLLCFG_VCO_MULTIPLY_FACTOR mutiplier,SPLLCFG_PREDIVIDE_FACTOR predivide,SPLLCFG_SOURCE source,SOSC_SIRC_FIRC_SPLL_DIV_VAL val1,SOSC_SIRC_FIRC_SPLL_DIV_VAL val2)
{
    volatile uint32_t temp;
    SCG->SPLLCSR=0;
    SCG->SPLLCFG=0;
    SCG->SPLLDIV=0;
    temp=SCG->SPLLCSR;
    while((temp&(1<<SPLL_LK))!=0)   //wait for SPLLCRS is unlock
    {
        temp=SCG->SPLLCSR;
    }
    SCG->SPLLCSR=0;//unlocj the SPLLCSr
    SCG->SPLLDIV=(val1<<DIV1)|(val2<<DIV2);
    temp=SCG->SPLLCFG;
    temp|=(predivide<<PREDIV)|(mutiplier<<MULT)|(source<<SOURCE);
    SCG->SPLLCFG=temp;
    temp=SCG->SPLLCSR;
    while((temp&(1<<SPLL_LK))!=0)//wait until the SPLLCSR is unlock
    {
         temp=SCG->SPLLCSR;
    }
    SCG->SPLLCSR|=(1<<SPLLEN);//enable the SPLLCSR
    temp=SCG->SPLLCSR;
    while((temp&(1<<SPLLVLD))==0)//wait until SPLL_CLK is valid 
    {
        temp=SCG->SPLLCSR;
    }
}

/**
 * @brief Init RCCR register, the final mux and divider controller for System Clock Generator
 * @param source chose source
 * @param divcore final divider before CORE_CLK
 * @param divbus  final divider before BUS_CLK
 * @param divslow final divider befro FLASH_CLK
 * @note example we want to use SPLL, we can write 
 *       RCCR_Normal_run_init(System_PPL,Divide_by_2,Divide_by_2,Divide_by_3);
**/
void rccr_normal_run_init(uint8_t source,uint8_t divcore,uint8_t divbus,uint8_t divslow)
{
	volatile uint32_t temp=0;
	temp=SCG->RCCR;
  temp &= ~((0xfu << DIVSLOW) | (0xfu << DIVBUS) | (0xfu << DIVCORE)| (0xfu << SCS));
  temp|=(source<<SCS)|(((divcore))<<DIVCORE)|(((divbus))<<DIVBUS)|(((divslow))<<DIVSLOW);
  SCG->RCCR=temp;
  temp=SCG->CSR;
  while(temp!=SCG->RCCR)
	{
    temp=SCG->CSR;
  }
	
}

/**
 * @brief Init HCCR register, the final mux and divider controller for System Clock Generator
 * @param source chose source
 * @param divcore final divider before CORE_CLK
 * @param divbus  final divider before BUS_CLK
 * @param divslow final divider befro FLASH_CLK
 * @note example we want to use FIRC, we can write 
 *       RCCR_Normal_run_init(FIRC,Divide_by_2,Divide_by_2,Divide_by_3);
**/
void HCCR_High_run_init(uint8_t source,uint8_t divcore,uint8_t divbus,uint8_t divslow)
{
	volatile uint32_t temp=0;
	temp=SCG->HCCR;
  temp &= ~((0xfu << DIVSLOW) | (0xfu << DIVBUS) | (0xfu << DIVCORE)| (0xfu << SCS));
  temp|=(source<<SCS)|(((divcore-1))<<DIVCORE)|(((divbus-1))<<DIVBUS)|(((divslow-1))<<DIVSLOW);
  SCG->HCCR=temp;
  temp=SCG->CSR;
  while(temp!=SCG->HCCR)
	{
    temp=SCG->CSR;
  }
}

/**
 * @brief Init VCCR register, the final mux and divider controller for System Clock Generator
 * @param source chose source
 * @param divcore final divider before CORE_CLK
 * @param divbus  final divider before BUS_CLK
 * @param divslow final divider befro FLASH_CLK
 * @note example we want to use SIRC, we can write 
 *       RCCR_Normal_run_init(SIRC,Divide_by_2,Divide_by_2,Divide_by_3);
**/
void VCCR_Very_low_power_run_init(uint8_t source,uint8_t divcore,uint8_t divbus,uint8_t divslow)
{
	volatile uint32_t temp=0;
	temp=SCG->VCCR;
  temp &= ~((0xfu << DIVSLOW) | (0xfu << DIVBUS) | (0xfu << DIVCORE)| (0xfu << SCS));
  temp|=(source<<SCS)|(((divcore-1))<<DIVCORE)|(((divbus-1))<<DIVBUS)|(((divslow-1))<<DIVSLOW);
  SCG->VCCR=temp;
  temp=SCG->CSR;
  while(temp!=SCG->VCCR)
	{
    temp=SCG->CSR;
  }
}

/**
 * @brief Option 1 : Slow RUN (typically using the undivided FIRC)1,
*         CORE_CLK: 48mhz,BUS_CLK 48mhz, FLASH_CLK: 24mhz
**/
 void Slow_Run_Fast_IRC()
{
    volatile uint32_t temp=0;
    temp=SCG->RCCR;
    temp&=~((0xf<<SCS)|(0xf<<DIVCORE)|(0xf&DIVBUS)|(0xf&DIVSLOW));
    temp|=(FIRC<<SCS)|(Divide_by_2<<DIVCORE)|(Divide_by_1<<DIVBUS)|(Divide_by_2<<DIVSLOW);
    SCG->RCCR=temp;//INIT for slow run
    temp=SCG->CSR;
    while(temp!=SCG->RCCR)//wait for system clock is FIRC
    {
        temp=SCG->CSR;
    }
}

/**
 * @brief Option 2 : Option 2: Normal RUN (with VCO_CLK = 320 MHz, SPLL_CLK = 160 MHz)
*         CORE_CLK: 80mhz,BUS_CLK 40mhz, FLASH_CLK: 26,77mhz
**/
 void Normal_run_system_pll_160()
{
    volatile uint32_t temp=0;
    sosc_8mhz_init(DIV_divided_by_1,DIV_divided_by_1);//init SOSC
    SPLL_INIT(Multiply_factor_40,Divide_factor_1,System_Oscillator,DIV_divided_by_2,DIV_divided_by_4);//init spll
    temp=SCG->RCCR;
    temp&=~((0xf<<SCS)|(0xf<<DIVCORE)|(0xf&DIVBUS)|(0xf&DIVSLOW));
    temp|=(System_PPL<<SCS)|(Divide_by_2<<DIVCORE)|(Divide_by_2<<DIVBUS)|(Divide_by_3<<DIVSLOW);//Get SPLL_CLK as clock, set up for CORE_CLK,BUS_CLOCk,FLASH_CLK 
    SCG->RCCR=temp;//init for normal run with SPLL_CLK=160MHZ
    temp=SCG->CSR;
    while(temp!=SCG->RCCR)//wait until system clock is pll
    {
        temp=SCG->CSR;
    }
}

/**
 * @brief Option 3: Normal RUN (with VCO_CLK = 256 MHz, SPLL_CLK = 128 MHz)
 *        CORE_CLK: 64mhz,BUS_CLK 32mhz, FLASH_CLK: 21.33mhz
**/
 void Normal_run_system_pll_128()
{
    volatile uint32_t temp=0;
    sosc_8mhz_init(DIV_divided_by_1,DIV_divided_by_1);//init SOSC
    SPLL_INIT(Multiply_factor_32,Divide_factor_1,System_Oscillator,DIV_divided_by_2,DIV_divided_by_4);//init spll
    temp=SCG->RCCR;
    temp&=0;
    temp|=(System_PPL<<SCS)|(Divide_by_2<<DIVCORE)|(Divide_by_2<<DIVBUS)|(Divide_by_3<<DIVSLOW);//Get SPLL_CLK as clock, set up for CORE_CLK,BUS_CLOCk,FLASH_CLK 
    SCG->RCCR=temp;//init for normal run with SPLL_CLK=128MHZ
    temp=SCG->CSR;
    while(temp!=SCG->RCCR)
    {
        temp=SCG->CSR;
    }
}

/**
 * @brief Option 4: High Speed RUN (with VCO_CLK = 224 MHz, SPLL_CLK = 112 MHz)
 *        CORE_CLK: 112mhz,BUS_CLK 56mhz, FLASH_CLK: 28mhz
**/
 void High_speed_run_pll_112()
{
    volatile uint32_t temp=0;
    sosc_8mhz_init(DIV_divided_by_1,DIV_divided_by_1);//init SOSC
    SPLL_INIT(Multiply_factor_28,Divide_factor_1,System_Oscillator,DIV_divided_by_2,DIV_divided_by_4);//init spll
    temp=SCG->HCCR;
    temp&=~((0xf<<SCS)|(0xf<<DIVCORE)|(0xf&DIVBUS)|(0xf&DIVSLOW));
    temp|=(System_PPL<<SCS)|(Divide_by_1<<DIVCORE)|(Divide_by_2<<DIVBUS)|(Divide_by_4<<DIVSLOW);//Get SPLL_CLK as clock, set up for CORE_CLK,BUS_CLOCk,FLASH_CLK 
    SCG->HCCR=temp;//set up for high speed mode
    temp=SCG->CSR;
    while(temp!=SCG->HCCR)
    {
        temp=SCG->CSR;
    }
}

/**
 * @brief Option 5: High Speed RUN 80 (with VCO_CLK = 320 MHz, SPLL_CLK = 160 MHz)
 *        CORE_CLK: 80mhz,BUS_CLK 80mhz, FLASH_CLK: 40mhz
**/
 void High_speed_run_pll_160()
{
    volatile uint32_t temp=0;
    sosc_8mhz_init(DIV_divided_by_1,DIV_divided_by_1);//
    SPLL_INIT(Multiply_factor_40,Divide_factor_1,System_Oscillator,DIV_divided_by_2,DIV_divided_by_4);
    temp=SCG->HCCR;
    temp&=~((0xf<<SCS)|(0xf<<DIVCORE)|(0xf&DIVBUS)|(0xf&DIVSLOW));
    temp|=(System_PPL<<SCS)|(Divide_by_2<<DIVCORE)|(Divide_by_1<<DIVBUS)|(Divide_by_2<<DIVSLOW);//Get SPLL_CLK as clock, set up for CORE_CLK,BUS_CLOCk,FLASH_CLK 
    SCG->HCCR=temp;
    temp=SCG->CSR;
    while(temp!=SCG->HCCR)
    {
        temp=SCG->CSR;
    }
}

/**
 * @brief Option 6: Very Low Power RUN, VLPR (with SIRC_CLK = 8 MHz)
 *        CORE_CLK: 4mhz,BUS_CLK 4mhz, FLASH_CLK: 1mhz
**/
 void Very_low_power_run()
{
    volatile uint32_t temp=0;
    SIRC_8MHZ_INIT(VERY_LOW_POWER_RUN);//init SIRC
    temp=SCG->VCCR;
    temp&=~((0xf<<SCS)|(0xf<<DIVCORE)|(0xf&DIVBUS)|(0xf&DIVSLOW));
    temp|=(SIRC<<SCS)|(Divide_by_2<<DIVCORE)|(Divide_by_1<<DIVBUS)|(Divide_by_4<<DIVSLOW);
    SCG->VCCR=temp;
    temp=SCG->CSR;
    while(((temp&((1<<SCS)|(1<<SCS_1)|(1<<SCS_2)|(1<<SCS_3)))>>SCS)!=SIRC)
    {
        temp=SCG->CSR;
    }
}

/**
 * @brief create a flexible clock source base on the desired CORE_CLK,BUS_CLOCK<,FLASH_CLOCK,
 *        and you can chose between oscilator or fast internal clock
 * @note  When you enter CORE_Frequency, the value must be from 1MHZ->160MHZ,
 *        and the unit is MHZ, Bus clock and flash must smaller than core clock.
 *        The advise is to chose a beautiful number like 80,40,20. If you chose
 *        wrong parameter , the chip will use the default clock. If some numbers
 *        are not suitable for the system, it can lead to Hardware Fault Exception
 *        
**/
void CLOCK_CONFIG_FREQUENCY_FOR_NORMAL_RUN(float CORE_SYS_CLOCK,float BUS_CLOCK,float FLASH_CLOCK,SPLLCFG_SOURCE Clock_source)
{
    int divcore=0;
    int bus=0;
    int divslow=0;
    if((CORE_SYS_CLOCK<=160)&&(CORE_SYS_CLOCK>=1)&&(BUS_CLOCK<=CORE_SYS_CLOCK)&&(FLASH_CLOCK<=CORE_SYS_CLOCK))
    {

    }
    else
    {
        return;
    }
    if(Clock_source==System_Oscillator)
    {
        volatile uint32_t temp=0;
        sosc_8mhz_init(DIV_divided_by_1,DIV_divided_by_1);
        if(CORE_SYS_CLOCK>40&&CORE_SYS_CLOCK<=160)
        {
            SPLL_INIT(Multiply_factor_40,Divide_factor_1,Clock_source,DIV_divided_by_2,DIV_divided_by_4);
            divcore=(int)(160/CORE_SYS_CLOCK);//calculate for CORE_CLK
            bus=(int)(160/(BUS_CLOCK*divcore));//calculate for BUS_CLK
            divslow=(int)(160/(FLASH_CLOCK*divcore));//calculate for FLASH_CLK
        }
        else if(CORE_SYS_CLOCK<=40&&CORE_SYS_CLOCK>=8)
        {
            SPLL_INIT(Multiply_factor_40,Divide_factor_4,Clock_source,DIV_divided_by_2,DIV_divided_by_4);
            divcore=(int)(40/CORE_SYS_CLOCK);
            bus=(int)(40/(BUS_CLOCK*divcore));
            divslow=(int)(40/(FLASH_CLOCK*divcore));
        }
        else if(CORE_SYS_CLOCK<8)
        {
            SPLL_INIT(Multiply_factor_16,Divide_factor_8,Clock_source,DIV_divided_by_2,DIV_divided_by_4);
            divcore=(int)(10/CORE_SYS_CLOCK);
            bus=(int)(10/(BUS_CLOCK*divcore));
            divslow=(int)(10/(FLASH_CLOCK*divcore));
        }
        else
        {
            return;
        }
        temp=SCG->RCCR;
        temp &= ~((0xfu << DIVSLOW) | (0xfu << DIVBUS) | (0xfu << DIVCORE)| (0xfu << SCS));
        temp|=(System_PPL<<SCS)|(((divcore-1))<<DIVCORE)|(((bus-1))<<DIVBUS)|(((divslow-1))<<DIVSLOW);
        SCG->RCCR=temp;
        temp=SCG->CSR;
        while(temp!=SCG->RCCR)
        {
            temp=SCG->CSR;
        }
    }
    else if(Clock_source==Fast_Internal_Reference_Clock)
    {
        volatile uint32_t temp=0;
        if(CORE_SYS_CLOCK>48&&CORE_SYS_CLOCK<=160)
        {
            SPLL_INIT(Multiply_factor_20,Divide_factor_3,Clock_source,DIV_divided_by_2,DIV_divided_by_4);
            divcore=(int)(160/CORE_SYS_CLOCK);
            bus=(int)(160/(BUS_CLOCK*divcore));
            divslow=(int)(160/(FLASH_CLOCK*divcore));
        }
        else if(CORE_SYS_CLOCK<=48)
        {
            SPLL_INIT(Multiply_factor_16,Divide_factor_8,Clock_source,DIV_divided_by_2,DIV_divided_by_4);
            divcore=(int)(48/CORE_SYS_CLOCK);
            bus=(int)(48/(BUS_CLOCK*divcore));
            divslow=(int)(48/(FLASH_CLOCK*divcore));
        }
        temp=SCG->RCCR;
        temp &= ~((0xfu << DIVSLOW) | (0xfu << DIVBUS) | (0xfu << DIVCORE)| (0xfu << SCS));
        temp|=(System_PPL<<SCS)|(((divcore-1)&0xf)<<DIVCORE)|(((bus-1)&0xf)<<DIVBUS)|(((divslow-1)&0xf)<<DIVSLOW);
        SCG->RCCR=temp;
        temp=SCG->CSR;
        while(temp!=SCG->RCCR)
        {
            temp=SCG->CSR;
        }
    }
    else
    {
        return;
    }
}


/**
 * @brief create a flexible clock source base on the desired CORE_CLK,BUS_CLOCK<,FLASH_CLOCK,
 *        and you can only use slow external clock
 * @note  When you enter CORE_Frequency, the value must be from 1MHZ->8MHZ,
 *        and the unit is MHZ, Bus clock and flash must smaller than core clock.
 *        The advise is to chose a beautiful number like 8,4,2. If you chose
 *        wrong parameter , the chip will use the default clock. If some numbers
 *        are not suitable for the system, it can lead to Hardware Fault Exception
**/
void CLOCK_SIRC_CONFIG_FREQUENCY_NORMAL_RUN(float CORE_SYS_CLOCK,float BUS_CLOCK,float FLASH_CLOCK)
{
    volatile uint32_t temp=0;
    if((CORE_SYS_CLOCK<=8)&&(CORE_SYS_CLOCK>=1)&&(BUS_CLOCK<=CORE_SYS_CLOCK)&&(FLASH_CLOCK<=CORE_SYS_CLOCK))
    {

    }
    else
    {
        return;
    }
    SIRC_8MHZ_INIT(NORMAL_RUN);
    int divcore=(int)(8/CORE_SYS_CLOCK);
    int bus=(int)(8/(BUS_CLOCK*divcore));
    int divslow=(int)(8/(FLASH_CLOCK*divcore));
    temp=SCG->RCCR;
    temp &= ~((0xfu << DIVSLOW) | (0xfu << DIVBUS) | (0xfu << DIVCORE)| (0xfu << SCS));
    temp|=(SIRC<<SCS)|(((divcore-1)*0xf)<<DIVCORE)|(((bus-1)&0xf)<<DIVBUS)|(((divslow-1)&0xf)<<DIVSLOW);
    SCG->RCCR=temp;
    temp=SCG->CSR;
    while(temp!=SCG->RCCR)
    {
        temp=SCG->CSR;
    }
}