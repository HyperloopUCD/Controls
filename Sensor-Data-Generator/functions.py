import math
import random

#Realistic temperature and pressure functions to be added later


#constant, y = c
def constant(constant, noise_factor):
	if noise_factor == 0:
		return constant
	else:
		generated_noise = random.uniform(-noise_factor, noise_factor)
		constant += generated_noise
		return generated_noise

#sigmoid, 1/(1 + e^-x)
def sigmoid(seconds_elapsed, noise_factor):
	if noise_factor == 0:
		return 1 / (1 + math.exp(-seconds_elapsed))
	else:
		generated_noise = random.uniform(-noise_factor, noise_factor)
		tmp = 1 / (1 + math.exp(-seconds_elapsed))
		tmp += generated_noise
		return tmp

#linear, y = mx + b
def linear(slope, intercept, seconds_elapsed, noise_factor):
	if noise_factor == 0:
		return slope * seconds_elapsed + intercept
	else:
		generated_noise = random.uniform(-noise_factor, noise_factor)
		tmp = slope * seconds_elapsed + intercept
		tmp += generated_noise
		return tmp

#exponental, y = base^(seconds_elapsed +- noise)
def exponential(base, seconds_elapsed, noise_factor):
	if noise_factor == 0:
		return base ** seconds_elapsed
	else:
		generated_noise = random.uniform(-noise_factor, noise_factor)
		tmp = base ** (seconds_elapsed + generated_noise)
		return tmp



