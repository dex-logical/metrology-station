#include "aht20.h"

#define AHT20_ADDR (0x38 << 1)

AHT20_Data AHT20_Read(I2C_HandleTypeDef *hi2c)
{
    AHT20_Data data = {0.0f, 0.0f};
    uint8_t cmd_init[3] = {0xBE, 0x08, 0x00};
    uint8_t cmd_measure[3] = {0xAC, 0x33, 0x00};
    uint8_t buf[7] = {0};

    // Инициализация
    HAL_I2C_Master_Transmit(hi2c, AHT20_ADDR, cmd_init, 3, 100);
    HAL_Delay(10);

    // Запуск измерения
    HAL_I2C_Master_Transmit(hi2c, AHT20_ADDR, cmd_measure, 3, 100);
    HAL_Delay(80);

    // Читаем 7 байт
    HAL_I2C_Master_Receive(hi2c, AHT20_ADDR, buf, 7, 100);

    // Парсим данные
    uint32_t raw_hum = ((uint32_t)buf[1] << 12) |
                       ((uint32_t)buf[2] << 4)  |
                       (buf[3] >> 4);

    uint32_t raw_temp = ((uint32_t)(buf[3] & 0x0F) << 16) |
                        ((uint32_t)buf[4] << 8)  |
                        buf[5];

    data.humidity    = (raw_hum  * 100.0f) / 1048576.0f;
    data.temperature = (raw_temp * 200.0f / 1048576.0f) - 50.0f;

    return data;
}
