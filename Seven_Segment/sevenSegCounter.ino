// Arduino Code for sevenSegCounter
//
#include "sevenSeg.h"

// Consistent to 5461AS Seven Segment Display Pins
#define ANODE_1 6
#define ANODE_2 8
#define ANODE_3 9
#define ANODE_4 12
#define NUM_ANODES 4

#define SSEG_DP_PIN 3
#define SSEG_A_PIN 11
#define SSEG_B_PIN 7
#define SSEG_C_PIN 4
#define SSEG_D_PIN 2
#define SSEG_E_PIN 1
#define SSEG_F_PIN 10
#define SSEG_G_PIN 5

Byte anodes[] = {ANODE_1, ANODE_2, ANODE_3, ANODE_4};
Byte cathodePins[] = {SSEG_DP_PIN, SSEG_A_PIN, SSEG_B_PIN, SSEG_C_PIN, SSEG_D_PIN, SSEG_E_PIN, SSEG_F_PIN, SSEG_G_PIN};

SevenSegmentDisplay sseg(anodes, cathodePins, NUM_ANODES);

void setup()
{
    Serial.begin(115200);
    sseg.begin();
}

void loop()
{
    digitalWrite(anodes[0], LOW);

    sseg.setCathode('-');
    delay(100000);

    /*
    sseg.setCathode('0');
    delay(1000);
    sseg.setCathode('1');
    delay(1000);
    sseg.setCathode('2');
    delay(1000);
    sseg.setCathode('3');
    delay(1000);
    sseg.setCathode('4');
    delay(1000);
    sseg.setCathode('5');
    delay(1000);
    sseg.setCathode('6');
    delay(1000);
    sseg.setCathode('7');
    delay(1000);
    sseg.setCathode('8');
    delay(1000);
    sseg.setCathode('9');
    delay(1000);
    */
}