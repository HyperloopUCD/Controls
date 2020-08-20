//
// Created by John Long on 2019-03-10.
//

#ifndef PD2_ONELOOP_HEALTH_H
#define PD2_ONELOOP_HEALTH_H
#include "sensors.h"

void sensor_health(Sensor* sensor, int second);
double standard_deviation(double* data, int num_values);
double mean(double* data, int num_values);

#endif //PD2_ONELOOP_HEALTH_H
