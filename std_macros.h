



#ifndef STD_MACROS_H_
#define STD_MACROS_H_



#include <avr/io.h>			// include all registers for avr micro
#define F_CPU 16000000UL	// set freq for micro 
#include <util/delay.h>		// include delay header file 
#include <avr/interrupt.h>	// include all interrupts registers 

#define SETBIT(REG,BIT) (REG |= 1<<BIT)
#define TOGBIT(REG,BIT) (REG ^= (1<<BIT))
#define CLRBIT(REG,BIT) (REG &=~(1<<BIT))
#define READBIT(REG,BIT) ((REG>>BIT)&1)

#endif
