/*
 * LCD.h
 *
 * Created: 3/12/2022 1:17:29 PM
 *  Author: safifi
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "std_macros.h"


#define LCD_INIT_PORT()  DDRA |= 0b11111100; 									// init lcd port 

#define D7(val) if(val == 0)  CLRBIT(PORTA,7); else  SETBIT(PORTA,7);			//   cmd & data writing to pins
#define D6(val) if(val == 0)  CLRBIT(PORTA,6); else  SETBIT(PORTA,6);
#define D5(val) if(val == 0)  CLRBIT(PORTA,5); else  SETBIT(PORTA,5);
#define D4(val) if(val == 0)  CLRBIT(PORTA,4); else  SETBIT(PORTA,4);
#define RS(val) if(val == 0)  CLRBIT(PORTA,3); else  SETBIT(PORTA,3);
#define EN(val) if(val == 0)  CLRBIT(PORTA,2); else  SETBIT(PORTA,2);

#define _cursor_off      		0x0c;								// cursor off cmd
#define _cursor_on        		0x0e;								// cursor on cmd 
#define _cursor_blk        		0x0f;								// cursor blinking cmd	
#define _cursor_shift_r 		0x14;								// cursor shift right					
#define _cursor_shift_l 		0x10;								// cursor shoft left
	
#define _shift_r 				0x1c;								// display shift right				
#define _shift_l 				0x18;								// display shift left

/*****************************************************************************
* Function Name: LCD_init
* Purpose      : initialize LCD to work in 4-bit mode - clear lcd - cursor off
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_init(void);

/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : Send a specific command (cmd) to lcd (valid only with 4-bit mode)
* Parameters   : cmd  (command to be done by lcd)
* Return value : void
*****************************************************************************/
void LCD_write_command(uint8_t cmd);

/*****************************************************************************
* Function Name: LCD_write_char
* Purpose      : Write a specific Ascii char (data) to lcd (valid only with 4-bit mode)
* Parameters   : data  (data to be written on lcd)
* Return value : void
*****************************************************************************/
void LCD_write_char(uint8_t data);

/*****************************************************************************
* Function Name: LCD_write_char
* Purpose      : Write a specific Ascii char (data) to lcd (valid only with 4-bit mode)
* Parameters   : data  (data to be written on lcd)
* Return value : void
*****************************************************************************/
void LCD_write_int(uint32_t data);
/*****************************************************************************
* Function Name: LCD_write_string 
* Purpose      : Write a specific Ascii string (data) to lcd (valid only with 4-bit mode)
* Parameters   : *data  (pointer to data to be written on lcd)
* Return value : void
*****************************************************************************/
void LCD_write_string(uint8_t *str);




#endif /* LCD_H_ */