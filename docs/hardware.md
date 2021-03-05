# Hardware Setup

This section of the documentation explains the way the hardware is setup and lain out as well as interaction with software.

## Components
- Arduino UNO Board
- 4 Single Colour LEDs
- RGB LED
- Buzzer

## Arduino UNO Board
The microcontroller will be used to send and control electrical signals used by components.

## Single Colour LEDs
These LEDs will be setup in a row of 4 with alternating colours (red and green in this case). The purpose is to indicate time in 1/4 millisecond intervals.
### Interactions
Every millisecond a variable called *milliCount* will increase by 1.

**0 to 250 milsec lapsed:**
- First LED will be turned on
- All else will stay off
**250 to 500 milsec lapsed:**
- First LED will stay on
- Second LED wil be turned on
- All else will stay off
**500 to 750 milsec lapsed:**
- First and second LEDs will stay on
- Third LED wil be turned on
- Fourth LED will stay off
**750 to 999 milsec lapsed:**
- First, second and third LEDs will stay on
- Fourth LED wil be turned on
**1000 milsec lapsed:**
- Variable *milliCount* is set to 0
- All LEDs are turned off

## RGB LED
In the software, the timer will be able to be started, stopped and have a time limit set using commands in the Arduino Serial Monitor (see *Commands* for more information).
### Interations
**Blue light:**
- Waiting to be started
- Listening to any Serial Monitor commands
**Green light:**
- Timer has started counting
- Every millisecond the variable *timeElasped* is increased by one
**Red light, Blinking:**
- Triggered when *timeElasped* equals *timeLimit*
- Stops after 5 seconds
- *timeElapsed* is set to 0

## Buzzer
The buzzer acts as another form of time indication, just on a larger scale that is counted in 10 second periods.
### Interactions
Variable *buzzerTime* increases by 1 every millisecond.
**Every 1 second (*buzzerTime* == 1000, 2000, ..., 9000):**
- Medium pitch
- Quiet
- Short
**Every 10 seconds (*buzzerTime* == 10000):**
- Low pitch
- Loud
- Long
- *buzzerTime* is set to 0

## Footnote
Running this timer for a long period may cause the variables/counter to become desynced with an external timer due to Arduino data transfer rate.