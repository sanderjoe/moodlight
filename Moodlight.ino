#include <Adafruit_NeoPixel.h>

#define PIN 4
#define LED_COUNT 50

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("ready");
  
  leds.begin();
  clearLEDs();
  leds.show();
  char inByte = ' ';
}

void loop() {
  int ledColor[50];
  if(Serial.available()){
    for(int i = 0; i < 4; i++){
      char inByte = Serial.read();
      ledColor[i] = inByte;
      Serial.println(inByte);
    }
    
    leds.setPixelColor(ledColor[0], ledColor[1], ledColor[2], ledColor[3]);
    leds.show();    
    int i;
    for (i = 0; i < 4; i = i + 1) {
      Serial.println(ledColor[i]);  
           
    }  
    
}
}
    

void clearLEDs(){
  for(int i=0; i<LED_COUNT; i++){
    leds.setPixelColor(i, 0);
  }
}


 

 
