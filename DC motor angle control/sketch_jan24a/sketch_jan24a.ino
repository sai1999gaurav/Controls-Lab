float Kp = 50;   // Max deviation = 8-4.5 = 3.5 ||  255/3.5 = 72
float Ki = 0.1;
float Kd = 3;
int potvalue, initangle, targetangle;
//#include <PID_v1.h>
#define potoutput A10
const int motorpin1 = 9;
const int motorpin2 = 10;
const int enable = 6;
float error = 0;
float previousError = 0;
float totalError = 0;
float power = 0;
float avgSensor;
int highval =0;

void PID_program()
{ 
    //readSensor(); 
    previousError = error; // save previous error for differential 
    error = targetangle - potvalue; // Count how much robot deviate from center
    totalError += error; // Accumulate error for integral
    
    power = (Kp*error) + (Kd*(error-previousError)) + (Ki*totalError);
    //Serial.println(power);
    highval = 45 + abs(power*190/(Kp*500));  //65-255
    if(highval>255)
    highval = 255;
    Serial.println(highval);
    if(power>0) // Turn left
    {  
        analogWrite(motorpin1, highval); //high
        digitalWrite(motorpin2, LOW);
    }
    else // Turn right
    {
      analogWrite(motorpin2, highval);
      digitalWrite(motorpin1, LOW);
    }
}

void setup() {
 Serial.begin(9600);
 pinMode(potoutput, INPUT);  // 0 to 1023//  --- (v + 512)%1023
 pinMode(enable, OUTPUT);
 pinMode(motorpin1, OUTPUT);
 pinMode(motorpin2, OUTPUT);
 digitalWrite(enable, HIGH);
 initangle = analogRead(potoutput);
 targetangle = (initangle + 512)%1023;
 Serial.print("Iangle: ");
 Serial.println(initangle);
 Serial.print("tangle: ");
 Serial.println(targetangle);

  // put your setup code here, to run once:

}

void loop() {
  delay(10 );
  potvalue = analogRead(potoutput);
  Serial.print("Angle: ");
  Serial.println(potvalue);
  PID_program();
  //analogWrite(motorpin1, 65);
  //analogWrite(motorpin2, 0);

  
  // put your main code here, to run repeatedly:

}
