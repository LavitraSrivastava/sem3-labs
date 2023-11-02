module mux4to1(W,S,f);
input [0:3]W;
input [1:0]S;
output reg f;

always@(W or S)
begin
if (S==2'b00)
	f=W[0];
else if (S==2'b01)
	f=W[1];
else if (S==2'b10)
	f=W[2];
else
	f=W[3];
end
endmodule
