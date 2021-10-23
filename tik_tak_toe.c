// TIK TAK TOE game in C

#include<stdio.h>
#include<stdlib.h>

// function prototype
void chooseplayer();
void drawboard();

//global variable
char a[9]={'1','2','3','4','5','6','7','8','9'};
int count=0;

void reinitializarrays()
{
    for(int i=0,j=49;i<=8;i++,j++){
        a[i]=(char)j;       //typecasting integer to char
    }
}
void gamename()
{
    printf("\n\n\t\t++|++===========================++|++");
    printf("\n\t\t\t TIK TAK TOE GAME");
    printf("\n\t\t++|++===========================++|++");
    printf("\n\n\t\tPress any key to start the game :\n");
    getchar();

}

int checkwinner()
{
    if((a[0]=='X' && a[1]=='X' && a[2]=='X') || (a[0]=='X' && a[3]=='X' && a[6]=='X') || (a[0]=='X' && a[4]=='X' && a[8]=='X') || (a[1]=='X' && a[4]=='X' && a[7]=='X') || (a[2]=='X' && a[5]=='X' && a[8]=='X') || (a[2]=='X' && a[4]=='X' && a[6]=='X') || (a[3]=='X' && a[4]=='X' && a[5]=='X') || (a[6]=='X' && a[7]=='X' && a[8]=='X'))
    {
        return 100;
    }
    else if((a[0]=='O' && a[1]=='O' && a[2]=='O') || (a[0]=='O' && a[3]=='O' && a[6]=='O') || (a[0]=='O' && a[4]=='O' && a[8]=='O') || (a[1]=='O' && a[4]=='O' && a[7]=='O') || (a[2]=='O' && a[5]=='O' && a[8]=='O') || (a[2]=='O' && a[4]=='O' && a[6]=='O') || (a[3]=='O' && a[4]=='O' && a[5]=='O') || (a[6]=='O' && a[7]=='O' && a[8]=='O'))
    {
        return 200;
    }
    else 
    {
        return 300;
    }

}
void startgame(char player,char position)
{
    int i;
    for (i=0;i<=8;i++)
    {
        if(player == '1' && position == a[i])
        {   
            a[i]='X';
            drawboard();
        }
        else if(player == '2' && position == a[i])
        { 
            a[i]='O';
            drawboard();
        }
    }

}

void chooseplayer()
{
    char player = 0,position=0;
    printf("\n\n\t\t Chose player : \n\t\t <1> for player 1 \n\t\t <2> for player 2\n");
    fflush(stdin);
    scanf("%c", &player);
    printf("\n\t\t Player %c \n\t\t enter position :\n", player);
    fflush(stdin);
    scanf("%c", &position);
    count++;
    startgame(player,position);
}

void playerSymbol()
{
    printf("\n\n\t\t++|++===========================++|++");
    printf("\n\t\t player 1 : X \n\t\t player 2 : O ");
    printf("\n\t\t++|++===========================++|++\n");
}

void drawboard()
{
    system("cls");

    printf("\n\t\t++|++===========================++|++");
    printf("\n\t\t  |\t   |---|---|---|\t  |");
    printf("\n\t\t  |\t   | %c | %c | %c |\t  |",a[0],a[1],a[2]);
    printf("\n\t\t  |\t   |---|---|---|\t  |");
    printf("\n\t\t  |\t   | %c | %c | %c |\t  |",a[3],a[4],a[5]);
    printf("\n\t\t  |\t   |---|---|---|\t  |");
    printf("\n\t\t  |\t   | %c | %c | %c |\t  |",a[6],a[7],a[8]);
    printf("\n\t\t  |\t   |---|---|---|\t  |");
    printf("\n\t\t++|++===========================++|++");
}



// begin main function
int main()
{
    start:
    gamename();
    drawboard();
    playagain:
    playerSymbol();
    chooseplayer();
    int win=checkwinner();
    char Yn;

    if(count<9)
    {
        if (win==100){
            printf("\n\n\t\t++|++===========================++|++");
            printf("\n\t\t   congratulations Player 1 won!!!");
            printf("\n\t\t++|++===========================++|++");

        }
        else if (win==200)
        {   
            printf("\n\n\t\t++|++===========================++|++");
            printf("\n\t\t   congratulations Player 2 won!!!");
            printf("\n\t\t++|++===========================++|++");
        }
        else
        {
            goto playagain;
        }
    }
    else
    {
        printf("\n\n\t\t++|++===========================++|++");
        printf("\n\t\tMatch Draw\n");
        printf("\n\t\t++|++===========================++|++");

    }
        printf("\n\n\t\tDo you wanna play it again?\n\t\tPress :\n\t\t'y' for Yes :\n\t\t'n' for No :\n");
        fflush(stdin);
        scanf("%c",&Yn);
        if(Yn =='y'|| Yn =='Y'){
            reinitializarrays();
            goto start;
        }
        else
        {
            return 0;
        }
    return 0;
}
// end of main
