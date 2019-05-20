//
// Created by  Pedro Faria - A72640 07/05/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//
#include "estado.h"
#include "interpretador.h"
//
#include "etc.h"
#include "jogar.h"
#include "historico.h"
//
#include "files.h"
/*
 * TODO:
 * criar 1 top que contem 1 estado completo, sempre que se joga guarda-se o estado completo, para fazer undo basta 2 ciclos for e e.grelha[i][j] = h.grelha[i][j];
 */

int addHjogada(ESTADO e){ // adiciona 1 jogada ao historico
    struct Historico* temp;
    temp = (struct Historico*)malloc(sizeof(struct Historico));

    if (!temp) printf("\nHistorico cheio\n");
    for(int i=0;i<8;i++) {   // muda linha
        for (int j = 0; j < 8; j++) { // muda coluna
            temp->h.grelha[i][j] = e.grelha[i][j];
        }
    }
    temp->prox =top;
    top=temp;
    return (EXIT_SUCCESS);
}

ESTADO undoJogada(ESTADO e) {
    for(int i=0;i<8;i++) {   // muda linha
        for (int j = 0; j < 8; j++) { // muda coluna
            e.grelha[i][j] = top->h.grelha[i][j];
        }
    }
    rmUltimaJogada();
    return e;
}
void rmUltimaJogada(){

    struct Historico* temp;
    if (top == NULL) printf("Stack Vazia\n");
    else {
        temp = top;
        top = top->prox;
        free(temp);
    }
}
