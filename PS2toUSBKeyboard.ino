/* PS2Keyboard library example
 * 
 * PS2Keyboard now requries both pins specified for begin()
 *
 * keyboard.begin(data_pin, irq_pin);
 * 
 * Valid irq pins:
 *     Arduino Uno:  2, 3
 *     Arduino Due:  All pins, except 13 (LED)
 *     Arduino Mega: 2, 3, 18, 19, 20, 21
 *     Teensy 2.0:   All pins, except 13 (LED)
 *     Teensy 2.0:   5, 6, 7, 8
 *     Teensy 1.0:   0, 1, 2, 3, 4, 6, 7, 16
 *     Teensy++ 2.0: 0, 1, 2, 3, 18, 19, 36, 37
 *     Teensy++ 1.0: 0, 1, 2, 3, 18, 19, 36, 37
 *     Sanguino:     2, 10, 11
 * 
 * for more information you can read the original wiki in arduino.cc
 * at http://www.arduino.cc/playground/Main/PS2Keyboard
 * or http://www.pjrc.com/teensy/td_libs_PS2Keyboard.html
 * 
 * Like the Original library and example this is under LGPL license.
 * 
 * Modified by Cuninganreset@gmail.com on 2010-03-22
 * Modified by Paul Stoffregen <paul@pjrc.com> June 2010
 */
   
#include <PS2Keyboard.h>

const int DataPin = 4;
const int IRQpin =  3;

PS2Keyboard keyboard;

void setup() {
    delay(1000);
    keyboard.begin(DataPin, IRQpin);
    Serial.begin(115200);
    Serial.println("Keyboard Test:");
}

void loop() {
    if (keyboard.available()) {

        // read the next key
        char c = keyboard.read();

        
        if(c == PS2_TAB) {
            if (keyboard.altPressed()) {
                Serial.print("[ALT][Tab]");
                Keyboard.press(KEY_LEFT_ALT);
                Keyboard.write(KEY_TAB);
                Keyboard.release(KEY_LEFT_ALT);
            } else if (keyboard.guiPressed()) {
                Serial.print("[GUI][Tab]");
                Keyboard.press(KEY_LEFT_GUI);
                Keyboard.write(KEY_TAB);
                Keyboard.release(KEY_LEFT_GUI);
            } else {
                Serial.print("[Tab]");
                Keyboard.write(KEY_TAB);
            }
        } else if(c == PS2_ENTER) {
            Serial.println("[RETURN]");
            Keyboard.write(KEY_RETURN);
        } else if(c == PS2_BACKSPACE) {
            Serial.println("[BACKSPACE]");
            Keyboard.write(KEY_BACKSPACE);
        } else if(c == PS2_ESC) {
            Serial.println("[ESC]");
            Keyboard.write(KEY_ESC);
        } else if(c == PS2_INSERT) {
            Serial.println("[INSERT]");
            Keyboard.write(KEY_INSERT);
        } else if(c == PS2_DELETE) {
            Serial.println("[DELETE]");
            Keyboard.write(KEY_DELETE);
        } else if(c == PS2_HOME) {
            Serial.println("[HOME]");
            Keyboard.write(KEY_HOME);
        } else if(c == PS2_END) {
            Serial.println("[END]");
            Keyboard.write(KEY_END);
        } else if(c == PS2_PAGEUP) {
            Serial.println("[PAGEUP]");
            Keyboard.write(KEY_PAGE_UP);
        } else if(c == PS2_PAGEDOWN) {
            Serial.println("[PAGEDOWN]");
            Keyboard.write(KEY_PAGE_DOWN);
        } else if(c == PS2_UPARROW) {
            Serial.println("[UPARROW]");
            Keyboard.write(KEY_UP_ARROW);
        } else if(c == PS2_LEFTARROW) {
            Serial.println("[LEFTARROW]");
            Keyboard.write(KEY_LEFT_ARROW);
        } else if(c == PS2_DOWNARROW) {
            Serial.println("[DOWNARROW]");
            Keyboard.write(KEY_DOWN_ARROW);
        } else if(c == PS2_RIGHTARROW) {
            Serial.println("[RIGHTARROW]");
            Keyboard.write(KEY_RIGHT_ARROW);
        } else if(c == PS2_F1) {
            Serial.println("[F1]");
            Keyboard.write(KEY_F1);
        } else if(c == PS2_F2) {
            Serial.println("[F2]");
            Keyboard.write(KEY_F2);
        } else if(c == PS2_F3) {
            Serial.println("[F3]");
            Keyboard.write(KEY_F3);
        } else if(c == PS2_F4) {
            Serial.println("[F4]");
            Keyboard.write(KEY_F4);
        } else if(c == PS2_F5) {
            Serial.println("[F5]");
            Keyboard.write(KEY_F5);
        } else if(c == PS2_F6) {
            Serial.println("[F6]");
            Keyboard.write(KEY_F6);
        } else if(c == PS2_F7) {
            Serial.println("[F7]");
            Keyboard.write(KEY_F7);
        } else if(c == PS2_F8) {
            Serial.println("[F8]");
            Keyboard.write(KEY_F8);
        } else if(c == PS2_F9) {
            Serial.println("[F9]");
            Keyboard.write(KEY_F9);
        } else if(c == PS2_F10) {
            Serial.println("[F10]");
            Keyboard.write(KEY_F10);
        } else if(c == PS2_F11) {
            Serial.println("[F11]");
            Keyboard.write(KEY_F11);
        } else if(c == PS2_F12) {
            Serial.println("[F12]");
            Keyboard.write(KEY_F12);
        } else if(c == PS2_CAPSLOCK) {
            Serial.println("[CAPSLOCK]");
            Keyboard.write(KEY_CAPS_LOCK);
        } else if(c == PS2_NUMLOCK) {
            Serial.println("[NUMLOCK]");
            // Unimplemented in HID??
        }
        else {
            // otherwise, just print all normal characters
            Serial.print("Key: ");
            Serial.println(c);

            if (keyboard.altPressed()) {
                Keyboard.press(KEY_LEFT_ALT);
                Keyboard.write(c);
                Keyboard.release(KEY_LEFT_ALT);
            } else if(keyboard.ctrlPressed()) {
                Keyboard.press(KEY_LEFT_CTRL);
                Keyboard.write(c);
                Keyboard.release(KEY_LEFT_CTRL);
            } else {
                Keyboard.write(c);
            }
            
        }
    }
}


