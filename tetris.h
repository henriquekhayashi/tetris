/*
Jogo interativo tetris implementado em linguagem c para uso 
no console (terminal de comando)

autor:Henrique
data:28/08/2019

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Configuração das dimensoes da matriz principal do jogo
#define COLUMNS 14
#define ROWS 50

//Configuração de teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_A 97
#define TECLA_D 100
#define TECLA_R 114

//Criando as orientações das peças
#define ORIENTACAO_UP 1
#define ORIENTACAO_LEFT 2
#define ORIENTACAO_DOWN 3
#define ORIENTACAO_RIGHT 4

//Criando os tipos de peças
#define TIPO_L 1
#define TIPO_L_R 2 //L reverso
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5 //Z reverso
#define TIPO_O 6 //Quadrado
#define TIPO_I 7

//Configurações de layou
#define PIXEL 219
#define EMPTY 32

//Configurações de mecanismo de colisão
#define CHECK_SIDE 1
#define UNCHECK_SIDE 0
#define NONE 0

//Estrutura padrão de componentes
typedef struct{
    int i; //posição linhas da matriz
    int j; //posição colunas matriz
    int orientacao; //orientação da peça
    int tipo; // o tipo de 7 possiveis

    int width; //largura
    int height; //altura
}Bloco;


/*
    Inicializa a matriz principal com 'espaços vazios'

*/
void init(char matrix[ROWS][COLUMNS]);

/*
    Mostra o conteúdo da matriz principal na tela
    do computador.
*/
void printMatrix(char matrix[ROWS][COLUMNS]);

void drawBar(char matrix[ROWS][COLUMNS], Bloco* barra, int simbolo); 

/*
    Inicializar peça do tipo barra
*/
void initBar(Bloco *barra);

/*
    rotacionar peça
*/
void rotate(Bloco *barra);
/*
    colisão com a base
*/

int collisionDetect(char matrix[ROWS][COLUMNS],Bloco barra, int direcao);

/*
    colisão entre peças
*/

int collisionBar(char matrix[ROWS][COLUMNS],Bloco barra, int collisionSides, int side);

//