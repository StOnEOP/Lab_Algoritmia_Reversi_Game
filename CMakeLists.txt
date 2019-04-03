cmake_minimum_required(VERSION 3.10.2)
project(LA C)

set(CMAKE_C_STANDARD 99)

add_executable(LA main.c estado.h estado.c interpretador.h interpretador.c)
#target_link_libraries(LA m)