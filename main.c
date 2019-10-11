/*
Jogo interativo tetris implementado em linguagem c para uso no console (terminal de comando)

Para exectuar:
    > start programa.exe

autor:Henrique
data:28/08/2019

.c-o.ex start.\pr
.\compile
-o pr -d debug=1
*/

#include "tetris.h"
#define DEBUG 1
/*
    Parte principal do programa, responsável por iniciar
    chamar e as funções auxiliares.
*/

main()
{
    char matrix [ROWS][COLUMNS];
    //int posI, posJ;
    Bloco tijolo;

    //posição inicial do personagem
    tijolo.i=0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_UP;
    tijolo.width = 1;
    tijolo.height = 4;

   // posI = ROWS/2;
   // posJ = COLUMNS/2;
   
    //inicializando matriz
    init(matrix);
    int m;

    int tecla;

    //apagar o cursor da tela
    ShowConsoleCursor(0);
   
    system("cls");
   
   //while(tecla != 27){ /*!kbhit()*/
    while(1){ /*!kbhit()*/
        
        
            gotoxy(0,0);
    
    //print posição do @
    #if DEBUG == 1
        printf("@ = (%d,%d)\n", tijolo.i, tijolo.j);
    #endif
    
    //apaga @
    //matrix[posI][posJ+1] = ' ';
    //matrix[posI-1][posJ] = ' ';
    


    //escreve@
     drawBar(matrix, &tijolo, PIXEL);
    
    printMatrix(matrix);
   
   //print tecla
    //printf("%d", m);
   
    //b = getch();
    //if(posJ>COLUMNS-COLUMNS) posJ--;
    //walk left
    /*if(posJ>0) posJ--;
    */
    //matrix[posI][posJ] = ' ';


    //APAGAR
  drawBar(matrix, tijolo, EMPTY);
    //224

   // walk down
    if(tijolo.i<ROWS-1) tijolo.i++;

    

    if(kbhit()){
        tecla = getch();
       
       //print tecla
        //m = tecla;
    }

  
    /*
    sem if 224 ele precisa fazer o loop uma segunda vez para exectuar o movimento
    224
    75 ou 77
    */

    switch(tecla){
        case 224: 
            if(kbhit()) tecla = getch();
                switch(tecla){
                    case 75: 
                        if(tijolo.j > 0)tijolo.j--;
                    break;
                    case 77: 
                        if(tijolo.j < COLUMNS-1)tijolo.j++;
                    break;
                }
        break;
        case 97: 
            if(tijolo.j > 0)tijolo.j--;
        break;
        case 100: 
            if(tijolo.j < COLUMNS-1)tijolo.j++;
        case 114:

            if(tijolo.orientacao == ORIENTACAO_UP)tijolo.orientacao = ORIENTACAO_LEFT;
            else if(tijolo.orientacao == ORIENTACAO_LEFT)tijolo.orientacao = ORIENTACAO_UP;
        break;
    }

    // sair com esc
    if (tecla == 27) break;

    //apaga tecla
    tecla = 0;

    }
    
    
    
    system("PAUSE");
    
}


            
