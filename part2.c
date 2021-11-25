#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 10

int main()
{
    int command;
    char Numbers[size][7] = {0};
    int Num1 = 0;
    int Exit = 0;
    while (Exit != 1)
    {

        printf("\n1-Add\n2-Search\n3-Delete\n4-List\n5-Exit\n");
        printf("Insert a number then press enter: ");
        scanf_s("%d", &command);

        switch (command)
        {
        case 1: //add

            int c;
            if ((c = getchar()) != '\n' && c != EOF)
            {
            }
            printf("Add a new number\n");
            printf("Type the number then hit enter\n");
            for (int i = 0; i < 7; i++)
            {
                int ch = getchar();

                Numbers[Num1][i] = ch - 48;
            }
            Num1++;

            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            break;
        case 2: //search

        case 3: //delete
            int delete;
            printf("Which number would you like to delete?\n");
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
            Num1--;
            break;
        case 4: //list
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
            Exit++;
            break;
        }
    }
}