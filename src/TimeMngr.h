// myTimer.h

#ifndef _MYTIMER_h
#define _MYTIMER_h

#include "Signals.h"

class TimeMngr
{
 protected:
	 unsigned long pMills = 0;
	 unsigned long	interval;
	 bool enable = false;

 public:
	Signals<> SignalTimeout;

	TimeMngr() {
		enable = false;
	}

	TimeMngr(unsigned long intervalMs, bool tmrStart)
	{
		interval = intervalMs;
		pMills = millis();
		enable = tmrStart;
	}

	void setInterval(unsigned long milisec) {
		interval = milisec;
	}

	void start(void) {
		enable = true;
		pMills = millis();
	}

	void stop(void) {
		enable = false;
	}

	void tick(void) {
		if (enable) {
			unsigned long cMills = millis();
			if (cMills - pMills >= interval) {
				pMills = cMills;
				SignalTimeout.emit();
			}
		}
	}
};

#endif

