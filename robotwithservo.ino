#include <Servo.h>
Servo servoMotor1;
int posServo1 = 0;

double channel[6];

int motor1pin1 = 2; // IN1
int motor1pin2 = 3; // IN2

int motor2pin1 = 4; // IN3
int motor2pin2 = 5; // IN4

int MotorPWM;

void setup() {
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  Serial.begin(9600);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  servoMotor1.attach(7);   
}

void loop() {
  channel[0] = pulseIn(8, HIGH);
  channel[1] = pulseIn(9, HIGH);
  channel[2] = pulseIn(10, HIGH);
  channel[3] = pulseIn(11, HIGH);
  channel[4] = pulseIn(12, HIGH);
  channel[5] = pulseIn(13, HIGH);
  
  Serial.print(channel[0]);
  Serial.print(" - ");
  Serial.print(channel[1]);
  Serial.print(" - ");
  Serial.print(channel[2]);
  Serial.print(" - ");
  Serial.print(channel[3]);
  Serial.print(" - ");
  Serial.print(channel[4]);
  Serial.print(" - ");
  Serial.println(channel[5]);

  if(channel[1] > 1550){
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
  }
  if(channel[1] < 1450){
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
  }
  if(channel[1] > 1450 && channel[1] < 1550){
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW); 
  }
  if(channel[1] > 1450 && channel[1] < 1550 && channel[0] < 1450){
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH); 
  }
  if(channel[1] > 1450 && channel[1] < 1550 && channel[0] > 1550){
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);

      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW); 
  }
  if((channel[3] >= 1450) && (channel[3] <= 1550)){
    posServo1 = 90;
    servoMotor1.write(posServo1);
  }
  else if(channel[3]<1400){
    for(int i = 90; posServo1 < 180; posServo1 ++){
      servoMotor1.write(posServo1);
      i = posServo1;
      delay(10);     
    }                       
  }
  else if(channel[3]>1600){
    for(int i = 90; posServo1 > 0; posServo1 --){
      servoMotor1.write(posServo1);
      i = posServo1;
      delay(10);        
    }     
  }
}
