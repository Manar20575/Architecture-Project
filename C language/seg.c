// A module for 7 segment and its decoder
#include <stdio.h>
#include "seg.h"
int *seg (int data, int *display)
{
    switch (data)
    {
                            // abcdefg 
        4'b0000 : display = ~7'b1111110;
        4'b0001 : display = ~7'b0110000;
        4'b0010 : display = ~7'b1101101;
        4'b0011 : display = ~7'b1111001;
        4'b0100 : display = ~7'b0110011;
        4'b0101 : display = ~7'b1011011;
        4'b0110 : display = ~7'b1011111;
        4'b0111 : display = ~7'b1110000;
        4'b1000 : display = ~7'b1111111;
        4'b1001 : display = ~7'b1111011;
        default : display = ~7'b1111110;
    }
    return display;
}