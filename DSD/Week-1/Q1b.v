module Q1b(f,a,b,c,d);
input a,b,c,d;
output f;
assign f=(b&~c)|(c&~d);
endmodule
