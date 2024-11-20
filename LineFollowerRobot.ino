// Motor I
int motor1P1 = 27;
int motor1P2 = 26;
int enable1 = 14;
int motor1IR = 34;
int motor1IRValue = 0;

// Motor II
int motor2P1 = 25;
int motor2P2 = 33;
int enable2 = 32;
int motor2IR = 35;
int motor2IRValue = 0;

// Setting PWM properties
const int freq = 30000;
const int pwm1 = 0;
const int pwm2 = 1;
const int resolution = 8;
int dutyCycle1 = 160;
int dutyCycle2 = 170;

void setup() {
  // sets the pins as outputs:
  pinMode(motor1P1, OUTPUT);
  pinMode(motor1P2, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(motor1IR, INPUT_PULLUP);

  pinMode(motor2P1, OUTPUT);
  pinMode(motor2P2, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(motor2IR, INPUT_PULLUP);

  // configure LED PWM functionalities
  ledcSetup(pwm1, freq, resolution);
  ledcSetup(pwm2, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1, pwm1);
  ledcAttachPin(enable2, pwm2);

  ledcWrite(pwm1, dutyCycle1);
  ledcWrite(pwm2, dutyCycle2);

  Motor1Forward();
  Motor2Forward();
}

void loop() {
  motor1IRValue = digitalRead(motor1IR);
  if(motor1IRValue == LOW) {
    dutyCycle1 = dutyCycle1 - 20;
    ledcWrite(pwm1, dutyCycle1);  // Corrected line
  } else {    
    Motor1Forward();
    dutyCycle1 = dutyCycle1 + 20;
    ledcWrite(pwm1, dutyCycle1);
  }

  motor2IRValue = digitalRead(motor2IR);
  if(motor2IRValue == LOW) {
    dutyCycle2 = dutyCycle2 - 20;
    ledcWrite(pwm2, dutyCycle2);
  } else {
    dutyCycle2 = dutyCycle2 + 20;
    ledcWrite(pwm2, dutyCycle2);
  }
}

void Motor1Forward() {  
  digitalWrite(motor1P1, LOW);
  digitalWrite(motor1P2, HIGH);
}

void Motor2Forward() {  
  digitalWrite(motor2P1, LOW);
  digitalWrite(motor2P2, HIGH);
}

void Motor1Stop() {  
  digitalWrite(motor1P1, LOW);
  digitalWrite(motor1P2, LOW);
}

void Motor2Stop() {  
  digitalWrite(motor2P1, LOW);
  digitalWrite(motor2P2, LOW);
}
