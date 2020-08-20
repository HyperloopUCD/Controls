//
// Created by John Long on 2019-03-10.
//

#ifndef PD2_ONELOOP_SENSORS_H
#define PD2_ONELOOP_SENSORS_H

//For initial sensor declaration, where there is no data
#define NO_DATA NULL
//For indicating if a sensor is in a pair or not
typedef enum Paired{PAIR, NOT_PAIR} Paired;
//For indicating sensor units
typedef enum Units{PSI_G, PSI_A, CELSIUS, UNKNOWN} Units;
//For indicating health
typedef enum Health{NOMINAL, SICK, FAILURE} Health;

/*
 * Sensor Type includes:
 *  Sensor Name
 *  Whether or not sensor is paired with another sensor
 *  Units of the sensor
 *  data
 */
typedef struct Sensor
{
    char* name;
    Paired is_pair;
    struct Sensor* paired_sensor;
    Units units;
    double* data;
    Health health;
}Sensor;
#endif //PD2_ONELOOP_SENSORS_H
