/*
    Twilight LEDs

    An Arduino script used to make a Fade-in / Fade-Out effect with two LEDs.
    We synchronise the Fade effect to have one LED fading out while the other is fading in.
*/

int redLed = 9;      // the PWM pin the red LED is attached to
int greenLed = 10;   // the PWM pin the green LED is attached to
int brightness = 0;  // how bright the LED  should be
int fadeAmount = 5;  // how many points to fade the LED by


void setup() {
  // Set both Pins to be OUTPUT pins (we send data to it)
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}


void loop() {
  // to the Red LED, we add the current brightness value (0-255)
  // to the Green LED, we add the inverse value added to 255
  analogWrite(redLed, brightness);
  // We add the 255 in order to make it appear "synchronous"
  // A lag appeared with the value of Brightness going to 0 for both LEDs
  analogWrite(greenLed, -brightness+255);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
