`timescale 1ns/1ns
`include "f0.v"

module f0_tb();
reg a,b,c,d;
wire g;

f0 stg0(a,b,c,d,g);
initial begin
	$dumpfile("f0_tb.vcd");
	$dumpvars(0,f0_tb);
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
