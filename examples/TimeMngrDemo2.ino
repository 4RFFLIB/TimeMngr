#include <TimeMngr.h>

//TimeMngr library is using Signals library.

void myTmr1_lapse(){
  Serial.println("myTmr1 Lapse");
}

//create a timer with 1000ms interval, enable = true, attach callback function
TimeMngr  myTmr1(1000, true, myTmr1_lapse);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myTmr1.tickWithCallback();
}
