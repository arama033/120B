#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
enum States {Start, Init, PositiveRelease, NegRelease, Wait} state;
#endif

void Led_Tick() {

   switch(state)
  { 
  	 case Start:
  	 state = Init; 
	   break;
 
	case Init: 
	if ((PINA & 0x01) == 0x01)
      {
	state = PositiveRelease;
      }
	else
      {
	state = Init;
      }
	break;

	case PositiveRelease: 
	if  ((PINA & 0x01) == 0x01)
      {
	state = PositiveRelease;
      }
	else 
      {
	state = NegRelease;
      }
	break;
		
	case NegRelease:
	if  ((PINA & 0x01) == 0x01)
      {
	state = Wait;
      }
	else
      {
	state = NegRelease;
      }
	break;	
		
	case Wait:
	if ((PINA & 0x01) == 0x01)
      {
	state = Init;
      }
	else
      {
	state = Wait;
      }
	break;

	default: 
	state = Start;
	break;

	}

	switch(state)
	  { 
		case Start:
			PORTB = 0x01;
			break;
		case Init:
			PORTB = 0x01;
			break;
		case PositiveRelease:
			PORTB = 0x02;
			break;
		case NegRelease:
			PORTB = 0x02;
			break;
		case Wait:
			break;
		default:
			PORTB = 0x01;
			break; 
	}
}


int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF; 
	DDRB = 0xFF; PORTB = 0x00;
	
	state = Start;
	    
	while (1) { 
    Led_Tick();
    
    } 

	return 1;
}
