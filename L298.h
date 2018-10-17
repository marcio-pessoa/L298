/* L298.h - L298 DC Motor Control Library
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 * 
 * Change log
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
    void stop();
    void stopA();
    void stopB();
    void direct(byte speed=100);
    void directA(byte speed=100);
    void directB(byte speed=100);
    void reverse(byte speed=100);
    void reverseA(byte speed=100);
    void reverseB(byte speed=100);
  private:
    byte _in1_pin;
    byte _in2_pin;
    byte _in3_pin;
    byte _in4_pin;
    byte _speedA;
    byte _speedB;
};

#endif
