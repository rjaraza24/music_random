int snare;
int tom1;
int tom2;
int floortom;
int cymbal;
int highhat;


//const int ledPin = 13;      // LED connected to digital pin 13
////const int knockSensor = A1; // the piezo is connected to analog pin 0
//const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not


// these variables will change: 
//////////////////////
const int snarepin=A0;
const int tom1pin=A1;
const int tom2pin=A2;
const int floortompin=A3;
const int cymbalpin=A4;
const int highhatpin=A5;

#include <sd_l0.h>
#include <sd_l1.h>
#include <sd_l2.h>
#include <SimpleSDAudio.h>
#include <SimpleSDAudioDefs.h>

 
void setup()
{
  Serial.begin(9600);
  
 
  SdPlay.setSDCSPin(4); // chip select
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
  Serial.println("sd ready");
//  SdPlay.setFile("startup.raw"); // plays the startup tone.
//  SdPlay.play();
//    ref0 = ADCTouch.read(A0, 500);    //create reference values to
//    ref1 = ADCTouch.read(A1, 500);    //account for the capacitance of the pad
//    ref2 = ADCTouch.read(A2, 500);
//    ref3 = ADCTouch.read(A3, 500);
//    ref4 = ADCTouch.read(A4, 500);
//    ref5 = ADCTouch.read(A5, 500);
 
}

// these constants won't change:
       // variable used to store the last LED status, to toggle the light


void loop() {
  // read the sensor and store it in the variable sensorReading:
//    int pinA0 = ADCTouch.read(A0);   
//    int pinA1 = ADCTouch.read(A1);
//    int pinA2 = ADCTouch.read(A2);
//    int pinA3 = ADCTouch.read(A3);
//    int pinA4 = ADCTouch.read(A4);
//    int pinA5 = ADCTouch.read(A5);  

//     Serial.print(pinA0);
//     Serial.print(pinA1);
//     Serial.print(pinA2);
//     Serial.print(pinA3);
//     Serial.print(pinA4);
//     Serial.println(pinA5);
 
//    pinA0 -= ref0;       //reference values to remove offset
//    pinA1 -= ref1;  
//    pinA2 -= ref2;  
//    pinA3 -= ref3;
//    pinA4 -= ref4;
//    pinA5 -= ref5;   
   snare=analogRead(snarepin);
  tom1=analogRead(tom1pin);
    tom2=analogRead(tom2pin);
  floortom=analogRead(floortompin);
  cymbal=analogRead(cymbalpin);
  highhat=analogRead(highhatpin);


//
// Serial.print(snare);
//  Serial.print(" ");
// Serial.print(tom1);
//   Serial.print(" ");
// Serial.print(tom2);
//   Serial.print(" ");
// Serial.print(floortom);
//   Serial.print(" ");
// Serial.print(cymbal);
//   Serial.print(" ");
// Serial.println(highhat);
//
//
//   delay(100);
// Serial.println();
 
  
    if ( snare>50 && tom1<50 && tom2<50 && floortom<50 && highhat<50 && cymbal<50)
  {
    SdPlay.setFile("2_snare.raw");
    SdPlay.play();
    Serial.println("snare");
     delay(5);

  }
  if (snare<50 && tom1>50 && tom2<50 && floortom<50 && highhat<50 && cymbal<50)
  {
    SdPlay.setFile("2_tom1.raw");
    SdPlay.play();
    Serial.println("tom1");
     delay(5);

   
  }
  if (snare<50 && tom1<50 && tom2>50 && floortom<50 && highhat<50 && cymbal<50)
  {
    SdPlay.setFile("2_tom2.raw");
    SdPlay.play();
    Serial.println("tom2");
     delay(5);

  }
  if (snare<50 && tom1<50 && tom2<50 && floortom>150  && highhat<50 && cymbal<50)
  {
    SdPlay.setFile("3_kick.raw");
    SdPlay.play();
    Serial.println("kick");
     delay(5);

  }
  if (snare<50 && tom1<50 && tom2<50 && floortom<50 && highhat<50 && cymbal>50)
  {
    SdPlay.setFile("1_cy.raw");
    SdPlay.play();
    Serial.println("cymbal");
     delay(5);

  }
  if (snare<50 && tom1<50 && tom2<50 && floortom<50 && highhat>50 && cymbal<50)
  {
    SdPlay.setFile("1_ohh.raw");
    SdPlay.play();
    Serial.println("open highhat");
 delay(5);
  }
  delay(5);
  // delay to avoid overloading the serial port buffer
}
