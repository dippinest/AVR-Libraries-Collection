
#ifndef ANACOMP_H_
#define ANACOMP_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "anacomp_callback_configuration.h"

// input AIN0 is connected to an internal 1.22 volt source
#define ANACOMP_DIRECT_INPUT_IS_CONNECTED_TO_INTERNAL_VOLTAGE_SOURCE  true

// input AIN0 is not connected anywhere
#define ANACOMP_DIRECT_INPUT_IS_NOT_CONNECTED                         false

#define ANACOMP_INTERRUPT_TYPE_ANY_CHANGE              0b00
#define ANACOMP_INTERRUPT_TYPE_TRANSITION_FROM_1_TO_0  0b10
#define ANACOMP_INTERRUPT_TYPE_TRANSITION_FROM_0_TO_1  0b11

#define ANACOMP_STATE_IS_HIGH  true
#define ANACOMP_STATE_IS_LOW   false

// ===============================================================================

inline void ANACOMP_Set_Enable(bool is_enable)
{
	if (is_enable)
	{
		ACSR &= ~(1 << ACD);
	}
	else
	{
		ACSR |=  (1 << ACD);
	}
}

inline void ANACOMP_Direct_Input_Set_Connect(bool direct_input_is_connect)
{
	if (direct_input_is_connect)
	{
		ACSR |=  (1 << ACBG);
	}
	else
	{
		ACSR &= ~(1 << ACBG);
	}
}

inline void ANACOMP_Set_Interrupt_Enable(bool is_enable)
{
	if (is_enable)
	{
		ACSR |=  (1 << ACIE);
	}
	else
	{
		ACSR &= ~(1 << ACIE);
	}
}

inline void ANACOMP_Set_Connect_To_Timer1_Capture(bool is_connect)
{
	if (is_connect)
	{
		ACSR |=  (1 << ACIC);
	}
	else
	{
		ACSR &= ~(1 << ACIC);
	}
}

inline void ANACOMP_Set_Interrupt_Type(uint8_t interrupt_type)
{
	switch (interrupt_type)
	{
		case ANACOMP_INTERRUPT_TYPE_TRANSITION_FROM_1_TO_0:
		ACSR |=  (1 << ACIS1);
		ACSR &= ~(1 << ACIS0);
		break;
		
		case ANACOMP_INTERRUPT_TYPE_TRANSITION_FROM_0_TO_1:
		ACSR |=  (1 << ACIS1);
		ACSR |=  (1 << ACIS0);
		break;
		
		case ANACOMP_INTERRUPT_TYPE_ANY_CHANGE:
		default:
		ACSR &= ~(1 << ACIS1);
		ACSR &= ~(1 << ACIS0);
	}
}

// ===============================================================================

inline bool ANACOMP_Is_Enable()
{
	if (!(ACSR & (1 << ACD)))
	{
		return true;
	}
	
	return false;
}

inline bool ANACOMP_Direct_Input_Is_Connect()
{
	if (ACSR & (1 << ACBG))
	{
		return true;
	}
	
	return false;
}

inline bool ANACOMP_Interrupt_Is_Enable()
{
	if (ACSR & (1 << ACIE))
	{
		return true;
	}
	
	return false;
}

inline bool ANACOMP_To_Timer1_Capture_Is_Connect()
{
	if (ACSR & (1 << ACIC))
	{
		return true;
	}
	
	return false;
}

inline uint8_t ANACOMP_Get_Interrupt_Type()
{
	uint8_t interrupt_type = 0;
	
	interrupt_type |= (ACSR & (1 << ACIS1));
	interrupt_type |= (ACSR & (1 << ACIS0));
	
	if (interrupt_type == 0b01)
	{
		interrupt_type = ANACOMP_INTERRUPT_TYPE_ANY_CHANGE;
	}
	
	return interrupt_type;
}

// ===============================================================================

inline bool ANACOMP_Get_State()
{
	if (ACSR & (1 << ACO))
	{
		return ANACOMP_STATE_IS_HIGH;
	}
	
	return ANACOMP_STATE_IS_LOW;
}

// ===============================================================================

#ifdef ANACOMP_USE_CALLBACK

void ANACOMP_Set_CallBack_Function(void (*callback_function)());

void *ANACOMP_Get_CallBack_Function();

#endif

#endif
