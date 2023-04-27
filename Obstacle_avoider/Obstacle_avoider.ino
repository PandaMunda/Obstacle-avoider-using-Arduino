// Please read the description file for better understanding.
int trigPin = 9;
int echoPin = 10;
int acleft4 = 4;  // ac = anticlockwise
int cleft5 = 5;  // c = clockwise
int acright6 = 6;
int cright7 = 7;
int pwm = 3; // Use only if you want to control the speed of dc motor
int pwm1 = 11; // Use only if you want to control the speed of dc motor
long duration, distance;
void setup() {
  // put your setup code here, to run once:
delay(500);
Serial.begin(9600);
pinMode(acleft4, 1);
pinMode(cleft5, 1);
pinMode(acright6, 1);
pinMode(cright7, 1);
pinMode(trigPin, 1);
pinMode(echoPin, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, 0);
delayMicroseconds(2);   
digitalWrite(trigPin, 1);
delayMicroseconds(10);
duration = pulseIn(echoPin, 1);
distance = duration / 58.2;
delay(10);
Serial.println(distance);
analogWrite(pwm,110);   // Use only if you want to control the speed of dc motor
analogWrite(pwm1,110);   // Use only if you want to control the speed of dc motor
if (distance > 19)            
  {
    digitalWrite(cright7, 1);  // moving foward
    digitalWrite(acright6, 0);
    digitalWrite(cleft5, 1);                                
    digitalWrite(acleft4, 0);                                                       
  }
  if (distance < 18)
  {
    digitalWrite(cright7, 0);  // stoping             
    digitalWrite(acright6, 0);
    digitalWrite(cleft5, 0);                                
    digitalWrite(acleft4, 0);
    delay(500);
    digitalWrite(cright7, 0);  //moving backwards        
    digitalWrite(acright6, 1);
    digitalWrite(cleft5, 0);                                
    digitalWrite(acleft4, 1);
    delay(1100);
    digitalWrite(cright7, 0);  //stoping               
    digitalWrite(acright6, 0);
    digitalWrite(cleft5, 0);                                
    digitalWrite(acleft4, 0);  
    delay(500);  
    digitalWrite(cright7, 1);  //turning clockwise     
    digitalWrite(acright6, 0);   
    digitalWrite(acleft4, 1);                                 
    digitalWrite(cleft5, 0);  
    delay(1100);
  }
}

