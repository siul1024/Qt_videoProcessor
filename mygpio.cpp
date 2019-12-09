#include "mygpio.h"
#include "ui_mainwindow.h"

myGPIO::myGPIO()
{
    wiringPiSetup();
    pinMode(CS_MCP3008, OUTPUT);
    pinMode(1, OUTPUT);
    wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED);
    adcChannel = 3;
    adcValue = 0;
}
void myGPIO::read_mcp3008_adc(unsigned char adcChannel)
{
    unsigned char buff[3];
    buff[0] = 0x01;
    buff[1] = 0x80|((adcChannel & 0x07) << 4);
    buff[2] = 0x00;
    digitalWrite(CS_MCP3008, 0);
    wiringPiSPIDataRW(SPI_CHANNEL, buff, 3);
    buff[1] = 0x03 & buff[1];
    adcValue = (buff[1] << 8 | buff[2]);
    digitalWrite(CS_MCP3008, 1);
}

void myGPIO::read_brightness()
{
    read_mcp3008_adc(adcChannel);
    delay(100);
}

void myGPIO::blink()
{
    while(1)
    {
        digitalWrite(1, 1);
        delay(300);
        digitalWrite(1, 0);
        delay(300);
    }
}

