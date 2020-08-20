kalman_execute: run.o KalmanFilter.o
	g++ run.o KalmanFilter.o -o kalman_execute

run.o: run.cpp KalmanFilter.o
	g++ -c run.cpp

KalmanFilter.o: KalmanFilter.cpp KalmanFilter.h
	g++ -c KalmanFilter.cpp


