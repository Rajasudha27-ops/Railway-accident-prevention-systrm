#define TRIG 3
#define ECHO 4

#define IN1 5
#define IN2 6
#define ENA 9

long duration;
int distance;

void setup() {

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH, 30000);

  if (duration == 0) {
    distance = 999;
  } else {
    distance = duration * 0.034 / 2;
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) {

    // Stop model train
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);

    Serial.println("OBSTACLE DETECTED");
    Serial.println("TRAIN STOPPED");

  }

  else {

    // Start model train
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 150);

    Serial.println("TRACK CLEAR");
    Serial.println("TRAIN RUNNING");
  }

  delay(100);
}
