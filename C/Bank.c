#include <stdio.h>
#include <stdbool.h> 
int pcounter (bool updown, int pcount);
int tcounter (bool updown, int tcount);
int emptyflag (int pcount);
int fullflag (int pcount);
bool p_alarmflag (int pcount);
bool t_alarmflag (int tcount);
int waiting_time (int pcount, int tcount);
int main ()
{
    bool reset;
    bool full, empty, alarm;
    int pcount = 0, tcount = 0, wtime = 0, exit, check;
    int tcount_tst, pcount_tst;
    printf("Welcome to our bank system\n");
    while (true)
    {
        printf("To add teller enter 3\n");
        printf("To remove Teller enter -3\n");
        printf("To count up enter 7\n");
        printf("To count down enter -7\n");
        printf("To reset the system enter 0\n");
        printf("To exit from the system enter -1\n");
        scanf("%d", &check);
        switch (check)
        {
            case 3:
                tcount_tst = tcounter(1, tcount);
                tcount = tcount_tst != 4 ? tcount_tst : tcount;
                wtime = waiting_time (pcount, tcount);
                break;
            case -3:
                tcount_tst = tcounter(0, tcount);
                tcount = tcount_tst != -1 ? tcount_tst : tcount;
                wtime = waiting_time (pcount, tcount);
                break;
            case 7:
                pcount_tst = pcounter(1, pcount);
                pcount = pcount_tst != 8 ? pcount_tst : pcount;
                wtime = waiting_time (pcount, tcount);
                break;
            case -7:
                pcount_tst = pcounter(0, pcount);
                pcount = pcount_tst != -1 ? pcount_tst : pcount;
                wtime = waiting_time (pcount, tcount);
                break;
            case 0:
                pcount = 0;
                tcount = 0;
                wtime = waiting_time (pcount, tcount);
                break;
            case -1:
                exit = -1;
                break;
            default:
                printf("Enter a number from the list above\n");
        }   
        if (exit == -1)
        {
            break;
        }
        if (p_alarmflag (pcount_tst))
        {
            pcount_tst++;
        }
        if (t_alarmflag (tcount_tst))
        {
            tcount_tst++;
        }
        if (emptyflag (pcount))
        {
            printf("The queue is empty.\n");
        }
        if (fullflag (pcount))
        {
            printf("The queue is full.\n");
        }
        printf("Waiting time is %d\n", wtime);
        printf("The Pcount is %d\n\n", pcount);
    }
    printf("I hope you enjoyed using our small bank system :)\n");
    return 0;
}
int pcounter (bool updown, int pcount)
{
    if (updown == 1)
    {
        if (pcount == 7)
        {
            return 8;
        }
        pcount++;
    }
    else
    {
        if (pcount == 0)
        {
            return -1;
        }
        pcount--;
    }
    return pcount;
}
int tcounter (bool updown, int tcount)
{
    if (updown == 1)
    {
        if (tcount == 3)
        {
            return 4;
        }
        tcount++;
    }
    else
    {
        if (tcount == 0)
        {
            return -1;
        }
        tcount--;
    }
    return tcount;
}
int emptyflag (int pcount)
{
    return pcount == 0;
}
int fullflag (int pcount)
{
    return pcount == 7;
}
bool p_alarmflag (int pcount)
{
    if (pcount == 8)
    {
        printf("The maximum number of people we can add is 7, Now you only can remove.\n");
        return 1;
    }
    else if (pcount == -1)
    {
        printf("There is no one in the queue to leave.\n");
        return 1;
    }
    return 0;
}
bool t_alarmflag (int tcount)
{
    if (tcount == 4)
    {
        printf("The maximun number of tellers is 3, Now you only can remove.\n");
        return 1;
    }
    else if (tcount == -1)
    {
        printf("There is no tellers to remove.\n");
        return 1;
    }
    return 0;
}
int waiting_time (int pcount, int tcount)
{
    if (pcount == 0 || tcount == 0)
    {
        return 0;
    }
    int wtime[4][8] = {0}; // wtime[tcount][pcount]
    // We use the concatenation for the waiting time and people number  
    wtime[1][1] = 3; 
    wtime[1][2] = 6;
    wtime[1][3] = 4;
    wtime[1][4] = 14;
    wtime[1][5] = 15;
    wtime[1][6] = 18;
    wtime[1][7] = 21;
 
    wtime[2][1] = 3;
    wtime[2][2] = 4;
    wtime[2][3] = 6;
    wtime[2][4] = 9;
    wtime[2][5] = 10;
    wtime[2][6] = 12;
    wtime[2][7] = 6;

    wtime[3][1] = 3;
    wtime[3][2] = 4;
    wtime[3][3] = 5;
    wtime[3][4] = 6;
    wtime[3][5] = 7;
    wtime[3][6] = 8;
    wtime[3][7] = 9;

    return wtime[tcount][pcount];   
}
