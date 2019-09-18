/*
Jogo interativo tetris implementado em linguagem c para uso 
no console (terminal de comando)

autor:Henrique
data:28/08/2019

*/

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

//Configuração das dimensoes da matriz principal do jogo
#define COLUMNS 60
#define ROWS 25

//Configuração de teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_A 97
#define TECLA_B 100



/*
    Inicializa a matriz principal com 'espaços vazios'

*/
void init(char matrix[ROWS][COLUMNS]);

/*
    Mostra o conteúdo da matriz principal na tela
    do computador.
*/
void printMatrix(char matrix[ROWS][COLUMNS]);