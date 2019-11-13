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

    int i;
   
   
    while(1){ 
        
        
            gotoxy(0,0);
    
    //print posição do @
    #if DEBUG == 1
        printf("posicao = (%d,%d)\n", tijolo.i, tijolo.j);
        printf("dimensao = (%d, %d)\n", tijolo.width, tijolo.height);
                
        //matrix[(tijolo.i + tijolo.height/2)+1][tijolo.j]
        
    #endif
    
      //escreve@
     drawBar(matrix, &tijolo, PIXEL);
    
    printMatrix(matrix);
    
    //APAGAR
    
    /*if(!collisionDetect(matrix, tijolo, 0)){
        drawBar(matrix, &tijolo, EMPTY);
        // faz peça ir para baixo
        tijolo.i++;*/

    if(!collisionBar(matrix, tijolo, UNCHECK_SIDE, NONE)){
        drawBar(matrix, &tijolo, EMPTY);
        // faz peça ir para baixo
        tijolo.i++;
        
        
    }else{
        //check

        //nova peça
        initBar(&tijolo);
    }
    
  
    

   
  //  int m = getch();
    

    if(kbhit()){
        tecla = getch();
       
      
    }

    //MOVER
    switch(tecla){
        case ARROWS: 
            if(kbhit()) tecla = getch();
                switch(tecla){
                    case LEFT: 
                       /* if(tijolo.j - tijolo.width/2 > 0 )
                                                               
                        if(!collisionDetect(matrix, tijolo, LEFT))*/
                        if(!collisionBar(matrix, tijolo, CHECK_SIDE, LEFT))
                         tijolo.j--;
                    break;

                    case RIGHT: 
                        /*if(tijolo.j + tijolo.width/2 < COLUMNS-1)
                        if(!collisionDetect(matrix, tijolo, RIGHT))*/
                        if(!collisionBar(matrix, tijolo, CHECK_SIDE, RIGHT))
                        tijolo.j++;
                    break;
                }
        break;

        case TECLA_A: 
            if(tijolo.j - tijolo.width/2 > 0 )
                if(!collisionDetect(matrix, tijolo, LEFT))
                    tijolo.j--;
        break;
        
        case TECLA_D: 
            if(tijolo.j + tijolo.width/2 < COLUMNS-1)
                if(!collisionDetect(matrix, tijolo, RIGHT))
                    tijolo.j++;
        
        case 'R':
        case TECLA_R: //GIRAR
           if(!collisionDetect(matrix, tijolo, RIGHT)) 
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


            
