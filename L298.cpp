/* L298.cpp - L298 DC motor control
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
  // Direct
  digitalWrite(_in1_pin, HIGH);
  digitalWrite(_in2_pin, HIGH);
  digitalWrite(_in3_pin, HIGH);
  digitalWrite(_in4_pin, HIGH);
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
  // Direct
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
  // Direct
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
  _speedA = (speed * 255) / 100;
  _speedB = _speedA;
  analogWrite(_in1_pin, _speedA);
  analogWrite(_in2_pin, 0);
  analogWrite(_in3_pin, _speedB);
  analogWrite(_in4_pin, 0);
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
  _speedA = (speed * 255) / 100;
  _speedB = _speedA;
  analogWrite(_in1_pin, 0);
  analogWrite(_in2_pin, _speedA);
  analogWrite(_in3_pin, 0);
  analogWrite(_in4_pin, _speedB);
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
  _speedA = (speed * 255) / 100;
  analogWrite(_in3_pin, 0);
  analogWrite(_in4_pin, _speedA);
}
