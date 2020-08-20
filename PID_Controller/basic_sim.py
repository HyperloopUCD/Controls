import argparse
import numpy as np 
import matplotlib.pyplot as plt 
from scipy.integrate import odeint
from scipy import optimize

class Pod:
    def __init__(self, mass, friction_coeff, thrust):
        self.mass = mass
        self.friction_coeff = friction_coeff
        self.thrust = thrust

        self.pid = PID()

    def pid_setup(self, no_steps, thrust_bias = 0.0, Kc = 0.6, tauI = 0.3, tauD = 0.5):
        self.pid.setup(no_steps, thrust_bias, Kc, tauI, tauD)

    def get_accelaration(self, velocity, time, applied_thrust):
        dv_dt = (1.0 / self.mass) * (self.thrust*applied_thrust - self.friction_coeff*self.mass*9.8)
        return dv_dt

    def get_thrust(self, target_velocity, initial_velocity, prev_velocity, step):
        return self.pid.thrust(target_velocity, initial_velocity, prev_velocity, step)

class Simulation:
    def __init__(self, total_time, time_step, pod, pid_enable):
        self.total_time = total_time
        self.time_step = time_step
        self.no_steps = int(total_time / time_step + 1)
        self.time_vector = np.linspace(0, total_time, self.no_steps)
        self.vehicle = pod
        self.thrust_vector = np.zeros(self.no_steps)
        self.initial_velocity = 0.0
        self.target_velocity = 0.0
        self.velocity_vector = np.zeros(self.no_steps)
        self.target_vector = np.zeros(self.no_steps)
        self.pid_enable = pid_enable

    def setup(self, applied_thrust, start_time, target_velocity):
        self.thrust_vector[int(start_time):] = applied_thrust
        self.target_velocity = target_velocity

    def fit(self, parameters):
        time_vector = np.linspace(0, self.total_time, self.no_steps)
        thrust_vector = np.zeros(self.no_steps)
        velocity_vector = np.zeros(self.no_steps)
        target_vector = np.zeros(self.no_steps)
        target_velocity = 70
        initial_velocity = 0.0
        error = 0.0
        self.vehicle.pid_setup(self.no_steps, parameters[0], parameters[1], parameters[2], parameters[3])
        for i in range(self.no_steps - 1):
            if i == 50:
                target_velocity = 100
            if i == 100:
                target_velocity = 200
            if i == 150:
                target_velocity = 30
            
            current_thrust = self.vehicle.get_thrust(target_velocity, initial_velocity, velocity_vector[i - 1], i)
            #if current_thrust > 50.0:
                #current_thrust = 50.0
            #elif current_thrust < -50.0:
                #current_thrust = -50.0
            thrust_vector[i + 1] = current_thrust
            velocity = odeint(self.vehicle.get_accelaration, initial_velocity, [0, self.time_step], args = (current_thrust,))
            initial_velocity = velocity[-1]
            velocity_vector[i + 1] = initial_velocity
            target_vector[i + 1] = target_velocity
            error = error + abs(target_velocity - initial_velocity)
        return error
    
    def simulate(self):
        params = optimize.fmin(self.fit, [0.0, 0.6, 0.3, 0.5])
        self.vehicle.pid_setup(self.no_steps, params[0], params[1], params[2], params[3])
        plt.figure(1, figsize = (5, 4))
        plt.ion()
        plt.show()

        for i in range(self.no_steps - 1):
            if i == 50:
                self.target_velocity = 100
            if i == 100:
                self.target_velocity = 200
            if i == 150:
                self.target_velocity = 30
            
            if self.pid_enable:
                current_thrust = self.vehicle.get_thrust(self.target_velocity, self.initial_velocity, self.velocity_vector[i - 1], i)
                #if current_thrust > 50.0:
                    #current_thrust = 50.0
                #elif current_thrust < -50.0:
                    #current_thrust = -50.0
                self.thrust_vector[i + 1] = current_thrust
            else:
                #if current_thrust > 50.0:
                    #current_thrust = 50.0
                #elif current_thrust < -50.0:
                    #current_thrust = -50.0
                current_thrust= self.thrust_vector[i]
            velocity = odeint(self.vehicle.get_accelaration, self.initial_velocity, [0, self.time_step], args = (current_thrust,))
            self.initial_velocity = velocity[-1]
            self.velocity_vector[i + 1] = self.initial_velocity
            self.target_vector[i + 1] = self.target_velocity

            plt.clf()

            plt.subplot(2, 1, 1)
            plt.plot(self.time_vector[0: i + 1], self.velocity_vector[0: i + 1], 'b-', linewidth = 3)
            plt.plot(self.time_vector[0: i + 1], self.target_vector[0: i + 1], 'k--', linewidth = 2)
            plt.ylabel('Velocity')
            plt.legend(['Velocity', 'Target Velocity'], loc = 2)

            plt.subplot(2, 1, 2)
            plt.plot(self.time_vector[0: i + 1], self.thrust_vector[0: i + 1], 'b-', linewidth = 3)
            plt.ylabel('Thrust')
            plt.legend(['Thrust'])
            plt.xlabel('Time')

            plt.pause(0.1)

        plt.savefig("result.png")

class PID:
    def __init__(self, thrust_bias = 0.0, Kc = 0.6, tauI = 0.3, tauD = 0.5):
        self.thrust_bias = thrust_bias
        self.Kc = Kc
        self.tauI = tauI
        self.tauD = tauD
        self.sum_int = 0.0
        self.errors = np.zeros(201)
        self.integral_errors = np.zeros(201)

    def setup(self, no_steps, thrust_bias, Kc, tauI, tauD):
        self.thrust_bias = thrust_bias
        self.Kc = Kc
        self.tauI = tauI
        self.tauD = tauD
        self.errors = np.zeros(int(no_steps))
        self.integral_errors = np.zeros(int(no_steps))

    def thrust(self, target_velocity, initial_velocity, prev_velocity, step):
        error = target_velocity - initial_velocity
        self.errors[step + 1] = error
        self.sum_int = self.sum_int + error * 1
        current_thrust = self.thrust_bias + self.Kc * error + self.Kc / self.tauI * self.sum_int - self.Kc * self.tauD * (initial_velocity - prev_velocity)
        self.sum_int = self.sum_int - error * 1
        self.integral_errors[step + 1] = self.sum_int
        return current_thrust

parser = argparse.ArgumentParser()
parser.add_argument("--pod", nargs = '+', type = float, help = "mass friction_coeff max_thrust")
parser.add_argument("--sim", nargs = '+', type = float, help = "total_time thrust start_time expected_velocity")

args = parser.parse_args()

pod = Pod(args.pod[0], args.pod[1], args.pod[2])
sim = Simulation(args.sim[0], 1, pod, False)
#sim.setup(args.sim[1], args.sim[2], args.sim[3])
#print(optimize.fmin(sim.fit, [0.0, 0.6, 0.3, 0.5]))
#sim.simulate()

pod.pid_setup(args.sim[0] + 1)
sim_pid = Simulation(args.sim[0], 1, pod, True)
sim_pid.setup(args.sim[1], args.sim[2], args.sim[3])
sim_pid.simulate()    