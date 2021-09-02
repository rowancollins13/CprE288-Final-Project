/*
 * scan.h
 *
 *  Created on: Apr 20, 2021
 *      Author: jgortiz
 */

#ifndef SCAN_H_
#define SCAN_H_

#include "scan.h"
#include <stdio.h>
#include "servo.h"
#include <math.h>
#include "ping_template.h"
#include <string.h>
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"
#define M_PI 3.14159265358979323846

/*
 * starts the loop to scan for objects using both the ping sensor and ir sensor
 */
void scan();

/*
 * returns a float value of the suspected width of the object given it's angular width and distance
 */
float widthCalculator(int angle, float distance);

/*
 * outputs the parameters into putty into a readable format
 */
void sendToPutty(int obj, int angle, float distance, float width);

/*
 * returns an int value equal to the distance detected by the ir sensors
 */
int irDis(void);

#endif /* SCAN_H_ */
