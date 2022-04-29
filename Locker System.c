/*
 * Locker_System.c
 *
 * Created: 3/31/2022 1:15:45 PM
 *  Author: Eng_Ahmed_L
 */ 


#include "LOCKER.h"

uint8_t mode=0;

int main(void) {
	
	
	// check if password stored before or it is the first time to run the locker
	if(EEPROM_read(0)==0xff&&EEPROM_read(1)==0xff&&EEPROM_read(2)==0xff&&EEPROM_read(3)==0xff){ LOCK_pass_reset();	}
	
	
	// init the ports & locker
	LOCK_INIT_PORT();		// init locker port
	Lock(0);				// lock on for first time 
	LCD_init();				// init lcd 
	keypad_init();			// init keypad parameters
	
	int8_t _key;
	uint8_t flage=0;
	uint8_t state;
	
    while(1)
    {
		
		_key= keypad_scan();
		
		if(_key!=-1&&flage==0){
			
			flage++;
			
			if(_key=='/'&& LOCK_state()==0){				// change password by pressing '/' when the lock is opened
				
				Buzzer(1);
				_delay_ms(3000);
				Buzzer(0);
				LOCK_pass_change();
				
				}
			
			else if(_key=='X'&&LOCK_state()==0){				// close locker by pressing '*' when the lock is opened
				
				Lock(1);
				Buzzer(1);
				_delay_ms(100);
				Buzzer(0);
				}
				
			else if(_key=='='&&LOCK_state()==0){				// reset locker password by pressing '=' when the lock is opened
				
				Buzzer(1);
				_delay_ms(1500);
				Buzzer(0);
				Buzzer(1);
				_delay_ms(1500);
				Buzzer(0);
				LOCK_pass_reset();
			}
			
			
			else { LOCK_change();}
			
			
		}
		
		else if (_key==-1 && flage>0){flage=0;}
	}
}
      
	  
	  
	  
	    
   
	






void LOCK_pass_reset(void){
	
	EEPROM_write('0',0);
	EEPROM_write('0',1);
	EEPROM_write('0',2);
	EEPROM_write('0',3);
	
}

void LOCK_pass_change(void){
	int8_t _key3; uint8_t count=0;uint8_t flage3=0;
	LCD_write_command(0x01);
	LCD_write_string("enter new pass");
	LCD_write_command(0xc0);
	while(_key3=='/');
	while(count<5){
		_key3=keypad_scan();
		if (_key3!=-1&&flage3==0&&count<=3)
		{
			flage3++;
			EEPROM_write(_key3,count);
			LCD_write_char('*');
			Buzzer(1);
			_delay_ms(100);
			Buzzer(0);
			count++;
		}
		if (_key3==-1 && flage3>0){flage3=0;}	
		
		if (_key3=='c'&&count==4)
		{
			LCD_write_command(0x01);
			LCD_write_command(0x80);
			LCD_write_string("pass saved");
			count++;
			_delay_ms(3000);
			LCD_write_command(0x01);
			
		}
	}	
	
	
	
}


void LOCK_change(void){
	
	int8_t _key2; uint8_t count2=0;uint8_t flage2=0;
	uint8_t pass_arr[4];
	LCD_write_command(0xc8);
	LCD_write_char(EEPROM_read(0));
	LCD_write_char(EEPROM_read(1));
	LCD_write_char(EEPROM_read(2));
	LCD_write_char(EEPROM_read(3));
	
	LCD_write_command(0x80);
	
	while(count2<4){
		_key2=keypad_scan();
		if (_key2!=-1&&flage2==0&&count2<=3)
		{
			flage2++;
			
			LCD_write_char('*');
			pass_arr[count2]=_key2;
			Buzzer(1);
			_delay_ms(100);
			Buzzer(0);
			count2++;
		}
		if (_key2==-1 && flage2>0){flage2=0;}
					
	}
	
	
	if (pass_arr[0]!=EEPROM_read(0)){
		LCD_write_command(0x01);
		LCD_write_string("try again");
		_delay_ms(2000);
		LCD_write_command(0x01);
		LCD_write_command(0x80);
	} 
	else if (pass_arr[1]!=EEPROM_read(1)){
		LCD_write_command(0x01);
		LCD_write_string("try again");
		_delay_ms(2000);
		LCD_write_command(0x01);
		LCD_write_command(0x80);
	}
	else if (pass_arr[2]!=EEPROM_read(2)){
		LCD_write_command(0x01);
		LCD_write_string("try again");
		_delay_ms(2000);
		LCD_write_command(0x01);
		LCD_write_command(0x80);
	}
	else if (pass_arr[3]!=EEPROM_read(3)){
		LCD_write_command(0x01);
		LCD_write_string("try again");
		_delay_ms(2000);
		LCD_write_command(0x01);
		LCD_write_command(0x80);
	}
	else{
		 Lock(0);
		 LCD_write_command(0x01);
		 LCD_write_command(0x80);
		 LCD_write_string("locker opened");
		 _delay_ms(2000);
		 LCD_write_command(0x01);
		 LCD_write_command(0x80);
	}
			
}
