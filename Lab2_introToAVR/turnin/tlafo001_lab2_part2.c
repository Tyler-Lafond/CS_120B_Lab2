/*	Author: tlafo001
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab # 2  Exercise # 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char tempA;
	unsigned char cntavail;
    while (1) {
	cntavail = 4;
	tempA = PINA & 0x0F;
	while (tempA != 0x00)
	{
		if((tempA & 0x01) == 0x01)
		{
			cntavail--;
		}
		tempA = tempA >> 1;
	}
	PORTC = cntavail;
    }
    return 1;
}
