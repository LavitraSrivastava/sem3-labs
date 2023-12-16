`timescale 1ns/1ns
`include "input3dec.v"

module input3dec_tb();
reg [2:0]w;
wire f;

input3dec d1(w,f);
initial begin
	$dumpfile("input3dec_tb.vcd");
	$dumpvars(0,input3dec_tb);
	w=3'b000;#20;
	w=3'b001;#20;
	w=3'b010;#20;
	w=3'b011;#20;
	w=3'b100;#20;
	w=3'b101;#20;
	w=3'b110;#20;
	w=3'b111;#20;
	$display("Test complete");
end
endmodule
