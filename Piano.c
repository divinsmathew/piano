#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#include <mem.h>
int m, s, s1, s2, s3, s4, s5, s6, s7, s8;
void main()
{
    int sss, c, i, tt, ft, pr, sc, t = 0;
    void sounddef(int), player(char), sig(void), bod(void);
    char opt, o, op, so, a[1000];
    textcolor(GREEN);
    clrscr();
    for (sc = 0, pr = 0; pr <= 100; pr += sc, sc += 2)
    {
        bod();
        if (sc > 19)
            pr = 100;
        gotoxy(5, 12);
        printf("\t\t\t    LOADING PIANO.....%d%\n", pr);
        if (sc > 19)
            break;
        sig();
        if (pr == 100)
            break;
    }
    gotoxy(31, 18);
    printf("  PRESS ENTER!");
    getch();
defaul:
    m = 100;
    s = 200;
menu:
    clrscr();
    printf("\n\n\n\n\n\n\n\n\t\t\tPress Enter To Start Piano.\n\n\t\t\tPress X To Change Beep Settings.\n\n\t\t\tEnter U To Enter Recording Mode.\n\n\t\t\tPress Q to Exit.");
    gotoxy(1, 1);
    bod();
    opt = getch();
    if (opt == 'U' || opt == 'u')
    {
    again:
        clrscr();
        sounddef(s);
        printf("\n\n\t     \t Piano is On Recording Mode!\n\n\t You Can Play Piano Using Keyboard Keys From A-L.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t Once completed Press T To Stop Recording.");
        gotoxy(1, 1);
        bod();
        for (i = 0;; t++)
        {
            o = getch();
            if (o == 'a' || o == 's' || o == 'd' || o == 'f' || o == 'g' || o == 'h' || o == 'j' || o == 'k' || o == 'l' || o == 'A' || o == 'S' || o == 'D' || o == 'F' || o == 'G' || o == 'H' || o == 'J' || o == 'K' || o == 'L')
            {
                a[i] = o;
                i++;
            }
            player(o);
            if (o == 't' || o == 'T')
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
        for (i = 0;; i++)
        {

            if (a[i] == 'a' || a[i] == 'A')
            {
                sound(s);
                delay(m);
                nosound();
                delay(100);
            }
            if (a[i] == 's' || a[i] == 'S')
            {
                sound(s1);
                delay(m);
                nosound();
                delay(100);
            }
            if (a[i] == 'd' || a[i] == 'D')
            {
                sound(s2);
                delay(m);
                nosound();
                delay(100);
            }
            if (a[i] == 'f' || a[i] == 'F')
            {
                sound(s3);
                delay(m);
                nosound();
                delay(100);
            }
            if (a[i] == 'g' || a[i] == 'G')
            {
                sound(s4);
                delay(m);
                nosound();
                delay(100);
            }
            if (a[i] == 'h' || a[i] == 'H')
            {
                sound(s5);
                delay(m);
                nosound();
                delay(100);
            }
            if (a[i] == 'j' || a[i] == 'J')
            {
                sound(s6);
                delay(m);
                nosound();
                delay(100);
            }
            if (a[i] == 'k' || a[i] == 'K')
            {
                sound(s7);
                delay(m);
                nosound();
                delay(100);
            }
            if (a[i] == 'l' || a[i] == 'L')
            {
                sound(s8);
                delay(m);
                nosound();
                delay(100);
            }
            if (i == t)
                break;
        }
        clrscr();
        printf("\n\n\n\n\t\t\t\t  Clip Completed.\n\n\n\n\n\t\tEnter R To Here It Again.\n\n\t\tEnter B to Return To Menu.\n\n\t\tEnter Q To Exit.\n");
        gotoxy(1, 1);
        bod();
        so = getch();
        if (so == 'q' || so == 'Q')
        {
            i = 0;
            memset(a, 0, 1000);
            goto exit;
        }
        if (tolower(so) == 'r')
            goto replay;
        if ((so != 'q' || so != 'Q') || (so != 'r' || so != 'R'))
        {
            i = 0;
            memset(a, 0, 1000);
            goto menu;
        }
    }

    if (opt == 'x' || opt == 'X')
    {
        clrscr();
        printf("\n\n\tEnter N to Change Time Seconds\n\n\tEnter V to Change Frquenzy Settins\n\n\tEnter R to Reset Default Settings.\n");
        gotoxy(1, 1);
        bod();
        op = getch();
        if (op == 'N' || op == 'n')
        {
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
        }
        if (op == 'V' || op == 'v')
        {
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
        }
        if (op == 'r' || op == 'R')
        {
            gotoxy(7, 10);
            printf("\tRESTORING");
            for (c = 0; c <= 10; c++)
            {
                printf(".");
                delay(150);
            }
            printf("\n\n\n\n\tSuccessfully Restored To Default Settings.\n\n\tPress Enter To Return.\n");
            gotoxy(1, 1);
            bod();
            getch();
            goto defaul;
        }
    }
    if (opt == 'Q' || opt == 'q')
        goto exit;
piano:
    sounddef(s);
    clrscr();
    printf("\n\n\t Piano is ON! You Can Play It Using Keyboard Keys From A-L.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t   Press B To Go Back. \n\n\t\t\t   Press Q to Exit.");
    gotoxy(1, 1);
    bod();
    for (i = 0;; i++)
    {
        o = getch();
        if (o == '\n')
            exit(0);
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
        for (i = 3; i != -1; i--)
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