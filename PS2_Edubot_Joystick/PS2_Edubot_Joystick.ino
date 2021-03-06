#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>

Cytron_PS2Shield ps2(2,3);

#define led 13

//Pin declaration
const int RightEn = 5;
const int RightDir = 4;
const int LeftEn = 6;
const int LeftDir = 7;

void setup()
{
  pinMode(led, OUTPUT);
  
  //Motor Driver Pin Setup
  pinMode(RightEn,OUTPUT);
  pinMode(RightDir,OUTPUT);
  pinMode(LeftEn,OUTPUT);
  pinMode(LeftDir,OUTPUT);
  
  ps2.begin(9600);
}

void loop()
{
  joystick_control();
}

void joystick_control()
{
  if(ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)<100 || ps2.readButton(PS2_TRIANGLE)==0)
  forward();
  else
  halt();
  
  if(ps2.readButton(PS2_JOYSTICK_RIGHT_Y_AXIS)>150 || ps2.readButton(PS2_CROSS)==0)
  backward();
  else
  halt();
  
  if(ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS)>150 || ps2.readButton(PS2_CIRCLE)==0)
  right();
  else
  halt();
  
  if(ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS)<100 || ps2.readButton(PS2_SQUARE)==0)
  left();
  else
  halt();
}

void halt()
{
  analogWrite(RightEn, 0);
  analogWrite(LeftEn, 0);
}

void forward()
{
  digitalWrite(RightDir,HIGH);
  digitalWrite(LeftDir,LOW);
  analogWrite(RightEn, 255);
  analogWrite(LeftEn, 255);
}

void backward()
{
  digitalWrite(RightDir,LOW);
  digitalWrite(LeftDir,HIGH);
  analogWrite(RightEn, 255);
  analogWrite(LeftEn, 255); 
}

void right()
{
  digitalWrite(RightDir,HIGH);
  digitalWrite(LeftDir,LOW);
  analogWrite(RightEn, 0);
  analogWrite(LeftEn, 255);
}

void left()
{
  digitalWrite(RightDir,HIGH);
  digitalWrite(LeftDir,LOW);
  analogWrite(RightEn, 255);
  analogWrite(LeftEn, 0);
}
