import csv
import functions

###CONTROLS
#Units Unknown
dist_laser_sense = ['C_Las0', 'C_Las1']

###SPEED SENSING MODULE
#Units Unknown
dist_lidar_sense = ['SX_Las0', 'SX_Las1']

###BRAKING###
#Tenths of A Degree Celsius: XX.X
pressure_brake_sense = ['B_Pres0','B_Pres1','B_Pres2','B_Pres3','B_Pres4','B_Pres5','B_Pres6','B_Pres7','B_Pres8','B_Pres9']
#Tenths of A Degree Celsius: XX.X
thermo_brake_sense = ['B_Tem0', 'B_Tem1'];

###PROPULSION###
#PSIG (Gauge Pressure, relative to atmospheric pressure, i.e. 0 PSIG = standard atmospheric)
pressure_sense = ['P_Pres0','P_Pres1','P_Pres2','P_Pres3','P_Pres4', 'P_Pres5', 'P_Pres6']
#Tenths of A Degree Celsius: XX.X
prop_pressure_sense = ['P_Tem0','P_Tem1','P_Tem2','P_Tem3','P_Tem4','P_Tem5','P_Tem6','P_Tem7','P_Tem8']

####noisy sigmoid laser data
dist_laser_data = []
for sensor in dist_laser_sense:
	i = 0
	data_buff = []
	while i < 20:
		data_buff.append(str(functions.sigmoid(i, 0.5)))
		i += 1
	dist_laser_data.append([sensor] + data_buff)

####constant laser data
dist_lidar_data = []
for sensor in dist_lidar_sense:
	i = 0
	data_buff = []
	while i < 20:
		data_buff.append(str(functions.constant(100, 0)))
		i += 1
	dist_lidar_data.append([sensor] + data_buff)

####linear 
pressure_brake_data = []
for sensor in pressure_brake_sense:
	i = 0
	data_buff = []
	while i < 20:
		data_buff.append(str(functions.linear(1, 0, i, 0.3)))
		i += 1
	pressure_brake_data.append([sensor] + data_buff)


thermo_brake_data = []
for sensor in thermo_brake_sense:
	i = 0
	data_buff = []
	while i < 20:
		data_buff.append(str(functions.linear(2, 0, i, 0.4)))
		i += 1
	thermo_brake_data.append([sensor] + data_buff)

####exponential
pressure_sense_data = []
for sensor in pressure_sense:
	i = 0
	data_buff = []
	while i < 20:
		data_buff.append(str(functions.exponential(3, i, 0.8)))
		i += 1
	pressure_sense_data.append([sensor] + data_buff)

prop_pressure_data = []
for sensor in prop_pressure_sense:
	i = 0
	data_buff = []
	while i < 20:
		data_buff.append(str(functions.exponential(3, i, 0.8)))
		i += 1
	prop_pressure_data.append([sensor] + data_buff)


with open("out.csv", "w") as csv_file:
	writer = csv.writer(csv_file, delimiter=',') 
	for row in dist_laser_data:
		writer.writerow(row)
	for row in dist_lidar_data:
		writer.writerow(row)
	for row in pressure_brake_data:
		writer.writerow(row)
	for row in thermo_brake_data:
		writer.writerow(row)
	for row in pressure_sense_data:
		writer.writerow(row)
	for row in prop_pressure_data:
		writer.writerow(row)


