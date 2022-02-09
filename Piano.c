#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#include <mem.h>

#define UPARR 72
#define LEFTARR 75
#define DOWNARR 80
#define RIGHTARR 77
int m, s, s1, s2, s3, s4, s5, s6, s7, s8;
void main()
{
    FILE *save;
    int r, y, sss, c, i, tt, ft, fc, pr, sc, t;
    void sounddef(int), player(char), sig(void), bod(void), menu(int), recplayer(char);
    char opt, o, op, so, a[1000], rec[100];
    textcolor(GREEN);
    clrscr();
    /* for(sc=0,pr=0;pr<=100;pr+=sc,sc+=2)
     {
      bod();
      if(sc>19)
       pr=100;
      gotoxy(5,12);
      printf("\t\t\t    LOADING PIANO.....%d%\n",pr);
      if(sc>19)
       break;
      sig();
      if(pr==100)
       break;
     }
     gotoxy(31,18);
     printf("  PRESS ENTER!");
     getch();   */
defaul:
    m = 100;
    s = 200;
menu:
    clrscr();
    menu(1);
    gotoxy(54, 9);
    printf("%c", 174);

    for (y = 9;;)
    {
        if (kbhit())
        {
            opt = getch();
            if (opt == DOWNARR && y != 17)
            {
                clrscr();
                menu(1);
                gotoxy(54, y + 2);
                y += 2;
                printf("%c", 174);
            }
            if (opt == UPARR && y != 9)
            {
                clrscr();
                menu(1);
                gotoxy(54, y - 2);
                y -= 2;
                printf("%c", 174);
            }
            if (opt == 13)
                break;
        }
    }
    switch (y)
    {
    case 9:
        goto piano;
    case 11:
        goto settings;
    case 13:
        goto again;
    case 15:
        save = fopen("sav.pi", "r");
        flushall();
        fscanf(save, "%s", rec);
        fclose(save);
        sounddef(s);
        for (fc = 0; fc < strlen(rec); fc++)
            recplayer(rec[fc]);
        exit(0);
    case 17:
        goto exit;
    }
again:
    clrscr();
    sounddef(s);
    printf("\n\n\t\t\t   Piano is On Recording Mode!\n\n\n\t\t You Can Play Piano Using Keyboard Keys From A-L.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t Once completed Press Enter To Stop Recording.");
    gotoxy(1, 1);
    bod();
    for (i = 0;;)
    {
        o = getch();
        if (o == 13 || o == 'a' || o == 's' || o == 'd' || o == 'f' || o == 'g' || o == 'h' || o == 'j' || o == 'k' || o == 'l' || o == 'A' || o == 'S' || o == 'D' || o == 'F' || o == 'G' || o == 'H' || o == 'J' || o == 'K' || o == 'L')
        {
            a[i] = o;
            i++;
        }
        player(o);
        if (o == 13)
            break;
    }
    if (i == 0)
    {
        clrscr();
        for (sss = 5; sss != 0; sss--)
        {
            gotoxy(20, 10);
            printf("Nothing Recorded. Please Try Again In %d.", sss);
            gotoxy(1, 1);
            bod();
            delay(1000);
        }
        goto again;
    }
    clrscr();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\tSuccessfully Recorded. Press Enter To Here Your Recordings....");
    gotoxy(1, 1);
    bod();
    getch();
replay:
    clrscr();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t%c %c Playing....... %c %c\n", 14, 14, 14, 14);
    gotoxy(1, 1);
    bod();
    for (t = 0; t <= i; t++)
        recplayer(a[t]);
    y = 11;
smu:
    clrscr();
    menu(3);
    if (y != 11)
        gotoxy(54, y);
    else
        gotoxy(54, 11);
    printf("%c", 174);
    for (;;)
    {
        if (kbhit())
        {
            so = getch();
            if (so == DOWNARR && y != 17)
            {
                clrscr();
                menu(3);
                gotoxy(54, y + 2);
                y += 2;
                printf("%c", 174);
            }
            if (so == UPARR && y != 11)
            {
                clrscr();
                menu(3);
                gotoxy(54, y - 2);
                y -= 2;
                printf("%c", 174);
            }
            if (so == 13)
                break;
        }
    }
    switch (y)
    {
    case 11:
        goto replay;
    case 13:
        save = fopen("sav.pi", "w");
        fprintf(save, "%s", a);
        fclose(save);
        gotoxy(31, 23);
        printf("Succesfully Saved!");
        sleep(1);
        delline();
        goto smu;
    case 15:
        i = 0;
        memset(a, 0, 1000);
        goto menu;
    case 17:
        i = 0;
        memset(a, 0, 1000);
        goto exit;
    }
    if (opt == 99) /*Shold Never Occur, Just to prevent malfunctoning of GOTO*/
    {
    settings:
        clrscr();
        menu(2);
        gotoxy(54, 9);
        printf("%c", 174);
        for (y = 9;;)
        {
            if (kbhit())
            {
                op = getch();
                if (op == DOWNARR && y != 15)
                {
                    clrscr();
                    menu(2);
                    gotoxy(54, y + 2);
                    y += 2;
                    printf("%c", 174);
                }
                if (op == UPARR && y != 9)
                {
                    clrscr();
                    menu(2);
                    gotoxy(54, y - 2);
                    y -= 2;
                    printf("%c", 174);
                }
                if (op == 13)
                    break;
            }
        }
        switch (y)
        {
        case 9:
            clrscr();
            printf("\tCurrent beep time in millisecond is %d.\n\n\n\tPlease Enter the time in millisecond to change it.\n\n\n\tNOTE:[1s=1000ms].\n\n\n\t", m);
            gotoxy(1, 1);
            bod();
            gotoxy(7, 11);
            printf("Your Required Time :\t");
            scanf("%d", &tt);
            m = tt;
            printf("\n\n\tSuccessfully Changed To %dms.\n\n\tPress Any Key To Return", m);
            gotoxy(1, 1);
            bod();
            getch();
            goto menu;
        case 11:
            clrscr();
            printf("\n\n\n\n\n\tCurrent Staring Frequency Is %d.\n\n\n\tPlease Enter The New One : \t", s);
            gotoxy(1, 1);
            bod();
            gotoxy(36, 9);
            scanf("%d", &ft);
            s = ft;
            printf("\n\n\n\tStarting Frequency Successfully Changed To %d.\n\n\tPress Any Key To Return\n", s);
            gotoxy(1, 1);
            bod();
            getch();
            goto menu;
        case 13:
            gotoxy(20, 17);
            printf("\tRESTORING");
            for (c = 0; c <= 12; c++)
            {
                printf(".");
                delay(250);
            }
            printf("\n\n\n\t\t\tSuccessfully Restored To Default Settings.\n\n\t\t\tPress Enter To Return.\n");
            gotoxy(1, 1);
            bod();
            getch();
            goto defaul;
        case 15:
            goto menu;
        }
    }
    if (opt == 99) /*Shold Never Occur, Just to prevent malfunctoning og GOTO*/
    {
    piano:
        sounddef(s);
        clrscr();
        printf("\n\n\t Piano is ON! You Can Play It Using Keyboard Keys From A-L.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t   Press B To Go Back. \n\n\t\t\t   Press Q to Exit.");
        gotoxy(1, 1);
        bod();
        for (i = 0;; i++)
        {
            o = getch();
            player(o);
            if (o == 'B' || o == 'b')
                goto menu;
            if (o == 'q' || o == 'Q')
                goto exit;
        }
    exit:
        clrscr();
        gotoxy(23, 10);
        printf("Are You Sure You Want To Exit??  [Y/N]");
        gotoxy(1, 1);
        bod();
    h:
        so = getch();
        if (toupper(so) == 'Y')
        {
            clrscr();
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t     Bye\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tBy Divins.");
            gotoxy(1, 1);
            bod();
            for (i = -1; i != -1; i--)
            {
                gotoxy(44, 11);
                printf("(%d)", i);
                sleep(1);
            }
            exit(0);
        }
        else if (toupper(so) == 'N')
            goto menu;
        else
        {
            gotoxy(16, 20);
            printf("\t\tEnter 'Y' For Yes Or 'N' For No.");
            goto h;
        }
    }
}
void sounddef(int s)
{
    s1 = s + 100;
    s2 = s1 + 100;
    s3 = s2 + 100;
    s4 = s3 + 100;
    s5 = s4 + 100;
    s6 = s5 + 100;
    s7 = s6 + 100;
    s8 = s7 + 100;
}

void player(char o)
{
    if (o == 'a' || o == 'A')
    {
        sound(s);
        delay(m);
        nosound();
    }
    if (o == 's' || o == 'S')
    {
        sound(s1);
        delay(m);
        nosound();
    }
    if (o == 'd' || o == 'D')
    {
        sound(s2);
        delay(m);
        nosound();
    }
    if (o == 'f' || o == 'F')
    {
        sound(s3);
        delay(m);
        nosound();
    }
    if (o == 'g' || o == 'G')
    {
        sound(s4);
        delay(m);
        nosound();
    }
    if (o == 'h' || o == 'H')
    {
        sound(s5);
        delay(m);
        nosound();
    }
    if (o == 'j' || o == 'J')
    {
        sound(s6);
        delay(m);
        nosound();
    }
    if (o == 'k' || o == 'K')
    {
        sound(s7);
        delay(m);
        nosound();
    }
    if (o == 'l' || o == 'L')
    {
        sound(s8);
        delay(m);
        nosound();
    }
}
void sig(void)
{
    gotoxy(40, 7);
    printf("%c", 15);
    delay(100);
    gotoxy(41, 7);
    printf("%c", 16);
    gotoxy(39, 7);
    printf("%c", 17);
    delay(100);
    gotoxy(42, 7);
    printf("%c", 16);
    gotoxy(38, 7);
    printf("%c", 17);
    delay(100);
    gotoxy(37, 7);
    printf("%c", 17);
    gotoxy(43, 7);
    printf("%c", 16);
    delay(100);
    clrscr();
}
void bod(void)
{
    int i;
    gotoxy(0, 0);
    printf("%c", 201);
    for (i = 0; i < 77; i++)
        printf("%c", 205);
    printf("%c", 187);
    for (i = 0; i < 23; i++)
    {
        printf("\n");
        printf("%c", 186);
        if (i == 22)
            printf("\n");
    }
    printf("%c", 200);
    for (i = 0; i < 77; i++)
        printf("%c", 205);
    printf("%c", 188);
    for (i = 0; i < 23; i++)
    {
        gotoxy(79, i + 2);
        printf("%c", 186);
    }
}
void menu(int o)
{
    switch (o)
    {
    case 1:
        printf("\n\n\n\n\n\n\n\n\t\t\t Start Piano.\n\n\t\t\t Change Beep Settings.\n\n\t\t\t Enter Recording Mode.\n\n\t\t\t Play Saved Recordong.\n\n\t\t\t Exit.");
        gotoxy(1, 1);
        bod();
        break;
    case 2:
        printf("\n\n\n\n\n\n\n\n\t\t\t Change Time Seconds.\n\n\t\t\t Change Frquency Settings.\n\n\t\t\t Reset Default Settings.\n\n\t\t\t Go Back.");
        gotoxy(1, 1);
        bod();
        break;
    case 3:
        printf("\n\n\n\n\t\t\t\t  Clip Completed.\n\n\n\n\n\n\t\t\t    Here It Again.\n\n\t\t\t    Save This Recording.\n\n\t\t\t    Return To Menu.\n\n\t\t\t    Exit.\n");
        gotoxy(1, 1);
        bod();
    }
}
void recplayer(char a)
{
    int i;

    if (a == 'a' || a == 'A')
    {
        sound(s);
        delay(m);
        nosound();
        delay(100);
    }
    if (a == 's' || a == 'S')
    {
        sound(s1);
        delay(m);
        nosound();
        delay(100);
    }
    if (a == 'd' || a == 'D')
    {
        sound(s2);
        delay(m);
        nosound();
        delay(100);
    }
    if (a == 'f' || a == 'F')
    {
        sound(s3);
        delay(m);
        nosound();
        delay(100);
    }
    if (a == 'g' || a == 'G')
    {
        sound(s4);
        delay(m);
        nosound();
        delay(100);
    }
    if (a == 'h' || a == 'H')
    {
        sound(s5);
        delay(m);
        nosound();
        delay(100);
    }
    if (a == 'j' || a == 'J')
    {
        sound(s6);
        delay(m);
        nosound();
        delay(100);
    }
    if (a == 'k' || a == 'K')
    {
        sound(s7);
        delay(m);
        nosound();
        delay(100);
    }
    if (a == 'l' || a == 'L')
    {
        sound(s8);
        delay(m);
        nosound();
        delay(100);
    }
}
