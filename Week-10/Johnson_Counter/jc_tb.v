`timescale 1ns/1ns
`include "jc.v" 
module jc_tb();
reg clk, set,clear; 
wire [4:0] Q;
jc jc1(clk, clear,set, Q);
initial
begin
	$dumpfile("jc_tb.vcd");
	$dumpvars(0, jc_tb);
	clk=0;
	forever #20 clk = ~clk;
end
initial begin
	clear = 0; set = 1; #40;
	set = 0;clear = 1;#320;
	$display("Test complete");
	$finish;
	
end
endmodule
