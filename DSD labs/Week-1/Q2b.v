module Q2b(f,a,b,c,d);
input a,b,c,d;
output f;
assign f = (~a&~c&~d)|(~b&d)|(c&d)|(a&b);
endmodule
