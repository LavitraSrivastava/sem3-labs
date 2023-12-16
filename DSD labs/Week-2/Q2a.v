module Q2a(A,B,C,D,f);
input A,B,C,D;
output f;
assign f = (C|D)&(B|C)&(~A|~B|~C|~D);
endmodule
