`timescale 1ns/1ns
`include "Q2a.v"

module Q2a_tb;
reg A,B,C,D;
wire f;

Q2a q2(A,B,C,D,f);
initial begin

	$dumpfile("Q2a_tb.vcd");
	$dumpvars(0,Q2a_tb);
	
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

