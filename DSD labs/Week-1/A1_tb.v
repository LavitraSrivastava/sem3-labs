`timescale 1ns/1ns
`include "A1.v"

module A1_tb();
reg a,b,c,d;
wire f1,f2;

A1 a1(f1,f2,a,b,c);
initial begin
	$dumpfile("A1_tb.vcd");
	$dumpvars(0,A1_tb);
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
