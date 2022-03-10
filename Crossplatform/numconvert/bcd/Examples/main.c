#define  F_CPU 16000000UL
#include <util/delay.h>

#include "AVR/Internal Peripherals/uart/uart.h"
#include "Crossplatform/numconvert/bcd/bcdcode.h"

int main(void)
{
	UART_Initialize(9600, true, true, false, false, false, UART_NUM_OF_DATA_BITS_8, UART_NUM_OF_STOP_BITS_1, UART_PARITY_BIT_NONE);
	
	unsigned char i = 0, bcd;
	
	while (1)
	{
		bcd = BCDCODE_UInt8_To_UInt8BCD(i);
		UART_StringFmt_Transmit("Counter: 0x%X (%d); BCD code: 0x%X; normal code: 0x%X\r\n", i, i, bcd, BCDCODE_UInt8BCD_To_UInt8(bcd));
		++i;
		
		_delay_ms(200);
	}
}