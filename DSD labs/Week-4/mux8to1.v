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
