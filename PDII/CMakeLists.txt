cmake_minimum_required(VERSION 3.13)
project(PD2_Oneloop C)

set(CMAKE_C_STANDARD 11)

add_executable(PD2_Oneloop main.c sensors.h health.h health.c)