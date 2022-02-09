#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <dos.h>
#include <stdlib.h>

void main()
{
    int c, i, m, tt, ft, s, s1, s2, s3, s4, s5, s6, s7, s8, pr, t = 0;
    char opt, o, op, so, a[1000];
    for (pr = 0; pr <= 100; pr++)
    {
        printf("\n\n\n\n\n\n\n\n\t\t\t       LOADING PIANO.....%d%\n", pr);
        delay(25);
        if (pr == 100)
            break;
        clrscr();
    }
    delay(1000);
defaul:
    m = 100;
    s = 200;
menu:
    clrscr();
    printf("\n\n\n\tPress P To Start Piano.\n\n\tPress X To Change Beep Setting.\n\n\tEnter U To Enter Recording Mode.\n\n\tPress Q to Exit.");

    opt = getch();
    if (opt == 'P' || opt == 'p')
        goto piano;
    if (opt == 'U' || opt == 'u')
    {
        s1 = s + 100;
        s2 = s1 + 100;
        s3 = s2 + 100;
        s4 = s3 + 100;
        s5 = s4 + 100;
        s6 = s5 + 100;
        s7 = s6 + 100;
        s8 = s7 + 100;
        ;
        for (i = 0;; i++, t++)
        {
            clrscr();
            printf("\n\n\t     \t Piano is On Recording Mode!\n\n\t You Can Play Piano Using Keyboard Keys From A-L.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t Once completed Press T To Stop Recording.");
            o = getch();
            if (o == 'a' || o == 's' || o == 'd' || o == 'f' || o == 'g' || o == 'h' || o == 'j' || o == 'k' || o == 'l' || o == 'A' || o == 'S' || o == 'D' || o == 'F' || o == 'G' || o == 'H' || o == 'J' || o == 'K' || o == 'L')
                a[i] = o;
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

            if (o == 't' || o == 'T')
                break;
        }
        clrscr();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\tSuccessfully Recorded. Press Enter To Here Your Recordings....");
        getch();
    re:
        clrscr();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t%c %c Playing....... %c %c\n", 14, 14, 14, 14);
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
        so = getch();
        if (so == 'B' || so == 'b')
        {
            flushall();
            i = 0;
            memset(a, 0, 1000);
            goto menu;
        }
        if (so == 'q' || so == 'Q')
            goto exit;
        if (so == 'r' || so == 'R')
            goto re;
    }

    if (opt == 'x' || opt == 'X')
    {
        clrscr();
        printf("\n\n\tEnter N to Change Time Seconds\n\n\tEnter V to Change Frquenzy Settins\n\n\tEnter R to Reset Default Settings.\n");
        op = getch();
        if (op == 'N' || op == 'n')
        {
            clrscr();
            printf("\tCurrent beep time in millisecond is %d.\n\n\n\tPlease Enter the time in millisecond to change it.\n\n\n\tNOTE:[1s=1000ms].\n\n\n\t", m);
            scanf("%d", &tt);
            m = tt;
            printf("\n\n\t\tSuccessfully Changed To %dms.\n\n\tPress Any Key To Return", m);
            getch();
            goto menu;
        }
        if (op == 'V' || op == 'v')
        {
            clrscr();
            printf("\tCurrent Staring Frequency Is %d.\n\n\n\tPlease Enter The New One.\n", s);
            scanf("%d", &ft);
            s = ft;
            printf("\tStarting Frequency Successfully Changed To %d.\n\n\tPress Any Key To Return\n", s);
            getch();
            goto menu;
        }
        if (op == 'r' || op == 'R')
        {
            printf("\n\n\tRESTORING");
            for (c = 0; c <= 10; c++)
            {
                printf(".");
                delay(150);
            }
            printf("\n\n\tSuccessfully Restored To Default Settings.\n\n\tPress Enter To Return.\n");
            getch();
            goto defaul;
        }
    }
    if (opt == 'Q' || opt == 'q')
        goto exit;
piano:
    s1 = s + 100;
    s2 = s1 + 100;
    s3 = s2 + 100;
    s4 = s3 + 100;
    s5 = s4 + 100;
    s6 = s5 + 100;
    s7 = s6 + 100;
    s8 = s7 + 100;
    ;
    for (i = 0;; i++)
    {
        clrscr();
        printf("\n\n\t Piano is ON! You Can Play It Using Keyboard Keys From A-L.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t   Press B To Go Back. \n\n\t\t\t   Press Q to Exit.");
        o = getch();
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
        if (o == 'B' || o == 'b')
            goto menu;
        if (o == 'q' || o == 'Q')
            goto exit;
    }

exit:
    clrscr();
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t     Bye\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tBy Divins.");
    getch();
}