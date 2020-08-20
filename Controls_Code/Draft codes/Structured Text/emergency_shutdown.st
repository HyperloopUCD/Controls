// Assumptions
    // the emergency shutdown state is triggered only if SYSTEM_FAIL is TRUE
	// the variable SYSTEM_FAIL will be passed into the function
	// currentState represents the state the system is currently in
PROGRAM	 emergency_shutdown
	FUNCTION check_shutdown
		VAR_INPUT
        	system_fail: BOOL;
		END_VAR
		IF system_fail
			IF POD_ACCELERATION > 0
				// close propulsion valves (subroutine)
				closePropValves();
			// activate brakes (subroutine)
			activateBrake();

			IF PROP_TNK_PRES != 0
				// Release Remaining pressure Tank (subroutine)
				releasePressure();
			
			// trigger stop state (set currentState to stop
			currentState = -1; 
			// -1 is a placeholder, replace with corresponding enum val 
	END_FUNCTION

	FUNCTION activateBrake
		// set brake pins to on
		// Brake pins (NOV-1, NOV-2, NOV-3, NOV-4, NCV-1, NCV-2) 
		// are set to 0  
	END_FUNCTION
	

	FUNCTION releasePressure
		// set pressure pins to on
	END_FUNCTION

	FUNCTION closePropValves
		// set S-1, S-2, S-3, S-4 to 0
	END_FUNCTION
	
END_PROGRAM