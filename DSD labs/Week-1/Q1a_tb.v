`timescale 1ns/1ns
`include "Q1a.v"

module Q1a_tb();
reg a,b,c,d;
wire f;
Q1a q1a(f,a,b,c,d);
initial begin
	$dumpfile("Q1a_tb.vcd");
	$dumpvars(0,Q1a_tb);
	a=0;b=0;c=0;d=0;#20;
	a=0;b=0;c=0;d=1;#20;
	a=0;b=0;c=1;d=0;#20;
	a=0;b=0;c=1;d=1;#20;
	a=0;b=1;c=0;d=0;#20;
	a=0;b=1;c=0;d=1;#20;
	a=0;b=1;c=1;d=0;#20;
	a=0;b=1;c=0;d=1;#20;
	a=1;b=0;c=0;d=0;#20;
	a=1;b=0;c=0;d=1;#20;
	a=1;b=0;c=1;d=0;#20;
	a=1;b=0;c=1;d=1;#20;
	a=1;b=1;c=0;d=0;#20;
	a=1;b=1;c=0;d=1;#20;
	a=1;b=1;c=1;d=0;#20;
	a=1;b=1;c=0;d=1;#20;
	$display("Test complete");
end
endmodule
