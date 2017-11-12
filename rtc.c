#ifndef _RTC_C
#define _RTC_C

#include "stm32f1xx_hal.h"

#include "rtc.h"

int8_t DS1307Write(I2C_HandleTypeDef hi, uint8_t address, uint8_t data)
{
	uint8_t TxBuffer[2];
	TxBuffer[0]=address;
	TxBuffer[1]=data;

	if(HAL_I2C_Master_Transmit(&hi,(DS1307_ADDR), TxBuffer, 2, 100) !=HAL_OK)
		return -1;
	return 0;
}

int8_t DS1307Read(I2C_HandleTypeDef hi, uint8_t address, uint8_t *data)
{
	uint8_t i;
	i = address;
	if(HAL_I2C_Master_Transmit(&hi,(DS1307_ADDR), &i, 1, 100) != HAL_OK)
	{
		return -1;
	}
	else
	{
		if(HAL_I2C_Master_Receive(&hi,(DS1307_ADDR), data, 1, 100) != HAL_OK)
			return -1;
	}
	return 0;
}



#endif // RTC
