double channel[6];

int motor1pin1 = 8; // IN1
int motor1pin2 = 9; // IN2

int motor2pin1 = 10; // IN3
int motor2pin2 = 11; // IN4

int MotorPWM;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}

void loop() {
  channel[0] = pulseIn(2, HIGH);
  channel[1] = pulseIn(3, HIGH);
  channel[2] = pulseIn(4, HIGH);
  channel[3] = pulseIn(5, HIGH);
  channel[4] = pulseIn(6, HIGH);
  channel[5] = pulseIn(7, HIGH);
  
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
      delay(1000);
  }
  if(channel[1] < 1450){
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
      delay(1000);
  }
  
  if(channel[1] > 1450 && channel[1] < 1550){
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
      delay(1000);
  }  

}
 
