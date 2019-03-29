//
// Created by pedro on 29/03/2019.
//

#ifndef PROJ_INTERPRETADOR_H
#define PROJ_INTERPRETADOR_H

#include "estado.h"
#define PROMPT "Reversi"

ESTADO interpretar(ESTADO e,char *linha);

void interpretador(ESTADO e);

void print_prompt(ESTADO e);

#endif //PROJ_INTERPRETADOR_H
