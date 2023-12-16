`timescale 1ns/1ns
`include "Q1.v"

module Q1_tb;
reg A,B,C,D;
wire F, G;

Q1 q1(A,B,C,D,G,F);
initial begin

	$dumpfile("Q1_tb.vcd");
	$dumpvars(0,Q1_tb);
	
	A=0;B=0;C=0;D=0;#20;
	A=0;B=0;C=0;D=1;#20;
	A=0;B=0;C=1;D=0;#20;
	A=0;B=0;C=1;D=1;#20;
	A=0;B=1;C=0;D=0;#20;
	A=0;B=1;C=0;D=1;#20;
	A=0;B=1;C=1;D=0;#20;
	A=0;B=1;C=1;D=1;#20;
	A=1;B=0;C=0;D=0;#20;
	A=1;B=0;C=0;D=1;#20;
	A=1;B=0;C=1;D=0;#20;
	A=1;B=0;C=1;D=1;#20;
	A=1;B=1;C=0;D=0;#20;
	A=1;B=1;C=0;D=1;#20;
	A=1;B=1;C=1;D=0;#20;
	A=1;B=1;C=1;D=1;#20;
	
	$display("Test complete");
	
end

endmodule

