//
// Created by John Long on 2019-03-10.
//

#include "health.h"
#include "sensors.h"
#include <math.h>
#include <stdlib.h>

void sensor_health(Sensor* sensor, int second)
{
    //If data is ever 0 or does not have any data, reject immediately
    if(sensor->data[second] == 0 || sensor->data == NO_DATA)
    {
        sensor->health = FAILURE;
    }
    //If sensor is pair...
    //If both sensors have same value, health NOMINAL
    //If both sensors deviate, values must not exceed 2 SD from mean
    if(sensor->is_pair == PAIR)
    {
        if(sensor->data != sensor->paired_sensor->data)
        {
            double *paired_in = malloc(sizeof(double) * 2);
            double sensor_one_val = paired_in[0] = sensor->data[second];
            double sensor_two_val = paired_in[1] = sensor->paired_sensor->data[second];
            double avg = mean(paired_in, 2);
            double sd = standard_deviation(paired_in, 2);

            if (sensor_one_val > fabs(avg - (2 * sd)))
            {
                sensor->health = SICK;
            }
            else if (sensor_two_val > fabs(avg - (2 * sd)))
            {
                sensor->paired_sensor->health = SICK;
            }

        }
        else
        {
            sensor->health = NOMINAL;
            sensor->paired_sensor->health = NOMINAL;
        }
    }
    else
    {
        
    }
}

double standard_deviation(double* data, int num_values)
{
    double sum = 0;
    double avg = mean(data, num_values);
    //subtract each value from mean, then square
    for(int i = 0; i < num_values; ++i)
    {
        sum += pow(data[i] - avg, 2);
    }
    return sqrt(sum/num_values);
}

double mean(double* data, int num_values)
{
    double avg = 0;
    for(int i = 0; i < num_values; ++i)
    {
        avg += data[i];
    }
    avg  = avg / num_values;
    return avg;
}