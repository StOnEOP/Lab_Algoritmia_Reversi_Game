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
#include <malloc.h>

/*
 * weight = [[99,-8,8,6,6,8,-8,99],
            [-8,-24,-4,-3,-3,-4,-24,-8],
            [8,-4,7,4,4,7,-4,8],
            [6,-3,4,0,0,4,-3,6],
            [6,-3,4,0,0,4,-3,6],
            [8,-4,7,4,4,7,-4,8],
            [-8,-24,-4,-3,-3,-4,-24,-8],
            [99,-8,8,6,6,8,-8,99]]
 */


void addHjogada(int linha,int coluna){ // adiciona 1 jogada ao historico
    struct Historico* temp;
    temp = (struct Historico*)malloc(sizeof(struct Historico));

    if (!temp) printf("\nHistorico cheio\n");
    temp->linha = linha;
    temp->coluna= coluna;
    temp->prox =top;
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
