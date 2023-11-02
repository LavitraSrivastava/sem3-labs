`timescale 1ns/1ns
`include "dec2to4.v"

module dec2to4_tb;
  reg [1:0]w;
  reg e;
  wire [0:3]y;   


dec2to4 D1(w, e, y);
  initial begin
    $dumpfile("dec2to4_tb.vcd");
    $dumpvars(0, dec2to4_tb);

    e=1;
    w = 2'b00;#20;
    w = 2'b01;#20;
    w = 2'b10;#20;
    w = 2'b11;#20;
    
    e=0; w = 2'bX;#20;
    


   $display("Test complete");
  end
endmodule

