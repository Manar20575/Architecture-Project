// The top level module 
#include <stdio.h>
#include <stdbool.h> 
#include "counter.h"
#include "flags.h"
#include "teller.h"
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
    int tcount[1];
    // We use this to show two digits in seven segment
    int first_digit, second_digit;

    // We start counting the pcount whether it's increasing or decreasing 
    pcount = counter (reset, updown, clk, pcount, alarm);

    // For flags
    empty, full = flags(pcount, empty, full);

    // We prepare the tellers situation with 2bit instead of 3bit  
    * tcount = Teller (teller, tcount);

    // We calculate the waiting time by getting it from the rom 
    waiting_time wt(pcount, tcount, wtime);

    // Then we get the two digits separately
    assign first_digit = wtime % 10;
    assign second_digit = wtime / 10;

    // It's time to display the results above 
    seg d1 (first_digit, display1);
    seg d2 (second_digit, display2);		
    seg d3 (pcount, display3);
    return 0;
}
