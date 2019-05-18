//
// Created by pedro on 16/05/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//
#include "estado.h"
#include "interpretador.h"
//
#include "files.h"
#include "etc.h"

/*
 * TODO:
 * falta adicionar a forma como grava e mais dificilmente como le, dependendo do nivel do bot 0 se MANUAL
 */

void save(ESTADO e,char ficheiro[MAX_BUF]){ // recebe 1 estado e 1 nome de ficheiro e cria esse ficheiro

    FILE *file;
    char c;

    file =fopen(ficheiro,"w"); // abre 1 ficheiro com o nome guardado na variavel ficheiro em modo de escrita
    fprintf(file,"%c %c\n",e.modo,valorToChar(e.peca)); // imprime as instruçoes para o ficheiro
    for(int i=0;i<8;i++){   // muda linha
        for(int j=0;j<8;j++){ // muda coluna
            c = valorToChar(e.grelha[i][j]);
            fprintf(file,"%c",c);
        }
        fprintf(file,"\n"); // muda de linha
    }
    fclose(file);
}

ESTADO load(ESTADO e,char ficheiro[MAX_BUF]){ // PROD FINAL
    FILE *file;
    char k,c;
    int i,j;

    file =fopen(ficheiro,"r");
    fscanf(file,"%c %c\n",&c,&k);
    e.modo=c;
    e.peca=charToValor(k);
    for (i = 0; i <=7; ++i){
        for (j = 0; j < 8; ++j){
            fscanf(file, "%c", &k);
            e.grelha[i][j] = charToValor(k);
        }
        fscanf(file, "%c\n", &k);
    }
    return e;
}


