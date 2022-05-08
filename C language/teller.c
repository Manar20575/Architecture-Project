// Module for encoding the 3bit tellers conditions into 2bit 
// this by using Full Adder to make 3 Taller  00 01 10 00
#include <stdio.h>
#include "teller.h"
#include <stdbool.h> 
int *Teller (int teller[2], int tcount[1])
{
    // Sum is tcount[0] 
    // S = A ^ B ^ C
    tcount [0] = teller[0] ^ teller[1] ^ teller[2];

    // Carry is the tcount[1]
    // Carry = AB + ACin + BCin
    tcount [1] = (teller[0] & teller[1]) + (teller[2] & teller[1]) + (teller[0] & teller[2]);

    return tcount;
}
