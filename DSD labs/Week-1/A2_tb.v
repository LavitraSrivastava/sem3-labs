`timescale 1ns/1ns
`include "A2.v"

module A2_tb();
reg a,b,c,d;
wire f;

A2 a2(f,a,b,c,d);
initial begin
	$dumpfile("A2_tb.vcd");
	$dumpvars(0,A2_tb);
	a=0;b=0;c=0;d=0;#20;
	a=0;b=0;c=0;d=1;#20;
	a=0;b=0;c=1;d=0;#20;
	a=0;b=0;c=1;d=1;#20;
	a=0;b=1;c=0;d=0;#20;
	a=0;b=1;c=0;d=1;#20;
	a=0;b=1;c=1;d=0;#20;
	a=0;b=1;c=1;d=1;#20;
	a=1;b=0;c=0;d=0;#20;
	a=1;b=0;c=0;d=1;#20;
	a=1;b=0;c=1;d=0;#20;
	a=1;b=0;c=1;d=1;#20;
	a=1;b=1;c=0;d=0;#20;
	a=1;b=1;c=0;d=1;#20;
	a=1;b=1;c=1;d=0;#20;
	a=1;b=1;c=1;d=1;#20;
	$display("Test complete");
end
endmodule	
