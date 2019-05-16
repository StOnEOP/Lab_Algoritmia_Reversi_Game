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

void load(ESTADO e,char ficheiro[MAX_BUF]){
    FILE *file;
    char c[9];

    file =fopen(ficheiro,"r");
    fscanf(file,"%c %c\n",e.modo,charToValor(e.peca));
    while(fgets(c, sizeof(c),file)) {
        for (int i = 0; i < 8; i++) {   // muda linha
            for (int j = 0; j < 8; j++) { // muda coluna
                e.grelha[i][j] = charToValor(c);
            }
        }
    }
}

VALOR charToValor(char c){ // converte 1 char em Valor
    if( c =='O') return VALOR_O;
    if( c =='X') return VALOR_X;
    if( c =='-') return VAZIA;
    else printf("ERRO: charToValor INVALIDO!!\n");

}
char valorToChar(VALOR p){ // converte da variavel VALOR, para 1 char
    if (p == VALOR_O) return 'O';
    if (p == VALOR_X) return 'X';
    if (p == VAZIA)   return '-';
    else printf("ERROR: valorToChar INVALIDO!!\n");
}