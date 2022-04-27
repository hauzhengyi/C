#include<stdio.h>
#define ROW 7
#define COL 5
int maze[ROW][COL] = {
    {2, 0, 2, 2, 2 },
    {2, 2, 2, 0, 2 },
    {2, 0, 0, 2, 2 },
    {2, 2, 2, 2, 0 },
    {2, 0, 2, 2, 2 },
    {0, 0, 2, 2, 0 },
    {0, 0, 2, 2, 2 }
};
int solveMaze(int row, int col)
{
    maze[row][col] = 1;
    if(row == ROW-1 && col == COL-1)
        return 1;
    if(row != 0)
        if(maze[row-1][col] == 2)
            if(solveMaze(row-1, col)) return 1;
    if(row != ROW-1)
        if(maze[row+1][col] == 2)
            if(solveMaze(row+1, col)) return 1;
    if(col != 0)
        if(maze[row][col-1] == 2)
            if(solveMaze(row, col-1)) return 1;
    if(col != COL-1)
        if(maze[row][col+1] == 2)
            if(solveMaze(row, col+1)) return 1;
    maze[row][col] = 2;
    return 0;
}
int main()
{
    int i, j;
    if(solveMaze(0, 0))
        for(i = 0; i < ROW; i++) {
            for(j = 0; j < COL; j++)
                printf("%d ", maze[i][j]);
            printf("\n");
        }
    else
        printf("Maze not solvable");
}
