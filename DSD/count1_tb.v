`timescale 1ns/1ns
`include "count1.v"

module count1_tb();
reg [5:0]b;
wire [2:0]f;

count1 c1(b,f);
initial begin
	$dumpfile("count1_tb.vcd");
	$dumpvars(0,count1_tb);
	b=6'b111111;#20;
	b=6'b111100;#20;
	b=6'b001001;#20;
	b=6'b000001;#20;
	$display("Test complete");
end
endmodule
