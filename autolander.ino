/* Switch to a console and send a command to install my usual stuff */

/* Based on https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardMessage
   and https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardLogout
*/

/* Intended for the Arduino Micro.
   Pinout at https://content.arduino.cc/assets/Pinout-Micro_latest.png
 */

#include "Keyboard.h"

const int Step_Button_Pin = 0;
const int Go_Button_Pin = 1;
const int LED_pin_base = 2;

int selection = 0;

/* TODO: debounce all the buttons together: take a reading only when none of them has changed in the debounce interval */
unsigned long last_step_debounce_time = 0;
unsigned long last_go_debounce_time = 0;
unsigned long debounce_delay = 50;

int previous_step_button_state = HIGH;
int previous_go_button_state = HIGH;
int done = 0;

int digits[16] = {
                  0b00111111,   /* 0 */
                  0x00000110,   /* 1 */
}

void display_selection() {
  int segment;
  for (segment = 0; segment < 8; segment++) {
  }
}
  
void setup() {
    // make the pushButton pin an input:
    pinMode(buttonPin, INPUT);
    pinMode(ReadyLEDPin, OUTPUT)
    digitalWrite(ReadyLEDPin, HIGH))
    digitalWrite(DoneLEDPin, LOW)
    // initialize control over the keyboard:
    Keyboard.begin();
}

void loop() {
    int buttonState = digitalRead(buttonPin);

    if (buttonState != previousButtonState) {
        last_debounce_time = millis();
        if ((buttonState == HIGH)
            && ((millis() - last_debounce_time) > debounce_delay)
            && !done) {
            digitalWrite(ReadyLEDPin, LOW)
                /* Switch to a console */
                Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F2);
            delay(1000);
            Keyboard.releaseAll();
        
            Keyboard.print(command);
        
            digitalWrite(DoneLEDPin, HIGH);
            done = 1;
        }
        previousButtonState = buttonState;
    }
}

/* put at the end as it was confusing Emacs' indenter for things below it */
char *command = "curl https://raw.githubusercontent.com/hillwithsmallfields/land/trunk/land | sudo python3 - --configuration https://raw.githubusercontent.com/hillwithsmallfields/land/trunk/config-%x.json\n"
