`timescale 1ns/1ns
`include "Encoder4_2.v"

module Encoder4_2_tb;
  reg [3:0]w;   // 4-bit input
  wire [1:0]y;
  wire z;   


Encoder4_2 E1(w, y, z);

  initial begin
    $dumpfile("Encoder4_2_tb.vcd");
    $dumpvars(0, Encoder4_2_tb);


    w = 4'b0001;
    #20;


    w = 4'b0010;
    #20;


    w = 4'b0100;
    #20;



    w = 4'b1000;
    #20;


    w = 4'b0000;
    #20;

    $display ("Test Complete");

  end
endmodule

