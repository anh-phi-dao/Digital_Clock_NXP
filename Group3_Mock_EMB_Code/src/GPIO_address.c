/**
 * **
  ******************************************************************************
  * @file    GPIO_address.c
  * @author  Dao Anh Phi
  * @brief   GPIO_addres config
  *          This file provides firmware functions to manage the following
  *          functionalities of GPIO .
  *           + INIT GPIO
  *           + Toggle logic in port
  *           + Set/clear bit for port
  
**/

#include "GPIO_address.h"
#include "PCC_address.h"
#include "PORT_address.h"

/**
 * @brief To init the specific port into general purpose
 *        input output 
 * @param g : GPIO module (ex: GPIOA)
 * @param PT : PORT number
 * @param dir :input/output
 * @param mode we can choose normal mode or interrupt pr interrupt with
 *             dma
 * @note ex: I want PORTC13 is external interrupt with rising edge detection
 *       we write GPIO_INIT(GPIOC,PORT13,INPUT,ISF_INTERRUPT_RISING_EDGE)
**/
void gpio_init(GPIO *g,GPIO_PORT PT,GPIO_DIRECTION dir,GPIO_MODE mode)
{
    Port* p;
    if(g==GPIOA)
    {
        p=PORTA;
        PCC->PCC_PORTA|=(1<<30);//enable the clock source for porta
    }
    else if(g==GPIOB)
    {
        p=PORTB;
        PCC->PCC_PORTB|=(1<<30);//enable the clock source for portb
    }
    else if(g==GPIOC)
    {
        p=PORTC;
        PCC->PCC_PORTC|=(1<<30);//enable the clock source for portc
    }
    else if(g==GPIOD)
    {
        p=PORTD;
        PCC->PCC_PORTD|=(1<<30);//enable the clock source for portd
    }
    else if (g==GPIOE)
    {
        p=PORTE;
        PCC->PCC_PORTE|=(1<<30);//enable the clock source for porte
    }
    else
    {
        return;
    }
    p->PCR[PT]|=(1<<8)|(mode<<16);//config the corresponding port to gpio and desired mode
    if(dir==INPUT)//config the input or output
    {
        g->PDDR&=~(1<<PT);
    }
    else if(dir==OUTPUT)
    {
        g->PDDR|=(1<<PT);
    }
}

/**
 * @brief Toggle the output pin
 * @param g : GPIO module (ex: GPIOA)
 * @param PT : PORT number
 * @note ex: PINA12 is 0, we want the PIN to become 1
 *       and reverse in sequence, we
 *       write TOGGLE_OUTPUT_PORT(GPIOA,PORT12);
**/
void TOGGLE_OUTPUT_PORT(GPIO* gpio, GPIO_PORT PT)
{
    gpio->PTOR|=(1<<PT);
}

/**
 * @brief Toggle the output pin
 * @param g : GPIO module (ex: GPIOA)
 * @param PT : PORT number
 * @note ex: We want PTD15 always stay at logic 1
 *       write SET_OUTPUT_PORT(GPIOA,PORT15)
**/
void SET_OUTPUT_PORT(GPIO* gpio,GPIO_PORT PT)
{
    gpio->PSOR|=(1<<PT);
}

/**
 * @brief Toggle the output pin
 * @param g : GPIO module (ex: GPIOA)
 * @param PT : PORT number
 * @note ex: We want PTD15 always stay at logic 0
 *       write CLEAR_OUTPUT_PORT(GPIOA,PORT15)
**/
void CLEAR_OUTPUT_PORT(GPIO* gpio,GPIO_PORT PT)
{
    gpio->PCOR|=(1<<PT);
}

/**
 * @brief check the input pin
 * @param g : GPIO module (ex: GPIOA)
 * @param PT : PORT number
 * @retval 0 or 1 depends on the logic that the pin reads;
 * @note ex: PTC13 is connected to a button, in oder to
 *       check the logic of the button we write 
 *       CHECK_INPUT_PORT(GPIOC,PORT13)
**/
char CHECK_INPUT_PORT(GPIO* gpio, GPIO_PORT PT)
{
    if(((gpio->PDIR)&(1<<PT))!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}