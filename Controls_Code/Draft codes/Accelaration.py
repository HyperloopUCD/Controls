from poddistance import poddistance
from coast import coast
from propulsion_system import activate_propulsion_system, close_propulsion_valves
from pressure_gauge import prop_tnk_pres
from accelaration_gauge import pod_accelaration

def slowcrawl():
    #Signal to the controls that the pod goes 5 mph
    print("I'm going 5 mph")
    while(True):
        if poddistance >= 3000:
            gofast()
            break

def gofast():
    activate_propulsion_system()
    print("I'm going really fast")
    while(True):
        if prop_tnk_pres<=200:
            while(True):
                if pod_accelaration <= 0:
                    close_propulsion_valves()
                    coast()
