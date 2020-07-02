#include <ADCTouch.h>
#include <sd_l0.h>
#include <sd_l1.h>
#include <sd_l2.h>
#include <SimpleSDAudio.h>
#include <SimpleSDAudioDefs.h>

 
int ref0, ref1, ref2, ref3, ref4, ref5;       //reference values to remove offset
 
void setup()
{
    // No pins to setup, pins can still be used regularly, although it will affect readings
 
    Serial.begin(9600);
  SdPlay.setSDCSPin(4); // chip select
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
  Serial.println("sd ready");
    
 
    ref0 = ADCTouch.read(A0, 500);    //create reference values to
    ref1 = ADCTouch.read(A1, 500);    //account for the capacitance of the pad
    ref2 = ADCTouch.read(A2, 500);
    ref3 = ADCTouch.read(A3, 500);
    ref4 = ADCTouch.read(A4, 500);
    ref5 = ADCTouch.read(A5, 500);
}
 
void loop()
{
    int pinA0 = ADCTouch.read(A0);   
    int pinA1 = ADCTouch.read(A1);
    int pinA2 = ADCTouch.read(A2);
    int pinA3 = ADCTouch.read(A3);
    int pinA4 = ADCTouch.read(A4);
    int pinA5 = ADCTouch.read(A5);  

//     Serial.print(pinA0);
//     Serial.print(pinA1);
//     Serial.print(pinA2);
//     Serial.print(pinA3);
//     Serial.print(pinA4);
//     Serial.println(pinA5);
 
    pinA0 -= ref0;       //reference values to remove offset
    pinA1 -= ref1;  
    pinA2 -= ref2;  
    pinA3 -= ref3;
    pinA4 -= ref4;
    pinA5 -= ref5;   
    
    if (pinA0 > 60)   
    {
      Serial.println("A0"); 
          
  SdPlay.setFile("1_kick.raw");
    SdPlay.play();//UP_ARROW
      delay(200);
  
    }   
    if (pinA1 > 60)
    {
      Serial.println("A1");
       SdPlay.setFile("1_tom1.raw");
    SdPlay.play(); //DOWN_ARROW
      delay(1);
     }          
     if (pinA2 > 60)
     {
      Serial.println("A2");  
      SdPlay.setFile("1_cy.raw");
    SdPlay.play();//LEFT_ARROW
      delay(2);
     }
      if (pinA3 > 60)
    {
      Serial.println("A3");
      SdPlay.setFile("1_tom2.raw");
    SdPlay.play();//RIGHT_ARROW
      delay(3);
     }         
     if (pinA4 > 60)
     {
      Serial.println("A4");
      SdPlay.setFile("1_snare.raw");
    SdPlay.play();//RETURN
      delay(4);
     }          
     if (pinA5 > 60)
     {
      Serial.println("A5");
      SdPlay.setFile("1_ft.raw");
    SdPlay.play();//BACKSPACE
     delay(5);
     }          

}
