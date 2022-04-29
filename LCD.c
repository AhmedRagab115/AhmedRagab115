/*
 * LCD.c
 *
 * Created: 3/12/2022 1:17:16 PM
 *  Author: safifi
 */ 
#include "LCD.h"

void LCD_init(void){
	LCD_INIT_PORT();						// init port of lcd needs to be changed 
	LCD_write_command(0x3);					// write cmd  0x3  3 times to init lcd 			
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x2);					// write cmd to enable 4-bit mode 
	LCD_write_command(0x28);
	LCD_write_command(0x08);
	LCD_write_command(0x01);				// clear lcd cmd
	LCD_write_command(0x06);				//to make curser increment to right
	LCD_write_command(0x0c);				//to turn on the display
	_delay_ms(20);
}

void LCD_write_command(uint8_t cmd){ // 0x82
	RS(0);
	D4(READBIT(cmd,4));
	D5(READBIT(cmd,5));
	D6(READBIT(cmd,6));
	D7(READBIT(cmd,7));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);

	D4(READBIT(cmd,0));
	D5(READBIT(cmd,1));
	D6(READBIT(cmd,2));
	D7(READBIT(cmd,3));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}

void LCD_write_char(uint8_t data){
	RS(1);
	D4(READBIT(data,4));
	D5(READBIT(data,5));
	D6(READBIT(data,6));
	D7(READBIT(data,7));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);

	D4(READBIT(data,0));
	D5(READBIT(data,1));
	D6(READBIT(data,2));
	D7(READBIT(data,3));
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);	
}


void LCD_write_string(uint8_t *str){
	
	uint8_t i=0;
	
	while(str[i]!='\0'&&i<16){
		LCD_write_char(str[i]);
		i++;
	}
	
}



void LCD_write_int(uint32_t data){
	
	int8_t i=0;
	uint8_t str[10];
	
	if(data==0) { LCD_write_char('0');}
	
	for(i=0;data!=0;i++){
		str[i]=data%10+48;
		data/=10;
	}
	
	
	while(i>0){
		
		LCD_write_char(str[i-1]);
		i--;
		
	}
	
	
}