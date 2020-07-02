
#include <sd_l0.h>
#include <sd_l1.h>
#include <sd_l2.h>
#include <SimpleSDAudio.h>
#include <SimpleSDAudioDefs.h>
#include "FastLED.h"
#define NUM_LEDS 10
#define DATA_PIN 19
#define relay 17

boolean cig = false;
boolean trgd = false;


/***********
 * sd d10
 * sd d11
 * sd d12
 * sd chip 14
 * speaker 9
 * cigbutt laser d2-d7
 * santzer laser d8
 * LED 19
 * Relay 17
 * 
 *
************/

int irLsr = 7;
int irLsr2 = 2 ;
int irLsr3 = 3;
int irLsr4 = 4;
int irLsr5 = 5;
int irLsr6 = 6;  // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int irSan = 8;


CRGB leds[NUM_LEDS];

void setup() {
//  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(irLsr, INPUT);     // declare sensor as input
  pinMode(irSan, INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
       FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  
  SdPlay.setSDCSPin(14); // chip select
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
  Serial.println("sd ready");
  digitalWrite(relay, HIGH);
  delay(2000);
  
}
 
void loop(){
//   if(!digitalRead(irLsr) && cig ==false){
////      trgd = true;
//      cig = true;
//      delay(50);
//      Serial.println("cigbutt");
//      
//   }

   if((!digitalRead(irLsr)||!digitalRead(irLsr2)||!digitalRead(irLsr3)||!digitalRead(irLsr4)||!digitalRead(irLsr5)||!digitalRead(irLsr6)) && cig ==false){
//      trgd = true;
      cig = true;
      delay(50);
      Serial.println("cigbutt");
      
   }

   if(cig == true){
      for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      leds[whiteLed] = CRGB::Green;
      FastLED.show();
      trgd = true;
      Serial.println("green");
   }

   }
  
  if (!digitalRead(irSan) && trgd == true)  // check if the input is HIGH
  {        
      for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      leds[whiteLed] = CRGB::Red;
      FastLED.show();
      }    
      
      Serial.println("san red");

    digitalWrite(relay, LOW);
    delay(1000);
        digitalWrite(relay, HIGH);
 
    delay(1000);
    SdPlay.setFile("barbie.raw");
    SdPlay.play();
     delay(30000);// turn LED ON
    trgd = false;
    cig = false;
    

    if (pirState == LOW) 
  {
      Serial.println("Motion detected!"); // print on output change
      pirState = HIGH;
    }
  } 

  
  else if(digitalRead(irLsr) && cig ==false)
  {
//     trgd = false; 

     
     for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      leds[whiteLed] = CRGB::Blue;
      FastLED.show();
   }  
   
    SdPlay.setFile("");
    SdPlay.play(); // turn LED OFF
  
    if (pirState == HIGH)
  {
      Serial.println("Motion ended!");  // print on output change
      pirState = LOW;
    }
    Serial.println("----");
  }
 
     delay(100); 
}
