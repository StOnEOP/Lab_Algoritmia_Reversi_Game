//
// Created by Pedro Faria - A72640 on 29/03/2019.
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
#include "validas.h"
#include "undo.h"

ESTADO interpretar (ESTADO e, char *linha) {

    char cmd[MAX_BUF];
    char ficheiro[MAX_BUF];
    char peca[MAX_BUF];
    int lin, col,n;

    n = sscanf(linha, "%s", cmd);

    switch (toupper(linha[0])) {
        case 'N' :
            n = sscanf(linha, "%s %s", cmd, peca);
            switch (toupper(peca[0])) {
                case 'X' :
                    e = gInicial(e, VALOR_X, 'M');
                    break;
                case 'O' :
                    e = gInicial(e, VALOR_O, 'M');
                    break;
                default:
                    printf("Tem de escolher a peça que quer jogar: X ou O\n");
            }
            e.modo='M';
            break;
        case 'L':
            n = sscanf(linha,"%s %s", cmd, ficheiro);//falta fazer o Fopen e ler o ficheiro
            printf("Num. de parametros lidos:%d\n",n);
            printf("Ler um jogo do fcheiro:%s\n",ficheiro);
            break;
        case 'E':
            n =sscanf(linha,"%s %s",cmd,ficheiro);
            printf("Gravar um jogo no ficheiro:%s\n", ficheiro);
            save(e,ficheiro); // recebe o estado atual do jogo e um nome de ficheiro e cria esse ficheiro {FARIA.C}
            break;
        case 'J':
            n= sscanf(linha, "%s %d %d", cmd, &lin, &col);
            lin--;
            col--;
            e= jogar(e,lin,col);
            printf("Num de parametros lidos:%d\n",n);
            printf("Jogar na posição lina: %d e coluna: %d\n",lin,col);

            break;
        case 'S':
            printf("Sugestão de jogadas\n");
            e=validasJogada(e);
            break;
        case 'U':
            printf("Desfazendo ultima jogada\n");
            undoJogada(e);
            break;
        case 'H':
            break;
        case 'A':

            e.modo='A';
            break;
        case 'Q':
            exit(0);
        default:
            printf("Comando Invalido!\n");
    }
    printa(e);
    return e;
}

void print_prompt(ESTADO e){
    switch (e.peca){
        case VALOR_X:
            printf("%s X>",PROMPT);
            break;
        case VALOR_O:
            printf("%s O>",PROMPT);
            break;
        default:
            printf("%s ?>", PROMPT);
    }
}

void interpretador(ESTADO e){
    char linha[MAX_BUF];
    print_prompt(e);
    while (fgets(linha,MAX_BUF,stdin)){
        e= interpretar(e,linha);
        print_prompt(e);
    }
}
