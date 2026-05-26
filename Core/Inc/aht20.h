#ifndef AHT20_H
#define AHT20_H

#include "main.h"
#include <stdint.h>

typedef struct {
    float temperature;
    float humidity;
} AHT20_Data;

AHT20_Data AHT20_Read(I2C_HandleTypeDef *hi2c);

#endif
