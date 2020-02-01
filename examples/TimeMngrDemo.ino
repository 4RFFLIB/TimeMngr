#include <TimeMngr.h>

//TimeMngr library is using Signals library.

//create a timer with 1000ms interval with enable = true
TimeMngr  myTmr1(1000, true);

//create a timer object
TimeMngr  myTmr2 = TimeMngr();

void myTmr1_lapse(){
  Serial.println("myTmr1 Lapse");
}

void myTmr2_lapse(){
  Serial.println("myTmr2 Lapse");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myTmr2.setInterval(300);
  myTmr2.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  myTmr1.tick();
  myTmr2.tick();
  
  myTmr1.SignalTimeout.connect(myTmr1_lapse);
  myTmr2.SignalTimeout.connect(myTmr2_lapse);
}
