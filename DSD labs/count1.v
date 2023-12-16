module fulladder(cin,x,y,s,cout);
input cin,x,y;
output s,cout;
assign s = cin^x^y;
assign cout = (cin&x)|(x&y)|(cin&y);
endmodule

module count1(b,f);
input [5:0]b;
output [2:0]f;
wire [1:0]m0;
wire [1:0]m1;
wire c;
fulladder f0(b[0],b[1],b[2],m0[0],m0[1]);
fulladder f1(b[3],b[4],b[5],m1[0],m1[1]);
fulladder f2(1'b0,m0[0],m1[0],f[0],c);
fulladder f3(c,m0[1],m1[1],f[1],f[2]);
endmodule
