// Channels of RGB LED
#define RGB_red 10
#define RGB_green 9 
#define RGB_blue 11

// LEDs representing 250 millisecond intervals
#define LED_1 3
#define LED_2 4
#define LED_3 5
#define LED_4 6

// The buzzer
#define BUZZER 13

// Various counters
int timeElapsed = 0; // Total time elapsed
int milliCount = 0; // Milliseconds elapsed in a second, resets at 1000
int buzzerCount = 0; // Milliseconds elapsed over a 10 seconds period, resets at 10000

//
bool isCounting = true;

// Time until auto stop
int timeLimit = 60000;

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

  Serial.begin(9600);
}

void loop() {
  if(isCounting){
    setRGB(0, 255, 0);
    timeElapsed += 50;
    milliCount += 50;
    buzzerCount += 50;

    // Colouring the four LEDs
    if(milliCount >= 0 && milliCount <=249){
      setFourLED(1);
    }
    else if(milliCount >= 250 && milliCount <=499){
      setFourLED(2);
    }
    else if(milliCount >= 500 && milliCount <=749){
      setFourLED(3);
    }
    else if(milliCount >= 750 && milliCount <=1000){
      setFourLED(4);
    }

    // Controlling the buzzer
    if(buzzerCount == 1000 ||
      buzzerCount == 2000 ||
      buzzerCount == 3000 ||
      buzzerCount == 4000 ||
      buzzerCount == 5000 ||
      buzzerCount == 6000 ||
      buzzerCount == 7000 ||
      buzzerCount == 8000 ||
      buzzerCount == 9000) {
      analogWrite(BUZZER, 150);
    }
    else if(buzzerCount == 10000){
      analogWrite(BUZZER, 255);
    }
    else {
      analogWrite(BUZZER, 0);
    }

    // Checking the values of variables
    if(milliCount == 1000){
      milliCount = 0;
    }
    if(buzzerCount == 10000){
      buzzerCount = 0;
    }

    // Has the timer finished counting
    if(timeElapsed == timeLimit){
      isCounting = false;
      setRGB(255, 0, 0);
      delay(500);
      buzzerCount = 0;
      setRGB(0, 0, 0);
      delay(500);
      setRGB(0, 0, 255);
      Serial.println("Timer has finished counting");
    }
    else {
      delay(50);
      Serial.println("[ timeElapsed: " + String(timeElapsed) + ", milliCount: " + String(milliCount) + ", buzzerCount: " + String(buzzerCount) + " ]");
    }
  }
  else {
    setRGB(0, 0, 255);
  }
}

void setRGB(int a, int b, int c){
  analogWrite(RGB_red, a);
  analogWrite(RGB_green, b);
  analogWrite(RGB_blue, c);
}

void setFourLED(int i){
  if(i == 1){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
  else if(i == 2){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
  else if(i == 3){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, LOW);
  }
  else if(i == 4){
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
  }
}
