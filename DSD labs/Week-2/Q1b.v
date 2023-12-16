module Q1b(A,B,C,D,f);
input A,B,C,D;
output f;
assign f = (C & ~D) | (B & ~C);
endmodule
