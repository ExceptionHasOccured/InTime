# Terminal Commands
This section of the documentation outlines the correct commands to be used within the Serial Monitor.

## timer -s
Starts the timer.
*terminal()* returns the value *start:0* which is interpreted by the main code in *void loop()*.
### Interations
- Updates variable *timerActive* to be true
- Allows 1 to be added to variables *milliCount*, *timeElapsed* and *buzzerTime* every millisecond
- Changes RGB led from blue to green

## timer -e
Force ends the timer.
*terminal()* returns the value *interupt:0* which is interpreted by the main code in *void loop()*.
### Interactions
- Updates variable *timerActive* to be false
- Prevents 1 to be added to variables *milliCount*, *timeElapsed* and *buzzerTime* every millisecond
- Sets variables *milliCount*, *timeElapsed* and *buzzerTime* to 0
- Changes RGB led from green to blue

## timer -t int
Set the variable *timeLimit* to the value in the place of int.
*terminal()* returns the value *setTime:int* (int being the secong argument) which is interpreted by the main code in *void loop()*.