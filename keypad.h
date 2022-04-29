/*
 * keypad.h
 *
 * Created: 3/18/2022 10:50:24 AM
 *  Author: safifi
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_macros.h"
/* PC0 to PC3 input pull up */
#define KEYPAD_INIT_PORT()  DDRC = 0b11110000;  PORTC = 0b00001111;

#define K0()  READBIT(PINC,0)
#define K1()  READBIT(PINC,1)
#define K2()  READBIT(PINC,2)
#define K3()  READBIT(PINC,3)

#define K4(val) if(val == 0)  CLRBIT(PORTC,4); else  SETBIT(PORTC,4);
#define K5(val) if(val == 0)  CLRBIT(PORTC,5); else  SETBIT(PORTC,5);
#define K6(val) if(val == 0)  CLRBIT(PORTC,6); else  SETBIT(PORTC,6);
#define K7(val) if(val == 0)  CLRBIT(PORTC,7); else  SETBIT(PORTC,7);


void keypad_init(void);

int8_t keypad_scan(void);



#endif /* KEYPAD_H_ */