/* L298.h - L298 Dual Full-Bridge Driver Control Library
 *
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 *
 * Change log
 * 2019-02-12
 *         Fixed: Speed control was not working.
 *
 * 2018-12-26
 *         Added: setDeltaA() and setDeltaB() methods.
 *
 * 2018-12-25
 *         Added: getDeltaA() and getDeltaB() methods.
 *
 * 2018-12-24
 *         Added: getDirectionA() and getDirectionB() methods.
 *
 * 2017-11-04
 *         Experimental version.
 */

#ifndef L298_h
#define L298_h

#include "Arduino.h"

class L298
{
  public:
    L298();
    void attach(byte in1_pin, byte in2_pin,
                byte in3_pin=false, byte in4_pin=false);
    void stopA();
    void stopB();
    void directA(byte speed=255);
    void directB(byte speed=255);
    void reverseA(byte speed=255);
    void reverseB(byte speed=255);
    void setDeltaA(byte speed);
    void setDeltaB(byte speed);
    byte getDeltaA();
    byte getDeltaB();
    bool getDirectionA();
    bool getDirectionB();
  private:
    void update();
    byte _in1_pin;
    byte _in2_pin;
    byte _in3_pin;
    byte _in4_pin;
    byte _a1;
    byte _a2;
    byte _b1;
    byte _b2;
};

byte delta(byte x, byte y);
byte direction(byte x, byte y);

#endif
