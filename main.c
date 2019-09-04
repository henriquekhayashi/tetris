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

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");
    while(!kbhit()){
        
            gotoxy(0,0);
    
    //apaga @
    //matrix[posI][posJ+1] = ' ';
    matrix[posI-1][posJ] = ' ';
    //escreve@
    matrix[posI][posJ] = '@';

    printMatrix(matrix);
    //b = getchar();
    //if(posJ>COLUMNS-COLUMNS) posJ--;
    //walk left
    /*if(posJ>0) posJ--;
    */

   // walk down
    if(posI<ROWS-1) posI++;
    }
    

    
    system("PAUSE");
    //.c-o.ex start.\pr
}


            
