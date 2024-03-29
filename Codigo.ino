#include <Ultrasonic.h>
#define echo 2
#define trigger 1
#define ENA 0                      
#define ENB 0  
Ultrasonic ultrasonic(trigger, echo);

#define PH1 11
#define PH2 10
#define PH3 9
#define PH4 6

#define S1 A0
#define S2 A1
  
void setup()
{
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
 pinMode(PH1, OUTPUT);
 pinMode(PH2, OUTPUT);
 pinMode(PH3, OUTPUT);
 pinMode(PH4, OUTPUT);
 pinMode(ENA,OUTPUT);              
  pinMode(ENB,OUTPUT);              
  analogWrite(ENA,120);             
  analogWrite(ENB,120);             
  delay(1000);          
}
  
void loop()
{
robo_frente();
 float dist_cm = distancia();  
  if(dist_cm >= 100 && digitalRead(S1) == 0 && digitalRead(S2) == 0)
  {
    decisao();
  }
else {if(dist_cm < 100 && dist_cm > 0 && digitalRead(S1) == 0 && digitalRead(S2) == 0){
while (digitalRead(S1) == 0);
robo_frente();
}
}  
if(digitalRead(S1) == 1 && digitalRead(S2) == 0){
robo_tras();
}
if(digitalRead(S1) == 0 && digitalRead(S2) == 1)
robo_frente();
}
float distancia()                   
{
  float cmMsec;
  
  cmMsec = ( Ultrasonic::CM);
  return(cmMsec);                   
delay(10);
} 
void robo_frente()                  
{
  digitalWrite(PH1,HIGH);
  digitalWrite(PH2,LOW);
  digitalWrite(PH3,HIGH);
  digitalWrite(PH4,LOW);
} 
void robo_tras()
{
robo_parado();
delay(250);
robo_esquerda();
delay(250);
robo_frente();
}
void robo_esquerda()             
{
  digitalWrite(PH1,HIGH);
  digitalWrite(PH2,LOW);
  digitalWrite(PH3,LOW);
  digitalWrite(PH4,HIGH); 
} 
void robo_parado()                  
{
  digitalWrite(PH1,LOW);
  digitalWrite(PH2,LOW);
  digitalWrite(PH3,LOW);
  digitalWrite(PH4,LOW);   
} 
void decisao()                      
{
  robo_parado();
  delay(500);
  robo_esquerda();
  delay(400);                       
  robo_parado();
  delay(500);
}
