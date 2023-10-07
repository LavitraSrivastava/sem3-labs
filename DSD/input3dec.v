module dec2to4(w,en,y);
input [1:0]w;
input en;
output reg [0:3]y;
integer k;

always@(w or en)
begin
	y=4'b0000;
	if (en==1)
	begin
		for(k=0; k<=3;k++)
		if (w==k)
			y[k]=1;
	end
end
endmodule


module input3dec(w,f);
input [2:0]w;
output f;
wire [0:7]m;

dec2to4 d1(w[1:0],~w[2],m[0:3]);
dec2to4 d2(w[1:0],w[2],m[4:7]);
assign f = (m[3]|m[5]|m[6]|m[7]);
endmodule
