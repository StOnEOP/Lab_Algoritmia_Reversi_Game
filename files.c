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
 * falta adicionar a forma como le, dependendo do nivel do bot 0 se MANUAL
 */

void save(ESTADO e,char ficheiro[MAX_BUF]){ // recebe 1 estado e 1 nome de ficheiro e cria esse ficheiro

    FILE *file;
    char c;

    file =fopen(ficheiro,"w"); // abre 1 ficheiro com o nome guardado na variavel ficheiro em modo de escrita
    if (e.modo == 'A'){         // caso seja modo de jogo BOT, tera de guardar 3 variaveis, nao 2
        char k = e.nivel + '0';
        fprintf(file,"%c %c %c\n",e.modo,valorToChar(e.peca),k);
    }else fprintf(file,"%c %c\n",e.modo,valorToChar(e.peca)); // imprime as instruçoes para o ficheiro



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
    int i,j,n=0;
    /*
     * TODO:
     * Em modo automático (A), após leitura do ficheiro, o próximo jogador a jogar é sempre o humano!
     * apenas falta devolver a peçaBot e saltar para o proximo jogador
     *
     */
    file =fopen(ficheiro,"r");
    fscanf(file,"%c",&c);
    if (c=='A'){
        fscanf(file,"%c %c %d\n",&c,&k,&n);
    }else fscanf(file,"%c %c \n",&e.modo,&k);
    e.modo=c;
    e.peca=charToValor(k);
    e.nivel = n;
    /*
     * TODO:
     * NAO ESTA A LER O MODO ? tambem nao grava modo nem nivel AI quando feito apartir de 1 load, logo o load nao esta a guardar bem essas variaveis
     * Idealmente o load teria de ser feito com Fgets, guardar a variavel numa string, remover espaços e por os valores da string no estado. pois de momento apenas aceita
     * tabuleiros com estaços entre valores
     */

    for (i = 0; i < 8; ++i){
        for (j = 0; j < 8; ++j){
            fscanf(file,"%c ",&k);
            e.grelha[i][j] = charToValor(k);
        }

        fscanf(file, "\n",k);
    }
    return e;
}


