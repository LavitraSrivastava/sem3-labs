`timescale 1ns/1ns
`include "Q2.v"

module Q2_tb;
reg cin, x, y;
wire s,cout;

Q2 q2(cin,x,y,s,cout);
initial begin

	$dumpfile("Q2_tb.vcd");
	$dumpvars(0,Q2_tb);
	
	cin=0;x=0;y=0;#20;
	cin=0;x=0;y=1;#20;
	cin=0;x=1;y=0;#20;
	cin=0;x=1;y=1;#20;
	cin=1;x=0;y=0;#20;
	cin=1;x=0;y=1;#20;
	cin=1;x=1;y=0;#20;
	cin=1;x=1;y=1;#20;
	
	$display("Test complete");
	
end

endmodule

