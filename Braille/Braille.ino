#include "Braille.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 12); // RX, TX

#define buzz 10

#define L1 8 
#define L2 6 
#define L3 4 
#define R1 9  
#define R2 7 
#define R3 5 
#define Space 2 
#define Enter 3
#define Mode 13

#define vLu A1
#define vRu A0
#define vLd A2
#define vRd A3

bool SEnter, SSpace, Mo;
bool text[7]={1,1,1,1,1,1,1};

char a, lastIN='1';
bool flag=HIGH;

Braille braille(L1,L2,L3,R1,R2,R3,Mode,vLu,vRu,vLd,vRd);

void setup() 
{
  pinMode(Space,INPUT);
  pinMode(Enter,INPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600); 
  
  tone(buzz, 70, 1500);   //Beep 2 times when code starts
  delay(500);
  noTone(buzz);
  delay(500);
  tone(buzz, 70, 1500);
  delay(500);
  noTone(buzz);
  delay(500);
}

void loop() 
{
  braille.bRead();
  SEnter=digitalRead(Enter);
  SSpace=digitalRead(Space);
  if(SSpace==LOW){
      a=braille.getch();
      Serial.println(a);
      mySerial.print(a);
      delay(200);
      braille.emp();
  }else if(SEnter==LOW){
    a=braille.getch();
    if(a==' '){
      Serial.println();
      mySerial.println();
      braille.emp();
      delay(200);
    }else{
      a = toupper(a);
      Serial.println(a);
      mySerial.print(a);
      delay(200);
      braille.emp();
      }
   }
   else{}
}
