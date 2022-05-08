// The top level module 
#include <stdio.h>
#include <stdbool.h> 
#include "counter.h"
#include "flags.h"
#include "teller.h"
#include "wtime.h"
#include "seg.h"
int main ()
{
    // We have five inputs to get from the user
    bool clk, reset, updown;
    int teller[2];

    // We give four outputs
    // Two for empty or flag
    // ,one for showing the number of people in queue
    //  and one for showing the waiting time
    bool full, empty, alarm;
    int pcount;
    int display1, display2, display3;
    int tcount[1], wtime;
    // We use this to show two digits in seven segment
    int first_digit, second_digit;

    // We start counting the pcount whether it's increasing or decreasing 
    pcount = counter (reset, updown, clk, pcount, alarm);

    // For flags
    empty, full = flags(pcount, empty, full);

    // We prepare the tellers situation with 2bit instead of 3bit  
    *tcount = Teller (teller, tcount);

    // We calculate the waiting time by getting it from the rom 
    wtime = waiting_time(pcount, tcount, wtime);

    // Then we get the two digits separately
    first_digit = wtime % 10;
    second_digit = wtime / 10;

    // It's time to display the results above 
    display1 = seg (first_digit, display1);
    display2 = seg (second_digit, display2);		
    display3 = seg (pcount, display3);
    return 0;
}
