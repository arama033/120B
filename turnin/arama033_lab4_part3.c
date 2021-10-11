#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, Init, Hash, why, Unlocked, Locked, Invalid} state;

void Tick() {
	switch(state) {
	case Start:
	state = Init;
	break;

	case Init:
	if ((PINA & 0x07) == 0x04) 
        {//if pa2/# pressed
	state = Hash;
	}
	else if ((PINA & 0x87) == 0x80) 
       {//if pa7 pressed lock
	state = Locked;
	}
	else 
       {
	state = Init;
	}
	break;

	case Hash:
	if ((PINA & 0x07) == 0x04) 
      {//remain in hash till further inp
       state = Hash;
      }
       else 
       {//move to y, check if y is pressed on arrival
        state = why;
        }
       break;

	case why:
	if ((PINA & 0x07) == 0x02) 
      {//if y/pa1 pressed
        state = Unlocked;
      }
	else if (PINA == 0x00) 
      {//nothing pressed yet, remain
	state = why;
	}
      else if(((PINA & 0x07) == 0x02) && ((PINA & 0x07) == 0x04))
      {//if both hash and y pressed same time? not sure based on gradescope test
      state = invalid;
      }
     else 
     {
     state = Init;
     }
    break;

     case Unlocked:
     if ((PINA & 0x07) == 0x02) 
      {//since y was pressed remain unlocked till notice, coming from hash
     state = Unlocked;
      }
    else 
       {
      state = Init;
       }
        break;

	case Locked:
	if ((PINA & 0x87) == 0x80) 
      {//ifpa7 1 locked
         state = Locked;
     }
          else 
          {
          state = Init;
         }
         break;
	}

 	 case Invalid:
 	 {
	  break;
	  }


	switch(state) {
		case Start:
		PORTB = 0x00;
		break;
		case Init:
	       PORTB = 0x00;
		break;
		case Hash:
		break;
		case why:
		break;
		case Unlocked:
		PORTB = 0x01;
		break;
		case Locked:
		PORTB = 0x00;
		break;

	}
}



int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    while (1) {
	Tick();
    }
    return 1;
}
