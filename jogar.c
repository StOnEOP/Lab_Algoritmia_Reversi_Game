//
// Created by Pedro Faria - A72640 02/05/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estado.h"
#include "interpretador.h"
#include "faria.h"
#include "jogar.h"

void limpavalidas(ESTADO *e){
    for(int i=0;i<8;i++) {
        for (int j = 0; j < 8; j++) {
            if(e->grelha[i][j]==VALIDA){
                e->grelha[i][j]=VAZIA;
            }
        }
    }

}

void jogar(ESTADO *e,int linha,int coluna){ // verifica se a jogada é valida e joga-a
    // verificar se a jogada é valida e se o local selecionado está vazio
    limpavalidas(e);
    check(e,linha,coluna);
    if (e->grelha[linha-1][coluna-1] == VALIDA) {
        e->grelha[linha-1][coluna-1] = e->peca;
    }else printf("Jogada Invalida\n");





}
void check(ESTADO *e,int linha,int coluna){
    checkLinha(e, linha, coluna);
    checkColuna(e, linha, coluna);
    checkDiagEsq(e, linha, coluna);
    checkDiagDir(e, linha, coluna);
}

void jogadaValida(ESTADO *e,int linha,int coluna){
    check(e,linha,coluna);



}
/*VALOR oposto(VALOR v){
    if(v==VALOR_X){
        return VALOR_O;
    }else if(v==VALOR_O){
        return VALOR_X;
    }
}*/

int checkLinha(ESTADO *e,int linha,int coluna){
    int p = 0;int r=0; int l=linha; int c =coluna; int c2=coluna-2;
    if(e->grelha[linha-1][coluna]== inverte(e)){
        while(e->grelha[linha-1][c]!=e->peca || coluna < 8 ){
            ++c;
            p=1;




        }
            if(e->grelha[linha-1][c]==e->peca && p==1){
                e->grelha[linha-1][coluna-1]=VALIDA;

        }

    }else if(e->grelha[linha-1][coluna-2]== inverte(e)){
        while(e->grelha[linha-1][c2]!=e->peca || coluna > 0 ){
            --c2;
            r=1;



        }

        if(e->grelha[linha-1][c2]==e->peca&&r==1){
            e->grelha[linha-1][coluna-1]=VALIDA;


        }

    }

}

int checkColuna(ESTADO *e,int linha, int coluna) {
    int p = 0;int r=0; int l=linha; int c =coluna; int l2 =linha-2;
    if(e->grelha[linha][coluna-1]== inverte(e)){
        while(e->grelha[l][coluna-1]!=e->peca||linha < 8 || coluna < 8 ){
            ++l;
            p=1;


        }
        if(e->grelha[l][coluna-1]==e->peca&&p==1){
            e->grelha[linha-1][coluna-1]=VALIDA;
        }


    }else if(e->grelha[linha-2][coluna-1]== inverte(e)){
        while(e->grelha[l2][coluna-1]!=e->peca||linha >0|| coluna > 0 ){
            --l2;
            r=1;


        }
        if(e->grelha[l2][coluna-1]== e->peca && r==1){
            e->grelha[linha-1][coluna-1]=VALIDA;
        }


    }

}


int checkDiagDir(ESTADO *e,int linha, int coluna){ // verifica se há uma jogada valida na Diagonal direita
    int c = coluna;int l = linha; int p = 0; int r=0;int c2=coluna-2; int l2=linha-2;
    if(e->grelha[linha][coluna]==inverte(e)){
        while(e->grelha[c][l]!=e->peca || c < 8||l > 0){
            ++c;
            --l;
            p=1;

        }
        if(e->grelha[l][c]==e->peca&& p==1){
            e->grelha[linha-1][coluna-1]=VALIDA;
        }

    }else if(e->grelha[linha-2][coluna-2]==inverte(e)){
        while(e->grelha[l2][c2]!=e->peca||c>0||l<8){
            --c2;
            ++l2;
            r=1;

        }
        if(e->grelha[l2][c2]==e->peca && r==1){
            e->grelha[linha-1][coluna-1]=VALIDA;
        }
    }


}

int checkDiagEsq(ESTADO *e,int linha, int coluna) { // verifica se há uma jogada valida na Diagonal direita
    int c = coluna-2;int l = linha;int c2 =coluna;int l2=linha-2; int r = 0; int p = 0;
    if(e->grelha[linha][coluna-2]==inverte(e)){
        while(e->grelha[l][c] !=e->peca || l>0||c>0){
            --c;
            --l;
            p=1;
        }
        if(e->grelha[l][c]==e->peca&&p==1){
            e->grelha[linha-1][coluna-1]=VALIDA;
        }
    }else if(e->grelha[linha-2][coluna]==inverte(e)){
        while(e->grelha[l2][c2]!=e->peca||l2<8||c2<8){
            ++l2;
            ++c2;
            r=1;

        }
        if(e->grelha[l2][c2]==e->peca&&r==1){
            e->grelha[linha-1][coluna-1]=VALIDA;
        }

    }



}//void virarPecas(ESTADO e,int linha,int coluna){}

void pontos(ESTADO e){
    printf("\n\t1 2 3 4 5 6 7 8\n"
           "\t________________\n\n");

    char c = ' ';


    for (int i = 0; i < 8; i++) {
        printf("%d|\t",(i+1));        // imprime a label á esquerda
        for (int j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
                case VALIDA: {
                    c = '.';
                }

            }
            printf("%c ", c);

        }
        printf("\n");
    }
    printf("\n");

}
