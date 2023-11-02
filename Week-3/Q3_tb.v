`timescale 1ns/1ns
`include "Q3.v"

module Q3_tb;
reg ctrl;
reg [3:0] X, Y;
wire [3:0]S;
wire carryout;

Q3 q3(ctrl, X, Y, S, carryout);
initial begin

	$dumpfile("Q3_tb.vcd");
	$dumpvars(0,Q3_tb);
	
	ctrl = 0; 
	X = 4'b0001; Y = 4'b0000;#3 
	X = 4'b0010; Y = 4'b0100;#3 
	X = 4'b0101; Y = 4'b0011;#3
	ctrl = 1;
	X = 4'b0001; Y = 4'b0000;#3
	X = 4'b0010; Y = 4'b0001;#3
	
	$display("Test complete");
	
end

endmodule

