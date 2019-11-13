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
        if(barra->i>=0)matrix[barra->i][barra->j] = simbolo;
        if(barra->i-1>=0) matrix[barra->i-1][barra->j] = simbolo;
        if(barra->i-2>=0) matrix[barra->i-2][barra->j] = simbolo;
        if(barra->i+1<=ROWS && barra->i+1>=0) matrix[barra->i+1][barra->j] = simbolo;
        if(barra->i+2<=ROWS && barra->i+2>=0) matrix[barra->i+2][barra->j] = simbolo;
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
        if(barra->i+1<=ROWS) matrix[barra->i+1][barra->j] = simbolo;
        if(barra->i+2<=ROWS) matrix[barra->i+2][barra->j] = simbolo;
        break;
    }
    
        
       
}

void initBar(Bloco *barra){

    //barra->i=-2;
    barra->i=2;
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

int collisionDetect(char matrix[ROWS][COLUMNS], Bloco barra, int direcao){
    int retorno = 0;
    int i;
    
    //borda
    if ((barra.i + barra.height/2)  >= (ROWS-1))
        retorno = 1;

    //peça
    switch(direcao){
        case LEFT:
            for(i=barra.i -(barra.height/2); i<=barra.i +(barra.height/2); i++)
                if (matrix[i][(barra.j-barra.width/2)-1] == '\xdb')
                    retorno = 1;

        break;
        case RIGHT:
            for(i=barra.i -(barra.height/2); i<=barra.i +(barra.height/2); i++)
                if (matrix[i][(barra.j + barra.width/2)+1] == '\xdb')
                    retorno = 1;
        break;
        default:
            for(i=barra.j -(barra.width/2); i<=barra.j +(barra.width/2); i++)
                if (matrix[(barra.i +barra.height/2)+1][i] == '\xdb')
                    retorno = 1;

    }

    
    return retorno;
}

int collisionBar(char matrix[ROWS][COLUMNS],Bloco barra, int collideSides, int side){

    int retorno = 0;
    int i;
    
    //COLISAO COM A BAASE
    if((barra.i+1) >= ROWS)
    retorno = 1;

    //colisao com a base da barracom outras pecas
    if (matrix[barra.i+1][barra.j] != EMPTY)
        retorno = 1;
    
//colisão base horizontal
int t2 = barra.width/2;
if(matrix[barra.i+1][barra.j+t2] != EMPTY)
retorno = 1;
if(matrix[barra.i+1][barra.j-t2] != EMPTY)
retorno = 1;

//colisão lateral horizontal

if(collideSides==1){
    if(side==RIGHT && matrix[barra.i][barra.j + t2 + 1] != EMPTY)
        retorno = 1;
    if(side==RIGHT && barra.j + t2 +1 >=COLUMNS)
        retorno = 1;

    if(side==LEFT && matrix[barra.i][barra.j - t2 + 1] != EMPTY)
        retorno = 1;
    if(side==LEFT && barra.j - t2 - 1 < 0)
        retorno =1;

}

//colisao lateral vertical
if(collideSides==CHECK_SIDE &&
    (barra.orientacao == ORIENTACAO_UP ||
        barra.orientacao == ORIENTACAO_DOWN)){

    int i;
    for(i=0; i<barra.height; i++){
        if(side==RIGHT && matrix[barra.i-i][barra.j+1] != EMPTY)
        retorno = 1;
        if(side==RIGHT && matrix[barra.i-i][barra.j-1] != EMPTY)
        retorno = 1;
    }
        }
    
    return retorno;
}