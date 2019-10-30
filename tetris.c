/*
Jogo interativo tetris implementado em linguagem c para uso 
no console (terminal de comando)

autor:Henrique
data:28/08/2019

*/
#define DEBUG 1
#include "tetris.h"
#define ESPACO "\t\t\t\t"

/*
    Inicializa a matriz principal com 'espaços vazios'

*/

void init(char matrix[ROWS][COLUMNS])
{
    int i,j;

    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLUMNS; j++)
        {
            matrix[i][j] = ' ';
        }   
    }
}

/*
    Mostra o conteúdo da matriz principal na tela
    do computador.
*/

void printMatrix(char matrix[ROWS][COLUMNS])
{
    int i,j;
    //borda de cima
    printf("\n");
    printf(ESPACO);
     for(j=0; j<COLUMNS+2; j++)
        {
           printf("*");
        }

    printf("\n");

    //correr pelo y da matriz
    for(i=0; i<ROWS; i++)
    {
        //print borda esquerda
        printf(ESPACO);
        printf("*");

        //correr pelo x da matriz
        for(j=0; j<COLUMNS; j++)
        {
            //print mapa
            printf("%c", matrix[i][j]);
        }

        //print borda direita
        
        printf("*");  

        printf("\n");
    }

    //print borda debaixo
    printf(ESPACO);
    for(j=0; j<COLUMNS+2; j++)
        {
        
           printf("*");
        }
}

//desenhar blocos
void drawBar(char matrix[ROWS][COLUMNS], Bloco *barra, int simbolo){
switch(barra->orientacao){
    case ORIENTACAO_UP:
        matrix[barra->i][barra->j] = simbolo;
        if(barra->i-1>=0) matrix[barra->i-1][barra->j] = simbolo;
        if(barra->i-2>=0) matrix[barra->i-2][barra->j] = simbolo;
        if(barra->i-3>=0) matrix[barra->i-3][barra->j] = simbolo;
        if(barra->i-4>=0) matrix[barra->i-4][barra->j] = simbolo;
        break;
    case ORIENTACAO_LEFT:
        
        //if(barra->j-1>=0) 
        //if(barra->j-2>=0)
        //if(barra->j+1<=COLUMNS)
        matrix[barra->i][barra->j-1] = simbolo;
        matrix[barra->i][barra->j-2] = simbolo;        
        matrix[barra->i][barra->j+1] = simbolo;
        matrix[barra->i][barra->j+2] = simbolo;
        matrix[barra->i][barra->j] = simbolo;
        break;

    case ORIENTACAO_RIGHT:
        
        //if(barra->j-1>=0) 
        //if(barra->j-2>=0)
        //if(barra->j+1<=COLUMNS)
        matrix[barra->i][barra->j-1] = simbolo;
        matrix[barra->i][barra->j-2] = simbolo;        
        matrix[barra->i][barra->j+1] = simbolo;
        matrix[barra->i][barra->j+2] = simbolo;
        matrix[barra->i][barra->j] = simbolo;
        break;

    case ORIENTACAO_DOWN:
        matrix[barra->i][barra->j] = simbolo;
        if(barra->i-1>=0) matrix[barra->i-1][barra->j] = simbolo;
        if(barra->i-2>=0) matrix[barra->i-2][barra->j] = simbolo;
        if(barra->i-3>=0) matrix[barra->i-3][barra->j] = simbolo;
        if(barra->i-4>=0) matrix[barra->i-4][barra->j] = simbolo;
        break;
    }
    
        
       
}

void initBar(Bloco *barra){

    barra->i=0;
    barra->j = COLUMNS/2;
    barra->tipo = TIPO_I;
    barra->orientacao = ORIENTACAO_UP;
    barra->width = 1;
    barra->height = 5;

    /*
    #if DEBUG == 1
        printf("INIT@ = (%d,%d)\n", barra->i, barra->j);
        system("pause");
        
    #endif
    */
}
void rotate(Bloco *barra){
        if(barra->orientacao == ORIENTACAO_RIGHT)
            barra->orientacao = ORIENTACAO_UP;
            
        else
            
            barra->orientacao++;

        //else if(barra->orientacao == ORIENTACAO_LEFT)barra->orientacao = ORIENTACAO_UP;
           
        //right to up
        //else barra->orientacao++;

        //inverte dimensoes
        int aux = barra->width;
        barra->width = barra->height;
        barra->height = aux;

        //resolvendo bug dos cantos    
        if(barra->j< (barra->width/2)) 
            barra->j=barra->width/2;
        if(barra->j> COLUMNS - (barra->width/2) -1)
            barra->j= COLUMNS - (barra->width/2) -1;
            }
int collisionDetect(char matrix[ROWS][COLUMNS], Bloco barra){
    int retorno = 0;

    if ((barra.i + barra.height/2)  >= (ROWS-1))
        retorno = 1;

    return retorno;
}