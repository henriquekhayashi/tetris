/*
Jogo interativo tetris implementado em linguagem c para uso 
no console (terminal de comando)

autor:Henrique
data:28/08/2019

*/

#include "tetris.h"

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
            /* if(i==0)matrix[i][j] = '*';
            else if(i==ROWS-1)matrix[i][j] = '*';
            else if(j==0)matrix[i][j] = '*';
            else if(j==COLUMNS-1)matrix[i][j] = '*';
            else*/
            //if( i!=0 && i!=ROWS-1 && J!=0 && J!=ROWS-1)
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
     for(j=0; j<COLUMNS+2; j++)
        {
           printf("*");
        }

    printf("\n");

    //correr pelo y da matriz
    for(i=0; i<ROWS; i++)
    {
        //print borda esquerda
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

    //borda debaixo
    for(j=0; j<COLUMNS+2; j++)
        {
           printf("*");
        }
}