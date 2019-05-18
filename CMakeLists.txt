cmake_minimum_required(VERSION 3.10.2)
project(LA C)

set(CMAKE_C_STANDARD 99)

add_executable(LA main.c estado.h estado.c interpretador.h interpretador.c etc.c etc.h jogar.c jogar.h historico.c historico.h undo.c undo.h validas.c validas.h check.c check.h files.c files.h bot.c bot.h)
#target_link_libraries(LA m)