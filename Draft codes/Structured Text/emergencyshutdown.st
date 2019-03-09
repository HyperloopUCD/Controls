PROGRAM Emergency_Shutdown
    FUNCTION CheckShutdown
        VAR_INPUT
            system_fail: BOOL;
        END_VAR
        VAR
            pod_accelaration: INT; 
            tank_pressure: INT;
        END_VAR
        IF system_fail THEN
            pod_accelaration := GETPODACCELARATION();
            IF pod_accelaration > 0 THEN
                ClosePropValves();
            END_IF
            ActivateBrake();
            IF tank_pressure <> 0 THEN
                ReleasePressure();
            END_IF
            CURRENT_STATE = -1;
        END_IF
    END_FUNCTION
    FUNCTION ActivateBrake
    
    END_FUNCTION
    FUNCTION ReleasePressure
    
    END_FUNCTION
    FUNCTION ClosePropValves
    
    END_FUNCTION
END_PROGRAM