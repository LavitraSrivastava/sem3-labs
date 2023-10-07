`timescale 1ns/1ns
`include "full_adder.v"

module full_adder_tb();
reg cin,x,y;
wire s,cout;

full_adder fa1(cin,x,y,s,cout);
initial begin
	$dumpfile("full_adder_tb.vcd");
	$dumpvars(0,full_adder_tb);
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
