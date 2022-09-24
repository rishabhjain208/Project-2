#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
void gameRule();
void resetBoard();
void printbored();
void evilcomputer();
int winner();
void computer();
void XplayerMove();
void OplayerMove();
int countbored(char);
void playwithsmartcomp();
void playwithevilcomp();
void playwithplayer();
char place[10]={'o',' ',' ',' ',' ',' ',' ',' ',' ',' '};
int main()
{
    int n;
    char r;
    do{

        gameRule();
        resetBoard();
        printf("\n\tWELCOME TO TIC TAC TOE GAME MENU\n\n");
        printf("1. You want to play with Smart computer : \n");
        printf("\n");
        printf("2. You want to play with Evil computer : \n");
        printf("\n");
        printf("3. You want to play with your friend : \n");
        printf("\n");
        printf("\nEnter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                playwithsmartcomp();
            break;
            case 2:
                playwithevilcomp();
            break;
            case 3:
                 playwithplayer();

            break;
            default:
            printf("\nInvalid choice please select Valid choice :) \n");
        }
          printf("\nWould you like to play again? \n ");
          printf("\nPress y for (YES) and press n (NO) :) ");
          scanf("%c");
          scanf("%c", &r);
          system("cls");
        }while(r=='y');

        printf("\n\t  THANK YOU FOR PLAYING \n");
        return 0;

}
void gameRule()
{
    printf("\n\tWELCOME TO TIC TAC TOE GAME \n\n");
    printf("\n\n\n\t\t\tRULE OF TIC TAC TOE GAME\n\n\n");
    printf("1.X moves first\n\n");
    printf("2.A piece may be placed on any empty space\n\n");
    printf("3.A player wins by being the first to connect a line of friendly pieces from one side or corner of the board to the other.\n\n");
    printf("4.The game ends when either one player wins or it is no longer possible for a player to win (in which case the result is a draw).");
    printf("\n\n\tPress any key for continue the game.....\n ");
    getch();
    system("cls");
}
void resetBoard()
{
    for(int i=0; i<=9; i++)
        place[i]=' ';
}
void printbored()
{
    //system("cls");
    printf("\n------GAME STARTED------ \n\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",place[1],place[2],place[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",place[4],place[5],place[6]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",place[7],place[8],place[9]);
    printf("   |   |   \n");
}
/*void egbored()
{
    system("cls");
    printf("\n------GAME STARTED------ \n\n");
    printf("\n\nTHIS IS A EXAMPLE BORED MOVE YOUR CHANCE IN EMPTY BORED\n\n");
    //printf("\n------GAME STARTED------ \n\n");
    printf("   |   |   \n");
    printf(" 1 | 2 | 3 \n");
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" 4 | 5 | 6 \n");
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" 7 | 8 | 9 \n");
    printf("   |   |   \n");
}*/
int winner()
{
    if(place[1]==place[2] && place[2]==place[3] && place[1] != ' ')
    return place[1];
    if(place[4]==place[5] && place[5]==place[6] && place[4] != ' ')
    return place[4];
    if(place[7]==place[8] && place[8]==place[9] && place[7] != ' ')
    return place[7];
    if(place[1]==place[4] && place[4]==place[7] && place[1] != ' ')
    return place[1];
    if(place[2]==place[5] && place[5]==place[8] && place[2] != ' ')
    return place[2];
    if(place[3]==place[6] && place[6]==place[9] && place[3] != ' ')
    return place[3];
    if(place[1]==place[5] && place[5]==place[9] && place[1] != ' ')
    return place[1];
    if(place[3]==place[5] && place[5]==place[7] && place[3] != ' ')
    return place[3];

    if(countbored('X') + countbored('O') <= 9)
        return 'C';
    else
        return 'D';
}
void computer()
{
    srand(time(0));
    int value;
    do{
        value = rand() % 9;
    }while(place[value] != ' ');
     place[value] = 'O';
}
void evilcomputer()
{

    srand(time(0));
    int value;
    do{
        value = rand() % 10;
    }while(place[value] != ' ');
     place[value] = 'O';
     place[value] = 'O';
}
void XplayerMove()
{
    int value;
    while(1)
    {
        printf("\nEnter your move in between (1-9) : ");
        scanf("%d",&value);
        if(value < 1 || value > 9)
            printf("\nPlease Select the value form (1-9)\n");
         else if(place[value] != ' ')
                printf("\nPlease Select the Empty Position\n");
         else
         {
             place[value] = 'X';
             break;
         }
    }

}
void OplayerMove()
{
    int value;
    while(1)
    {
        printf("\nEnter your move in between (1-9) : ");
        scanf("%d",&value);
        if(value < 1 || value > 9)
            printf("\nPlease Select the value form (1-9)\n");
         else if(place[value] != ' ')
                printf("\nPlease Select the Empty Position\n");
         else
         {
             place[value] = 'O';
             break;
         }
    }

}
int countbored(char symbol)
{
   int total = 0;

   for(int i = 0; i <= 9; i++)
   {
         if(place[i] == symbol)
         {
            total += 1;
         }

   }
   return total;
}
void playwithsmartcomp()
{
     char str[20];
    printf("Enter the your name ");
    scanf("%s",&str);
    while(1)
    {
        system("cls");
        printbored();
        if(countbored('X') == countbored('O'))
        {
             printf("\n%s 's Turn \n",str);
             XplayerMove();
        }
        else
        {
            computer();
        }

        int check = winner();
        if(check == 'X')
        {
            system("cls");
            printbored();
            printf("\a\a\a\a\a\a\a\a\a \n Congratulations %s you Win the game :)\n",str);
            break;

        }
        else if(check=='O')
        {
            system("cls");
            printbored();
            printf("\a\a\a\a\a\a\a\a\a \n Computer win the game :)\n");
            break;
        }
        else if(check=='D')
        {
            printf("\a\a\a\a\a\a\a\a\a \n Drew the game :)\n");
            break;
        }
    }
}
void playwithevilcomp()
{
     char str[20];
    printf("Enter the your name ");
    scanf("%s",&str);
    while(1)
    {
        system("cls");
        printbored();
        if(countbored('X') == countbored('O'))
        {
             printf("\n%s 's Turn \n",str);
             XplayerMove();
        }
        else
        {
            evilcomputer();
        }

        int check = winner();
        if(check == 'X')
        {
            system("cls");
            printbored();
            printf("\a\a\a\a\a\a\a\a\a \n Congratulations %s you Win the game :)\n",str);
            break;

        }
        else if(check=='O')
        {
            system("cls");
            printbored();
            printf("\a\a\a\a\a\a\a\a\a \n Evil Computer win the game :)\n");
            break;
        }
        else if(check=='D')
        {
            printf("\a\a\a\a\a\a\a\a\a \n Drew the game :)\n");
            break;
        }
    }
}

void playwithplayer()
{
     char str1[20],str2[20];

    printf("Enter the X player name ");
    scanf("%s",&str1);
    printf("Enter the O player name ");
    scanf("%s",&str2);
    fflush(stdin);

    while(1)
    {   system("cls");
        printbored();
        if(countbored('X') == countbored('O'))
        {
             printf("\n%s 's Turn \n",str1);
             XplayerMove();
        }
        else
        {
             printf("\n%s 's Turn \n",str2);
             OplayerMove();
        }

        int check = winner();
        if(check == 'X')
        {
            system("cls");
            printbored();
            printf("\a\a\a\a\a\a\a\a\a \n Congratulations %s you Win the game :)\n",str1);
            break;

        }
        else if(check=='O')
        {
            system("cls");
            printbored();
            printf("\a\a\a\a\a\a\a\a\a \n Congratulations %s you Win the game :)\n",str2);
            break;
        }
        else if(check=='D')
        {
            printf("\a\a\a\a\a\a\a\a\a \n Drew the game :)\n");
            break;
        }
    }
}
