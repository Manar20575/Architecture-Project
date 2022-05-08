// A module for 7 segment and its decoder
module seg (data, display);
input [3:0]data;
output reg [6:0]display;
always @(*)
begin
case(data)
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
endcase
end
endmodule

module seg_t ();
  reg [3:0] data;
  wire [6:0]display;
  initial
  begin 
  data = 0;
  #100; data = 1;
  #100; data = 2;
  #100; data = 3;
  end
  seg tst(data, display);
endmodule