#ifndef _DS1307_H
#define _DS1307_H

#include "stm32f1xx_hal.h"

#define RTC_ADDR		(0x68<<1)

int8_t DS1307Read(I2C_HandleTypeDef hi, uint8_t address, uint8_t *data);	// The function of reading data from DS1307


int8_t DS1307Write(I2C_HandleTypeDef hi, uint8_t address, uint8_t data);	// The function of writing data to DS1307

#endif
