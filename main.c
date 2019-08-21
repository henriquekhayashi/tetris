#include <stdio.h>
#include <stdlib.h>
#define COLUMNS 30
#define ROWS 10

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

void printMatrix(char matrix[ROWS][COLUMNS])
{
    int i,j;

    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLUMNS; j++)
        {
            printf("%c", matrix[i][j]);
        }   
        printf("\n");
    }
            
}

main()
{
    char matrix [ROWS][COLUMNS];
    int posI, posJ;
    int a = 1;
    char b = a;
    posI = ROWS/2;
    posJ = COLUMNS/2;
    init(matrix);
    while(!kbhit()){
        system("cls");

    
    matrix[posI][posJ-1] = ' ';
    matrix[posI][posJ] = '@';

    printMatrix(matrix);
    //b = getchar();

    if(posJ<COLUMNS-1) posJ++;

    }
    
    
    system("PAUSE");
    
}