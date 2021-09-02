/*
 * movement.h
 *
 *  Created on: Feb 12, 2021
 *      Author: rowan
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include "open_interface.h"
/*
 * moves the roomba forward distance_mm and stops if it comes into contact with a cliff, boundary, or object
 *
 * returns an int that represents distance moved
 */
int moveForward(oi_t *sensor_data, double distance_mm);

/*
 * rotates the roomba to the right the value of degrees
 */
void turnRight(oi_t *sensor_data, double degrees);

/*
 * rotates the roomba to the left the value of degrees
 */
void turnLeft(oi_t *sensor_data, double degrees);

/*
 * returns an absolute value of the first parameter
 */
double ABS();

/*
 * backs up the roomba distance_mm
 */
void backup(oi_t *sensor_data, double distance_mm);


#endif /* MOVEMENT_H_ */
