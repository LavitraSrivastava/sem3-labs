module mux4to1(w,s,f);
input [0:3]w;
input [1:0]s;
output reg f;
always@(w or s)
begin
if (s==0)
	f=w[0];
else if (s==1)
	f=w[1];
else if (s==2)
	f=w[2];
else if (s==3)
	f=w[3];
end
endmodule


module fulladder_4to1mux(cin,a,b,s,c);
input cin,a,b;
output s,c;
wire [1:0]d;
wire [0:3]m1,m2;
assign m1 = {b,~b,~b,b};
assign m2 = {1'b0,b,b,1'b1};
assign d= {cin,a};
mux4to1 s0(m1,d,s);
mux4to1 s1(m2,d,c);
endmodule
