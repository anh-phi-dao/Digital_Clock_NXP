/**
 * @file Timer_config.c
 * @author Dao Anh Phi 
 * @brief This file is used for controlling timer modules including
						+LPIT 
						+FLEX TIMER
**/

#include "Timer_config.h"
#include "PCC_address.h"

/**
 * @note In LPIT module ,we should follow this order
 * 			1.void LPIT_MODULE_ENABLE(uint8_t psc)
 * 			2.void LPIT_CONFIG(LPIT_TIMER_CHANNEL_NUMBER number,volatile uint32_t value,LPIT_TCTRLn_MODE mode,char TROT_Option,char TSOI_Option,char TSOT_Option,char Chain_Option)
 * 			3.void LPIT_ENABLE(LPIT_TIMER_CHANNEL_NUMBER number,char interrupt_option)
 * 		 When the timer runs, if we want the timer counts to another value, use LPIT_CHANGE_VALUE(LPIT_TIMER_CHANNEL_NUMBER number,uint32_t value);
 * 		 When we want to stop timer, use void LPIT_DISABLE(LPIT_TIMER_CHANNEL_NUMBER number,char interrupt_option)	
**/

/**
* @brief call this function first if yoy want to use LPIT
**/
void LPIT_MODULE_ENABLE(uint8_t psc)
{
	PCC->PCC_LPIT=(psc<<24);//enable peripheral clock// SPLLLDIV2
    PCC->PCC_LPIT|=(1<<30);//enable core clock
    LPIT->MCR|=(1<<0);//enable LPIT,allow LPIT rn in debug mode, reset timer value after reset
}
/**
* @brief Set up the counter value, set up mode
**/
void LPIT_CONFIG(LPIT_TIMER_CHANNEL_NUMBER number,volatile uint32_t value,LPIT_TCTRLn_MODE mode,char TROT_Option,char TSOI_Option,char TSOT_Option,char Chain_Option)
{   
    LPIT->TIMER_X[number].TVAL=value;
    LPIT->TIMER_X[number].TCTRL|=(1<<TRG_SRC)|(mode<<MODE)|(TROT_Option<<TROT)|(TSOI_Option<<TSOI)|(TSOT_Option<<TSOT)|(Chain_Option<<CHAIN);//internal source,enable timer
}

/**
* @brief update the periods value when LPIT is running
* @param number :LPIT_TIMER_CHANNEL_n
@ @param value : this will effect the time since counter begin to decrease untill a trigger happens
**/
void LPIT_CHANGE_VALUE(LPIT_TIMER_CHANNEL_NUMBER number,uint32_t value)
{
	LPIT->TIMER_X[number].TCTRL&=~(1<<T_EN);
	LPIT->TIMER_X[number].TVAL=value;
	LPIT->TIMER_X[number].TCTRL|=(1<<T_EN);
}
/**
* @brief enable the LPIT with corresponding channel
* @param number :LPIT_TIMER_CHANNEL_n
@ @param interrupt_option : INTERRUPT/NO_INTERRUPT
**/
void LPIT_ENABLE(LPIT_TIMER_CHANNEL_NUMBER number,char interrupt_option)
{
		if(interrupt_option!=0)
    {
        LPIT->MIER|=(1<<number);
    }
    else
    {

    }
    LPIT->SETTEN|=(1<<number);
		LPIT->TIMER_X[number].TCTRL|=(1<<T_EN);
}
/**
* @brief disable the LPIT with corresponding channel
* @param number :LPIT_TIMER_CHANNEL_n
@ @param interrupt_option : INTERRUPT/NO_INTERRUPT
**/
void LPIT_DISABLE(LPIT_TIMER_CHANNEL_NUMBER number,char interrupt_option)
{
		if(interrupt_option==0)
		{
			LPIT->MIER&=~(1<<number);
		}
		else
		{
			
		}
		LPIT->TIMER_X[number].TCTRL&=~(1<<T_EN);
    LPIT->CLRTEN|=(1<<number);
}

void LPIT_DISABLE_MODULE()
{
    LPIT->MCR=0;
}

/**
* @brief Read the current value of COUNTER while it is decreasing
* @param number :LPIT_TIMER_CHANNEL_n
@ @retval return the value of TIMER_X[number].CVAL
**/
uint32_t LPIT_READ_CURRENT_VALUE(LPIT_TIMER_CHANNEL_NUMBER number)
{
    volatile uint32_t temp;
    temp=LPIT->TIMER_X[number].CVAL;
    return temp;
}

void FLEXTIMER_EDGE_ALLIGNED_PWM_SET_UP(Flex_Timer* flex,int number_of_channel)
{
	/* Enable registers updating from write buffers */
	flex->MODE=(1<<0);
	flex->CNTIN=0;
	flex->control[number_of_channel].CnSC=(1<<5)|(1<<2);
}

void FLEXTIMER_EDGE_ALLIGNED_PWM_SET_DUTY_CYCLE(Flex_Timer* flex,int number_of_channel,int period,int end_cycle)
{
	flex->control[number_of_channel].CnV=period;
	flex->MOD=end_cycle;
	flex->CNT=0;
}

void FLEXTIMER_EDGE_ALLIGNED_PWM_INIT(Flex_Timer* flex,int number_of_channel)
{
	flex->SC=(1<<3)|(1<<(number_of_channel+16));
}

