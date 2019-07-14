const int Trigger = 12;
const int Eco = 13;

const int Left_Forward = 2;
const int Left_Backwards = 3;
const int Right_Forward = 4;
const int Right_Backwards = 5;

void setup() {
  pinMode(Left_Forward, OUTPUT);
  pinMode(Left_Backwards, OUTPUT);
  pinMode(Right_Forward, OUTPUT);
  pinMode(Right_Backwards, OUTPUT);

  pinMode(Trigger, OUTPUT);
  pinMode(Eco, INPUT);

  Serial.begin(9600);
  Serial.println("Starting The Obstacle Avoidance Car I Hope This Works.");
}

void loop() {
  Forward();
  
  long Duration, Distance;
  
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  Duration = pulseIn(Eco, HIGH);
  Distance = (Duration/2)/29.1;

  if (Distance < 20) {
    Backwards();
    delay(1000);
    Right();
    delay(1000);
  }

}

void Forward() {
  Serial.println("Going Forward");
  digitalWrite(Left_Forward, HIGH);
  digitalWrite(Left_Backwards, LOW);
  digitalWrite(Right_Forward, HIGH);
  digitalWrite(Right_Backwards, LOW);
}

void Backwards() {
  Serial.println("Going Backwards");
  digitalWrite(Left_Forward, LOW);
  digitalWrite(Left_Backwards, HIGH);
  digitalWrite(Right_Forward, LOW);
  digitalWrite(Right_Backwards, HIGH);
}

void Right() {
  Serial.println("Going Right");
  digitalWrite(Left_Forward, LOW);
  digitalWrite(Left_Backwards, HIGH);
  digitalWrite(Right_Forward, HIGH);
  digitalWrite(Right_Backwards, LOW);
}
