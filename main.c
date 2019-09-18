/*
Jogo interativo tetris implementado em linguagem c para uso no console (terminal de comando)

Para exectuar:
    > start programa.exe

autor:Henrique
data:28/08/2019

*/

#include "tetris.h"

/*
    Parte principal do programa, responsável por iniciar
    chamar e as funções auxiliares.
*/

main()
{
    char matrix [ROWS][COLUMNS];
    int posI, posJ;
    int a = 1;
    char b = a;
    posI = ROWS/2;
    posJ = COLUMNS/2;
    init(matrix);
    int m;

    int tecla;

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");
    while(tecla != 27){ /*!kbhit()*/
        
        
            gotoxy(0,0);
    
    //apaga @
    //matrix[posI][posJ+1] = ' ';
    //matrix[posI-1][posJ] = ' ';
    

    //escreve@
    matrix[posI][posJ] = '@';

    printMatrix(matrix);
    printf("%d", m);
    //b = getch();
    //if(posJ>COLUMNS-COLUMNS) posJ--;
    //walk left
    /*if(posJ>0) posJ--;
    */
    //matrix[posI][posJ] = ' ';
    matrix[posI][posJ] = ' ';

    //224

   // walk down
    if(posI<ROWS-1) posI++;

    

    if(kbhit()){
        tecla = getch();
        /*if(tecla == 'a')
        posJ--;*/
        m = tecla;
    }

  
  

    switch(tecla){
        //case 224: 
            //if(kbhit()) tecla = getch();
               // switch(tecla){
                    case 75: 
                        if(posJ > 0)posJ--;
                    break;
                    case 77: 
                        if(posJ < COLUMNS-1)posJ++;
                    break;
                //}
        //break;
        case 97: 
            if(posJ > 0)posJ--;
        break;
        case 100: 
            if(posJ < COLUMNS-1)posJ++;
        break;
    }

    //apaga tecla
    tecla = 0;

    }
    
    
    
    system("PAUSE");
    //.c-o.ex start.\pr
}


            
