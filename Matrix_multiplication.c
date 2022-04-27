#include <stdio.h>

int main(void)
{
    int error=1;
    while(error==1) //this is used to ensure the user enters a valid matrix dimension
    {
        int row1,column1,row2,column2;
        printf("Enter rows and columns for first matrix:\n");
        scanf("%d",&row1);
        scanf("%d",&column1);
        printf("Enter rows and columns for second matrix:\n");
        scanf("%d",&row2);
        scanf("%d",&column2);

        if (row2==column1)
        {
            error=0;    //sets error to 0 after the user enters a valid dimension so that the program won't loop after that.
            int matrix1[row1][column1];
            int matrix2[row2][column2];
            int arow=1,acolumn=1,brow=1,bcolumn=1;

            printf("Enter elements of matrix 1:\n");
            while(arow<=row1)   //this part collects all the inputs and places them correctly in each corresponding matrix slot.
            {
                while(acolumn<=column1)
                {
                    printf("Enter elements a%d%d: ",arow,acolumn);
                    scanf("%d",&matrix1[arow][acolumn]);
                    ++acolumn;
                }
                ++arow;
                acolumn=1;
            }

            printf("\nEnter elements of matrix 2:\n");
            while(brow<=row2)
            {
                while(bcolumn<=column2)
                {
                    printf("Enter elements b%d%d: ",brow,bcolumn);
                    scanf("%d",&matrix2[brow][bcolumn]);
                    ++bcolumn;
                }
                ++brow;
                bcolumn=1;
            }

            int matrix3[row1][column2];
            int i=1,j=1;
            arow=1,acolumn=1,brow=1,bcolumn=1;

            while(i<=row1)
            {
                while(j<=column2)
                {
                    matrix3[i][j]=0;
                    ++j;
                }
                j=1;
                ++i;
            }
            i=1;

            while(i<=row1)  //this is where the matrix multiplication is actually done
            {
                while(j<=column2)
                {
                    while(acolumn<=column1)
                    {
                        matrix3[i][j]+=(matrix1[i][acolumn]*matrix2[brow][j]);
                        ++acolumn;
                        ++brow;
                    }
                    ++j;
                    acolumn=1,brow=1;
                }
                ++i;
                j=1;
            }

            i=1;
            printf("\nThe resulting matrix is\n");
            while(i<=row1)  //this loop displays the result in matrix form
            {
                while(j<=column2)
                {
                    printf("%d\t",matrix3[i][j]);
                    ++j;
                }
                printf("\n");
                j=1;
                ++i;
            }

        }

        else
        {
            printf("\aError: invalid matrix dimensions.\n\n");
        }
    }
    return 0;
}

