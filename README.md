\# Metrology Station



A simple weather station based on STM32 Nucleo F411RE.



\## Hardware

\- STM32 Nucleo F411RE

\- SSD1315 OLED display (I2C)

\- AHT20 + BMP280 module (coming soon)



\## Features

\- Display temperature and humidity on OLED

\- Switch between screens with onboard button

\- Custom I2C display driver based on stm32-ssd1306 library



\## Connections

| Component | Pin |

|-----------|-----|

| SSD1315 SCL | PB6 |

| SSD1315 SDA | PB7 |



\## Roadmap

\- \[ ] Fix DHT11 reading (replace with AHT20+BMP280)

\- \[ ] Add photoresistor (light level)

\- \[ ] Add KiCad schematic

