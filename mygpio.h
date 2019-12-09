#ifndef MYGPIO_H
#define MYGPIO_H

#include <wiringPi.h>
#include <wiringPiSPI.h>

class myGPIO
{

public:
    myGPIO();

    const int CS_MCP3008 = 10;
    int SPI_CHANNEL = 0;
    int SPI_SPEED = 1000000;

    int adcChannel;
    int adcValue;

    int threadpt;

    void read_brightness();

private:
    void read_mcp3008_adc(unsigned char adcChannel);

public:
    static void blink();

};




#endif // MYGPIO_H
