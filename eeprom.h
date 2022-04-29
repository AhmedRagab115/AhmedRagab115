/*
 * eeprom.h
 *
 * Created: 3/25/2022 11:36:45 AM
 *  Author: safifi
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "std_macros.h"

void EEPROM_write(uint8_t data, uint16_t addr);
uint8_t EEPROM_read(uint16_t addr);





#endif /* EEPROM_H_ */