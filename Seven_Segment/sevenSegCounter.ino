// Arduino Code for sevenSegCounter
//
#include "sevenSeg.h"

// Consistent to 5461AS Seven Segment Display Pins
#define ANODE_1 13
#define ANODE_2 12
#define ANODE_3 11
#define ANODE_4 10
#define NUM_ANODES 4

Byte anodes[] = {ANODE_1, ANODE_2, ANODE_3, ANODE_4};

SevenSegmentDisplay sseg(anodes, NUM_ANODES);

void setup()
{
    Serial.begin(115200);
    sseg.begin();
}

void loop()
{
    int i;

    for (i = 0; i < 3000; i++)
        sseg.displayNum(i, 1);
}