// A module for counting the number of people
#include <stdio.h>
#include "counter.h"
#include<stdbool.h> 
int counter (bool reset, bool updown, bool clk, int pcount, bool alarm)
{
  while (clk | reset)
  {
    // If we reset we get the counter to 0 and the line is empty and not full
   if (reset)
      {
        pcount = 0;
        alarm = 0;
      }
	 else
	 {
	  // If we chose up we increase the number of people and if it's full 
	  // we light the alarm up and not count up
    if (updown)
      {
        if(pcount == 7)
        {
          alarm = 1;
        }
        else
        {
          alarm = 0;
          pcount++;
        }
      }
    // If we chose down we decrease the number of people and if it's empty
    // we light the alarm and stop count down
	  else
	  {
        if (pcount == 0)
        {
          alarm  = 1;
        }
        else
        {
          alarm = 0;
          pcount--;
        }
      }
     }
  }
}
