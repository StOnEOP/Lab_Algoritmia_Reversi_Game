//
// Created by  Pedro Faria - A72640 07/05/2019.
//

#ifndef LA_HISTORICO_H
#define LA_HISTORICO_H
struct Historico{
    int linha;
    int coluna;
    char peca;
    struct Historico* prox;

};
struct  Historico* top;

void addHjogada(int linha,int coluna);
void rmUltimaJogada();
#endif //LA_HISTORICO_H
