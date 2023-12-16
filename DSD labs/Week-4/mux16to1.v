module mux16to1(W,S,f);
input [0:15]W;
input [3:0]S;
output f;
wire [0:1]M;
mux8to1 m1(W[0:7],S[2:0],M[0]);
mux8to1 m2(W[8:15],S[2:0],M[1]);
mux2to1 m3(M[0:1], S[3], f);
endmodule



module mux2to1(W,S,f);
input [0:1]W;
input S;
output reg f;
always@(W or S)
case (S)
1'b0: f=W[0];
1'b1: f=W[1];
endcase
endmodule



module mux8to1(W,S,f);
input [0:7]W;
input [2:0]S;
output reg f;

always@(W or S)
case (S)
3'b000: f=W[0];
3'b001: f=W[1];
3'b010: f=W[2];
3'b011: f=W[3];
3'b100: f=W[4];
3'b101: f=W[5];
3'b110: f=W[6];
3'b111: f=W[7];
endcase
endmodule
