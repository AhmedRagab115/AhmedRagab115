/*
 * IncFile1.h
 *
 * Created: 3/31/2022 1:22:57 PM
 *  Author: Eng_Ahmed_L
 */ 


#ifndef LOCKER_H_
#define LOCKER_H_

#include "std_macros.h"
#include "eeprom.h"
#include "LCD.h"
#include "keypad.h"

#define LOCK_INIT_PORT()  DDRB |= 0b11;

#define Buzzer(val) if(val == 0)  CLRBIT(PORTB,0); else  SETBIT(PORTB,0);
#define Lock(val) if(val == 0)  CLRBIT(PORTB,1); else  SETBIT(PORTB,1);
#define LOCK_state()  READBIT(PINB,1)




void LOCK_pass_reset(void);
/*****************************************************************************
* Function Name: LOCK_reset
* Purpose      : reset password for initial value 0000 
* Parameters   : void
* Return value : void
*****************************************************************************/


void LOCK_pass_change(void);
/*****************************************************************************
* Function Name: LOCK_pass_change
* Purpose      : change password for entered value 
* Parameters   : void
* Return value : void
*****************************************************************************/


void LOCK_change(void);
/*****************************************************************************
* Function Name: LOCK_change
* Purpose      : open the lock 
* Parameters   : void
* Return value : void
*****************************************************************************/

#endif /* LOCKER_H_ */