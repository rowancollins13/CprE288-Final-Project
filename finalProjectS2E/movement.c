/*
 * movement.c
 *
 *  Created on: Feb 12, 2021
 *      Author: rowan
 */

#include "open_interface.h"
#include "math.h"

/*
 * moves the roomba forward distance_mm and stops if it comes into contact with a cliff, boundary, or object
 *
 * returns an int that represents distance moved
 */
int moveForward(oi_t *sensor_data, double distance_mm)
{
    double sum = 0;
    oi_setWheels(350,350);
    while (sum < distance_mm)
    {
       oi_update(sensor_data);
       sum += sensor_data -> distance;
       if (sensor_data->bumpLeft || sensor_data->bumpRight)
       {
           break;
       }

       if (checkCliff(sensor_data))
       {
           break;
       }

       if (checkBoundary(sensor_data))
       {
           break;
       }
    }
    oi_setWheels(0,0);
    if (sum > distance_mm)
        sum = distance_mm;
    return (int) sum;
}

/*
 * returns an absolute value of the first parameter
 */
double ABS(double number)
{
    if (number <= 0)
        return -1 * number;
    else
        return number;
}

/*
 * rotates the roomba to the left the value of degrees
 */
void turnLeft(oi_t *sensor_data, double degrees)
{
    double sum = 0;
    oi_setWheels(-30,30);
    while (sum < degrees)
    {
       oi_update(sensor_data);
       sum += ABS(sensor_data -> angle);
    }
    oi_setWheels(0,0);

}


/*
 * backs up the roomba distance_mm
 */
void backup(oi_t *sensor_data, double distance_mm)
{
    double sum = 0;
    oi_setWheels(-350,-350);
    while (sum < 150)
    {
       oi_update(sensor_data);
       sum += ABS(sensor_data -> distance);
    }
    oi_setWheels(0,0);
}

/*
 * rotates the roomba to the right the value of degrees
 */
void turnRight(oi_t *sensor_data, double degrees)
{
    double sum = 0;
    oi_setWheels(30, -30);
    while (sum < degrees)
    {
       oi_update(sensor_data);
       sum += ABS(sensor_data -> angle);
    }
    oi_setWheels(0,0);

}



