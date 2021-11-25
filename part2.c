#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 10

int main()
{   //initializing variables
    int command;
    char Numbers[size][7] = {0};
    int Num1 = 0;
    int Exit = 0;


    //main loop
    while (Exit != 1)
    {
        //displaying options
        printf("\n1-Add\n2-Search\n3-Delete\n4-List\n5-Exit\n");
        printf("Insert a number then press enter: ");
        scanf_s("%d", &command);

        //picking command
        switch (command)
        {
        case 1: //add

            int c;//clearing getchar buffer
            if ((c = getchar()) != '\n' && c != EOF)
            {
            }

            printf("Add a new number\n");
            printf("Type the number then hit enter\n");
            for (int i = 0; i < 7; i++)
            {//getting each number as an individual value in the array, i kind of cheated it by using getchar
                int ch = getchar();

                //getchar stores the number in ascii as the number+48
                Numbers[Num1][i] = ch - 48;
            }
            Num1++;//going to the next row in the array for the next add command

            //clearing the getchar buffer again
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            break;
        case 2: //search

        case 3: //delete
            int delete;
            printf("Which number would you like to delete?\n");

            //printing all the numbers with a number beside it indicating row
            for (int i = 0; i < size; i++)
            {
                printf("%d - ", i + 1);
                for (int j = 0; j < 7; j++)
                {
                    printf("%d ", Numbers[i][j]);
                }
                puts("");
            }

            printf("Number: ");
            scanf_s("%d", &delete);
            //this loop just overwrites the number with the number below it, so the cleared row is put at the bottom
            for (int i = delete - 1; i < size; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    if (i == size-1)
                    {
                        Numbers[i][j] = 0;
                    }
                    else if (i < size)
                    {
                        Numbers[i][j] = Numbers[i + 1][j];
                    }
                }
            }
            //decreasing the num counter for the add command
            Num1--;
            break;

        case 4: //list
        //this just prints the entire array, it could probably be optimized so it only prints the row if it has a number
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    printf("%d ", Numbers[i][j]);
                }
                puts("");
            }
            break;

        case 5: //exit
        //by setting exit to 1, the while loop ends
            Exit++;
            break;
        }
    }
}