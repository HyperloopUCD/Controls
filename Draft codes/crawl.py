CUR_POD_DISTANCE = 0  # in centimeters
CRAWL_SPEED = 223.52  # in centimeters / second
END_DISTANCE = 123000  # in centimeters
CRAWL_POWER = 50	

def slowCrawl(CRAWL_POWER):
  pwmControl(power)


def crawl():
  if CUR_POD_DISTANCE < END_DISTANCE:
    slowCrawl(CRAWL_POWER)
  else:
  	slowCrawl(0)  # Stop the motors
  	cmd = 5

crawl()