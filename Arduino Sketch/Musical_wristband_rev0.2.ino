#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>
#include "pitches.h"
#ifdef __AVR__
#include <avr/power.h>
#endif
/*
 * This sketch uses the  
 * CapitiveSense Library by
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 *
 * and the NeoPixel Library
 * by Adafruit Industries
 */

//Which PWM pin on Arduino connects to the buzzer's PWM pin?
#define BUZZER 9

//Which pin on Arduino connects to the NeoPixel's DIN pin?
#define PIXELPIN 8

//How many NeoPixels are used in a single strip?
#define NUM_LEDS 1

//How many capacitive sensors are connected to Arduino?
#define NUM_SENSORS 12

//Set the brightness % of the NeoPixel
#define BRIGHTNESS 50

//Test and set the sensor threshold to trigger output 
#define SENSOR_THRESHOLD 200

//Set as "true" to view sensor values in Serial Monitor
bool debug = true;

/* Pins on Arduino that connect to sensors
 * Can be any IO pins except for BUZZER pin, NeoPixel pin
 * and the pins that act as reference for sensors (pin 2 and 10 in this case)
 */
int sensorPins[12] = {3, 4, 5, 6, 7, 14, 15, 16, A0, A1, A2, A3};

long sensorVals[NUM_SENSORS];
long start = 0;

CapacitiveSensor mySensors[12] = {
  CapacitiveSensor(2,sensorPins[0]),
  CapacitiveSensor(2,sensorPins[1]),
  CapacitiveSensor(2,sensorPins[2]),
  CapacitiveSensor(2,sensorPins[3]),
  CapacitiveSensor(2,sensorPins[4]),
  CapacitiveSensor(10,sensorPins[5]),
  CapacitiveSensor(10,sensorPins[6]),
  CapacitiveSensor(10,sensorPins[7]),
  CapacitiveSensor(10,sensorPins[8]),
  CapacitiveSensor(10,sensorPins[9]),
  CapacitiveSensor(10,sensorPins[10]),
  CapacitiveSensor(10,sensorPins[11]),
};

  
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIXELPIN, NEO_GRBW + NEO_KHZ800);


void setup()                    
{
  for (int i = 0; i < NUM_SENSORS; i++){
  mySensors[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
}

   pinMode(BUZZER, OUTPUT);
   Serial.begin(9600);
   strip.setBrightness(BRIGHTNESS);
   strip.begin();
   strip.show(); // Initialize all pixels to 'off'
}

void loop()                    
{
       
  for (int i = 0; i < NUM_SENSORS; i++){
  sensorVals[i] = mySensors[i].capacitiveSensor(30);
  if(sensorVals[i] > SENSOR_THRESHOLD){
    colorWipe(i);
    toneController(i);
  } else {
      analogWrite(BUZZER, 0);
      colorWipe(12); // Off
    }
}
     if (debug){
      showDebug();
     }
  
}

//function to define which sensor will trigger which Neopixel's color
void colorWipe(int colorCode) {
  uint32_t color;
  switch(colorCode){
    case 0:
    color = Wheel(50);
    break;
    case 1:
    color = Wheel(60);
    break;
    case 2:
    color = Wheel(80);
    break;
    case 3:
    color = Wheel(90);
    break;
    case 4:
    color = Wheel(100);
    break;
    case 5:
    color = Wheel(120);
    break;
    case 6:
    color = Wheel(140);
    break;
    case 7:
    color = Wheel(160);
    break;
    case 8:
    color = Wheel(180);
    break;
    case 9:
    color = Wheel(200);
    break;
    case 10:
    color = Wheel(220);
    break;
    case 11:
    color = Wheel(240);
    break;

  }

    strip.setPixelColor(0, color);   
    //strip.show() means send buffer to neopixels
    strip.show();
 
}

//function to define which sensor will trigger which musical note
void toneController(int sensorPin){
  switch(sensorPin){
    case 0:
    playNote(NOTE_C4);
    break;
    case 1:
    playNote(NOTE_G4);
    break;
    case 2:
    playNote(NOTE_A4);
    break;
    case 3:
    playNote(NOTE_F4);
    break;
    case 4:
    playNote(NOTE_E4);
    break;
    case 5:
    playNote(NOTE_D4);
    break;
    case 6:
    playNote(NOTE_C5);
    break;
    case 7:
    playNote(NOTE_G5);
    break;
    case 8:
    playNote(NOTE_A5);
    break;
    case 9:
    playNote(NOTE_F5);
    break;
    case 10:
    playNote(NOTE_E5);
    break;
    case 11:
    playNote(NOTE_D5);
    break; 
    
  }
  
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3,0);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3,0);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0,0);
}

void playNote(int note){
  tone(BUZZER, note, 150);

}

//function to show sensor values
void showDebug(){
 
    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    for (int i = 0; i < NUM_SENSORS; i++){
      Serial.print("Sensor ");
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(sensorVals[i]);
      Serial.print("\t");   
    }
    

    Serial.println();                  // print sensor output 

}

