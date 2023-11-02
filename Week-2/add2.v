module add2(x1,x2,x3,x4,f);
input x1,x2,x3,x4;
output f;
assign f = (x1&x4&(x2|x3))|(x2&x3&(x1|x4));
endmodule
