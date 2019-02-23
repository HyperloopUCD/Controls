// Assumptions
    // the emergency shutdown state is triggered only if SYSTEM_FAIL is true
	// the variable SYSTEM_FAIL will be passed into the function
	// currentState represents the state the system is currently in
	
void checkShutdown(bool system_fail) {
	if (system_fail) {
		if (POD_ACCELERATION > 0) {
			// close propulsion valves (subroutine)
			closePropValves();
		}
		
		// activate brakes (subroutine)
		activateBrake();

		if (PROP_TNK_PRES != 0) {
			// Release Remaining pressure Tank (subroutine)
			releasePressure();
		} 
		
		// trigger stop state (set currentState to stop
		currentState = -1; 
		// -1 is a placeholder, replace with corresponding enum val 
	}
	
}

void activateBrake(void) {
	// set brake pins to on
	// Brake pins (NOV-1, NOV-2, NOV-3, NOV-4, NCV-1, NCV-2) 
	// are set to 0  
	
}

void releasePressure(void) {
	// set pressure pins to on
}

void closePropValves(void) {
	// set S-1, S-2, S-3, S-4 to 0
}