/*

Isha Kanu
Design Challenge #3
Joel Swanson
ATLS 5410-002
 
 */


#include <Adafruit_CircuitPlayground.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

#define CAP_THRESHOLD   65 

/**Setting up the ability to read capactive touch on the Circuit Playgroun**/
boolean capButton(uint8_t pad) {
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) {
    return true;
  } else {
    return false;
  }
}

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600); // Starting the serial monitor
  CircuitPlayground.begin(); // Initializing the Circuit Playground
  myservo.attach(A10);  // attaches the servo to pin A10 on the circuit playground

}

void loop() {

  if (capButton(6)) { // if the 6 pin is activated through capactive touch
    Serial.println("Pin 6 activated - bottom of the cone");
    
    
    for (int i = 0 ; i < 10; i++) {// loop through all of the LEDs and turn them on
      CircuitPlayground.setPixelColor(i, 0, 75, 255); // light blue colour
    }
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15); 
    }

  } else { // if pin 6 is not activated turn off all of the LEDS
    CircuitPlayground.clearPixels();
  }

    if (capButton(9)) {// if the 9 pin is activated through capactive touch
    Serial.println("Pin 9 activated - top of the cone");
    
    for (int i = 0 ; i < 10; i++) { // loop through all of the LEDs and turn them on
      CircuitPlayground.setPixelColor(i, 255, 0, 200); // light pink 
    }
    
    
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);
      }

  } else { // if not turn off all of the LEDS
    CircuitPlayground.clearPixels();
  }

}
