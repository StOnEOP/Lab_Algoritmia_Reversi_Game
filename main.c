#include <stdio.h>
#include "estado.h"
#include "interpretador.h"


int main() {
    ESTADO e = {0};
    printf("Para começar a jogar use o cmand: N <peça> \n");
    interpretador (e);
    return 0;
}