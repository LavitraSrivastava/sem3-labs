module Q1(A, B, C, D, G, F);
input A, B, C, D;
output G, F;
assign G = (C & ~D) | (~C & D);
assign F = (A & G) | (B & ~G);
endmodule
