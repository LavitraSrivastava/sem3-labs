`timescale 1ns/1ns
`include "half_adder.v"

module half_adder_tb();
reg x,y;
wire s,c;

half_adder ha1(x,y,c,s);
initial begin
	$dumpfile("half_adder_tb.vcd");
	$dumpvars(0,half_adder_tb);
	x=0;y=0;#20;
	x=0;y=1;#20;
	x=1;y=0;#20;
	x=1;y=1;#20;
	$display("Test complete");
end
endmodule
