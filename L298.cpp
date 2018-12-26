/* L298.cpp - L298 DC Motor Control Library
 * 
 */

#include "Arduino.h"
#include "L298.h"

/* L298
 * 
 * Description
 *   L298 DC motor control.
 * 
 *   L298 ()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
L298::L298() {
}

/* attach
 * 
 * Description
 *   Attach motor.
 * 
 *   motor.attach(byte in1_pin, byte in2_pin, byte in3_pin, byte in4_pin)
 * 
 * Parameters
 *   byte in1_pin
 *   byte in2_pin
 *   byte in3_pin
 *   byte in4_pin
 * 
 * Returns
 *   void
 */
void L298::attach(byte in1_pin, byte in2_pin, byte in3_pin, byte in4_pin) {
  pinMode(in1_pin, OUTPUT);
  pinMode(in2_pin, OUTPUT);
  pinMode(in3_pin, OUTPUT);
  pinMode(in4_pin, OUTPUT);
  _speedA = 100;  // Percent
  _speedB = 100;  // Percent
  _in1_pin = in1_pin;
  _in2_pin = in2_pin;
  _in3_pin = in3_pin;
  _in4_pin = in4_pin;
  _straightA = true;
  _straightB = true;
  stop();
}

/* stop
 * 
 * Description
 *   Stop motors.
 * 
 *   motor.stop()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::stop() {
  stopA();
  stopB();
}

/* stopA
 * 
 * Description
 *   Stop motor A.
 * 
 *   motor.stopA()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::stopA() {
  _speedA = 0;
  digitalWrite(_in1_pin, HIGH);
  digitalWrite(_in2_pin, HIGH);
}

/* stopB
 * 
 * Description
 *   Stop motor B.
 * 
 *   motor.stopB()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::stopB() {
  _speedB = 0;
  digitalWrite(_in3_pin, HIGH);
  digitalWrite(_in4_pin, HIGH);
}

/* direct
 * 
 * Description
 *   Start motors to run directly.
 * 
 *   motor.direct()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::direct(byte speed) {
  directA(speed);
  directB(speed);
}

/* directA
 * 
 * Description
 *   Start motor A to run directly.
 * 
 *   motor.directA()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::directA(byte speed) {
  _straightA = true;
  _speedA = (speed * 255) / 100;
  analogWrite(_in1_pin, _speedA);
  analogWrite(_in2_pin, 0);
}

/* directB
 * 
 * Description
 *   Start motor B to run directly.
 * 
 *   motor.directB()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::directB(byte speed) {
  _straightB = true;
  _speedB = (speed * 255) / 100;
  analogWrite(_in3_pin, _speedB);
  analogWrite(_in4_pin, 0);
}

/* reverse
 * 
 * Description
 *   Start motors to run reversly.
 * 
 *   motor.reverse()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::reverse(byte speed) {
  reverseA(speed);
  reverseB(speed);
}

/* reverseA
 * 
 * Description
 *   Start motor A to run reversly.
 * 
 *   motor.reverseA()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::reverseA(byte speed) {
  _straightA = false;
  _speedA = (speed * 255) / 100;
  analogWrite(_in1_pin, 0);
  analogWrite(_in2_pin, _speedA);
}

/* reverseB
 * 
 * Description
 *   Start motor B to run reversly.
 * 
 *   motor.reverseB()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::reverseB(byte speed) {
  _straightB = false;
  _speedA = (speed * 255) / 100;
  analogWrite(_in3_pin, 0);
  analogWrite(_in4_pin, _speedA);
}

/* getDirectionA
 * 
 * Description
 *   Get motor A direction.
 * 
 *   motor.getDirectionA()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   bool
 */
bool L298::getDirectionA() {
  return _straightA;
}

/* getDirectionB
 * 
 * Description
 *   Get motor B direction.
 * 
 *   motor.getDirectionB()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   bool
 */
bool L298::getDirectionB() {
  return _straightB;
}

/* getSpeedA
 * 
 * Description
 *   Get motor B direction.
 * 
 *   motor.getSpeedA()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   byte
 */
byte L298::getSpeedA() {
  return _speedA;
}

/* getSpeedB
 * 
 * Description
 *   Get motor B direction.
 * 
 *   motor.getSpeedB()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   byte
 */
byte L298::getSpeedB() {
  return _speedB;
}
