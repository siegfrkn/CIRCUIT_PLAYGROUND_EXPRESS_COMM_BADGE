///////////////////////////////////////////////////////////////////////////////
// Circuit Playground Express Pedometer Color Change Neopixels
//
// Author: Katrina Siegfried
// MIT License (https://opensource.org/licenses/MIT)
// Based on the Circuit Playground Tap Code by Carter Nelson and Bike Light Rainbow Chaser by Carter Nelson
 
#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

#define TAP_THRESHOLD       50          // Tap detect threshold

// Enable ONE of these lines to pick a sound to play back when tapped:
#include "coin.h" // Super Mario coin sound
//#include "trek.h" // Star Trek TNG communicator noise

 
bool tapDetected;

int colorIndex;
int startIndex;


///////////////////////////////////////////////////////////////////////////////

void tapCallback() {
  tapDetected = true;
}
 
 
///////////////////////////////////////////////////////////////////////////////
void setup(void) {
  Serial.begin(9600);
 
  CircuitPlayground.begin();

  CircuitPlayground.setBrightness(255);
  
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
  CircuitPlayground.setAccelTap(1, TAP_THRESHOLD);
  
  attachInterrupt(digitalPinToInterrupt(36), tapCallback, FALLING);
 
  tapDetected = false;
}
 
///////////////////////////////////////////////////////////////////////////////

void loop() {

  if (tapDetected) {
    Serial.println("TAP!");

    // Play sound data in the audio[] array (declared in one of the .h files).
    // This function "blocks" -- that is, program flow stops until sound is
    // done playing -- it does not play in the background.
    CircuitPlayground.speaker.playSound(audio, sizeof(audio), SAMPLE_RATE);
  
    // Calling speaker.end() after playing a sound is optional -- this will
    // turn off the pin 13 LED (it's connected to a microcontroller pin that's
    // also related to the speaker), but there's a small audible click when it
    // turns off.  Tradeoffs!
    CircuitPlayground.speaker.end();
    
    tapDetected = false;
    
  }


}
