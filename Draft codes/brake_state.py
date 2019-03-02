POD_VELOCITY = 100

activateBrake()

if POD_VELOCITY <= 0:
	disengageBrake()
	cmd = 7