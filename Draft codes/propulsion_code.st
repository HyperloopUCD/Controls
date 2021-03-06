VAR:
// PRESSURE VAR
PPV_0: INT;      // Pressure PPV_0 at A-1
PPV_1: INT;      // Pressure PPV_1 at A-2
PPV_2: INT;      // Pressure PPV_2 at A-3
PPV_3: INT;      // Pressure PPV_3 at A-4
PPV_4: INT;      // Pressure PPV_4 at TA-3 and TA-4
PPV_5: INT;      // Pressure PPV_5 at TA-1 and TA-2
PPV_6: INT;      // Pressure PPV_6 at TA-5

PPV_0_STATUS: Bool;
PPV_1_STATUS: Bool;
PPV_2_STATUS: Bool;
PPV_3_STATUS: Bool;
PPV_4_STATUS: Bool;
PPV_5_STATUS: Bool;
PPV_6_STATUS: Bool;

// SOLENOID VAR
S_1: INT; 	// SOLENOID READINGS 
S_2: INT;
S_3: INT;
S_4: INT;
S_5: INT;

// TEMPEARTUE VAR
PT0: INT;   // TEMPEATURE OF PT0 MEASURED AT NOZZLE 1
PT1: INT;	// TEMPEATURE OF PT1 MEASURED AT NOZZLE 1
PT2: INT;	// TEMPEATURE OF PT2 MEASURED AT NOZZLE 2
PT3: INT;	// TEMPEATURE OF PT3 MEASURED AT NOZZLE 2
PT4: INT;	// TEMPEATURE OF PT4 MEASURED AT TA_1 AND TA_2
PT5: INT;	// TEMPEATURE OF PT5 MEASURED AT TA_1 AND TA_2
PT6: INT;	// TEMPEATURE OF PT6 MEASURED AT TA_3 AND TA_4
PT7: INT;	// TEMPEATURE OF PT7 MEASURED AT TA_3 AND TA_4
PT8: INT;	// TEMPEATURE OF PT8 MEASURED AT TA_5

// Constant Definition
CONSTANT PRESSURE_NOTOPEN: = FALSE;
CONSTANT RRESSURE_OPEN: = TRUE;
CONSTANT PROPULSION_TANK_MAX_PRESSURE: = 4550;
CONSTANT PILOT_AIR_MAX_PRESSURE: = 250;
CONSTANT SOLENOID_MAX_VOLTAGE: = 24;
CONSTANT SYS_FAILURE: FALSE;
CONSTANT NORMAL: = TRUE;
CONSTANT NOMINAL: = ;
CONSTANT TBD: = ;

// SYSTEM VAR
POPSYS: Bool;  // PROPULSION SYSTEM STATUS

END_VAR




// PRESSURE PROBLEM
IF PPV_0 <> SICK AND PPV_0 == UNDEFINED THEN
POPSYS: = SYS_FAILURE;
PPV_0_STATUS = PRESSURE_NOTOPEN;

ELSIF PPV_1 <> SICK AND PPV_1 == UNDEFINED THEN
POPSYS: = SYS_FAILURE;
PPV_1_STATUS = PRESSURE_NOTOPEN;

ELSIF PPV_2 <> SICK AND PPV_2 == UNDEFINED THEN
POPSYS: = SYS_FAILURE;
PPV_2_STATUS = PRESSURE_NOTOPEN;

ELSIF PPV_3 <> SICK AND PPV_3 == UNDEFINED THEN
POPSYS: = SYS_FAILURE;

ELSIF PPV_4 <> SICK AND PPV_4 == UNDEFINED THEN
POPSYS: = SYS_FAILURE;

ELSIF (PPV_0 <> UNDEFINED AND PPV_1 <> UNDEFINED AND PPV_2 <> UNDEFINED AND PPV_3 <> UNDEFINED) AND (PPV_0 – PPV_2 > 30 OR PPV_0 – PPV_3 > 30 OR PPV_1 - PPV_2 > 30 OR PPV_1 – PPV_3 > 30) THEN
	POPSYS: = SYS_FAILURE;

ELSIF (PT_0 <> UNDEFINED AND PT_1 <> UNDEFINED AND PT_2 <> UNDEFINED AND PT_3 <> UNDEFINED) AND (PT_0 – PT_2 > 40 OR PT_0 – PT_3 > 40 OR PT_1 - PT_2 > 40 OR PT_1 – PT_3 > 40) THEN
	POPSYS: = SYS_FAILURE;

ELSIF (PPV_5 > PROPULSION_TANK_MAX_PRESSURE) OR (PPV_4 > PROPULSION_TANK_MAX_PRESSURE) OR (PPV_6 > PILOT_AIR_MAX_PRESSURE) THEN
	POPSYS: = SYS_FAILURE;

END_IF

// Solenoid values
IF S_1 < SOLENOID_MAX_VOLTAGE OR S_2 < SOLENOID_MAX_VOLTAGE OR S_3 < SOLENOID_MAX_VOLTAGE OR S_4 < SOLENOID_MAX_VOLTAGE THEN
	POPSYS: = SYS_FAILURE

END_IF


// TEMPERATURE PROBLEM

IF (PT4 == NOMINAL AND PT5 == NOMINAL) AND (PT4 + PT5)/2 <> TBD THEN
	POPSYS: = SYS_FAILURE;

ELSIF (PT4 == SICK OR PT5 == SICK) AND (PT4 <> TBD OR PT5 <> TBD) THEN 
	POPSYS: = SYS_FAILURE;

ELSIF (PT6 == NOMINAL AND PT7 == NOMINAL) AND (PT6 + PT7)/2 <> TBD THEN
	POPSYS: = SYS_FAILURE;

ELSIF (PT6 == SICK OR PT7 == SICK) AND (PT6 <> TBD OR PT7 <> TBD) THEN 
	POPSYS: = SYS_FAILURE;

ELSIF PT8 == NOMINAL AND PT8 <> TBD THEN
	POPSYS: = SYS_FAILURE;

END_IF