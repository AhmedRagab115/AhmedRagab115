/*
 * eeprom.c
 *
 * Created: 3/25/2022 11:36:34 AM
 *  Author: safifi
 */ 
#include "eeprom.h"

void EEPROM_write(uint8_t data, uint16_t addr){
	EEAR = addr;
	EEDR = data;
	SETBIT(EECR, EEMWE);
	SETBIT(EECR, EEWE);  // start write
	while(READBIT(EECR,EEWE) == 1);
}

uint8_t EEPROM_read(uint16_t addr){
	EEAR = addr;
	SETBIT(EECR, EERE);  // start write
	return EEDR;
}
