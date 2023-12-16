module Q3(ctrl, X, Y, S, carryout);
input ctrl;
input [3:0] X, Y;
output [3:0]S;
output carryout;
wire [3:0]Yc;
wire [3:1]C;
assign Yc[3] = Y[3] ^ ctrl;
assign Yc[2] = Y[2] ^ ctrl;
assign Yc[1] = Y[1] ^ ctrl;
assign Yc[0] = Y[0] ^ ctrl;
full_adder s0(ctrl, X[0], Yc[0], S[0], C[1]);
full_adder s1(C[1], X[1], Yc[1], S[1], C[2]);
full_adder s2(C[2], X[2], Yc[2], S[2], C[3]);
full_adder s3(C[3], X[3], Yc[3], S[3], carryout);
endmodule

module full_adder(cin, x, y, s, cout);
input cin, x, y; 
output s, cout;
assign s = x^y^cin;
assign cout = (x&y)|(x&cin)|(y&cin);
endmodule
