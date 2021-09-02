/*
 * servo.h
 *
 *  Created on: Apr 7, 2021
 *      Author: jgortiz
 */

#ifndef SERVO_H_
#define SERVO_H_

#include <stdint.h>
#include <stdbool.h>
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"

/*
 * responsible for initializing the servo motors
 */
void servo_init(void);

/*
 * responsible for moving the servo motor to the specified degree
 */
void servo_move(float degrees);



#endif /* SERVO_H_ */
