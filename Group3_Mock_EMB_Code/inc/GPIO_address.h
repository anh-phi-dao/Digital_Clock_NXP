/**
  * @file    GPIO_address.h
  * @author  Dao Anh Phi
  * @brief   GPIO config
  *          This file provides firmware functions to manage the register, define 
  *          register address,mask for GPIO registers.
**/
#ifndef HOMEWORK_GPIO_ADDRESS_H
#define HOMEWORK_GPIO_ADDRESS_H
#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

/**
 * @brief use for GPIO_INIT()
**/
typedef enum  GPIO_MODE
{
	No_interrupt,
	ISF_DMA_RISING_EDGE,
	ISF_DMA_FALLING_EDGE,
	ISF_DMA_BOTH_EDGE,
	MODE_Reserved,
	MODE_Reserved1,
	MODE_Reserved2,
	MODE_Reserved3,
	ISF_INTERRUPT_LOGIC_0,
	ISF_INTERRUPT_RISING_EDGE,
	ISF_INTERRUPT_FALLING_EDGE,
	ISF_INTERRUPT_BOTH_EDGE,
	ISF_INTERRUPT_LOGIC_1,
	MODE_Reserved4,
	MODE_Reserved5,
	MODE_Reserved6,
}GPIO_MODE;

/**
 * @brief use for GPIO_INIT()
**/
typedef enum 
{
	INPUT,
	OUTPUT,
}GPIO_DIRECTION;

/**
 * @brief use for GPIO_INIT()
**/
typedef enum
{
	PORT0,
	PORT1,
	PORT2,
	PORT3,
	PORT4,
	PORT5,
	PORT6,
	PORT7,
	PORT8,
	PORT9,
	PORT10,
	PORT11,
	PORT12,
	PORT13,
	PORT14,
	PORT15,
	PORT16,
	PORT17,
	PORT18,
	PORT19,
	PORT20,
	PORT21,
	PORT22,
	PORT23,
	PORT24,
	PORT25,
	PORT26,
	PORT27,
	PORT28,
	PORT29,
	PORT30,
	PORT31,
}GPIO_PORT;

/**
 * @brief GPIOx register
**/
typedef struct 
{
	volatile uint32_t PDOR;
	volatile uint32_t PSOR;
	volatile uint32_t PCOR;
	volatile uint32_t PTOR;
	volatile uint32_t PDIR;
	volatile uint32_t PDDR;
	volatile uint32_t PIDR;
	
}GPIO;

#define GPIOA ((GPIO*)0x400FF000UL)
#define GPIOB ((GPIO*)0x0400FF040UL)
#define GPIOC ((GPIO*)0x0400FF080UL)
#define GPIOD ((GPIO*)0x0400FF0C0UL)
#define GPIOE ((GPIO*)0x0400FF100UL)

void gpio_init(GPIO *g,GPIO_PORT PT,GPIO_DIRECTION dir,GPIO_MODE mode);
void TOGGLE_OUTPUT_PORT(GPIO* gpio, GPIO_PORT PT);
void SET_OUTPUT_PORT(GPIO* gpio,GPIO_PORT PT);
void CLEAR_OUTPUT_PORT(GPIO* gpio,GPIO_PORT PT);
char CHECK_INPUT_PORT(GPIO* gpio, GPIO_PORT PT);



#ifdef __cplusplus
}
#endif
#endif 

