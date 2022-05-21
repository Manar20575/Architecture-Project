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
    // inputs 
    bool reset;
    int pcount = 0, tcount = 0, exit, check;
    // output
    bool full, empty, alarm;
    int wtime = 0;
    // for checking the limits of inputs
    int tcount_tst, pcount_tst;

    // This statement to welcome the user in first input
    printf("Welcome to our bank system\n");
    printf("To add teller enter 3\n");
    printf("To remove Teller enter -3\n");
    printf("To count up enter 7\n");
    printf("To count down enter -7\n");
    printf("To reset the system enter 0\n");
    printf("To exit from the system enter -1\n");
    while (true)
    {
        scanf("%d", &check);
        switch (check)
        {
            // if the input is 3 the teller count is increased by 1
            // with the condition for the alarm if the user crossed the limits
            case 3:
                tcount_tst = tcounter(1, tcount);
                tcount = tcount_tst != 4 ? tcount_tst : tcount;
                wtime = waiting_time (pcount, tcount);
                break;
            // if the input is -3 the teller count is decreased by 1
            // with the condition for the alarm if the user crossed the limits
            case -3:
                tcount_tst = tcounter(0, tcount);
                tcount = tcount_tst != -1 ? tcount_tst : tcount;
                wtime = waiting_time (pcount, tcount);
                break;
            // if the input is 7 the people count is increased by 1
            // with the condition for the alarm if the user crossed the limits
            case 7:
                pcount_tst = pcounter(1, pcount);
                pcount = pcount_tst != 8 ? pcount_tst : pcount;
                wtime = waiting_time (pcount, tcount);
                break;
            // if the input is -7 the people count is decreased by 1
            // with the condition for the alarm if the user crossed the limits
            case -7:
                pcount_tst = pcounter(0, pcount);
                pcount = pcount_tst != -1 ? pcount_tst : pcount;
                wtime = waiting_time (pcount, tcount);
                break;
            // if the input is 0 the program is reset  
            case 0:
                pcount = 0;
                tcount = 0;
                wtime = waiting_time (pcount, tcount);
                break;
            // if the input is -1 the program colse
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
        // Check limits
        if (p_alarmflag (pcount_tst))
        {
            pcount_tst++;
        }
        if (t_alarmflag (tcount_tst))
        {
            tcount_tst++;
        }
        // check if empty
        if (emptyflag (pcount))
        {
            printf("The queue is empty.\n");
        }
        // Check if full
        if (fullflag (pcount))
        {
            printf("The queue is full.\n");
        }
        // Print the number of people and waiting time in every order
        printf("Waiting time is %d\n", wtime);
        printf("The Pcount is %d\n\n", pcount);
    }
    // This statement to end the program
    printf("I hope you enjoyed using our small bank system :)\n");
    return 0;
}
// The counter of people with limits [0:7]
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
// The counter of tellers with limits [0:3]
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
// If empty 
int emptyflag (int pcount)
{
    return pcount == 0;
}
// If full
int fullflag (int pcount)
{
    return pcount == 7;
}
// If crossed the limits for people
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
// If crossed the limits for tellers
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
// function for calculating the waiting time
int waiting_time (int pcount, int tcount)
{
    int sub, sum, mult;
    // wtime = 3 * (pcount + tcount - 1) / tcount
    // if pcount = 0, wtime = 0
    if (pcount == 0 || tcount == 0)
    {
        return 0;
    }
    // sub = tcount - 1
    sub = tcount - 1;
    // sum = sub + pcount
    sum = sub + pcount;
    // mult = 3 * sum // in for loop for assembly
    mult = 0;
    for (int i = 0; i < 3; i++)
    {
        mult += sum;
    }
    // result = mult / tcount
    int quot = 0;
    while (mult >= tcount)
    {
        mult -= tcount;
        quot++;
    }
    return quot;   
}
