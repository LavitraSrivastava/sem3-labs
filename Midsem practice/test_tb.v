`timescale 1ns/1ns
`include "test.v"

module test_tb();
reg a,b,c;
wire f;

test t1(a,b,c,f);
initial begin
    $dumpfile("test_tb.vcd");
    $dumpvars(0,test_tb);

    a=0;b=0;c=0;#20;
    a=0;b=0;c=1;#20;
    a=0;b=1;c=0;#20;
    a=0;b=1;c=1;#20;
    a=1;b=0;c=0;#20;
    a=1;b=0;c=1;#20;
    a=1;b=1;c=0;#20;
    a=1;b=1;c=1;#20;

    $display("Test complete");
end
endmodule