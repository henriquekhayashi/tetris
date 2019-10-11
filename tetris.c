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
    printf("\n");
    printf("\t\t\t\t\t");
     for(j=0; j<COLUMNS+2; j++)
        {
           printf("*");
        }

    printf("\n");

    //correr pelo y da matriz
    for(i=0; i<ROWS; i++)
    {
        //print borda esquerda
        printf("\t\t\t\t\t");
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
    printf("\t\t\t\t\t");
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
        break;
    case ORIENTACAO_LEFT:
        

        if(barra->j-1<=0) barra->j++;
        matrix[barra->i][barra->j-1] = simbolo;
        if(barra->j-2<=0) barra->j+=2;
        matrix[barra->i][barra->j-2] = simbolo;        
        if(barra->j+1<=COLUMNS) matrix[barra->i][barra->j+1] = simbolo;
        matrix[barra->i][barra->j] = simbolo;
        break;
    }
    
        
       
}