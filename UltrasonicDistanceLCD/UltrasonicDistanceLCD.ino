#include <LiquidCrystal.h>

LiquidCrystal LCD(1, 2, 4, 5, 6, 7);


const int trigPin = 9;
const int echoPin = 10;

long duration;
double distance;

void setup() {
  LCD.begin(16,2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  LCD.print("Distance: ");
  LCD.print(distance,1);
  LCD.print("cm");
  LCD.setCursor(0,0);
  delay(100);
}
