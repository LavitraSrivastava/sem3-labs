`timescale 1ns/1ns
`include "Q2.v"
module Q2_tb();
reg clk,clear;
wire [2:0]Q;
Q2 q2(clear,clk,Q);
initial begin
	$dumpfile("Q2_tb.vcd");
	$dumpvars(0,Q2_tb);
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
