// Assumptions
	// BRAKE_SUBSTATE1 and BRAKE_SUBSTATE2 will be enumerated
		// 2 - failure
		// 1 - sick
		// 0 - nominal
	// PROP_STATE will be enumerated
		// 1 - nominal
		// 0 - failure
	// In evalBattery, the following variables are temporary
		// maxBattVoltage
		// maxBattTemp
		// maxBattCurrent
	// In evalComm, the following bool variable is created
		// commState
			// true - comms are working fine
			// false - comms are not working


/* Instead of returning SYSTEM_FAIL, you can call checkShutdown()
   and pass SYSTEM_FAIL as an argument like so:
   checkShutdown(SYSTEM_FAIL); */
   
bool triggerShutdown() {
	if (evalBrake() >= 2) {
		// failure occurs
		BRAKE_FlAG = false;
		SYSTEM_FAIL = true;
		return SYSTEM_FAIL;
		
	} else if (!evalProp()) {
		// failure occurs
		PROP_FLAG = false;
		SYSTEM_FAIL = true;
		return SYSTEM_FAIL;
		
	} else if (!evalBattery()) {
		// failure occurs
		BAT_FLAG = false;
		SYSTEM_FAIL = true;	
		return SYSTEM_FAIL;
		
	} else if (!evalComm) {
		// failure occurs
		COMM_FLAG = false;
		SYSTEM_FAIL = true;
		return SYSTEM_FAIL;
		
	} else {
		// failure does not occurs
		SYSTEM_FAIL = false;
		return SYSTEM_FAIL;
	}
}	
	
// change function parameter if necessary	
int evalBrake(void) {
	// evaluates some brake logic with sensors
	// returns sum of BRAKE_SUBSTATE1 and BRAKE_SUBSTATE2
	return BRAKE_SUBSTATE1 + BRAKE_SUBSTATE2;
}


// change function parameter if necessary	
bool evalProp(void) {
	// evaluates some propulsion logic with sensors
	// returns PROP_STATE
	return PROP_STATE;
}

// change function parameter if necessary	
bool evalBattery(void) {
	// evaluates some battery logic
	// change all conditions as needed
	if (BATTERY_CURRENT > maxBattCurrent) {
		return false;
		
	} else if (BATTERY_TEMP > maxBattTemp) {
		return false;
		
	} else if (BATTERY_VOLTAGE > maxBattVoltage) {
		return false;
		
	} else {
		return true;
	}
}

// change function parameter if necessary	
bool evalComm(void) {
	// evaluate some communications logic
	// set commState
	return commState;
}	