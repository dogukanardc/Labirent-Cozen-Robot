#include <L298N.h>

#define soltrigPin 2
#define solechoPin 3
#define ortatrigPin 4
#define ortaechoPin 5
#define sagtrigPin 6
#define sagechoPin 7
#define ENA 8
#define ENB 13
#define IN1 9
#define IN2 10
#define IN3 11
#define IN4 12

L298N solmotor(ENA, IN1, IN2);
L298N sagmotor(ENB, IN3, IN4);

void setup() {
  Serial.begin (9600);
  pinMode(sagtrigPin, OUTPUT);
  pinMode(sagechoPin, INPUT);
  pinMode(ortatrigPin, OUTPUT);
  pinMode(ortaechoPin, INPUT);
  pinMode(soltrigPin, OUTPUT);
  pinMode(solechoPin, INPUT);

  solmotor.setSpeed(128);
  sagmotor.setSpeed(128);
}


void loop() {
  long sure1, sag;
  digitalWrite(sagtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sagtrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sagtrigPin, LOW);
  sure1 = pulseIn(sagechoPin, HIGH);
  sag = (sure1 / 2) / 29.1;

  long sure2, orta;
  digitalWrite(ortatrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ortatrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ortatrigPin, LOW);
  sure2 = pulseIn(ortaechoPin, HIGH);
  orta = (sure2 / 2) / 29.1;

  long sure3, sol;
  digitalWrite(soltrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(soltrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(soltrigPin, LOW);
  sure3 = pulseIn(solechoPin, HIGH);
  sol = (sure3 / 2) / 29.1;

  if (sol < 10 and sag < 10 and orta > 10) {
    Serial.println("ileri gider");
    Serial.println(sag);
    Serial.println(orta);
    Serial.println(sol);
    Serial.println();
    solmotor.forward();
    sagmotor.forward();
    delay(500);
    sagmotor.stop();
    solmotor.stop();
  }
  else if (sol > 10 and sag > 10 and orta > 10) {
    Serial.println("BOMBOŞ");
    Serial.println(sag);
    Serial.println(orta);
    Serial.println(sol);
    Serial.println();
  }
  else if (sol < 10 and sag > 10 and orta < 10) {
    Serial.println("sag gider");
    Serial.println(sag);
    Serial.println(orta);
    Serial.println(sol);
    Serial.println();
    solmotor.backward();
    sagmotor.forward();
    delay(200);
    sagmotor.stop();
    solmotor.stop();
  }
  else if (sol > 10 and sag < 10 and orta < 10) {
    Serial.println("sola gider");
    Serial.println(sag);
    Serial.println(orta);
    Serial.println(sol);
    Serial.println();
    solmotor.forward();
    sagmotor.backward();
    delay(200);
    sagmotor.stop();
    solmotor.stop();
  }
  else if (sol > 10 and sag > 10 and orta < 10) {
    long randsayi;
    randsayi = random(1, 10);
    if (randsayi < 5) {
      Serial.println("RANDOM - sola gider");
      Serial.println(sag);
      Serial.println(orta);
      Serial.println(sol);
      Serial.println();
      solmotor.backward();
      sagmotor.forward();
      delay(200);
      sagmotor.stop();
      solmotor.stop();
    }
    if (randsayi > 5) {
      Serial.println("RANDOM - saga gider");
      Serial.println(sag);
      Serial.println(orta);
      Serial.println(sol);
      Serial.println();
      solmotor.forward();
      sagmotor.backward();
      delay(200);
      sagmotor.stop();
      solmotor.stop();
    }
  }
  else if (sol < 10 and sag > 10 and orta > 10) {
    long randsayi;
    randsayi = random(1, 10);
    if (randsayi < 5) {
      Serial.println("RANDOM - saga gider");
      Serial.println(sag);
      Serial.println(orta);
      Serial.println(sol);
      Serial.println();
      solmotor.forward();
      sagmotor.backward();
      delay(200);
      sagmotor.stop();
      solmotor.stop();
    }
    if (randsayi > 5) {
      Serial.println("RANDOM - ortaya gider");
      Serial.println(sag);
      Serial.println(orta);
      Serial.println(sol);
      Serial.println();
      solmotor.forward();
      sagmotor.forward();
      delay(500);
      sagmotor.stop();
      solmotor.stop();
    }
  }
  else if (sol > 10 and sag < 10 and orta > 10) {
    long randsayi;
    randsayi = random(1, 10);
    if (randsayi < 5) {
      Serial.println("RANDOM - sola gider");
      Serial.println(sag);
      Serial.println(orta);
      Serial.println(sol);
      Serial.println();
      solmotor.backward();
      sagmotor.forward();
      delay(200);
      sagmotor.stop();
      solmotor.stop();
    }
    if (randsayi > 5) {
      Serial.println("RANDOM - ortaya gider");
      Serial.println(sag);
      Serial.println(orta);
      Serial.println(sol);
      Serial.println();
      solmotor.forward();
      sagmotor.forward();
      delay(500);
      sagmotor.stop();
      solmotor.stop();
    }
  }
  else if (sol < 10 and sag < 10 and orta < 10) {
    Serial.println("ters gider");
    Serial.println(sag);
    Serial.println(orta);
    Serial.println(sol);
    Serial.println();
    solmotor.forward();
    sagmotor.forward();
    delay(1200);
    sagmotor.stop();
    solmotor.stop();
  }
  
  delay(1000);

}
