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
#include "display.h"
#define DEBUG 1
/*
    Parte principal do programa, responsável por iniciar
    chamar e as funções auxiliares.
*/

int main()
{
    char matrix [ROWS][COLUMNS];
    //int posI, posJ;
    Bloco tijolo;

    //posição inicial do personagem
 /* tijolo.i=0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_UP;
    tijolo.width = 1;
    tijolo.height = 5;
*/

    //apagar o cursor da tela
    ShowConsoleCursor(0);
   
    system("cls");

    //posicao inicial do personagem
    initBar(&tijolo);
   
    //inicializando matriz
    init(matrix);
    int m;

    int tecla;

   
   
    while(1){ 
        
        
            gotoxy(0,0);
    
    //print posição do @
    #if DEBUG == 1
        printf("posicao = (%d,%d)\n", tijolo.i, tijolo.j);
        printf("dimensao = (%d, %d)\n", tijolo.width, tijolo.height);
    #endif
    
      //escreve@
     drawBar(matrix, &tijolo, PIXEL);
    
    printMatrix(matrix);
    
    //APAGAR
    
    if(!collisionDetect(matrix, tijolo)){
        drawBar(matrix, &tijolo, EMPTY);
    
        // faz posilçao ir para baixo
        if(tijolo.i<ROWS-1) tijolo.i++;
    }else{
        initBar(&tijolo);
    }
    
  //drawBar(matrix, &tijolo, EMPTY);
    

   

    

    if(kbhit()){
        tecla = getch();
       
      
    }

    //MOVER
    switch(tecla){
        case ARROWS: 
            if(kbhit()) tecla = getch();
                switch(tecla){
                    case LEFT: 
                        if(tijolo.j - tijolo.width/2 > 0 ) tijolo.j--;
                        //else if(tijolo.j > 0 && tijolo.orientacao != ORIENTACAO_LEFT  )tijolo.j--;
                        
                    break;
                    case RIGHT: 
                        if(tijolo.j + tijolo.width/2 < COLUMNS-1)tijolo.j++;
                    break;
                }
        break;
        case TECLA_A: 
            if(tijolo.j > 0)tijolo.j--;
        break;
        case TECLA_D: 
            if(tijolo.j < COLUMNS-1)tijolo.j++;
        case 'R':
        case TECLA_R: //GIRAR

           rotate(&tijolo);
        break;
    }

    // sair com esc
    if (tecla == ESC) break;

    //apaga tecla
    tecla = 0;

    }
    
    
    
    system("PAUSE");
    
    return 0;
}


            
