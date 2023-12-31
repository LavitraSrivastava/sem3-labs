`timescale 1ns/1ns
`include "mux4to1.v"

module mux4to1_tb;
reg [0:3]W;
reg [1:0]S;
wire f;

mux4to1 m1(W,S,f);
initial begin
	$dumpfile("mux4to1_tb.vcd");
	$dumpvars(0,mux4to1_tb);
	
	W=4'b1001;
	S=2'b00;#20;
	S=2'b01;#20;
	S=2'b10;#20;
	S=2'b11;#20;
	
	$display("Test complete");
end
endmodule
