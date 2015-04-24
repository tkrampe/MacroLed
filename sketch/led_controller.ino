#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIXEL_IO_PIN        6
#define NUM_PIXELS 16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIXEL_IO_PIN, NEO_GRB + NEO_KHZ800);
byte buff[48];
int index=0;
int offset=0;

void setup() {
  pixels.begin();
  Serial.begin(9600); 
  
  for(int i=0;i<NUM_PIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(10,10,10));
  }
  
  pixels.show();
}

void loop() {
  if (Serial.available() != 48) 
      return;
  
  Serial.readBytes(buff, 48);
  
  for(index=0; index<NUM_PIXELS; index++){
    offset = index * 3;
    pixels.setPixelColor(index, pixels.Color(buff[offset], buff[offset+1], buff[offset+2]));
  }

  pixels.show();  
}
