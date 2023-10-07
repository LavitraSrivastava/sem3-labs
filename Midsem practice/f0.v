module mux4to1(w,s,f);
input [0:3]w;
input [1:0]s;
output reg f;
always@(s or w)
begin
if(s==0)
f=w[0];
else if(s==1)
f=w[1];
else if(s==2)
f=w[2];
else
f=w[3];
end
endmodule

module f0(a,b,c,d,g);
input a,b,c,d;
output g;
wire [0:3]m0;
wire [1:0]m1;
assign w = {c,~c&d,d,1'b0};
assign s = {a,b};
mux4to1 mux1(m0[0:3],m1[1:0],g);
endmodule
