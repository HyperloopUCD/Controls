idle_val = "DO_NOT_BEGIN" #Current state of idle_val (GLOBAL VARIABLE)

def waiting_idle_begin():
    global idle_val
    while(idle_val!="BEGIN"): #Waiting for command BEGIN
        idle_val = input("Input BEGIN TO START: ")
    return True

def system_check_state():
    global idle_val
    arr_sensors = ["check_battery","check_propulsion","check_brakes"]
    brake_actuation_test_bool = None
    check_battery = None
    check_propulsion = None
    check_brakes = None
    check_all_sensors_data = None

    if(idle_val=="BEGIN"):
        current_pod_state = "STATIONARY"
        brake_actuation_test_bool = brake_actuation_test()
        check_sensor_data = sensor_data()
        if (check_sensor_data == True):
            for i in range(len(arr_sensors)):
                print(arr_sensors[i])
                check_battery = battery(1, 1, 1) #battery(temperature, voltage, current)
                check_propulsion = propulsion(1,1) #propulsion(pressure, temperature);
                check_brakes =  brakes(1,1) #brakes(pressure, temperature)

            if(check_battery==check_propulsion==check_brakes==True):
                print("ALL SYSTEMS FINE")
                print("GIVE ARM COMMAND")
            elif (check_battery==check_propulsion==check_brakes==False):
                print("SYSTEMS NOT WORKING")
                print("GIVE EGSD COMMAND")
            else:
                waiting_idle_begin()
                print("GOING TO IDLE STATE")




def monitoring_station(temperature, voltage, current, pressure):
    if((temperature==1 or temperature==None) and (voltage==1 or voltage==None) and (current==1 or current==None) and (pressure==1 or pressure==None)):
        return True

def battery(temperature, voltage, current):
    monitoring_station_val = monitoring_station(temperature,voltage,current,None)
    if(monitoring_station_val == True):
        return True
    else:
        return False

def propulsion(pressure, temperature):
    monitoring_station_val = monitoring_station(temperature,None,None,pressure)
    if(monitoring_station_val == True):
        return True
    else:
        return False

def brakes(pressure, temperature):
    monitoring_station_val = monitoring_station(temperature,None,None,pressure)
    if(monitoring_station_val == True):
        return True
    else:
        return False

def brake_actuation_test():
    return True

def sensor_data():
    return True

def main():
    waiting_idle_begin()
    system_check_state()

main()