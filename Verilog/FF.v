// It's a FlipFlop, follow-up module for the clock divider
// get the input and change it with the debounced clock
module FF (clk, d, q);
  input clk, d;
  output reg q;
  always @ (posedge clk)
  begin
    q <= d;
  end
endmodule
