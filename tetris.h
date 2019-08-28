/*
Jogo interativo tetris implementado em linguagem c para uso 
no console (terminal de comando)

autor:Henrique
data:28/08/2019

*/

#include <stdio.h>
#include <stdlib.h>

//Configuração das dimensoes da matriz principal do jogo
#define COLUMNS 30
#define ROWS 10
/*
    Inicializa a matriz principal com 'espaços vazios'

*/
void init(char matrix[ROWS][COLUMNS]);

/*
    Mostra o conteúdo da matriz principal na tela
    do computador.
*/
void printMatrix(char matrix[ROWS][COLUMNS]);