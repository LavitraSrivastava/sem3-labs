`timescale 1ns/1ns
`include "mux8to1.v"

module mux8to1_tb;
reg [0:7]W;
reg [2:0]S;
wire f;

mux8to1 m1(W,S,f);
initial begin
	$dumpfile("mux8to1_tb.vcd");
	$dumpvars(0,mux8to1_tb);
	
	W=8'b10011001;
	S=3'b000;#20;
	S=3'b001;#20;
	S=3'b010;#20;
	S=3'b011;#20;
	S=3'b100;#20;
	S=3'b101;#20;
	S=3'b110;#20;
	S=3'b111;#20;
	
	$display("Test complete");
end
endmodule
