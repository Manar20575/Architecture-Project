// Module to show If the queue is empty or full
#include <stdio.h>
#include "flags.h"
#include <stdbool.h> 
int flags (int pcount, bool empty, bool full)
{
  while (pcount)
  {
    // If it's 7 it's full and not empty
    if(pcount == 7)
    {
        full = 1;
        empty = 0;
    }
    // If it's 0 it's empty and not full
    else if(pcount == 0)
        {
            empty = 1;
            full = 0;
        }
    // Else it's neither
    else
        {
            full = 0;
            empty = 0;
        }
    }
}
