`timescale 1ns/1ns
`include "additional_1.v"

module additional_1_tb;
  reg [1:0]w;
  reg e;
  wire [0:3]y;   


Decoder2_4 D1(w, e, y);
  initial begin
    $dumpfile("additional_1_tb.vcd");
    $dumpvars(0, additional_1_tb);

 e=0;
    	w=0;#20;
    	w=1;#20;
    	w=2;#20;
    	w=3;#20;
    	w=4;#20;
    	w=5;#20;
    	w=6;#20;
    	w=7;#20;
    	w=8;#20;
    	w=9;#20;
    	w=10;#20;
    	w=11;#20;
    	w=12;#20;
    	w=13;#20;
    	w=14;#20;
    	w=15;#20;
    e=1;
    	w=4'bx;#20;
    


   $display("Test complete");
  end
endmodule

