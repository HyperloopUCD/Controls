// Assumptions
    // the emergency shutdown state is triggered only if SYSTEM_FAIL is true
	// the variable SYSTEM_FAIL will be passed into the function
	// currentState represents the state the system is currently in
	
checkShutdown(BOOL system_fail) {
	IF system_fail THEN
		IF POD_ACCELERATION > 0 THEN
			// close propulsion valves (subroutine)
			closePropValves();
		END_IF;
		
		// activate brakes (subroutine)
		activateBrake();

		IF PROP_TNK_PRES <> 0 THEN
			// Release Remaining pressure Tank (subroutine)
			releasePressure();
		END_IF; 
		
		// trigger stop state (set currentState to stop
		currentState:= -1; 
		// -1 is a placeholder, replace with corresponding enum val 
	END_IF;
	
}

activateBrake() {
	// set brake pins to on
	// Brake pins (NOV-1, NOV-2, NOV-3, NOV-4, NCV-1, NCV-2) 
	// are set to 0  
	
}

releasePressure() {
	// set pressure pins to on
}

closePropValves() {
	// set S-1, S-2, S-3, S-4 to 0
}