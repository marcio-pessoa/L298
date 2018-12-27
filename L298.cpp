/* L298.cpp - L298 Dual Full-Bridge Driver Control Library
 * 
 */

#include "Arduino.h"
#include "L298.h"

/* L298
 * 
 * Description
 *   L298 Dual Full-Bridge Driver Control.
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
  _a1 = 0;
  _a2 = 0;
  _b1 = 0;
  _b2 = 0;
}

/* attach
 * 
 * Description
 *   Attach pins.
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
  _in1_pin = in1_pin;
  _in2_pin = in2_pin;
  _in3_pin = in3_pin;
  _in4_pin = in4_pin;
  update();
}

/* update
 * 
 * Description
 *   Update driver Output.
 * 
 *   motor.update()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::update() {
  digitalWrite(_in1_pin, _a1);
  digitalWrite(_in2_pin, _a2);
  digitalWrite(_in3_pin, _b1);
  digitalWrite(_in4_pin, _b2);
}

/* stopA
 * 
 * Description
 *   Stop Output A.
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
  _a1 = 0;
  _a2 = 0;
  update();
}

/* stopB
 * 
 * Description
 *   Stop Output B.
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
  _b1 = 0;
  _b2 = 0;
  update();
}

/* directA
 * 
 * Description
 *   Start a Conventional electric current on Output A.
 * 
 *   motor.directA()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::directA(byte delta) {
  _a1 = delta;
  _a2 = 0;
  update();
}

/* directB
 * 
 * Description
 *   Start a Conventional electric current on Output B.
 * 
 *   motor.directB()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::directB(byte delta) {
  _b1 = delta;
  _b2 = 0;
  update();
}

/* reverseA
 * 
 * Description
 *   Start a Real electric current on Output A.
 * 
 *   motor.reverseA()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::reverseA(byte delta) {
  _a1 = 0;
  _a2 = delta;
  update();
}

/* reverseB
 * 
 * Description
 *   Start a Real electric current on Output B.
 * 
 *   motor.reverseB()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::reverseB(byte delta) {
  _b1 = 0;
  _b2 = delta;
  update();
}

/* speedA
 * 
 * Description
 *   Set motor A speed.
 * 
 *   motor.speedA()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::setDeltaA(byte delta) {
  if (getDirectionA()) {
    directA(delta);
  }
  else {
    reverseA(delta);
  }
}

/* speedB
 * 
 * Description
 *   Set motor B speed.
 * 
 *   motor.speedB()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void L298::setDeltaB(byte delta) {
  if (getDirectionB()) {
    directB(delta);
  }
  else {
    reverseB(delta);
  }
}

/* getDirectionA
 * 
 * Description
 *   Get Output A electric current direction.
 * 
 *   motor.getDirectionA()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   true: Conventional electric current flow
 *   false: Real electric current flow
 */
bool L298::getDirectionA() {
  return direction(_a1, _a2);
}

/* getDirectionB
 * 
 * Description
 *   Get Output B electric current direction.
 * 
 *   motor.getDirectionB()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   true: Conventional electric current flow
 *   false: Real electric current flow
 */
bool L298::getDirectionB() {
  return direction(_b1, _b2);
}

/* getDeltaA
 * 
 * Description
 *   Get delta in Output A.
 * 
 *   motor.getDeltaA()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   byte
 */
byte L298::getDeltaA() {
  return delta(_a1, _a2);
}

/* getDeltaB
 * 
 * Description
 *   Get delta in Output B.
 * 
 *   motor.getDeltaB()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   byte
 */
byte L298::getDeltaB() {
  return delta(_b1, _b2);
}

/* delta
 * 
 * Description
 *   Calculate delta.
 * 
 *   delta()
 * 
 * Parameters
 *   x
 *   y
 * 
 * Returns
 *   byte
 */
byte delta(byte x, byte y) {
  if (x > y) {
    return x - y;
  }
  else {
    return y - x;
  }
}

/* direction
 * 
 * Description
 *   Calculate direction.
 * 
 *   direction()
 * 
 * Parameters
 *   x
 *   y
 * 
 * Returns
 *   byte
 */
byte direction(byte x, byte y) {
  if (x > y) {
    return true;
  }
  else {
    return false;
  }
}
