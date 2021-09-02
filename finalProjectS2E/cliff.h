#ifndef CLIFF_H_
#define CLIFF_H_

// checks for cliffs under the roomba
int checkCliff(oi_t *sensor_data);

// Checks for a boundary and returns an int value that represents where the boundary is in relation to the roomba
int checkBoundary(oi_t *sensor_data);


#endif /* CYBOT_SCAN_H_ */
