/*	Author: tlafo001
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab # 2  Exercise # 4
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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
	unsigned char tempA;
	unsigned char tempB;
	unsigned char tempC;
	unsigned char tempD;
	unsigned short weightDiff;
	unsigned short totalWeight;
    while (1) {
	
	tempA = PINA;
	tempB = PINB;
	tempC = PINC;
	if (tempA > tempC)
	{
		weightDiff = tempA - tempC;
	}
	else if (tempC > tempA)
	{
		weightDiff = tempC - tempA;
	}
	else
	{
		weightDiff = 0;
	}

	totalWeight = tempA + tempB + tempC;

	tempD = totalWeight >> 4;
	tempD = tempD << 2;

	if (totalWeight > 140)
	{
		tempD = tempD | 0x01;
	}
	if (weightDiff > 80)
	{
		tempD = tempD | 0x02;
	}

	PORTD = tempD;
    }
    return 1;
}
