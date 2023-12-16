module Q2a(f,a,b,c,d);
input a,b,c,d;
output f;
assign f = (b&c) | (c&~d) | (~b&c) | (~a&b&d);
endmodule
