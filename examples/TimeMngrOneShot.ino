#include <TimeMngr.h>

#define led 13
TimeMngr ledFlasher;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(13, OUTPUT);
  ledFlasher.enableOneShotMode();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    uint8_t c = Serial.read();
    if (c == 'q') {
      ledFlasher.setInterval(100);
      ledFlasher.startOneShot(ledOn, ledOff);
    }
    else if (c == 'w') {
      ledFlasher.setInterval(1000);
      ledFlasher.startOneShot(ledOn, ledOff);
    }
  }
  ledFlasher.tickWithCallback();
}

void ledOn() {
    digitalWrite(13, HIGH);
}

void ledOff() {
    digitalWrite(13, LOW);
}
