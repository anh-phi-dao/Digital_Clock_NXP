/**
 * **
  ******************************************************************************
  * @file    Cortex_M4.c
  * @author  Dao Anh Phi
  * @brief   Cortex_M4 config
  *          This file provides firmware functions to manage the following
  *          functionalities that is common in ARM Cortex M4.
  *           + System Tick Timer
  *           + Nested Vector Interrupt Controllers
  *           + Call back function for NVIC
  *           +  
  
**/


#include <stdio.h>
#include "Cortex_M4.h"
#include "PORT_address.h"
#include "GPIO_address.h"
#include "Timer_config.h"


/**
 * @brief init the ARM CORTEX M4 System tick timer
 * @param interrupt_option if interrupt_option=1,
 *                         enable interrupt
**/
void sys_tick_init(uint8_t interrupt_option)
{
    SYST->RVR=0xffffff;//
    SYST->CVR=0;//clear flag
    if(interrupt_option==0)
    {
        SYST->CSR=5;//enable systick,use internal clcok
    }
    else
    {
        SYST->CSR=7;// enable systick,use internal clock, enable interrupt
    }
}

/**
 * @brief disable the ARM CORTEX M4 System tick timer
 * 
**/
void Sys_tick_dis()
{
    SYST->CSR=0;//disable systick
}

/**
 * @brief load the value that we want to load to systick
 * @param value systick will count from (value-1)->0
 * 
**/
void sys_tick_load_value(uint32_t value)
{
    SYST->RVR=(value-1)&0xffffff;
    SYST->CVR=0;
}

void DELAY_SYSTEM_TICK_NO_INTERRUPT(uint32_t time)
{
    sys_tick_load_value(time);
    while((SYST->CSR&(1<<COUNTFLAG))==0)
    {

    }
}

/**
 * @brief init the nested vector interrupt controller
 *        to use interrupts
 * @param vector contain NVIC ID, NVIC non-IPR register number
 *               ,NVIC IPR register number
 * @param priority to determine the priority of the interrupt vector
 * @note ex want to use PTC13 external interrupt, first we have to init
 *       the NVIC, we write NVIC_init(PORTC_NVIC,1); 
 *       priority is optinal
**/
void nvic_init(NVIC_VECTOR vector,uint8_t priority)
{
    NVIC->ICPR[vector.NONE_IPR_NUMBER]|=1<<(vector.NVIC_ID%32);
    NVIC->IPR[vector.IPR_NUMER]|=priority<<(8*(vector.NVIC_ID%4)+4);
    NVIC->ISER[vector.NONE_IPR_NUMBER]|=1<<(vector.NVIC_ID%32);
}

/**
 * @brief use the same as NVIC_init(NVIC_VECTOR vector); but this time
 *        disable the interrupt that we want
 * @param vector contain NVIC ID, NVIC non-IPR register number
 *               ,NVIC IPR register number
**/
void NVIC_DISABLE(NVIC_VECTOR vector)
{
    NVIC->ICPR[vector.NONE_IPR_NUMBER]|=1<<(vector.NVIC_ID%32);
    NVIC->ICER[vector.NONE_IPR_NUMBER]|=1<<(vector.NVIC_ID%32);
    NVIC->IPR[vector.IPR_NUMER]&=~(0xff<<(8*(vector.NVIC_ID%4)+4));
}

/**
 * @brief put this in PORTA_IRQHandle()
 *        pass in a desired function
 * @param interrupt function pointer that point to a function
 *        we want
 * @note ex, we want handler() can be processed when interrupt at PORTA occur
 *       inside PORTA_IRQHandle(), we write PTA_INTERRUPT(handler);remember handler
 *       must be a void function and doesn't contain parameter    
**/
void PTA_INTERRUPT(void (*interrupt)())
{
    PORTA->ISFR|=0xFFFFFFFFUL;
    interrupt();
}

/**
 * @brief put this in PORTB_IRQHandle()
 *        pass in a desired function
 * @param interrupt function pointer that point to a function
 *        we want
 * @note ex, we want handler() can be processed when interrupt at PORTA occur
 *       inside PORTB_IRQHandle(), we write PTB_INTERRUPT(handler);remember handler
 *       must be a void function and doesn't contain parameter    
**/
void PTB_INTERRUPT(void (*interrupt)())
{
    PORTB->ISFR|=0xFFFFFFFFUL;
    interrupt();
}

/**
 * @brief put this in PORTC_IRQHandle()
 *        pass in a desired function
 * @param interrupt function pointer that point to a function
 *        we want
 * @note ex, we want handler() can be processed when interrupt at PORTC occur
 *       inside PORTC_IRQHandle(), we write PTC_INTERRUPT(handler);remember handler
 *       must be a void function and doesn't contain parameter    
**/
void PTC_INTERRUPT(void (*interrupt)())
{
    PORTC->ISFR|=0xFFFFFFFFUL;
    interrupt();
}
/**
 * @brief put this in PORTD_IRQHandle()
 *        pass in a desired function
 * @param interrupt function pointer that point to a function
 *        we want
 * @note ex, we want handler() can be processed when interrupt at PORTC occur
 *       inside PORTC_IRQHandle(), we write PTC_INTERRUPT(handler);remember handler
 *       must be a void function and doesn't contain parameter    
**/
void PTD_INTERRUPT(void (*interrupt)())
{
    PORTD->ISFR|=0xFFFFFFFFUL;
    interrupt();
}
/**
 * @brief put this in PORTD_IRQHandle()
 *        pass in a desired function
 * @param interrupt function pointer that point to a function
 *        we want
 * @note ex, we want handler() can be processed when interrupt at PORTC occur
 *       inside PORTC_IRQHandle(), we write PTC_INTERRUPT(handler);remember handler
 *       must be a void function and doesn't contain parameter    
**/
void PTE_INTERRUPT(void (*interrupt)())
{
    PORTE->ISFR|=0xFFFFFFFFUL;
    interrupt();
}

/**
 * @brief put this in PORTA_IRQHandle()
 *        pass in a desired function, and port number
 * @param interrupt function pointer that point to a function
 *        we want
 * @param port the number of port that proceed the interrupt
 * @note ex, we hace PTA13 as external interrupt, and we want
 *       blink() function is proceeded in the interrupt
 *       we write PTA_PORT_INTERRUPT(blink,13) or we use
 *       enum for "GPIO_address.h" library and write
 *       PTA_PORT_INTERRUPT(blink,PORT13);
**/
void PTA_PORT_INTERRUPT(void (*interrupt)(),int port)
{
    if((PORTA->PCR[port]&(1<<24))!=0)
    {
        PORTA->PCR[port]|=(1<<24);
        interrupt();
    }
    else
    {

    }
}

/**
 * @brief put this in PORTB_IRQHandle()
 *        pass in a desired function, and port number
 * @param interrupt function pointer that point to a function
 *        we want
 * @param port the number of port that proceed the interrupt
 * @note ex, we hace PTB16 as external interrupt, and we want
 *       blink() function is proceeded in the interrupt
 *       we write PTA_PORT_INTERRUPT(blink,16) or we use
 *       enum for "GPIO_address.h" library and write
 *       PTA_PORT_INTERRUPT(blink,PORT16);
**/
void PTB_PORT_INTERRUPT(void (*interrupt)(),int port)
{
    if((PORTB->PCR[port]&(1<<24))!=0)
    {
        PORTB->PCR[port]|=(1<<24);
        interrupt();
    }
    else
    {
        
    }
}

/**
 * @brief put this in PORTC_IRQHandle()
 *        pass in a desired function, and port number
 * @param interrupt function pointer that point to a function
 *        we want
 * @param port the number of port that proceed the interrupt
 * @note ex, we hace PTC16 as external interrupt, and we want
 *       blink() function is proceeded in the interrupt
 *       we write PTC_PORT_INTERRUPT(blink,16) or we use
 *       enum for "GPIO_address.h" library and write
 *       PTC_PORT_INTERRUPT(blink,PORT16);
**/
void PTC_PORT_INTERRUPT(void (*interrupt)(),int port)
{
    if((PORTC->PCR[port]&(1<<24))!=0)
    {
        PORTC->PCR[port]|=(1<<24);
        interrupt();
    }
    else
    {
        
    }
}

/**
 * @brief put this in PORTD_IRQHandle()
 *        pass in a desired function, and port number
 * @param interrupt function pointer that point to a function
 *        we want
 * @param port the number of port that proceed the interrupt
 * @note ex, we hace PTD16 as external interrupt, and we want
 *       blink() function is proceeded in the interrupt
 *       we write PTD_PORT_INTERRUPT(blink,16) or we use
 *       enum for "GPIO_address.h" library and write
 *       PTD_PORT_INTERRUPT(blink,PORT16);
**/
void PTD_PORT_INTERRUPT(void (*interrupt)(),int port)
{
    if((PORTD->PCR[port]&(1<<24))!=0)
    {
        PORTD->PCR[port]|=(1<<24);
        interrupt();
    }
    else
    {
        
    }
}

/**
 * @brief put this in PORTE_IRQHandle()
 *        pass in a desired function, and port number
 * @param interrupt function pointer that point to a function
 *        we want
 * @param port the number of port that proceed the interrupt
 * @note ex, we hace PTE16 as external interrupt, and we want
 *       blink() function is proceeded in the interrupt
 *       we write PTE_PORT_INTERRUPT(blink,16) or we use
 *       enum for "GPIO_address.h" library and write
 *       PTE_PORT_INTERRUPT(blink,PORT16);
**/
void PTE_PORT_INTERRUPT(void (*interrupt)(),int port)
{
    if((PORTE->PCR[port]&(1<<24))!=0)
    {
        PORTE->PCR[port]|=(1<<24);
        interrupt();
    }
    else
    {
        
    }
}

/**
 * @brief put this in LPIT_Ch0_IRQHandle()
 *        pass in a desired function
 * @param interrupt function pointer that point to a function
 *        we want to handle in interrupt
 */
void LPIT_CHANNEL_0_INTERRUPT(void (*interrupt)())
{
    if((LPIT->MSR&(1<<0))!=0)
    {
        LPIT->MSR|=1ul<<0;
        interrupt();
    }
}

/**
 * @brief put this in LPIT_Ch1_IRQHandle()
 *        pass in a desired function
 * @param interrupt function pointer that point to a function
 *        we want to handle in interrupt
 */
void LPIT_CHANNEL_1_INTERRUPT(void (*interrupt)())
{
    if((LPIT->MSR&(1<<1))!=0)
    {
        LPIT->MSR|=1ul<<1;
        interrupt();
    }
}


/**
 * @brief put this in LPIT_Ch2_IRQHandle()
 *        pass in a desired function
 * @param interrupt function pointer that point to a function
 *        we want to handle in interrupt
 */
void LPIT_CHANNEL_2_INTERRUPT(void (*interrupt)())
{
    if((LPIT->MSR&(1<<2))!=0)
    {
        LPIT->MSR|=1ul<<2;
        interrupt();
    }
}

/**
 * @brief put this in LPIT_Ch3_IRQHandle()
 *        pass in a desired function
 * @param interrupt function pointer that point to a function
 *        we want to handle in interrupt
 */
void LPIT_CHANNEL_3_INTERRUPT(void (*interrupt)())
{
    if((LPIT->MSR&(1ul<<3))!=0)
    {
        LPIT->MSR|=1ul<<3;
        interrupt();
    }
}


