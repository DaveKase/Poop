int mootor_1_a=2;
int mootor_1_b=3;
int mootor_2_a=4;
int mootor_2_b=5;

int motor1Pwm = 6;
int motor2Pwm = 7;
int mSpeed = 0;

void setup() {
  pinMode(mootor_1_a,OUTPUT);
  pinMode(mootor_1_b,OUTPUT);
  pinMode(mootor_2_a,OUTPUT);
  pinMode(mootor_2_b,OUTPUT);

  pinMode(motor1Pwm,OUTPUT);
  pinMode(motor2Pwm,OUTPUT);
}

void mootor_1_forward(int mSpeed){
  digitalWrite(mootor_1_a, LOW);
  digitalWrite(mootor_1_b, HIGH);
  setMotor1Speed(mSpeed);
}

void mootor_1_backward(int mSpeed){
  digitalWrite(mootor_1_b, LOW);
  digitalWrite(mootor_1_a, HIGH);
  setMotor1Speed(mSpeed);
}

void mootor_1_stop(){
  digitalWrite(mootor_1_a, LOW);
  digitalWrite(mootor_1_b, LOW);
  setMotor1Speed(0);
}

void mootor_2_forward(int mSpeed){
  digitalWrite(mootor_2_a, LOW);
  digitalWrite(mootor_2_b, HIGH);
  setMotor2Speed(mSpeed);
}

void mootor_2_backward(int mSpeed){
  digitalWrite(mootor_2_b, LOW);
  digitalWrite(mootor_2_a, HIGH);
  setMotor2Speed(mSpeed);
}

void mootor_2_stop(){
  digitalWrite(mootor_2_a, HIGH);
  digitalWrite(mootor_2_b, HIGH);
  setMotor2Speed(0);
}

void setMotor1Speed(int mSpeed) {
  analogWrite(motor1Pwm, mSpeed);
}

void setMotor2Speed(int mSpeed) {
  analogWrite(motor2Pwm, mSpeed);
}

void loop() {
  mootor_1_stop();
  mootor_2_stop();
  delay(3000);

  mSpeed = 2;
  //for(mSpeed = 0; mSpeed < 255; mSpeed += 10)
  //{
    mootor_1_forward(mSpeed);
    delay(3000);
  //}

  
  mootor_1_stop();
  delay(1000);
  mootor_1_backward(mSpeed);
  delay(3000);
  mootor_1_stop();
  delay(1000);

  mSpeed = 2;
  mootor_2_forward(mSpeed);
  delay(3000);
  mootor_2_stop();
  delay(1000);
  mootor_2_backward(mSpeed);
  delay(3000);
  mootor_2_stop();
  delay(1000);
}
