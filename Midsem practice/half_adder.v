module half_adder(x,y,c,s);
input x,y;
output c,s;
assign c = x&y;
assign s = x^y;
endmodule
