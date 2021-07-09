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

    public:
        SevenSegmentDisplay(Byte *anodePins, Byte *cathodePins, int numPins);

        void begin();

        void setCathode(char display);
        Byte getCathode();
};

#endif