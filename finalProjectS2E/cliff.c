/**
 * cliff.c
 *
 * @author Greg Matson
 *
 */

#include <open_interface.h>
#include <stdint.h>
#include "cliff.h"

// checks for cliffs under the roomba
int checkCliff(oi_t *sensor_data)
{

    if (sensor_data->cliffLeft)
        return 1;
    else if (sensor_data->cliffRight)
        return 2;
    else if (sensor_data->cliffFrontLeft)
        return 3;
    else if (sensor_data->cliffFrontRight)
        return 4;
    else
        return 0;

}

// Checks for a boundary and returns an int value that represents where the boundary is in relation to the roomba
int checkBoundary(oi_t *sensor_data)
{

    uint16_t data[4];

    if (sensor_data->cliffFrontRightSignal)
	return 0;
    if (sensor_data->cliffFrontLeftSignal;
	return 1;
    if (sensor_data->cliffRightSignal;
	return 2;
    if (sensor_data->cliffLeftSignal;
	return 3;

    return -1;
}
