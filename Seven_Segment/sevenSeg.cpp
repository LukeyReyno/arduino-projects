#include "sevenSeg.h"

// 74HC595 Shift Register
#define DATA_PIN 7 // DS
#define LATCH_PIN 6 // STCP
#define CLOCK_PIN 5 // SHCP

#define DECODER_VALUES 10 // 0 - 9

static Byte decoder[] = {
    0b01111110, // 0
    0b00110000,
    0b01101101,
    0b01111001,
    0b00110011,
    0b01011011,
    0b01011111,
    0b01110000,
    0b01111111,
    0b01111011, // 9
    0b10000001  // Default
};

SevenSegmentDisplay::SevenSegmentDisplay(Byte *anodePins, int numPins) : 
    anodePins(anodePins),
    numPins(numPins)
    {}

void SevenSegmentDisplay::begin() {
    int i;
    for (i = 0; i < numPins; i++)
    {
        pinMode(anodePins[i], OUTPUT);

        // Turns all anodes off
        digitalWrite(anodePins[i], HIGH);
    }

    pinMode(DATA_PIN, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
}

void displayOneDigit(int value)
{
    Byte cathode = (value < DECODER_VALUES) ? decoder[value] : decoder[DECODER_VALUES];

    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, cathode);
    digitalWrite(LATCH_PIN, HIGH);
}

void resetDigit()
{
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0);
    digitalWrite(LATCH_PIN, HIGH);
}

void SevenSegmentDisplay::setAnode(int anodeIndex)
{
    int i;

    for (i = 0; i < numPins; i++)
        digitalWrite(anodePins[i], HIGH);
    
    digitalWrite(anodePins[anodeIndex], LOW);
}

void SevenSegmentDisplay::displayNum(int value, unsigned seconds) 
{
    uint32_t period = seconds * 1000L;       // numSeconds * milli

    int value1 = value % 10;
    int value10 = value / 10 % 10;
    int value100 = value / 100 % 10;
    int value1000 = value / 1000 % 10;
    int values[] = {value1, value10, value100, value1000};
    int i;

    for(uint32_t tStart = millis();  (millis()-tStart) < period;)
    {
        for (i = 0; i < 4; i++)
        {
            resetDigit();
            setAnode(i);
            displayOneDigit(values[i]);
            delay(2);
        }
    }
}