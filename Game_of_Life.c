#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#define HEIGHT 20 //adjustable
#define WIDTH 40 //adjustable
#define TIME 10 //adjustable
#define SEED 57 //adjustable H20W40: 29(glider), 30(glider), 31(2-phase oscillator), 38(glider), 45(glider), 46(glider), 53(2-phase oscillator)

void hidecursor() //copied from stackOverflow, hides cursor
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

bool grid[HEIGHT][WIDTH]; //array representing the grid

void clear(bool grid[HEIGHT][WIDTH]); //this function sets all the cells to 0
void disp(bool grid[HEIGHT][WIDTH], unsigned short int emptySign); //this function prints out the grid, 0->dead, 1->live
void conway(bool grid[HEIGHT][WIDTH]); //this function copies the current grid, duplicates it, use the duplicate to check if the cell will come to live/die, and make changes on the original grid
int counter(bool gridRef[HEIGHT][WIDTH], int i, int j); //this function counts the neighbouring live cells

int main(void)
{
    int i, j;

    system("color a");
    clear(grid);

    while(1)
    {
        system("cls");
        disp(grid, 250);
        printf("0: Run\n1: Manual\n2: Random\n3: Clear\n");
        scanf("%d", &i);

        if(i == 0) break;


        if(i == 1)
        {
            while(1)
            {
                system("cls");
                disp(grid, 250);
                printf("Insert coordinate: (insert overflow value to back)\n");

                scanf("%d %d", &i, &j);
                if(grid[i][j]) grid[i][j] = 0; //erase
                else grid[i][j] = 1;
                if(i >= HEIGHT || j >= WIDTH || i < 0 || j < 0) break;
            }
        }


        if(i == 2)
        {
            unsigned int s; //seed for rand()
            short int d; //live cell density;

            while(1)
            {
                system("cls");
                disp(grid, 250);
                printf("Live cell density: (0 to back)\nIf (+): 1 live per _ dead cells\nIf (-): 1 dead per _ live cells\n");
                scanf("%d", &d);
                if(d == 0) break;

                while(1)
                {
                    system("cls");
                    disp(grid, 250);
                    printf("Seed: (0 to back)\n");
                    scanf("%d", &s);
                    if(s == 0) break;

                    srand(s); //seed

                    for(i=0; i<HEIGHT; i++)
                    {
                        for(j=0; j<WIDTH; j++)
                        {
                            if(d > 0) grid[i][j] = !(rand()%d); //controlling live cells
                            else grid[i][j] = rand()%-d; //controlling dead cells
                        }
                    }
                }

            }


        }


        if(i == 3) clear(grid);
    }


    hidecursor();
    while(1)
    {
        Sleep(TIME); //delay time(ms)
        conway(grid); //update grid by 1 generation
        //grid[HEIGHT-1][3] = 0; //this cell is buggy, had to turn it off
        system("cls"); //clearing the screen
        disp(grid, 0);
    }

}

void clear(bool grid[HEIGHT][WIDTH])
{
    int i, j;

    for(i=0; i<HEIGHT; i++) //initiate all cells to 0
    {
        for(j=0; j<WIDTH; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void disp(bool grid[HEIGHT][WIDTH], unsigned short int emptySign) //prints out the grid
{
    int i, j;

    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            printf("%c", grid[i][j]? 219 : emptySign); //219
        }
        printf("%d\n", i); //prints the row numbers
    }

    for(j=0; j<WIDTH; j++) //prints the column numbers
        printf("%d", j%10);
    printf("\n");

    for(j=0; j<=(WIDTH-1)/10; j++)
        printf("%d         ", j);
    printf("\n\n");
}

void conway(bool grid[HEIGHT][WIDTH]) //implementing the 4 rules
{
    bool gridRef[HEIGHT][WIDTH]; //creating a duplicate grid
    int i, j, neighbour;

    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            gridRef[i][j] = grid[i][j]; //copying content
        }
    }

    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            neighbour = counter(gridRef, i, j); //count on the duplicate grid, change the original

            if(gridRef[i][j]) //3 (summarized) rules for living cells: continues living if it has 2 or 3 living neighbouring cells, dies otherwise
            {
                if(neighbour < 2 || neighbour > 3) grid[i][j] = 0;
            }
            else //1 rule for dead cells: comes alive if it has exactly 3 living neighbouring cells
            {
                if(neighbour == 3) grid[i][j] = 1;
            }
        }
    }
}

int counter(bool gridRef[HEIGHT][WIDTH], int i, int j) //neighbour counting, corner cells have 3 neighbours, border cells have 5 neighbours, normal cells have 8 neighbours
{
    if(i==0 && j==0)            return gridRef[i][j+1] + gridRef[i+1][j] + gridRef[i+1][j+1] + gridRef[HEIGHT][0] + gridRef[HEIGHT][1] + gridRef[0][WIDTH] + gridRef[1][WIDTH] + gridRef[HEIGHT][WIDTH]; //upper left corner
    if(i==0 && j==WIDTH)        return gridRef[i][j-1] + gridRef[i+1][j] + gridRef[i+1][j-1] + gridRef[0][0] + gridRef[1][0] + gridRef[HEIGHT][WIDTH] + gridRef[HEIGHT][WIDTH-1] + gridRef[HEIGHT][0]; //upper right
    if(i==HEIGHT && j==0)       return gridRef[i][j+1] + gridRef[i-1][j] + gridRef[i-1][j+1] + gridRef[0][0] + gridRef[0][1] + gridRef[HEIGHT][WIDTH] + gridRef[HEIGHT-1][WIDTH] + gridRef[0][WIDTH]; //lower left
    if(i==HEIGHT && j==WIDTH)   return gridRef[i][j-1] + gridRef[i-1][j] + gridRef[i-1][j-1] + gridRef[HEIGHT][0] + gridRef[HEIGHT-1][0] + gridRef[0][WIDTH] + gridRef[0][WIDTH-1] + gridRef[0][0]; //lower right

    if(i==0)        return gridRef[i][j-1] + gridRef[i][j+1] + gridRef[i+1][j-1] + gridRef[i+1][j] + gridRef[i+1][j+1] + gridRef[HEIGHT][j-1] + gridRef[HEIGHT][j] + gridRef[HEIGHT][j+1];  //upper border
    if(j==0)        return gridRef[i-1][j] + gridRef[i+1][j] + gridRef[i-1][j+1] + gridRef[i][j+1] + gridRef[i+1][j+1] + gridRef[i-1][WIDTH] + gridRef[i][WIDTH] + gridRef[i+1][WIDTH];     //left border
    if(i==HEIGHT)   return gridRef[i][j-1] + gridRef[i][j+1] + gridRef[i-1][j-1] + gridRef[i-1][j] + gridRef[i-1][j+1] + gridRef[0][j-1] + gridRef[0][j] + gridRef[0][j+1];                 //lower border
    if(j==WIDTH)    return gridRef[i-1][j] + gridRef[i+1][j] + gridRef[i-1][j-1] + gridRef[i][j-1] + gridRef[i+1][j-1] + gridRef[i-1][0] + gridRef[i][0] + gridRef[i+1][0];                 //right border

    return gridRef[i][j-1] + gridRef[i][j+1] + gridRef[i-1][j-1] + gridRef[i-1][j] + gridRef[i-1][j+1] + gridRef[i+1][j-1] + gridRef[i+1][j] + gridRef[i+1][j+1]; //normal cells
}
