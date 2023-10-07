/*module full_adder(cin,x,y,s,cout);
input cin,x,y;
output s,cout;
assign s = cin^x^y;
assign cout = (cin&x)|(cin&y)|(x&y);
endmodule*/

//full_adder using half_adders

module half_adder(x,y,c,s);
input x,y;
output c,s;
assign c = x&y;
assign s = x^y;
endmodule

module full_adder(cin,x,y,s,cout);
input cin,x,y;
output s,cout;
wire m1,m2,m3;
half_adder h1(cin,x,
