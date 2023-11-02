`timescale 1ns/1ns
`include "upc.v"

module upc_tb();
reg clk,clear;
wire [3:0]Q;

upc upc1(clk,clear,Q);
initial begin
	$dumpfile("upc_tb.vcd");
	$dumpvars(0,upc_tb);
	clk=1;
	forever #20 clk=~clk;
end
initial begin
	clear=1;#40;
	clear=0;#320;
	$display("Test complete");
	$finish;
end
endmodule
