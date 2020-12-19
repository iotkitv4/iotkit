/* mbed simple Servo controller
 * Copyright (c) 2019, marcel.bernet@ch-open.ch
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef ACTORS_SERVOS_LIB_SERVO_H_
#define ACTORS_SERVOS_LIB_SERVO_H_

#define SERVO_MIN          750
#define SERVO_MAX         2500

/** Servo control class, based on a PwmOut
 *
 * Example:
 * @code
 * // Continuously sweep the servo through it's full range
 * #include "mbed.h"
 * #include "Servo.h"
 *
 * Servo myservo(D6);
 *
 * int main() {
 *     while(1) {
 *         for(int i=0; i<100; i++) {
 *             myservo = i/100.0;
 *             wait(0.01);
 *         }
 *         for(int i=100; i>0; i--) {
 *             myservo = i/100.0;
 *             wait(0.01);
 *         }
 *     }
 * }
 * @endcode
 */
class Servo
{
public:
    /** Create a servo object connected to the specified PwmOut pin
     *
     * @param pin PwmOut pin to connect to
     */
    Servo(PinName pin);

    /** Set the servo position, normalised to it's full range
     *
     * @param percent A normalised number 0.0-1.0 to represent the full range.
     */
    void write(float percent);

    /**  Read the servo motors current position
     *
     * @param returns A normalised number 0.0-1.0  representing the full range.
     */
    float read();

    /**  Shorthand for the write and read functions */
    Servo& operator= (float percent);
    Servo& operator= (Servo& rhs);
    operator float();

protected:
    PwmOut _pwm;
    float _p;
};

#endif /* ACTORS_SERVOS_LIB_SERVO_H_ */
