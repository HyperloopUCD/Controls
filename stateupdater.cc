

/*
cmd = 1 -> BEGIN cmd
cmd = 2 -> IDLE
cmd = 3 -> ARM
cmd = 4 -> LAUNCH
cmd = 5 -> stop
cmd = 6 -> CRAWL
cmd = 7 -> END
cmd = 8 -> EGSD

*/
int cmd = 0; // 

/*
1  idle
2  System check
3  Armed
4  Acceleration
5  Coast
6  Brake
7  stop
8  CRAWL
9  End
10 Emergency shutdown
*/
int currentState = 0;
int newState = 0;





