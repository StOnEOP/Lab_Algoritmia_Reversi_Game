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
    char k,c,n;
    int i,j;
    /*
     * TODO:
     * Em modo automático (A), após leitura do ficheiro, o próximo jogador a jogar é sempre o humano!
     * apenas falta devolver a peçaBot e saltar para o proximo jogador
     *
     */
    file =fopen(ficheiro,"r");
    fscanf(file,"%c ",&n);
    if (n =='A'){
        e.modo=n;
        fscanf(file,"%c %d\n",&k,&e.nivel);
        e.pecaBot= charToValor(k);
        e.peca =inverte(e.pecaBot);
    }else {
        e.modo='M';
        fscanf(file,"%c %c \n",&e.modo,&c);
        e.peca= charToValor(c);
    }

    for (i = 0; i < 8; ++i){
        for (j = 0; j < 8; ++j){
            fscanf(file,"%c ",&k);
            e.grelha[i][j] = charToValor(k);
        }

        fscanf(file,"\n",NULL);
    }
    return e;
}


