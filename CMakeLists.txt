cmake_minimum_required(VERSION 3.10)
project(LA C)

set(CMAKE_C_STANDARD 99)

add_executable(LA main.c estado.h estado.c interpretador.c interpretador.h)
#target_link_libraries(LA m)