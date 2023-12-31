`timescale 1ns/1ns
`include "add1.v"

module add1_tb;
reg a,b,c;
wire f1,f2;

add1 a1(a,b,c,f1,f2);
initial begin
	
	$dumpfile("add1_tb.vcd");
	$dumpvars(0,add1_tb);
	
	a=0;b=0;c=0;#20;
	a=0;b=0;c=1;#20;
	a=0;b=1;c=0;#20;
	a=0;b=1;c=1;#20;
	a=1;b=0;c=0;#20;
	a=1;b=0;c=1;#20;
	a=1;b=1;c=0;#20;
	a=1;b=1;c=1;#20;
	
	$display("Test complete");
	
end
endmodule
	
	
