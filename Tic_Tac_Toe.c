/**
    This is a code for tic-tac-toe.
    It uses a 2-dimension array to store and process the game information.
    The code currently only supports player vs. player mode.
    The final goal of this project is to create an unbeatable A.I.
    Further improvements includes random player to move first, random signs, multiple difficulty levels, 4x4 etc.
*/

#include<stdio.h>
#include<stdlib.h>  //test
#include<time.h>  //test

void sprt(char s);  //adds separator of any symbol
void disint(char arr[3][3]);  //displays game interface
void distmp(char arr[3][3]);  //displays template
void intl(char arr[3][3]);  //initializes all the entries
void input(char arr[3][3],int n,int m,int s);  //prompts input from the player
void ai(char arr[3][3], int n);  //A.I. function. Haven't figured out.
int windet(char arr[3][3]);  //reads template and detects winner
void draw(void);  //announces a drawn match
void annwin(int n);  //announces the winner
int restart();  //gives option to restart

void main(void)
{
    while(1)
    {
        char arr[3][3];
        int n,gg=0,s,m;  //round counter, end game indicator, starting player, game mode

        intl(arr);
        disint(arr);
        printf("\nPlay against? Bot:1 Player:0\n");  //choose play mode. These functions prompts input that are passed down into another function, moving them out of the main function creates mess
        scanf("%d",&m);
        disint(arr);
        if(m)  //choose starting player. Only appears when AI mode is chosen
        {
            printf("\nWho goes first? You:1 Bot:0\n");
            scanf("%d",&s);
        }
        disint(arr);
        for(n=0;n<9;n++)
        {
            input(arr,n,m,s);  //passes no. of round to determine which player's turn, passes game mode, passes starting player
            disint(arr);
            if(gg=windet(arr)) break;  //return 1 or 0
        }
        if(gg==0) draw();
        else annwin(n);  //player who made the final move wins
        if (restart());
        else break;
    }
    return 0;
}

void sprt(char s)
{
    int i;

    for(i=0;i<35;i++)
    printf("%c",s);
    printf("\n");
}

void disint(char arr[3][3])
{
    system("cls");  //clears screen
    sprt('*');
    printf("       Welcome to TIC-TAC-TOE!\n");
    sprt('*');
    sprt('-');
    printf("\t    How to play:\nEnter desired entry's corresponding\n      position on the num pad.\n");
    printf("\t   For reference:\n\t     [7][8][9]\n\t     [4][5][6]\n\t     [1][2][3]\n");
    sprt('-');
    sprt('=');
    printf("\n\tTIC\tTAC\tTOE\n\n");
    distmp(arr);
    sprt('=');
}

void distmp(char arr[3][3])
{
    int i,j;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\t");
            printf("[%c]",arr[i][j]);
        }
        printf("\n\n");
    }
}

void intl(char arr[3][3])
{
    char *pt=arr;
    int i;

    for(i=0;i<9;i++)
    {
        *(pt+i)=' ';
    }
}

void input(char arr[3][3],int n,int m,int s)
{


    int z,r,c;


    //when AI mode is chosen
    if(m)
    {
        if(s)  //when player goes first
        {
            if(n%2)  //decides when it is the AI's turn. Condition can be easily changed to swap first move.
            {
                ai(arr,n);
                return;
            }
        }
        else  //when AI goes first
        {
            if(n%2==0)
            {
                ai(arr,n);
                return;
            }
        }
    }


    //when PVP mode is chosen, or during player's turn in AI mode
    while(1)  //prevents input to occupied entry
    {
        while(1)  //prevents an invalid number
        {
                printf("\nIt's %c's turn: ",(n%2)?'x':'o');  //alternates signs
                scanf("%d",&z);  //the number's position on the num pad corresponds to the position of the entries
                if(z>0&&z<10) break;
                else printf("invalid input!\n\n");
        }
        c=(z-1)%3;  //determines column based on num pad layout
        r=(9-z)/3;  //determines row based on num pad layout
        if(arr[r][c]==' ') break;
        else printf("entry taken!\n\n");
    }
    arr[r][c]=(n%2)?'x':'o';


}

void ai(char arr[3][3],int n)
{


    int i,j,r;
    char *pt=arr;


    if(n<8)  //when there's only one entry left, skip this part and take the entry right away. Solved the lagging when there's one move away from a draw.
    {


        for(i=0;i<3;i++)  //winning move checker (for AI)
        {
            for(j=0;j<3;j++)  //scans through each entry
            {
                if(arr[i][j]==' ')  //proceeds only when entry is not taken
                {
                    arr[i][j]=(n%2)?'x':'o';  //checks for winning moves for the AI, before checking for the opponent's
                    if (windet(arr))
                    {
                        return;  //the function should end when a move is made, the correct move has already been made when checking
                    }
                    arr[i][j]=' ';  //returns to initial state if nothing happens
                }
            }
        }


        for(i=0;i<3;i++)  //winning move checker (for player)
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]==' ')
                {
                    arr[i][j]=(n%2)?'o':'x';  //reversed symbols so that it inserts opponent's symbol
                    if (windet(arr))
                    {
                        arr[i][j]=(n%2)?'x':'o';  //takes the entry to prevent opponent from taking it and winning
                        return;
                    }
                    arr[i][j]=' ';  //returns to initial state if nothing happens
                }
            }
        }


    }


    else  //finds the last entry and fills it
    {
        pt=arr;  //resetting the pointer
        for(i=0;i<9;i++)
        {
            if(*(pt+i)==' ')
            {
                *(pt+i)=(n%2)?'x':'o';
                return;
            }
        }
    }


    while(1) //fills random entry when no strategic moves can be made
    {
        pt=arr;
        srand(time(0));  //seed (don't understand yet)
        r=rand()%9;  //generates random number between 0-8
        if(*(pt+r)==' ')  //prevents filling taken entries
        {
            *(pt+r)=(n%2)?'x':'o';
            return;
        }
    }


}

int windet(char arr[3][3])
{
    int i;

    for(i=0;i<3;i++)
    {
        if((arr[i][0]==arr[i][1])&&(arr[i][1]==arr[i][2])&&(arr[i][0]!=' ')) return 1;  //scans rows
    }
    for(i=0;i<3;i++)
    {
        if((arr[0][i]==arr[1][i])&&(arr[1][i]==arr[2][i])&&(arr[0][i]!=' ')) return 1;  //scans columns
    }
    if((arr[0][0]==arr[1][1])&&(arr[1][1]==arr[2][2])&&(arr[0][0]!=' ')) return 1; //scans horizontals
    if((arr[0][2]==arr[1][1])&&(arr[1][1]==arr[2][0])&&(arr[0][2]!=' ')) return 1; //scans horizontals
    return 0;
}

void draw(void)
{
    sprt('-');
    printf("            It's a draw!\n");
    sprt('-');
}

void annwin(int n)  //announces the winner
{
    sprt('*');
    printf("      Player %c wins the game!\n",(n%2)?'X':'O');
    sprt('*');
}

int restart()  //gives option to restart
{
    int a;

    printf("Play again? Yes:1 No:0\n");
    scanf("%d",&a);
    return (a);
}


