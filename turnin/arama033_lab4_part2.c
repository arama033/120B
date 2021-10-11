#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
enum States {start, init, increment, decrement, refresh, wait} state;
#endif

void tick() {	
   switch(state){
	case start: 
	state = init;
	break;

	case init: 
	if ((PINA & 0x01) && !(PINA & 0x02))
      {
	state = increment;
      }
	else if ((PINA & 0x02) && !(PINA & 0x01))
      {
	state = decrement;
      }
	else if ((PINA & 0x01) && (PINA & 0x02))
      {
	state = refresh;
      }
	else
      {
	state = wait;
      }
	break;

	case increment: 
	state = wait;
	break;


	case decrement: 
	state = wait;
	break;

	case wait:
	if ((PINA & 0x01) && (PINA & 0x02))
      {
	state = refresh;
      }
	else if (!(PINA & 0x01) && !(PINA & 0x02))
      {
	state = init;
      }
	else
	state = wait;
	break;


	case refresh: 
	if ((PINA & 0x01) && (PINA & 0x02))
      {
	state = refresh;
      }
	else
	state = wait;
	break;

	
	default: 
	state = start;
	break;

	}


	switch(state){  
	case start: 
	PORTC = 0x07;
	break;
		
	case init:
	PORTC = 0x07;
	break;		
	
	case increment: 
	if (PORTC < 0x09)
      {
	PORTC++;
      }
	else 
	PORTC = 0x09;
	break;
		
	case decrement: 
	if (PORTC > 0x00)
      {
	PORTC--;
      }
	else
	PORTC = 0x00;
	break;
		
	case wait:
	break;
	
	case refresh:
	PORTC = 0x00;
	break;
	
	default:
	PORTC = 0x07;
	break; 
	}
}


int main(void) {

	DDRA = 0x00; PORTA = 0xFF; 
	DDRC = 0xFF; PORTC = 0x00;
	state = start;
	    
	while (1) {
     tick();} 

	return 1;
}
