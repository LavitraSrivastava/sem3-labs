`timescale 1ns/1ns
`include "fulladder_4to1mux.v"

module fulladder_4to1mux_tb();
reg cin,a,b;
wire s,c;

fulladder_4to1mux f1(cin,a,b,s,c);
initial begin
	$dumpfile("fulladder_4to1mux_tb.vcd");
	$dumpvars(0,fulladder_4to1mux_tb);
	cin=0;a=0;b=0;#20;
	cin=0;a=0;b=1;#20;
	cin=0;a=1;b=0;#20;
	cin=0;a=1;b=1;#20;
	cin=1;a=0;b=0;#20;
	cin=1;a=0;b=1;#20;
	cin=1;a=1;b=0;#20;
	cin=1;a=1;b=1;#20;
	$display("Test complete");
end
endmodule
