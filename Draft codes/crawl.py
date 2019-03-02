CUR_POD_DISTANCE = 0  # in centimeters
CRAWL_SPEED = 223.52  # in centimeters / second
END_DISTANCE = 123000  # in centimeters
CRAWL_POWER = 50

def movePodWithMotor(power):
	pwmControl(power)

def slowCrawl(CRAWL_POWER):
  while CUR_POD_DISTANCE < END_DISTANCE:
    movePodWithMotor(CRAWL_POWER)

def crawl():
  slowCrawl(CRAWL_SPEED)
  brake()

crawl()