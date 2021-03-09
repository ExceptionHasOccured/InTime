# Software Code
This section of the documentation explains the code of the device in a psuedo-code style.

## Variables, Including Libraries and Defining Pins
```
// Importing library
#include <terminal.h>

// Channels of RGB LED
#define RGB_red 
#define RGB_green 
#define RGB_blue 

// LEDs representing 250 millisecond intervals
#define LED_1 
#define LED_2 
#define LED_3 
#define LED_4 

// The buzzer
#define BUZZER 

// Various counters
int timeElapsed = 0; // Total time elapsed
int milliCount = 0; // Milliseconds elapsed in a second, resets at 1000
int buzzerCount = 0; // Milliseconds elapsed over a 10 seconds period, resets at 10000

// Time until auto stop
int timeLimit = 60000;
```

## void setup()
Runs once on program start
### Code
```
void setup() {
	// Setup output for Channels of RGB LED
	pinMode(RGB_red, OUTPUT);
	pinMode(RGB_green, OUTPUT);
	pinMode(RGB_blue, OUTPUT);
	
	// Setup output for 250 milli. LEDs
	pinMode(LED_1, OUTPUT);
	pinMode(LED_2, OUTPUT);
	pinMode(LED_3, OUTPUT);
	pinMode(LED_4, OUTPUT);

	// Setup output for buzzer
	pinMode(BUZZER, OUTPUT);

	// Setup serial monitor
	Serial.begin(9600);
}
```