//
// Created by  Pedro Faria - A72640 07/05/2019.
//

#ifndef LA_HISTORICO_H
#define LA_HISTORICO_H
struct Historico{
    ESTADO h;
    struct Historico* prox;

};
struct  Historico* top;

int addHjogada(ESTADO e;);
void rmUltimaJogada();

ESTADO undoJogada(ESTADO e);
#endif //LA_HISTORICO_H
