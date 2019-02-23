


int UpdateStates(int currState, int cmd){
	/*
	cmd = 1 -> BEGIN cmd  M
	cmd = 2 -> IDLE    M
	cmd = 3 -> ARM     M
	cmd = 4 -> LAUNCH  M
	cmd = 5 -> stop  A/M
	cmd = 6 -> CRAWL M
	cmd = 7 -> END   M
	cmd = 8 -> EGSD  A/M
	cmd = 9 -> coast A
	

	*/
	int cmd = cmd; // 

	/*
	1  idle  
	2  System check 
	3  Armed
	4  Acceleration
	5  Coast
	6  Brake
	7  stop
	8  CRAWL
	9  End
	10 Emergency shutdown
	*/
	int currState = currState;
	int newState = 0;
	
	
	
	// go to emergency shutdown
	if(cmd == 8){
		newState = 10;
	}
	//transiton 1
	if(cmd ==2 && currState == 1){
		newState =2;
	}
	// transition 2
	if(cmd ==1 && currState ==2){
		newState = 1;
	}	
	// transition 3
	if(cmd == 3 && currState == 2){
		newState = 3;
	}
	// transition 4
	if (cmd == 4 && currState == 3){
		newState = 4;
	}
	// transition 5
	if (currState == 4 && cmd == 9){
		newState = 5;
	}
	// transition 6
	if (currState == 5 && cmd == 5){
		newState = 6;
	}
	// transition 7
	if (currState == 6 && POD_VELOCITY <= 0){
		newState = 7;
	}	
	// transition 8
	if (currState == 7 && cmd == 6){
		newState = 8;
	}
	// transition 9
	if (currState == 8 && cmd == 5){
		newState = 6;
	}	
	// transition 10
	if (currState == 7 && cmd == 7){
		newState = 9;
	}	
	return newState
}
