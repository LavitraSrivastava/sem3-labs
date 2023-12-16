module A2(f,x1,x2,x3,x4);
input x1,x2,x3,x4;
output f;
assign f = (x1&x2&x4)|(x2&x3&x4)|(x1&x3&x4)|(x1&x2&x3);
endmodule
