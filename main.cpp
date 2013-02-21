/*
 * This basic example sets a multi-use pin to GPIO, and then toggles the pin
 *  on and off. In this example, an LED is tied to the toggling pin.
 *
 * To use an LED, connect the cathode (negative) to P3-1 (ground), and the
 * anode (positive) to P2-15 (Module pin 16)
 *
 */

#include "predef.h"
#include <stdio.h>
#include <ctype.h>
#include <startnet.h>
#include <autoupdate.h>
#include <dhcpclient.h>
#include <pins.h>

extern "C" {
	void UserMain(void * pd);
}

const char * AppName = "Blink";

void UserMain(void * pd) {
	// Stock initialization code
	InitializeStack();
	if (EthernetIP == 0)
		GetDHCPAddress();
	OSChangePrio(MAIN_PRIO);
	EnableAutoUpdate();

	Pins[16].function(PIN_16_GPIO);		// Set module Pin 16 to GPIO

	while (1) {							// Main Loop
		Pins[16] = 1;					// Toggle Pin 16 HIGH
		OSTimeDly(TICKS_PER_SECOND);	// Wait 1 second
		Pins[16] = 0;					// Toggle Pin 16 LOW
		OSTimeDly(TICKS_PER_SECOND);	// Wait 1 second
	}
}
