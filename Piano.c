#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <ctype.h>
#include <string.h>
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
    FILE *sa1, *sa2, *sa3, *sa4, *sa5, *per1, *per2;
    int l, r, y, y2, y3, y4, y5, sss, c, i, tt, ft, fc, pr, sc, t, j, ff, sy, sys, in, cou, n, em;
    void sounddef(int), player(char), sig(void), bod(void), menu(int), recplayer(char), fplay(void), naam(char[5][50], int);
    char opt, o, op, so, a[1000], rec[100], nam[5][50], temp[50][50], newn[50], te[50];
    textcolor(BROWN);
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
     getch();*/
    if (access("sta1.pi", 00) && access("sta2.pi", 00))
    {
        printf("first run");
        sy = -1;
        getch();
    }
    else
    {
        per1 = fopen("sta1.pi", "r");
        fscanf(per1, "%d", &sy);
        fclose(per1);
        printf("%d", sy);
        per2 = fopen("sta2.pi", "r");
        for (n = -1; n < sy; fscanf(per2, "%s", nam[++n]))
            ;
        fclose(per2);
        getch();
    }
defaul:
    s = 200;
    m = 100;
    y = y3 = y4 = y5 = 9;
    y2 = 11;
menu:
    clrscr();
    menu(1);
    gotoxy(54, y);
    printf("%c", 174);
    for (;;)
    {
        if (kbhit())
        {
            opt = getch();
            if (opt == DOWNARR && y != 17)
            {
                clrscr();
                menu(1);
                y += 2;
                gotoxy(54, y);
                printf("%c", 174);
            }
            if (opt == UPARR && y != 9)
            {
                clrscr();
                menu(1);
                y -= 2;
                gotoxy(54, y);
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
        goto play;
    case 17:
        goto exit;
    }
    if (opt == 99) /*Shold Never Occur, Just to prevent malfunctoning of GOTO*/
    {
    play:
        clrscr();
        gotoxy(1, 1);
        bod();
        if (sy == -1)
        {
        fof:
            gotoxy(10, 10);
            printf("\t  No Recordings Available!! Press Any Key To Return.");
            getch();
            goto menu;
        }
        memset(rec, 0, 100);
        naam(nam, sy);
        switch (sy)
        {
        case 0:
            sys = 9;
            break;
        case 1:
            sys = 11;
            break;
        case 2:
            sys = 13;
            break;
        case 3:
            sys = 15;
            break;
        case 4:
            sys = 17;
            break;
        default:
            goto fof;
        }
        gotoxy(54, y4);
        printf("%c", 174);
        for (;;)
        {
            if (kbhit())
            {
                opt = getch();
                if (opt == DOWNARR && y4 != sys)
                {
                    clrscr();
                    naam(nam, sy);
                    y4 += 2;
                    gotoxy(54, y4);
                    printf("%c", 174);
                }
                if (opt == UPARR && y4 != 9)
                {
                    clrscr();
                    naam(nam, sy);
                    y4 -= 2;
                    gotoxy(54, y4);
                    printf("%c", 174);
                }
                if (tolower(opt) == 'b')
                    goto menu;
                if (opt == 13)
                    break;
            }
        }
    otto:
        clrscr();
        menu(4);
        gotoxy(54, y5);
        printf("%c", 174);
        for (;;)
        {
            if (kbhit())
            {
                opt = getch();
                if (opt == DOWNARR && y5 != 15)
                {
                    clrscr();
                    menu(4);
                    y5 += 2;
                    gotoxy(54, y5);
                    printf("%c", 174);
                }
                if (opt == UPARR && y5 != 9)
                {
                    clrscr();
                    menu(4);
                    y5 -= 2;
                    gotoxy(54, y5);
                    printf("%c", 174);
                }
                if (opt == 13)
                    break;
            }
        }
        switch (y4)
        {
        case 9:
            switch (y5)
            {
            case 9:
                sa1 = fopen(nam[0], "r");
                flushall();
                fscanf(sa1, "%s", rec);
                fclose(sa1);
                sounddef(s);
                fplay();
                for (fc = 0; fc < strlen(rec); fc++)
                    recplayer(rec[fc]);
                goto otto;
            case 11:
                gotoxy(24, 23);
                printf("Enter New Name: ");
                gets(newn);
                em = rename(nam[0], newn);
                if (em == 0)
                {
                    strcpy(nam[0], newn);
                    memset(newn, 0, 50);
                    gotoxy(23, 23);
                    printf("         Succesfully Renamed!                     ");
                    sleep(1);
                }
                else if (errno == 5)
                {
                    gotoxy(23, 23);
                    printf("Error: File Already Exists.");
                    sleep(1);
                }
                goto otto;

            case 13:
                gotoxy(19, 21);
                printf("Are You Sure You Want To Delete %s ? [Y/N]", nam[0]);
            bak1:
                flushall();
                so = getch();
                so = tolower(so);
                switch (so)
                {
                case 'y':
                    if (remove(nam[0]) == 0)
                    {
                        gotoxy(15, 23);
                        printf("               Succesfully Deleted!                     ");
                        sleep(1);
                    }
                    for (cou = 0, in = 0; cou <= sy; cou++)
                    {
                        if (cou != 0)
                        {
                            strcpy(temp[in], nam[cou]);
                            in++;
                        }
                    }
                    memset(nam, 0, sizeof(nam));
                    for (in = 0; in < sy; in++)
                        strcpy(nam[in], temp[in]);
                    memset(temp, 0, sizeof(temp));
                    sy--;
                    goto play;
                case 'n':
                    goto play;
                default:
                    gotoxy(20, 23);
                    printf(" Enter 'Y' for Yes Or 'N' For No.");
                    goto bak1;
                }
            case 15:
                goto play;
            }
        case 11:
            switch (y5)
            {
            case 9:
                sa2 = fopen(nam[1], "r");
                flushall();
                fscanf(sa2, "%s", rec);
                fclose(sa2);
                sounddef(s);
                fplay();
                for (fc = 0; fc < strlen(rec); fc++)
                    recplayer(rec[fc]);
                goto otto;
            case 11:
                gotoxy(24, 23);
                printf("Enter New Name: ");
                gets(newn);
                em = rename(nam[1], newn);
                if (em == 0)
                {
                    strcpy(nam[1], newn);
                    memset(newn, 0, 50);
                    gotoxy(23, 23);
                    printf("         Succesfully Renamed!                     ");
                    sleep(1);
                }
                else if (errno == 5)
                {
                    gotoxy(23, 23);
                    printf("Error: File Already Exists.");
                    sleep(1);
                }
                goto otto;
            case 13:
                gotoxy(19, 21);
                printf("Are You Sure You Want To Delete %s ? [Y/N]", nam[1]);
            bak2:
                flushall();
                so = getch();
                so = tolower(so);
                switch (so)
                {
                case 'y':
                    if (remove(nam[1]) == 0)
                    {
                        gotoxy(15, 23);
                        printf("               Succesfully Deleted!                     ");
                        sleep(1);
                        y4 -= 2;
                    }
                    for (cou = 0, in = 0; cou <= sy; cou++)
                    {
                        if (cou != 1)
                        {
                            strcpy(temp[in], nam[cou]);
                            in++;
                        }
                    }
                    memset(nam, 0, sizeof(nam));
                    for (in = 0; in < sy; in++)
                        strcpy(nam[in], temp[in]);
                    memset(temp, 0, sizeof(temp));
                    sy--;
                    goto play;
                case 'n':
                    goto play;
                default:
                    gotoxy(20, 23);
                    printf(" Enter 'Y' for Yes Or 'N' For No.");
                    goto bak2;
                }
            case 15:
                goto play;
            }
        case 13:
            switch (y5)
            {
            case 9:
                sa3 = fopen(nam[2], "r");
                flushall();
                fscanf(sa3, "%s", rec);
                fclose(sa3);
                sounddef(s);
                fplay();
                for (fc = 0; fc < strlen(rec); fc++)
                    recplayer(rec[fc]);
                goto otto;
            case 11:
                gotoxy(24, 23);
                printf("Enter New Name: ");
                gets(newn);
                em = rename(nam[2], newn);
                if (em == 0)
                {
                    strcpy(nam[2], newn);
                    memset(newn, 0, 50);
                    gotoxy(23, 23);
                    printf("         Succesfully Renamed!                     ");
                    sleep(1);
                }
                else if (errno == 5)
                {
                    gotoxy(23, 23);
                    printf("Error: File Already Exists.");
                    sleep(1);
                }
                goto otto;
            case 13:
                gotoxy(19, 21);
                printf("Are You Sure You Want To Delete %s ? [Y/N]", nam[2]);
            bak3:
                flushall();
                so = getch();
                so = tolower(so);
                switch (so)
                {
                case 'y':
                    if (remove(nam[2]) == 0)
                    {
                        gotoxy(15, 23);
                        printf("               Succesfully Deleted!                     ");
                        sleep(1);
                        y4 -= 2;
                    }
                    for (cou = 0, in = 0; cou <= sy; cou++)
                    {
                        if (cou != 2)
                        {
                            strcpy(temp[in], nam[cou]);
                            in++;
                        }
                    }
                    memset(nam, 0, sizeof(nam));
                    for (in = 0; in < sy; in++)
                        strcpy(nam[in], temp[in]);
                    memset(temp, 0, sizeof(temp));
                    sy--;
                    goto play;
                case 'n':
                    goto play;
                default:
                    gotoxy(20, 23);
                    printf(" Enter 'Y' for Yes Or 'N' For No.");
                    goto bak3;
                }
            case 15:
                goto play;
            }
        case 15:
            switch (y5)
            {
            case 9:
                sa4 = fopen(nam[3], "r");
                flushall();
                fscanf(sa4, "%s", rec);
                fclose(sa4);
                sounddef(s);
                fplay();
                for (fc = 0; fc < strlen(rec); fc++)
                    recplayer(rec[fc]);
                goto otto;
            case 11:
                gotoxy(24, 23);
                printf("Enter New Name: ");
                gets(newn);
                em = rename(nam[3], newn);
                if (em == 0)
                {
                    strcpy(nam[3], newn);
                    memset(newn, 0, 50);
                    gotoxy(23, 23);
                    printf("         Succesfully Renamed!                     ");
                    sleep(1);
                }
                else if (errno == 5)
                {
                    gotoxy(23, 23);
                    printf("Error: File Already Exists.");
                    sleep(1);
                }
                goto otto;
            case 13:
                gotoxy(19, 21);
                printf("Are You Sure You Want To Delete %s ? [Y/N]", nam[3]);
            bak4:
                flushall();
                so = getch();
                so = tolower(so);
                switch (so)
                {
                case 'y':
                    if (remove(nam[3]) == 0)
                    {
                        gotoxy(15, 23);
                        printf("               Succesfully Deleted!                     ");
                        sleep(1);
                        y4 -= 2;
                    }
                    for (cou = 0, in = 0; cou <= sy; cou++)
                    {
                        if (cou != 3)
                        {
                            strcpy(temp[in], nam[cou]);
                            in++;
                        }
                    }
                    memset(nam, 0, sizeof(nam));
                    for (in = 0; in < sy; in++)
                        strcpy(nam[in], temp[in]);
                    memset(temp, 0, sizeof(temp));
                    sy--;
                    goto play;
                case 'n':
                    goto play;
                default:
                    gotoxy(20, 23);
                    printf(" Enter 'Y' for Yes Or 'N' For No.");
                    goto bak4;
                }
            case 15:
                goto play;
            }
        case 17:
            switch (y5)
            {
            case 9:
                sa5 = fopen(nam[4], "r");
                flushall();
                fscanf(sa5, "%s", rec);
                fclose(sa5);
                sounddef(s);
                fplay();
                for (fc = 0; fc < strlen(rec); fc++)
                    recplayer(rec[fc]);
                goto otto;
            case 11:
                gotoxy(24, 23);
                printf("Enter New Name: ");
                gets(newn);
                em = rename(nam[4], newn);
                if (em == 0)
                {
                    strcpy(nam[4], newn);
                    memset(newn, 0, 50);
                    gotoxy(23, 23);
                    printf("         Succesfully Renamed!                     ");
                    sleep(1);
                }
                else if (errno == 5)
                {
                    gotoxy(23, 23);
                    printf("Error: File Already Exists.");
                    sleep(1);
                }
                goto otto;
            case 13:
                gotoxy(19, 21);
                printf("Are You Sure You Want To Delete %s ? [Y/N]", nam[4]);
            bak5:
                flushall();
                so = getch();
                so = tolower(so);
                switch (so)
                {
                case 'y':
                    if (remove(nam[4]) == 0)
                    {
                        gotoxy(15, 23);
                        printf("               Succesfully Deleted!                     ");
                        sleep(1);
                        y4 -= 2;
                    }
                    for (cou = 0, in = 0; cou <= sy; cou++)
                    {
                        if (cou != 4)
                        {
                            strcpy(temp[in], nam[cou]);
                            in++;
                        }
                    }
                    memset(nam, 0, sizeof(nam));
                    for (in = 0; in < sy; in++)
                        strcpy(nam[in], temp[in]);
                    memset(temp, 0, sizeof(temp));
                    sy--;
                    goto play;
                case 'n':
                    goto play;
                default:
                    gotoxy(20, 23);
                    printf(" Enter 'Y' for Yes Or 'N' For No.");
                    goto bak5;
                }
            case 15:
                goto play;
            }
        }
    }
    if (opt == 99) /*Shold Never Occur, Just to prevent malfunctoning of GOTO*/
    {
    again:
        clrscr();
        sounddef(s);
        printf("\n\n\t\t\t   Piano is On Recording Mode!\n\n\n\t\t You Can Play Piano Using Keyboard Keys From A-L.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t Once completed Press Enter To Stop Recording.");
        gotoxy(1, 1);
        bod();
        for (i = 0;;)
        {
            o = getch();
            if (o == 'a' || o == 's' || o == 'd' || o == 'f' || o == 'g' || o == 'h' || o == 'j' || o == 'k' || o == 'l' || o == 'A' || o == 'S' || o == 'D' || o == 'F' || o == 'G' || o == 'H' || o == 'J' || o == 'K' || o == 'L')
                a[i++] = o;
            player(o);
            if (o == 13)
                break;
        }
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
    fplay();
    for (t = 0; t <= i; t++)
        recplayer(a[t]);
smu:
    clrscr();
    menu(3);
    gotoxy(54, y2);
    printf("%c", 174);
    for (;;)
    {
        if (kbhit())
        {
            so = getch();
            if (so == DOWNARR && y2 < 17)
            {
                clrscr();
                menu(3);
                gotoxy(54, y2 + 2);
                y2 += 2;
                printf("%c", 174);
            }
            if (so == UPARR && y2 > 11)
            {
                clrscr();
                menu(3);
                gotoxy(54, y2 - 2);
                y2 -= 2;
                printf("%c", 174);
            }
            if (so == 13)
                break;
        }
    }
    switch (y2)
    {
    case 11:
        goto replay;
    case 13:
        goto reco;
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
    reco:
        gotoxy(24, 23);
        if (sy < 4)
        {
            printf("Enter A Name: ");
            gets(te);
            for (em = 0; em < sy + 1; em++)
                if (strcmp(te, nam[em]) == 0)
                {
                    gotoxy(22, 23);
                    printf("     Error: File Already Exists.");
                    sleep(1);
                    memset(te, 0, sizeof(te));
                    goto smu;
                }
            strcpy(nam[++sy], te);
            memset(te, 0, sizeof(te));
            sa1 = fopen(nam[sy], "w");
            fprintf(sa1, "%s", a);
            fclose(sa1);
            gotoxy(23, 23);
            printf("         Succesfully Saved!                             ");
            sleep(1);
            delline();
            goto smu;
        }
        else
            gotoxy(27, 23);
        printf("     Limit Of 5 Reached!!");
        sleep(1);
        goto smu;
    }

    if (opt == 99) /*Shold Never Occur, Just to prevent malfunctoning of GOTO*/
    {
    settings:
        clrscr();
        menu(2);
        gotoxy(54, y3);
        printf("%c", 174);
        for (;;)
        {
            if (kbhit())
            {
                op = getch();
                if (op == DOWNARR && y3 != 15)
                {
                    clrscr();
                    menu(2);
                    gotoxy(54, y3 + 2);
                    y3 += 2;
                    printf("%c", 174);
                }
                if (op == UPARR && y3 != 9)
                {
                    clrscr();
                    menu(2);
                    gotoxy(54, y3 - 2);
                    y3 -= 2;
                    printf("%c", 174);
                }
                if (op == 13)
                    break;
            }
        }
        switch (y3)
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
            /*
             clrscr();
             printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t     Bye\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tBy Divins.");
             gotoxy(1,1);
             bod();
             for(i=-3;i!=-1;i--)
             {
              gotoxy(44,11);
              printf("(%d)",i);
              sleep(1);
             */
            per1 = fopen("sta1.pi", "w");
            fprintf(per1, "%d", sy);
            fclose(per1);
            per2 = fopen("sta2.pi", "w");
            for (i = -1; i < sy; fprintf(per2, "%s\n", nam[i++]))
                ;
            fclose(per2);
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
        printf("\n\n\n\n\n\n\n\n\t\t\t Start Piano.\n\n\t\t\t Change Beep Settings.\n\n\t\t\t Enter Recording Mode.\n\n\t\t\t Play Saved Recording.\n\n\t\t\t Exit.");
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
        break;
    case 4:
        printf("\n\n\n\n\n\n\n\n\t\t\t Play This Recording.\n\n\t\t\t Rename This Recording.\n\n\t\t\t Delete This Recording.\n\n\t\t\t Go Back.");
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
void fplay(void)
{
    clrscr();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t%c %c Playing....... %c %c\n", 14, 14, 14, 14);
    gotoxy(1, 1);
    bod();
}
void naam(char nam[5][50], int sy)
{
    int j, i;
    gotoxy(13, 3);
    printf("\t\t\tYour Recordings:-");
    gotoxy(32, 22);
    printf("Press B to Go Back.");
    gotoxy(20, 9);
    for (j = 0, i = 11; j <= sy; j++, i += 2)
    {
        printf("%s", nam[j]);
        gotoxy(20, i);
    }
    gotoxy(1, 1);
    bod();
}
