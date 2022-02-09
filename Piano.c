#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <ctype.h>
#include <string.h>
#include <dos.h>
#include <time.h>
#include <mem.h>
#include <io.h>

#define UPARR 72
#define LEFTARR 75
#define DOWNARR 80
#define RIGHTARR 77
int m, s, s1, s2, s3, s4, s5, s6, s7, s8, color, decolor;
char type[50];
void main(void)
{
    FILE *sa1, *sa2, *sa3, *sa4, *sa5, *per1, *per2, *per3;
    int d, gm, l, r, y, y2, y3, y4, y5, y6, y7, sss, c, i, tt, ft, fc, pr, sc, t, j, ff, sy, sys, in, cou, n, em, am, iy, null, colset[3];
    void sounddef(int), player(char), sig(void), eff(void), bod(int), menu(int), recplayer(char), fplay(void);
    void dor(void), naam(char[5][50], int), nemu(char[50]);
    char opt, o, op, so, a[1000], rec[1000], nam[5][50], temp[50][50], newn[50], te[50];
    if ((access("sta1.pi", 00) || access("sta2.pi", 00) || access("sta3.pi", 00)))
    {
        textbackground(WHITE);
        textcolor(BLACK);
        clrscr();
        printf("\n\n\t\t    WELCOME TO THE SETUP OF PIANO by Divins.\n\t\t   ككككككككككككككككككككككككككككككككككككككككك \n\n\n\t   This Setup Will Install PIANO by Divins on your computer.\n\n\n\n");
        bod(BLACK);
        for (i = 2;; i++)
        {
            gotoxy(27, 15);
            if (i % 2 == 0)
                printf("PRESS ANY KEY TO CONTINUE");
            else
                printf("                         ");
            delay(300);
            if (kbhit())
                break;
        }
        gotoxy(27, 15);
        printf("                         ");

        for (i = 00; i < 101; i++)
        {
            gotoxy(21, 17);
            printf("Installation In Progress........%d%", i);
            delay(50);
        }
        clrscr();
        gotoxy(17, 7);
        printf(" Piano Is Successfully Installed On Your System.\n\t\tكككككككككككككككككككككككككككككككككككككككككككككككك \n\n\n\n\t Setup Will Now Guid You Through The First Time Run-Configurations.\n\n\t Please Select Your Preferences. You Also Can Change Them \n\n\t Manually After The Setup.");
        bod(BLACK);
        getch();
        for (i = 2;; i++)
        {
            gotoxy(27, 21);
            if (i % 2 == 0)
                printf("PRESS ANY KEY TO CONTINUE");
            else
                printf("                         ");
            delay(300);
            if (kbhit())
            {
                getch();
                break;
            }
        }
        clrscr();
        textbackground(WHITE);
        for (d = 0; d < 3; d++)
        {
            clrscr();
            switch (d)
            {
            case 2:
                strcpy(type, "Background");
                break;
            case 1:
                strcpy(type, "Text");
                break;
            case 0:
                strcpy(type, "Border");
                break;
            }
            y7 = 6;
            menu(5);
            gotoxy(50, y7);
            printf("%c", 174);
            for (;;)
            {
                if (kbhit())
                {
                    op = getch();
                    if (op == DOWNARR && y7 != 22)
                    {
                        clrscr();
                        menu(5);
                        y7 += 2;
                        gotoxy(50, y7);
                        printf("%c", 174);
                    }
                    if (op == UPARR && y7 != 6)
                    {
                        clrscr();
                        menu(5);
                        y7 -= 2;
                        gotoxy(50, y7);
                        printf("%c", 174);
                    }
                    if (op == 13)
                        break;
                }
            }
            switch (y7)
            {
            case 6:
                colset[d] = 0;
                break;
            case 8:
                colset[d] = 1;
                break;
            case 10:
                colset[d] = 2;
                break;
            case 12:
                colset[d] = 3;
                break;
            case 14:
                colset[d] = 4;
                break;
            case 16:
                colset[d] = 5;
                break;
            case 18:
                colset[d] = 6;
                break;
            case 20:
                colset[d] = 14;
                break;
            case 22:
                colset[d] = 15;
                break;
            }
        }
        per1 = fopen("sta1.pi", "w");
        fprintf(per1, "-1");
        fclose(per1);
        per2 = fopen("sta2.pi", "w");
        fclose(per2);
        per3 = fopen("sta3.pi", "w");
        for (i = 0; i < 3; i++)
            fprintf(per3, "%d ", colset[i]);
        fclose(per3);
        eff();
        clrscr();
        gotoxy(35, 3);
        printf("SUCCESS!");
        gotoxy(34, 4);
        printf("كككككككككك\n\n\n\n\n\n\n\n\t\tPiano Has Been Successfully Installed On Your System\n\n\t\tPlease Restart This Application To Continue.\n\n\n\n\n\t\tProgramme Will Close Now. ");
        bod(BLACK);
        getch();
        system("exit");
        system("exit");
        exit(0);
    }
    else
    {
        per1 = fopen("sta1.pi", "r");
        fscanf(per1, "%d", &sy);
        fclose(per1);
        printf("%d", sy);
        per2 = fopen("sta2.pi", "r");
        for (n = -1; n < sy;)
            fgets(nam[++n], 100, per2);
        fclose(per2);
        per3 = fopen("sta3.pi", "r");
        for (n = 0; n < 3; n++)
            fscanf(per3, "%d", &colset[n]);
        fclose(per3);
        color = colset[0];         // bod
        decolor = colset[1];       // text
        textbackground(colset[2]); // bg
    }
defaul:
    s = 200;
    m = 100;
    y = 13;
    y3 = y4 = y5 = 9;
    y2 = 11;
    y6 = 10;
    y7 = 6;
    textcolor(decolor);
    clrscr();
    for (sc = 0, pr = 0; pr <= 100; pr += sc, sc += 2)
    {
        bod(color);
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
            if (opt == DOWNARR && y != 21)
            {
                clrscr();
                menu(1);
                y += 2;
                gotoxy(54, y);
                printf("%c", 174);
            }
            if (opt == UPARR && y != 13)
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
    case 13:
        goto piano;
    case 15:
        goto settings;
    case 17:
        goto again;
    case 19:
        goto play;
    case 21:
        goto exit;
    }
    if (opt == 99) /*Shold Never Occur, Just to prevent malfunctoning of GOTO*/
    {
    play:
        clrscr();
        gotoxy(1, 1);
        bod(color);
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
        switch (y4)
        {
        case 9:
            iy = 0;
            break;
        case 11:
            iy = 1;
            break;
        case 13:
            iy = 2;
            break;
        case 15:
            iy = 3;
            break;
        case 17:
            iy = 4;
            break;
        }
    otto:
        for (em = 0; em <= sy; em++)
            if (nam[em][strlen(nam[em]) - 1] == '\n')
                nam[em][strlen(nam[em]) - 1] = '\0';
        clrscr();
        nemu(nam[iy]);
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
                    nemu(nam[iy]);
                    y5 += 2;
                    gotoxy(54, y5);
                    printf("%c", 174);
                }
                if (opt == UPARR && y5 != 9)
                {
                    clrscr();
                    nemu(nam[iy]);
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
                if (nam[0][strlen(nam[0]) - 1] == '\n')
                    nam[0][strlen(nam[0]) - 1] = '\0';
                sa1 = fopen(nam[0], "r");
                memset(rec, 0, sizeof(rec));
                fgets(rec, 1000, sa1);
                fclose(sa1);
                sounddef(s);
                fplay();
                for (fc = 0; fc < strlen(rec); fc++)
                    recplayer(rec[fc]);
                goto otto;
            case 11:
                if (nam[0][strlen(nam[0]) - 1] == '\n')
                    nam[0][strlen(nam[0]) - 1] = '\0';
                gotoxy(24, 23);
                printf("Enter New Name: ");
                gets(newn);
                for (null = 0, em = 0; newn[em] != '\0'; em++)
                    if (isspace(newn[em]) != 0)
                        null++;
                if (null == strlen(newn))
                {
                    null = 0;
                    gotoxy(23, 23);
                    printf("Error: Null String Detected!");
                    sleep(1);
                    goto otto;
                }
                if (rename(nam[0], newn) == 0)
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
                    memset(newn, 0, 50);
                    sleep(1);
                }
                goto otto;

            case 13:
                if (nam[0][strlen(nam[0]) - 1] == '\n')
                    nam[0][strlen(nam[0]) - 1] = '\0';
                gotoxy(19, 21);
                printf("Are You Sure You Want To Delete \"%s\" ? [Y/N]", nam[0]);
            bak1:
                flushall();
                so = tolower(getch());
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
                    goto otto;
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
                if (nam[1][strlen(nam[1]) - 1] == '\n')
                    nam[1][strlen(nam[1]) - 1] = '\0';
                sa2 = fopen(nam[1], "r");
                flushall();
                fscanf(sa2, "%s", rec);
                fclose(sa2);
                sounddef(s);
                fplay();
                ;
                for (fc = 0; fc < strlen(rec); fc++)
                    recplayer(rec[fc]);
                goto otto;
            case 11:
                if (nam[1][strlen(nam[1]) - 1] == '\n')
                    nam[1][strlen(nam[1]) - 1] = '\0';
                gotoxy(24, 23);
                printf("Enter New Name: ");
                gets(newn);
                for (null = 0, em = 0; newn[em] != '\0'; em++)
                    if (isspace(newn[em]) != 0)
                        null++;
                if (null == strlen(newn))
                {
                    null = 0;
                    gotoxy(23, 23);
                    printf("Error: Null String Detected!");
                    sleep(1);
                    goto otto;
                }
                if (rename(nam[1], newn) == 0)
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
                    memset(newn, 0, 50);
                }
                goto otto;
            case 13:
                if (nam[1][strlen(nam[1]) - 1] == '\n')
                    nam[1][strlen(nam[1]) - 1] = '\0';
                gotoxy(19, 21);
                printf("Are You Sure You Want To Delete \"%s\" ? [Y/N]", nam[1]);
            bak2:
                flushall();
                so = tolower(getch());
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
                    goto otto;
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
                if (nam[2][strlen(nam[2]) - 1] == '\n')
                    nam[2][strlen(nam[2]) - 1] = '\0';
                sa3 = fopen(nam[2], "r");
                flushall();
                fscanf(sa3, "%s", rec);
                fclose(sa3);
                sounddef(s);
                fplay();
                ;
                for (fc = 0; fc < strlen(rec); fc++)
                    recplayer(rec[fc]);
                goto otto;
            case 11:
                if (nam[2][strlen(nam[2]) - 1] == '\n')
                    nam[2][strlen(nam[2]) - 1] = '\0';
                gotoxy(24, 23);
                printf("Enter New Name: ");
                gets(newn);
                for (null = 0, em = 0; newn[em] != '\0'; em++)
                    if (isspace(newn[em]) != 0)
                        null++;
                if (null == strlen(newn))
                {
                    null = 0;
                    gotoxy(23, 23);
                    printf("Error: Null String Detected!");
                    sleep(1);
                    goto otto;
                }
                if (rename(nam[2], newn) == 0)
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
                    memset(newn, 0, 50);
                }
                goto otto;
            case 13:
                if (nam[2][strlen(nam[2]) - 1] == '\n')
                    nam[2][strlen(nam[2]) - 1] = '\0';
                gotoxy(19, 21);
                printf("Are You Sure You Want To Delete \"%s\" ? [Y/N]", nam[2]);
            bak3:
                flushall();
                so = tolower(getch());
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
                    goto otto;
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
                if (nam[3][strlen(nam[3]) - 1] == '\n')
                    nam[3][strlen(nam[3]) - 1] = '\0';
                sa4 = fopen(nam[3], "r");
                flushall();
                fscanf(sa4, "%s", rec);
                fclose(sa4);
                sounddef(s);
                fplay();
                ;
                for (fc = 0; fc < strlen(rec); fc++)
                    recplayer(rec[fc]);
                goto otto;
            case 11:
                if (nam[3][strlen(nam[3]) - 1] == '\n')
                    nam[3][strlen(nam[3]) - 1] = '\0';
                gotoxy(24, 23);
                printf("Enter New Name: ");
                gets(newn);
                for (null = 0, em = 0; newn[em] != '\0'; em++)
                    if (isspace(newn[em]) != 0)
                        null++;
                if (null == strlen(newn))
                {
                    null = 0;
                    gotoxy(23, 23);
                    printf("Error: Null String Detected!");
                    sleep(1);
                    goto otto;
                }
                if (rename(nam[3], newn) == 0)
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
                    memset(newn, 0, 50);
                }
                goto otto;
            case 13:
                if (nam[3][strlen(nam[3]) - 1] == '\n')
                    nam[3][strlen(nam[3]) - 1] = '\0';
                gotoxy(19, 21);
                printf("Are You Sure You Want To Delete \"%s\" ? [Y/N]", nam[3]);
            bak4:
                flushall();
                so = tolower(getch());
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
                    goto otto;
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
                if (nam[4][strlen(nam[4]) - 1] == '\n')
                    nam[4][strlen(nam[4]) - 1] = '\0';
                sa5 = fopen(nam[4], "r");
                flushall();
                fscanf(sa5, "%s", rec);
                fclose(sa5);
                sounddef(s);
                fplay();
                ;
                for (fc = 0; fc < strlen(rec); fc++)
                    recplayer(rec[fc]);
                goto otto;
            case 11:
                if (nam[4][strlen(nam[4]) - 1] == '\n')
                    nam[4][strlen(nam[4]) - 1] = '\0';
                gotoxy(24, 23);
                printf("Enter New Name: ");
                gets(newn);
                for (null = 0, em = 0; newn[em] != '\0'; em++)
                    if (isspace(newn[em]) != 0)
                        null++;
                if (null == strlen(newn))
                {
                    null = 0;
                    gotoxy(23, 23);
                    printf("Error: Null String Detected!");
                    sleep(1);
                    goto otto;
                }
                if (rename(nam[4], newn) == 0)
                {
                    strcpy(nam[4], newn);
                    memset(newn, 0, 50);
                    gotoxy(23, 23);
                    printf("         Succesfully Renamed!                     ");
                    sleep(1);
                }
                else if (errno == 5)
                {
                    memset(newn, 0, 50);
                    gotoxy(23, 23);
                    printf("Error: File Already Exists.");
                    sleep(1);
                }
                goto otto;
            case 13:
                if (nam[4][strlen(nam[4]) - 1] == '\n')
                    nam[4][strlen(nam[4]) - 1] = '\0';
                gotoxy(19, 21);
                printf("Are You Sure You Want To Delete \"%s\" ? [Y/N]", nam[4]);
            bak5:
                flushall();
                so = tolower(getch());
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
                    goto otto;
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
        bod(color);
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
            bod(color);
            delay(1000);
        }
        goto again;
    }
    clrscr();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\tSuccessfully Recorded. Press Enter To Here Your Recordings....");
    gotoxy(1, 1);
    bod(color);
    getch();
replay:
    fplay();
    ;
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
            for (null = 0, em = 0; te[em] != '\0'; em++)
                if (isspace(te[em]) != 0)
                    null++;
            if (null == strlen(te))
            {
                gotoxy(22, 23);
                printf("     Error: Null String Detected.");
                sleep(1);
                memset(te, 0, sizeof(te));
                goto smu;
            }
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
        gotoxy(59, y3);
        printf("%c", 174);
        for (;;)
        {
            if (kbhit())
            {
                op = getch();
                if (op == DOWNARR && y3 != 17)
                {
                    clrscr();
                    menu(2);
                    gotoxy(59, y3 + 2);
                    y3 += 2;
                    printf("%c", 174);
                }
                if (op == UPARR && y3 != 9)
                {
                    clrscr();
                    menu(2);
                    gotoxy(59, y3 - 2);
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
            printf("\n\n\n\n\tCurrent beep time in millisecond is %d.\n\n\n\tPlease Enter the time in millisecond to change it.\n\n\tNOTE:[1s=1000ms].", m);
            bod(color);
            gotoxy(7, 15);
            printf(" Your Required Time :\t");
            scanf("%d", &tt);
            if (tt == m)
            {
                printf("\n\n\n\tNo Changes Made. Press Any Key To Return.");
                bod(color);
                getch();
                goto settings;
            }
            m = tt;
            printf("\n\n\tSuccessfully Changed To %dms.\n\n\tPress Any Key To Return", m);
            gotoxy(1, 1);
            bod(color);
            getch();
            goto settings;
        case 13:
        col:
            clrscr();
            menu(4);
            gotoxy(54, y6);
            printf("%c", 174);
            for (;;)
            {
                if (kbhit())
                {
                    opt = getch();
                    if (opt == DOWNARR && y6 != 16)
                    {
                        clrscr();
                        menu(4);
                        y6 += 2;
                        gotoxy(54, y6);
                        printf("%c", 174);
                    }
                    if (opt == UPARR && y6 != 10)
                    {
                        clrscr();
                        menu(4);
                        y6 -= 2;
                        gotoxy(54, y6);
                        printf("%c", 174);
                    }
                    if (tolower(opt) == 'b')
                        goto menu;
                    if (opt == 13)
                        break;
                }
            }
            memset(type, 0, 50);
            switch (y6)
            {
            case 10:
                strcpy(type, "Text");
                break;
            case 12:
                strcpy(type, "Background");
                break;
            case 14:
                strcpy(type, "Border");
                break;
            case 16:
                goto settings;
            }
            clrscr();
            menu(5);
            gotoxy(50, y7);
            printf("%c", 174);
            for (;;)
            {
                if (kbhit())
                {
                    op = getch();
                    if (op == DOWNARR && y7 != 22)
                    {
                        clrscr();
                        menu(5);
                        y7 += 2;
                        gotoxy(50, y7);
                        printf("%c", 174);
                    }
                    if (op == UPARR && y7 != 6)
                    {
                        clrscr();
                        menu(5);
                        y7 -= 2;
                        gotoxy(50, y7);
                        printf("%c", 174);
                    }
                    if (tolower(op) == 'b')
                        goto menu;
                    if (op == 13)
                        break;
                }
            }
            eff();
            switch (y6)
            {
            case 10:
                switch (y7) // text color
                {
                case 6:
                    decolor = 0;
                    textcolor(decolor);
                    colset[1] = decolor;
                    goto col;
                case 8:
                    decolor = 1;
                    textcolor(decolor);
                    colset[1] = decolor;
                    goto col;
                case 10:
                    decolor = 2;
                    textcolor(decolor);
                    colset[1] = decolor;
                    goto col;
                case 12:
                    decolor = 3;
                    textcolor(decolor);
                    colset[1] = decolor;
                    goto col;
                case 14:
                    decolor = 4;
                    textcolor(decolor);
                    colset[1] = decolor;
                    goto col;
                case 16:
                    decolor = 5;
                    textcolor(decolor);
                    colset[1] = decolor;
                    goto col;
                case 18:
                    decolor = 6;
                    textcolor(decolor);
                    colset[1] = decolor;
                    goto col;
                case 20:
                    decolor = 14;
                    textcolor(decolor);
                    colset[1] = decolor;
                    goto col;
                case 22:
                    decolor = 15;
                    textcolor(decolor);
                    colset[1] = decolor;
                    goto col;
                }
            case 12:
                switch (y7) // bg color
                {
                case 6:
                    textbackground(BLACK);
                    colset[2] = 0;
                    goto col;
                case 8:
                    textbackground(BLUE);
                    colset[2] = 1;
                    goto col;
                case 10:
                    textbackground(GREEN);
                    colset[2] = 2;
                    goto col;
                case 12:
                    textbackground(CYAN);
                    colset[2] = 3;
                    goto col;
                case 14:
                    textbackground(RED);
                    colset[2] = 4;
                    goto col;
                case 16:
                    textbackground(MAGENTA);
                    colset[2] = 5;
                    goto col;
                case 18:
                    textbackground(BROWN);
                    colset[2] = 6;
                    goto col;
                case 20:
                    textbackground(YELLOW);
                    colset[2] = 14;
                    goto col;
                case 22:
                    textbackground(WHITE);
                    colset[2] = 15;
                    goto col;
                }
            case 14:
                switch (y7) // bod color
                {
                case 6:
                    color = 0;
                    bod(color);
                    colset[0] = color;
                    break;
                case 8:
                    color = 1;
                    bod(color);
                    colset[0] = color;
                    break;
                case 10:
                    color = 2;
                    bod(color);
                    colset[0] = color;
                    break;
                case 12:
                    color = 3;
                    bod(color);
                    colset[0] = color;
                    break;
                case 14:
                    color = 4;
                    bod(color);
                    colset[0] = color;
                    break;
                case 16:
                    color = 5;
                    bod(color);
                    colset[0] = color;
                    break;
                case 18:
                    color = 6;
                    bod(color);
                    colset[0] = color;
                    break;
                case 20:
                    color = 14;
                    bod(color);
                    colset[0] = color;
                    break;
                case 22:
                    color = 15;
                    bod(color);
                    colset[0] = color;
                    break;
                }
            }
            goto col;
        case 11:
            clrscr();
            printf("\n\n\n\n\n\tCurrent Staring Frequency Is %d.\n\n\n\tPlease Enter The New One : \t", s);
            gotoxy(1, 1);
            bod(color);
            gotoxy(36, 9);
            scanf("%d", &ft);
            if (s == ft)
            {
                printf("\n\n\n\tNo Changes Made. Press Any Key To Return.");
                bod(color);
                getch();
                goto settings;
            }
            s = ft;
            printf("\n\n\n\tStarting Frequency Successfully Changed To %d.\n\n\tPress Any Key To Return\n", s);
            gotoxy(1, 1);
            bod(color);
            getch();
            goto settings;
        case 15:
            colset[0] = color = 4;
            colset[1] = decolor = 6;
            colset[2] = 15;
            textbackground(WHITE);
            clrscr();
            eff();
            printf("\n\n\n\n\n\n\n\n\n\n\t\t  Successfully Restored To Default Settings.\n\n\t\t\t  Press Enter To Return.\n");
            bod(color);
            getch();
            goto defaul;
        case 17:
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
        bod(color);
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
        bod(color);
    h:
        so = getch();
        if (toupper(so) == 'Y')
        {
            per1 = fopen("sta1.pi", "w");
            fprintf(per1, "%d", sy);
            fclose(per1);
            for (em = 0; em <= sy; em++)
                if (nam[em][strlen(nam[em]) - 1] == '\n')
                    nam[em][strlen(nam[em]) - 1] = '\0';
            per2 = fopen("sta2.pi", "w");
            for (i = -1; i < sy;)
            {
                fputs(nam[++i], per2);
                fprintf(per2, "\n");
            }
            fclose(per2);
            per3 = fopen("sta3.pi", "w");
            for (i = 0; i < 3; i++)
                fprintf(per3, "%d ", colset[i]);
            fclose(per3);
            clrscr();
            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t     Bye\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tBy Divins.");
            gotoxy(1, 1);
            bod(color);
            for (i = 3; i != 0; i--)
            {
                gotoxy(44, 11);
                printf("(%d)", i);
                sleep(1);
            }
            system("exit");
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
void bod(int color)
{
    int i;
    textcolor(color);
    gotoxy(1, 1);
    cprintf("ة");
    for (i = 0; i < 77; i++)
        cprintf("ح");
    cprintf("»");
    for (i = 2; i < 25; i++)
    {
        gotoxy(1, i);
        cprintf("؛");
    }
    gotoxy(1, i);
    cprintf("ب");
    for (i = 0; i < 77; i++)
        cprintf("ح");
    cprintf("¼");
    for (i = 2; i < 25; i++)
    {
        gotoxy(79, i);
        cprintf("؛");
    }
    /* THE BOUNDARY IS DRAWN */
    textcolor(decolor);
}
void menu(int o)
{
    int i, j;
    switch (o)
    {
    case 1:
        gotoxy(25, 2);
        printf(" _____");
        gotoxy(25, 3);
        printf("|     \\\n");
        gotoxy(25, 4);
        printf("| (_)  ]\n");
        gotoxy(25, 5);
        printf("|  ___/\n");
        gotoxy(25, 6);
        printf("| |(_) __ _   _ __   ___\n");
        gotoxy(25, 7);
        printf("| || |/ _` \\ | `_ \\ /   \\ \n");
        gotoxy(25, 8);
        printf("| || | (_| | | | | | (_) )_\n");
        gotoxy(25, 9);
        printf("|_||_|\\__,_| |_| |_|\\___/(_)\n");
        gotoxy(1, 1);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t Start Piano.\n\n\t\t\t Change Settings.\n\n\t\t\t Enter Recording Mode.\n\n\t\t\t Play Saved Recording.\n\n\t\t\t Exit.");
        textcolor(color);
        gotoxy(1, 1);
        cprintf("ة");
        for (i = 0; i < 77; i++)
        {
            if (i == 8 || i == 16 || i == 57 || i == 65)
                cprintf("%c", 203);
            else
                cprintf("ح");
        }
        cprintf("»");
        gotoxy(2, 11);
        for (i = 0; i < 77; i++)
        {
            if (i == 8 || i == 16 || i == 57 || i == 65)
                cprintf("%c", 458);
            else
                cprintf("ح");
        }
        gotoxy(10, 2);
        cprintf("ب");
        cprintf("ح");
        cprintf("»");
        for (i = 3; i < 10; i++)
        {
            gotoxy(12, i);
            cprintf("؛");
        }
        gotoxy(12, i);
        cprintf("¼");
        gotoxy(11, i);
        cprintf("ح");
        gotoxy(10, i);
        cprintf("ة");
        gotoxy(18, 2);
        cprintf("¼");
        gotoxy(17, 2);
        cprintf("ح");
        gotoxy(16, 2);
        cprintf("ة");
        for (i = 3; i < 10; i++)
        {
            gotoxy(16, i);
            cprintf("؛");
        }
        gotoxy(16, i);
        cprintf("ب");
        cprintf("ح");
        cprintf("»");
        for (i = 2; i < 25; i++)
        {
            gotoxy(1, i);
            if (i == 11)
                cprintf("%c", 204);
            else
                cprintf("؛");
        }
        gotoxy(1, i);
        cprintf("ب");
        for (i = 0; i < 77; i++)
            cprintf("ح");
        cprintf("¼");
        for (i = 2; i < 25; i++)
        {
            gotoxy(79, i);
            if (i == 11)
                cprintf("%c", 185);
            else
                cprintf("؛");
        }
        gotoxy(59, 2);
        cprintf("ب");
        cprintf("ح");
        cprintf("»");
        for (i = 3; i < 10; i++)
        {
            gotoxy(61, i);
            cprintf("؛");
        }
        gotoxy(61, i);
        cprintf("¼");
        gotoxy(60, i);
        cprintf("ح");
        gotoxy(59, i);
        cprintf("ة");
        gotoxy(67, 2);
        cprintf("¼");
        gotoxy(66, 2);
        cprintf("ح");
        gotoxy(65, 2);
        cprintf("ة");
        for (i = 3; i < 10; i++)
        {
            gotoxy(65, i);
            cprintf("؛");
        }
        gotoxy(65, i);
        cprintf("ب");
        cprintf("ح");
        cprintf("»");
        for (i = 2; i < 25; i++)
        {
            gotoxy(1, i);
            if (i == 11)
                cprintf("%c", 204);
            else
                cprintf("؛");
        }
        gotoxy(1, i);
        cprintf("ب");
        for (i = 0; i < 77; i++)
            cprintf("ح");
        cprintf("¼");
        for (i = 2; i < 25; i++)
        {
            gotoxy(79, i);
            if (i == 11)
                cprintf("%c", 185);
            else
                cprintf("؛");
        }
        for (i = 0; i < 35; i++)
            cprintf("ح");
        /* THE BOUNDARY IS DRAWN */
        textcolor(decolor);
        break;
    case 2:
        printf("\n\n\n\n\n\n\n\n\t\t\t Change Sound-Time Manipulation.\n\n\t\t\t Change Frquency Settings.\n\n\t\t\t Change Appearences.\n\n\t\t\t Restore Settings.\n\n\t\t\t Go Back.");
        bod(color);
        break;
    case 3:
        printf("\n\n\n\n\t\t\t\t  Clip Completed.\n\n\n\n\n\n\t\t\t    Here It Again.\n\n\t\t\t    Save This Recording.\n\n\t\t\t    Return To Menu.\n\n\t\t\t    Exit.\n");
        bod(color);
        break;
    case 4:
        printf("\n\n\n\n\n\n\n\n\n\t\t\t Change Text Color.\n\n\t\t\t Change Background Color.\n\n\t\t\t Change Border Color.\n\n\t\t\t Go Back.");
        bod(color);
        break;
    case 5:
        printf("\n\t\t\t  Select Your %s Color.", type);
        gotoxy(27, 3);
        for (i = 0; i < strlen(type) + 19; i++)
            printf("ك");
        gotoxy(23, 6);
        textcolor(BLACK);
        cprintf("BLACK");
        gotoxy(23, 8);
        textcolor(BLUE);
        cprintf("BLUE");
        gotoxy(23, 10);
        textcolor(GREEN);
        cprintf("GREEN");
        gotoxy(23, 12);
        textcolor(CYAN);
        cprintf("CYAN");
        gotoxy(23, 14);
        textcolor(RED);
        cprintf("RED");
        gotoxy(23, 16);
        textcolor(MAGENTA);
        cprintf("MAGENTA");
        gotoxy(23, 18);
        textcolor(BROWN);
        cprintf("BROWN");
        gotoxy(23, 20);
        textcolor(YELLOW);
        cprintf("YELLOW");
        gotoxy(23, 22);
        textcolor(WHITE);
        cprintf("WHITE");
        textcolor(decolor);
        bod(color);
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
    bod(color);
}
void naam(char nam[5][50], int sy)
{
    int j, i;
    gotoxy(32, 3);
    printf("Your Recordings:-");
    gotoxy(32, 4);
    printf("ككككككككككككككككك");
    gotoxy(32, 23);
    printf("Press B to Go Back.");
    gotoxy(23, 9);
    for (j = 0, i = 11; j <= sy; j++, i += 2)
    {
        cprintf("%d.  %s", j + 1, nam[j]);
        gotoxy(23, i);
    }
    gotoxy(1, 1);
    bod(color);
}
void nemu(char nam[50])
{
    int l, i;
    l = 38 - ((strlen(nam)) / 2);
    gotoxy(l + 1, 3);
    puts(nam);
    gotoxy(l + 1, 4);
    for (i = 0; i < strlen(nam); i++)
        printf("ك");
    gotoxy(26, 9);
    printf("Play This Recording.\n\n\t\t\t Rename This Recording.\n\n\t\t\t Delete This Recording.\n\n\t\t\t Go Back.");
    gotoxy(1, 1);
    bod(color);
}
void eff(void)
{
    int i, c;
    for (c = 0; c <= 1; c++)
    {
        for (i = 37; i <= 43; i++)
        {
            gotoxy(34, 10);
            printf("  Working...");
            bod(color);
            gotoxy(i, 12);
            printf("%c", 790);
            delay(150);
            clrscr();
        }
        for (; i >= 37; i--)
        {
            gotoxy(34, 10);
            printf("  Working...");
            bod(color);
            gotoxy(i, 12);
            printf("%c", 790);
            delay(150);
            clrscr();
        }
    }
}