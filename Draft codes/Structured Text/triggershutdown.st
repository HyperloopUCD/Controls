PROGRAM Trigger_Shutdown
    FUNCTION Trigger
        VAR_INPUT
        
        END_VAR
        VAR_OUTPUT
            system_fail: BOOL; 
        END_VAR
        VAR
            brake_eval_int: INT; 
            brake_eval_bool: BOOL;
            prop_eval_bool: BOOL;
            bat_eval_bool: BOOL;
            comm_eval_bool: BOOL;
        END_VAR
        EvalBrake(brake_eval_int);
        IF brake_eval_int >= 2 THEN
            brake_eval_bool := FALSE;
            system_fail := TRUE;
            EvalProp(prop_eval_bool);
        ELSE IF NOT(prop_eval_bool) THEN
            prop_eval_bool := FALSE;
            system_fail := TRUE;
            EvalBattery(bat_eval_bool);
        ELSE IF NOT(prop_eval_bool) THEN
            bat_eval_bool := FALSE;
            system_fail := TRUE;
            EvalComm(comm_eval_bool);
        ELSE IF NOT(comm_eval_bool) THEN
            comm_eval_bool := FALSE;
            system_fail := TRUE;
        ELSE THEN
            system_fail := FALSE;
        END_IF
    END_FUNCTION 
    FUNCTION EvalBrake
        VAR_INPUT

        END_VAR
        VAR_OUTPUT
            brake_state: INT;
        END_VAR
        brake_state := BRAKE_SUBSTATE1 + BRAKE_SUBSTATE2;
    END_FUNCTION 
    FUNCTION EvalProp
        VAR_INPUT

        END_VAR
        VAR_OUTPUT
            prop_state: BOOL;
        END_VAR
        prop_state := PROP_STATE;
    END_FUNCTION 
    FUNCTION EvalBattery
        VAR_INPUT

        END_VAR
        VAR_OUTPUT
            batt_state: BOOL;
        END_VAR
        batt_state := BATT_STATE;
    END_FUNCTION 
    FUNCTION EvalComm
        VAR_INPUT

        END_VAR
        VAR_OUTPUT
            comm_state: BOOL;
        END_VAR
        comm_state := COMM_STATE;
    END_FUNCTION
END_PROGRAM
