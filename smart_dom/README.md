
# (c)Peter Riša

## Školský projekt "Smart dom"
 - Návrh domu riadeného cez WEB aplikáciu

## Dokumenty

## SW
 - webserver pre ESP8266
 - aplikácia pre ATmega2560
 
## Hardware
 - 1x WeMOS Mega + WiFi R3 ATmega2560 + ESP8266 USB-TTL for Arduino Mega NodeMCU
 - 2x DS18B20 teplomer modul pre Arduino
 - 1x displej 3.5" TFT LCD Screen Module 480 x 320 For Arduino UNO & MEGA 2560 R3 Board
 - 1x relé 5V 1/2/4/6/8/16 Channel Relay Board Module Optocoupler for Arduino PiC ARM AVR
 - 1x Prototypová doska pre Arduino MEGA 2560 - Shield Board
 - 1x TEMT6000 Professional Light Sensor Arduino 
 - 2x Peltier článok 1/5/10 TEC1-12706 12V 60W TEC Peltierelement Modul
 
## Použitá literatúra
 - https://circuits4you.com/2018/02/03/esp8266-nodemcu-adc-analog-value-on-dial-gauge/
 
 
## Nastavenie dosky WeMOS Mega

- nastavenie komunikácie medzi jednotlivými časťami procesorovej dosky

|	                             | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | RXD/TXD |
| USB izolovaný                  | -- | -- | -- | -- | -- | -- | -- | -- |    0    |
| ATmega2560 <-> ESP8266         | ON | ON | -- | -- | -- | -- | -- | -- |    0    |
| USB <-> ATmega2560 (vloženie)  | -- | -- | ON | ON | -- | -- | -- | -- |    0    |
| USB <-> ESP8266 (vloženie)     | -- | -- | -- | -- | ON | ON | ON | -- |    0    |
| USB <-> ESP8266 (práca)        | -- | -- | -- | -- | ON | ON | -- | -- |    0    |
| USB <-> ATmega2560 <-> ESP8266 | ON | ON | ON | ON | -- | -- | -- | -- |    3    |








|	                             | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | RXD/TXD |
|--------------------------------|----|----|----|----|----|----|----|----|---------|
| USB izolovaný                  | -- | -- | -- | -- | -- | -- | -- | -- |    0    |

|	                             | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | RXD/TXD |
|--------------------------------|----|----|----|----|----|----|----|----|---------|
| ATmega2560 <-> ESP8266         | ON | ON | -- | -- | -- | -- | -- | -- |    0    |

|	                             | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | RXD/TXD |
|--------------------------------|----|----|----|----|----|----|----|----|---------|
| USB <-> ATmega2560 (vloženie)  | -- | -- | ON | ON | -- | -- | -- | -- |    0    |

|	                             | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | RXD/TXD |
|--------------------------------|----|----|----|----|----|----|----|----|---------|
| USB <-> ESP8266 (vloženie)     | -- | -- | -- | -- | ON | ON | ON | -- |    0    |

|	                             | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | RXD/TXD |
|--------------------------------|----|----|----|----|----|----|----|----|---------|
| USB <-> ESP8266 (práca)        | -- | -- | -- | -- | ON | ON | -- | -- |    0    |


|	                             | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | RXD/TXD |
|--------------------------------|----|----|----|----|----|----|----|----|---------|
| USB <-> ATmega2560 <-> ESP8266 | ON | ON | ON | ON | -- | -- | -- | -- |    3    | 



 

