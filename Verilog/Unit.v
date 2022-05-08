// The top level module 
module Unit (clk, updown, reset, push, teller, 
full, empty, alarm, display1, display2, display3);

// We have five inputs to get from the user
input wire clk, reset, push, updown;
input [2:0] teller;

// We give four outputs
// Two for empty or flag
// ,one for showing the number of people in queue
//  and one for showing the waiting time
output wire full, empty, alarm;
wire [3:0] pcount;
output [6:0] display1, display2, display3;
wire [1:0] tcount;
wire [4:0] wtime;
// We use this to show two digits in seven segment
wire [3:0] first_digit, second_digit;

// We use this to get the debounced/divided clock
wire debounced_clk;

// First we divide the clock we take from FPGA
// And put it with the input from the push button to solve bouncing problem
slowClock divi(clk, reset, slow_clk);
FF ff (slow_clk, push, debounced_clk);

// We start counting the pcount whether it's increasing or decreasing 
UpDown_counter counter (debounced_clk, reset, updown, pcount, alarm);

// For flags
flags f (pcount, empty, full);

// We prepare the tellers situation with 2bit instead of 3bit  
Teller t (teller,tcount);

// We calculate the waiting time by getting it from the rom 
waiting_time wt(pcount, tcount, wtime);

// Then we get the two digits separately
assign first_digit = wtime % 10;
assign second_digit = wtime / 10;

// It's time to display the results above 
seg d1 (pcount, display1);
seg d2 (first_digit, display2);		
seg d3 (second_digit, display3);
endmodule