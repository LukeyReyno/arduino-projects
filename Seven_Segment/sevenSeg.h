#ifndef SEVENSEG_H
#define SEVENSEG_H

#define NUM_CATHODE_PINS 8

typedef unsigned char Byte;

class SevenSegmentDisplay {
    private:
        Byte *anodePins;
        Byte *cathodePins;
        Byte cathode;
        int numPins;

        void setAnode(int anodeIndex);

    public:
        SevenSegmentDisplay(Byte *anodePins, int numPins);

        void begin();
        void displayNum(int value, unsigned seconds);
};

#endif