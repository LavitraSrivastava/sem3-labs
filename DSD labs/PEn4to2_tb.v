`timescale 1ns/1ns
`include "PEn4to2.v"

module PEn4to2_tb();
reg [3:0]w;
wire [1:0]y;
wire z;

PEn4to2 p1(w,y,z);
initial begin
$dumpfile("PEn4to2_tb.vcd");
$dumpvars(0, PEn4to2_tb);

w=4'b1000;#20;
w=4'b0100;#20;
w=4'b0010;#20;
w=4'b0001;#20;
w=4'b0000;#20;

$display("Test complete");
end
endmodule
