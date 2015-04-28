#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIXEL_IO_PIN 6 //The pin going to the NeoPixel IN
#define NUM_PIXELS 16 //The NeoPixel 16 LED model is being used

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIXEL_IO_PIN, NEO_GRB + NEO_KHZ800);
byte buff[48]; //We are going to send RGB values for each LED so 16 LEDs x 3 bytes for the RGB values
int index=0;
int offset=0;

void setup() { 
  //Need to match the BAUD rate of the Bluetooth module
  //by default this should be 9600
  Serial.begin(9600);
  
  pixels.begin();
  
  //At startup we set all the pixels to a very light white 
  //so we no the device is on and running
  for(int i=0;i<NUM_PIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(10,10,10));
  }
  
  pixels.show();
}

void loop() {
  if (Serial.available() != 48) //Wait for all 48 bytes
      return;
  
  Serial.readBytes(buff, 48);
  
  //Set the pixel colors passed in
  for(index = 0; index < NUM_PIXELS; index++){
    offset = index * 3;
    pixels.setPixelColor(index, pixels.Color(buff[offset], buff[offset+1], buff[offset+2]));
  }

  pixels.show();  
}
