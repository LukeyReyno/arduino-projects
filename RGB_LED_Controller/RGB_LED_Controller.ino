// Arduino Code for RGB Manipulator
//
#include "myButton.h"

#define BUTTON_PIN 12
#define RED_RGB_PIN 11
#define GREEN_RGB_PIN 10
#define BLUE_RGB_PIN 9
#define RED_LED 4
#define GREEN_LED 3
#define BLUE_LED 2

#define MAX_COLOR_VALUE 255
#define MAX_ANALOG_READ 1023.0

static unsigned char redValue = 100;
static unsigned char greenValue = 100;
static unsigned char blueValue = 100;

//RED - 0, GREEN - 1, BLUE - 2
static unsigned char colorState = 0;

static int analogValue;
static int newValue;

Button colorStateSwitcher(BUTTON_PIN);

void setup()
{
  Serial.begin(115200);

  pinMode(RED_RGB_PIN, OUTPUT);
  pinMode(GREEN_RGB_PIN, OUTPUT);
  pinMode(BLUE_RGB_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(A0, INPUT);
  
  // Write Initial Values to the LED
  analogWrite(RED_RGB_PIN, redValue);
  analogWrite(GREEN_RGB_PIN, greenValue);
  analogWrite(BLUE_RGB_PIN, blueValue);
}

void loop()
{
  switch(colorState)
  {
    case 0:
        redValue = updateValue();
    	analogWrite(RED_RGB_PIN, redValue);
        digitalWrite(RED_LED, HIGH);
    	break;
    case 1:
        greenValue = updateValue();
    	analogWrite(GREEN_RGB_PIN, greenValue);
        digitalWrite(GREEN_LED, HIGH);
    	break;
    case 2:
        blueValue = updateValue();
    	analogWrite(BLUE_RGB_PIN, blueValue);
        digitalWrite(BLUE_LED, HIGH);
    	break;
  }
  printResults(analogValue, newValue, colorState, redValue, greenValue, blueValue);

  updateColorState();
}

void printResults(
        int analogValue, 
        int newValue, 
        unsigned char colorState,
        unsigned char redValue,
        unsigned char greenValue,
        unsigned char blueValue
    )
{
    /* Serial.print(analogValue);
     * Serial.print(" ----- ");
     * Serial.println(newValue);
     */

    Serial.print("RED: ");
    Serial.print(redValue);
    Serial.print("\tGREEN: ");
    Serial.print(greenValue);
    Serial.print("\tBLUE: ");
    Serial.println(blueValue);
    Serial.print("\n");
}

unsigned char updateValue()
{
  analogValue = analogRead(A0);
  newValue = MAX_COLOR_VALUE * (analogValue / MAX_ANALOG_READ);
  return newValue;
}

unsigned char updateColorState()
{
    if (colorStateSwitcher.isReleased())
    {
        colorState = (colorState + 1) % 3;
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, LOW);
    }
}