cmake_minimum_required(VERSION 3.17)
project(laboratory_work_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(laboratory_work_1 main.c linearform.c math.c mathComplex.h mathComplex.c console.h console.c tests.h tests.c)