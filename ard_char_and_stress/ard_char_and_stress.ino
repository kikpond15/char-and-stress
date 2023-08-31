#include <Servo.h>
Servo servo;
int cds, volum;
void setup() {
  Serial.begin(9600);
  servo.attach(6, 500, 2400);
  pinMode(3, OUTPUT);
}
void loop() {
  cds = analogRead(A0);
  volum = 1023 - analogRead(A1);
  print_info();
  if (cds <  volum) {
    spin_servo();
    delay(3000);
    knock_solenoid(10, 200);
  }
}

void spin_servo() {
  servo.write(0);
  delay(800);
  servo.write(90);
}

void knock_solenoid(int count, int t) {
  for (int i = 0; i < count; i++) {
    digitalWrite(3, HIGH);
    delay(50);
    digitalWrite(3, LOW);
    delay(t);
  }
}

void print_info() {
  Serial.print("cds:");
  Serial.print(cds);
  Serial.print(",  vol:");
  Serial.println(volum);
}
