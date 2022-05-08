// It's the ROM for the project
#include <stdio.h>
int waiting_time (pcount, tcount, wtime)
{
int pcount, tcount[1];
int wtime[4], rom[5];
// We use the concatenation for the waiting time and people number
    rom = {tcount,pcount};
    switch(rom)   
    {    
        6'b010000 : wtime <= 5'b00000; // 0
        6'b010001 : wtime <= 5'b00011; // 3 
        6'b010010 : wtime <= 5'b00110; // 6
        6'b010011 : wtime <= 5'b00100; // 4
        6'b010100 : wtime <= 5'b01110; // 14
        6'b010101 : wtime <= 5'b01111; // 15
        6'b010110 : wtime <= 5'b10010; // 18
        6'b010111 : wtime <= 5'b10101; // 21

        6'b100000 : wtime <= 5'b00000; // 0
        6'b100001 : wtime <= 5'b00011; // 3
        6'b100010 : wtime <= 5'b00100; // 4
        6'b100011 : wtime <= 5'b00110; // 6
        6'b100100 : wtime <= 5'b01001; // 9
        6'b100101 : wtime <= 5'b01010; // 10
        6'b100110 : wtime <= 5'b01100; // 12
        6'b100111 : wtime <= 5'b00110; // 6

        6'b110000 : wtime <= 5'b00000; // 0
        6'b110001 : wtime <= 5'b00011; // 3
        6'b110010 : wtime <= 5'b00100; // 4
        6'b110011 : wtime <= 5'b00101; // 5
        6'b110100 : wtime <= 5'b00110; // 6
        6'b110101 : wtime <= 5'b00111; // 7
        6'b110110 : wtime <= 5'b01000; // 8
        6'b110111 : wtime <= 5'b01001; // 9
        default : wtime <= 5'b00000; // 0
    }
}
