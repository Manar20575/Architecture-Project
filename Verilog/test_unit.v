// The top level module (TEST)
module Unit_test (clk, updown, reset, teller, 
full, empty, alarm, display1, display2, display3, pcount, tcount);

// We have five inputs to get from the user
input wire clk, reset, updown;
input [2:0] teller;

// We give four outputs
// Two for empty or flag
// ,one for showing the number of people in queue
//  and one for showing the waiting time
output full, empty, alarm;
output [3:0] pcount;
output [6:0] display1, display2, display3;
output [1:0] tcount;
wire [4:0]wtime;

// We use this to show two digits in seven segment
wire [3:0] first_digit = wtime % 10;
wire [3:0] second_digit = wtime / 10;

// We start counting the pcount whether it's increasing or decreasing 
UpDown_counter counter (clk, reset, updown, pcount, alarm);

// For flags
flags f (pcount, empty, full);

// We prepare the tellers situation with 2bit instead of 3bit  
Teller t (teller,tcount);

// We calculate the waiting time by getting it from the rom 
waiting_time wt(pcount, tcount, wtime);

// It's time to display the results above 
seg d1 (first_digit, display1);
seg d2 (second_digit, display2);		
seg d3 (pcount, display3);
endmodule

module unit_test_t ();
  reg clk, reset, updown;
  reg [2:0] teller;
  
  wire full, empty, alarm;
  wire [3:0] pcount;
  wire [1:0] tcount;
  wire [6:0] display1, display2, display3;
  initial
  begin 
  clk = 0;
  reset = 1;
  // Up
  #100; reset = 0; updown = 1; teller[2] = 0; teller[1] = 0; teller[0] = 0; 
  #100; reset = 0; updown = 1; teller[2] = 0; teller[1] = 0; teller[0] = 1;
  #100; reset = 0; updown = 1; teller[2] = 0; teller[1] = 1; teller[0] = 0;
  #100; reset = 0; updown = 1; teller[2] = 0; teller[1] = 1; teller[0] = 1;
  #100; reset = 0; updown = 1; teller[2] = 1; teller[1] = 0; teller[0] = 0;
  #100; reset = 0; updown = 1; teller[2] = 1; teller[1] = 0; teller[0] = 1;
  #100; reset = 0; updown = 1; teller[2] = 1; teller[1] = 1; teller[0] = 0;
  #100; reset = 0; updown = 1; teller[2] = 1; teller[1] = 1; teller[0] = 1;
  // Down
  #100; reset = 0; updown = 0; teller[2] = 0; teller[1] = 0; teller[0] = 0;
  #100; reset = 0; updown = 0; teller[2] = 0; teller[1] = 0; teller[0] = 1;
  #100; reset = 0; updown = 0; teller[2] = 0; teller[1] = 1; teller[0] = 0;
  #100; reset = 0; updown = 0; teller[2] = 0; teller[1] = 1; teller[0] = 1;
  #100; reset = 0; updown = 0; teller[2] = 1; teller[1] = 0; teller[0] = 0;
  #100; reset = 0; updown = 0; teller[2] = 1; teller[1] = 0; teller[0] = 1;
  #100; reset = 0; updown = 0; teller[2] = 1; teller[1] = 1; teller[0] = 0;
  #100; reset = 0; updown = 0; teller[2] = 1; teller[1] = 1; teller[0] = 1;
  end
  always 
    #50 clk <= ~clk;
    
  Unit_test tst(clk, updown, reset, teller, full, empty, alarm, display1, display2, display3, pcount, tcount);
endmodule
