`timescale 1ns/1ns
`include "Q1b.v"

module Q1b_tb;
reg A,B,C,D;
wire f;

Q1b q1(A,B,C,D,f);
initial begin

	$dumpfile("Q1b_tb.vcd");
	$dumpvars(0,Q1b_tb);
	
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

