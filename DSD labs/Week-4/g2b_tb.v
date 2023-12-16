`timescale 1ns/1ns
`include "g2b.v"

module g2b_tb;
parameter n=4;
reg [n-1:0]g;
wire [n-1:0]b;

g2b g1(g,b);
initial begin
	$dumpfile("g2b_tb.vcd");
	$dumpvars(0,g2b_tb);
	
	g=4'b0101;#20;
	g=4'b0111;#20;
	g=4'b1110;#20;
	g=4'b1001;#20;
	g=4'b0001;#20;
	g=4'b1000;#20;
	
	$display("Test complete");
end
endmodule
