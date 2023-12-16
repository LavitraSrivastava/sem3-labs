`timescale 1ns/1ns
`include "Q3.v"
module Q3_tb();
reg clk,clear;
wire [2:0]Q;
Q3 q3(clear,clk,Q);
initial begin
	$dumpfile("Q3_tb.vcd");
	$dumpvars(0,Q3_tb);
	clk=1;
	forever #10 clk=~clk;
end
initial begin
	clear=1;#20;
	clear=0;#400;
	$display("Test complete");
	$finish;
end
endmodule
