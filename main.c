#include <stdio.h>
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

    init(matrix);
    printMatrix(matrix);

    system("PAUSE");
}