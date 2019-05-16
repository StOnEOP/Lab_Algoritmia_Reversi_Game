//
// Created by pedro on 16/05/2019.
//

#ifndef LA_FILES_H
#define LA_FILES_H
void save(ESTADO e,char ficheiro[MAX_BUF]);
void load(ESTADO e,char ficheiro[MAX_BUF]);
VALOR charToValor(char c);
char valorToChar(VALOR p);
#endif //LA_FILES_H
