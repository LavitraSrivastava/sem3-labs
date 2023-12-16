`timescale 1ns/1ns
`include "Q1.v"
module Q1_tb();
reg clk,clear;
wire [2:0]Q;
Q1 q1(clear,clk,Q);
initial begin
	$dumpfile("Q1_tb.vcd");
	$dumpvars(0,Q1_tb);
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
