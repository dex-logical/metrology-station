# Metrology Station

A smart environmental monitoring station based on STM32 Nucleo F411RE.
Displays temperature, humidity, light level and distance.
A servo motor reacts automatically to sensor readings.

## Hardware
- STM32 Nucleo F411RE
- SSD1315 OLED display (I2C1)
- AHT20 + BMP280 climate sensor (I2C2)
- HC-SR04 ultrasonic distance sensor
- Photoresistor (ADC)
- SG90 servo motor (PWM)

## Features
- 4 screens switchable by onboard button
- Temperature and humidity (AHT20)
- Light level in % (photoresistor + ADC)
- Distance in mm (HC-SR04)
- Auto display off after 10 seconds of inactivity
- Display wakes up when object is detected nearby
- Servo opens/closes based on humidity and light level

## Connections
| Component | Pin |
|-----------|-----|
| SSD1315 SCL | PB6 |
| SSD1315 SDA | PB7 |
| AHT20/BMP280 SCL | I2C2 SCL |
| AHT20/BMP280 SDA | I2C2 SDA |
| HC-SR04 TRIG | PA9 |
| HC-SR04 ECHO | PA6 (via voltage divider) |
| Photoresistor | PA0 |
| SG90 signal | TIM10_CH1 |