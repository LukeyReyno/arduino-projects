#include "sevenSeg.h"

// Helper
void lightCathode(Byte cathodeValue, Byte* cathodePins)
{
    int i;

    Byte temp = cathodeValue;

    for (i = 0; i< NUM_CATHODE_PINS; i++)
    {
        digitalWrite(cathodePins[NUM_CATHODE_PINS - 1 - i], temp & 1);
        temp /= 2;
    }
}

SevenSegmentDisplay::SevenSegmentDisplay(Byte *anodePins, Byte *cathodePins, int numPins) : 
    anodePins(anodePins),
    cathodePins(cathodePins),
    numPins(numPins)
    {
        this->cathode = 0b10000001;
    }

void SevenSegmentDisplay::begin() {
    int i;
    for (i = 0; i < numPins; i++)
    {
        pinMode(anodePins[i], OUTPUT);

        // Turns all anodes off
        digitalWrite(anodePins[i], HIGH);
    }

    for (i = 0; i< NUM_CATHODE_PINS; i++)
        pinMode(cathodePins[i], OUTPUT);
}

void SevenSegmentDisplay::setCathode(char display) {
    bool read = digitalRead(anodePins[0]);
    
    switch (display)
    {
        case '0':
            this->cathode = 0b01111110;
            break;
        case '1':
            this->cathode = 0b00110000;
            break;
        case '2':
            this->cathode = 0b01101101;
            break;
        case '3':
            this->cathode = 0b01111001;
            break;
        case '4':
            this->cathode = 0b00110011;
            break;
        case '5':
            this->cathode = 0b01011011;
            break;
        case '6':
            this->cathode = 0b01011111;
            break;
        case '7':
            this->cathode = 0b01110000;
            break;
        case '8':
            this->cathode = 0b01111111;
            break;
        case '9':
            this->cathode = 0b01111011;
            break;
        default:
            this->cathode = 0b10000001;
            break;
    }
    lightCathode(this->cathode, this->cathodePins);
}

Byte SevenSegmentDisplay::getCathode()
{
    return this->cathode;
}