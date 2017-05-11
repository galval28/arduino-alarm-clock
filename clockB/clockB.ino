#include <stdio.h>
#include <Wire.h>
#include "rgb_lcd.h"
#include <CurieBLE.h>
rgb_lcd lcd;
//const int powerB = 1;
const int hrPin = 8;
const int minPin = 7;
const int switchPin = 5;
const int colorR = 255;
const int colorG = 50;
const int colorB = 150;
const int alrmPin = 0;

int iMin = 0;
int iHr = 0;
int exi=0;
int totalSec=0;
int seconds=0;
int minutes=0;
int hours =0;
//holds the minutes from the last time it was printed
int oMin =0;
//holds the hours from the last time it was printed
int oHr =0;
//the variables that hour the time the alarm is set for
int aMin =0;
int aHr=03;

void printTime(int iHr, int iMin){
  totalSec=millis()/1000;
  minutes=(totalSec/60)+iMin;
  seconds=totalSec%60;
  hours=(minutes/60)+iHr;
  minutes=(minutes%60);
  //if the time has changed from the last time the time was calualted then print it
  
     lcd.clear();
     lcd.print(hours);
     lcd.print(":");
     lcd.print(minutes);
  //save this time as the old time
     oMin=minutes;
     oHr=hours;
  //print the value that the alarm is set for
     lcd.setCursor(0,1);
     lcd.print("alrm set ");
     lcd.print(15);
     lcd.print(":");
     lcd.print(00);
     lcd.setCursor(0,0);
     if(minutes==0&&hours==15){
     tone(0,500);
     delay(50);
     noTone(0);
     tone(0,200);
     delay(50);
     noTone(0);
     tone(0,500);
     delay(50);
     noTone(0);
     tone(0,700);
     delay(50);
     noTone(0);
     }
     if(hours>23){
          hours=0;
        }
     if(minutes>59){
          iMin=0;
        }
}

void setup() {
  
  //set the pins to the right modes
  pinMode(hrPin,INPUT);
  pinMode(minPin,INPUT);
  pinMode(switchPin,INPUT);
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);

  totalSec=millis()/1000;
  minutes=(totalSec/60)+iMin;
  seconds=totalSec%60;
  hours=(minutes/60)+iHr;
  minutes=(minutes%60);
  //if the time has changed from the last time the time was calualted then print it
  
     lcd.clear();
     lcd.print(hours);
     lcd.print(":");
     lcd.print(minutes);
  //save this time as the old time
     oMin=minutes;
     oHr=hours;
  //print the value that the alarm is set for
     lcd.setCursor(0,1);
     lcd.print("alrm set ");
     lcd.print(aHr);
     lcd.print(":");
     lcd.print(aMin);
     lcd.setCursor(0,0);

}

void loop() {
  
  delay(250);
  if(digitalRead(hrPin)==!HIGH){
   iHr++;
   delay(400);
   if(iHr>23){
    iHr=0;
   }
  }
  if(digitalRead(minPin)==!HIGH){
   iMin++;
   delay(400);
   if(iMin>59){
    iMin=0;
   }
  }
  printTime(iHr,iMin);
}





