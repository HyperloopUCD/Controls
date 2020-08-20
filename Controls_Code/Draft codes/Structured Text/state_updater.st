PROGRAM update_states
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
    VAR_INPUT
        currState: INT;
        cmd: INT;
        END_VAR
        VAR_OUTPUT
            newState: INT;

            
    VAR
        newState: INT = 0;
    END_VAR

    FUNCTION update
        // go to emergency shutdown
        IF cmd == 8 THEN
            newState = 10;

        //transiton 1
        IF cmd ==2 && currState == 1 THEN
            newState =2;

        // transition 2
        IF cmd ==1 && currState ==2 THEN
            newState = 1;

        // transition 3
        IF cmd == 3 && currState == 2 THEN
            newState = 3;

        // transition 4
        IF cmd == 4 && currState == 3 THEN
            newState = 4;

        // transition 5
        IF currState == 4 && cmd == 9 THEN
            newState = 5;

        // transition 6
        IF currState == 5 && cmd == 5 THEN
            newState = 6;

        // transition 7
        IF currState == 6 && POD_VELOCITY <= 0 THEN
            newState = 7;

        // transition 8
        IF currState == 7 && cmd == 6 THEN
            newState = 8;

        // transition 9
        IF currState == 8 && cmd == 5 THEN
            newState = 6;

        // transition 10
        IF currState == 7 && cmd == 7 THEN
            newState = 9;
    END_FUNCTION
END_PROGRAM
