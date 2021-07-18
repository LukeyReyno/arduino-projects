// Arduino Code for sevenSegCounter
//
#include "sevenSeg.h"

// Consistent to 5461AS Seven Segment Display Pins
#define ANODE_1 13
#define ANODE_2 12
#define ANODE_3 11
#define ANODE_4 10
#define BUTTON 9
#define NUM_ANODES 4

Byte anodes[] = {ANODE_1, ANODE_2, ANODE_3, ANODE_4};

SevenSegmentDisplay sseg(anodes, NUM_ANODES);

void setup()
{
    pinMode(BUTTON, INPUT);
    sseg.begin();
}

void loop()
{
    if (digitalRead(BUTTON))
    {
        delay(1000);
        count(9999);
    }
}

void count(int numSeconds)
{
    int i;

    for (i = 0; i < numSeconds; i++)
    {
        sseg.displayNum(i, 1);
        if (digitalRead(BUTTON))
            break;
    }
}