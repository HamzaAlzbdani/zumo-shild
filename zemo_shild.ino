#include <Wire.h>
#include <ZumoShield.h>
#define LED_PIN 13 

//collects data from an analog sensor 
int pin1 = 2;  
int pin2 = 1;  
int pin3 = 3;                
int distance = 5; 
int distance2 = 0;
int distance3 = 0;
ZumoMotors motors; 
          

void setup()
{
 Serial.begin(9600);             
}
class Des 
{  
    public: 
    float dist;
    float volt;
    
    float discm(int des) 
    { 
        Serial.println(des);
        float volt = des * (5.0/1023.0); 
        Serial.println(volt);
        float dist= 1.0/(volt/23.0);
        Serial.println(dist);
        return dist;
        
        
    } 
    
}; 

  
void loop()
{
  
 Des distance1;
 distance1.discm(analogRead(pin1));

             
  
 
  
  if( distance>6 ){
  // run left motor backward

  digitalWrite(LED_PIN, LOW);

  for (int speed = 0; speed >= -400; speed--)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }

  for (int speed = -400; speed <= 0; speed++)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }
  // run right motor backward

  digitalWrite(LED_PIN, LOW);

  for (int speed = 0; speed >= -400; speed--)
  {
    motors.setRightSpeed(speed);
    delay(2);
  }

  for (int speed = -400; speed <= 0; speed++)
  {
    motors.setRightSpeed(speed);
    delay(2);
  }}
else{// run left motor forward
  
  digitalWrite(LED_PIN, HIGH);

  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }
  
  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setLeftSpeed(speed);
    delay(2);
  }
  // run right motor forward

  digitalWrite(LED_PIN, HIGH);

  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setRightSpeed(speed);
    delay(2);
  }

  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setRightSpeed(speed);
    delay(2);
  }}

  

  delay(500);
                
}
