// A modile for solving bouncing problem
// using clock divide
module slowClock (clk, reset, slow_clk);
  input clk, reset;
  output reg slow_clk;
  reg [24:0] count;
  always @ (posedge clk, posedge reset)
  begin
    // If it's reset we start from 0
    if(reset)
      begin
      count <= 0;
      slow_clk <= 0;
      end
    // If it's not we keep counting 1_000_000 then invert the clock
    // And start again from 0
    else
      begin
      if (count < 1_000_000)
        begin
        count <= count + 1;
        end
      else
        begin
        slow_clk = ~slow_clk;
        count <= 0;
        end
      end
  end 
endmodule
