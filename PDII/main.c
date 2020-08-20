#include <stdio.h>
#include "sensors.h"



//Distance Laser Sensors (PAIR)
//Forward declaration
Sensor C_Las0, C_Las1;
Sensor C_Las0 = {"C_Las0", PAIR, &C_Las1, UNKNOWN, NO_DATA, NOMINAL};
Sensor C_Las1 = {"C_Las1", PAIR, &C_Las0, UNKNOWN, NO_DATA, NOMINAL};

//Distance Lidar Sesnors (PAIR)
Sensor SX_Las0, SX_Las1;
Sensor SX_Las0 = {"SX_Las0", PAIR, &SX_Las1, UNKNOWN, NO_DATA, NOMINAL};
Sensor SX_Las1 = {"SX_Las1", PAIR, &SX_Las0, UNKNOWN, NO_DATA, NOMINAL};

//Pressure (Braking) Sensors (NON-PAIR)
Sensor B_Pres1 = {"B_Pres1", NOT_PAIR, NULL, PSI_A, NO_DATA, NOMINAL};
Sensor B_Pres2 = {"B_Pres2", NOT_PAIR, NULL, PSI_A, NO_DATA, NOMINAL};
Sensor B_Pres3 = {"B_Pres3", NOT_PAIR, NULL, PSI_A, NO_DATA, NOMINAL};
Sensor B_Pres4 = {"B_Pres4", NOT_PAIR, NULL, PSI_A, NO_DATA, NOMINAL};
Sensor B_Pres5 = {"B_Pres5", NOT_PAIR, NULL, PSI_A, NO_DATA, NOMINAL};
Sensor B_Pres6 = {"B_Pres6", NOT_PAIR, NULL, PSI_A, NO_DATA, NOMINAL};
Sensor B_Pres7 = {"B_Pres7", NOT_PAIR, NULL, PSI_A, NO_DATA, NOMINAL};
Sensor B_Pres8 = {"B_Pres8", NOT_PAIR, NULL, PSI_A, NO_DATA, NOMINAL};
Sensor B_Pres9 = {"B_Pres9", NOT_PAIR, NULL, PSI_A, NO_DATA, NOMINAL};

//Thermocouple Probes for Braking (PAIR)
Sensor B_Tem0, B_Tem1;
Sensor B_Tem0 = {"B_Tem0", PAIR, &B_Tem1, CELSIUS, NO_DATA, NOMINAL};
Sensor B_Tem1 = {"B_Tem1", PAIR, &B_Tem0, CELSIUS, NO_DATA, NOMINAL};

//Pressure (Propulsion) Sensors (NON-PAIR)
Sensor P_Pres0 = {"P_Pres0", NOT_PAIR, NULL, PSI_G, NO_DATA, NOMINAL};
Sensor P_Pres1 = {"P_Pres1", NOT_PAIR, NULL, PSI_G, NO_DATA, NOMINAL};
Sensor P_Pres2 = {"P_Pres2", NOT_PAIR, NULL, PSI_G, NO_DATA, NOMINAL};
Sensor P_Pres3 = {"P_Pres3", NOT_PAIR, NULL, PSI_G, NO_DATA, NOMINAL};
Sensor P_Pres4 = {"P_Pres4", NOT_PAIR, NULL, PSI_G, NO_DATA, NOMINAL};
Sensor P_Pres5 = {"P_Pres5", NOT_PAIR, NULL, PSI_G, NO_DATA, NOMINAL};
Sensor P_Pres6 = {"P_pres6", NOT_PAIR, NULL, PSI_G, NO_DATA, NOMINAL};

//Propulsion Pressure Sensors (NON-PAIR)
Sensor P_Tem0 = {"P_Tem0", NOT_PAIR, NULL, CELSIUS, NO_DATA, NOMINAL};
Sensor P_Tem1 = {"P_Tem1", NOT_PAIR, NULL, CELSIUS, NO_DATA, NOMINAL};
Sensor P_Tem2 = {"P_Tem2", NOT_PAIR, NULL, CELSIUS, NO_DATA, NOMINAL};
Sensor P_Tem3 = {"P_Tem3", NOT_PAIR, NULL, CELSIUS, NO_DATA, NOMINAL};
Sensor P_Tem4 = {"P_Tem4", NOT_PAIR, NULL, CELSIUS, NO_DATA, NOMINAL};
Sensor P_Tem5 = {"P_Tem5", NOT_PAIR, NULL, CELSIUS, NO_DATA, NOMINAL};
Sensor P_Tem6 = {"P_Tem6", NOT_PAIR, NULL, CELSIUS, NO_DATA, NOMINAL};
Sensor P_Tem7 = {"P_Tem7", NOT_PAIR, NULL, CELSIUS, NO_DATA, NOMINAL};
Sensor P_Tem8 = {"P_Tem8", NOT_PAIR, NULL, CELSIUS, NO_DATA, NOMINAL};

int main()
{

    return 0;
}