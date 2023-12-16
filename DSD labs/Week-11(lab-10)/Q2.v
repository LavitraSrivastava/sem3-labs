module srff(Q,s,r,clear,clk);
input s,r,clear,clk;
output reg Q;
always@(posedge clk)
begin
	if(clear==1)
		Q<=3'b001;
	else
		Q<=s|(Q&~r);
end
endmodule

module Q2(clear,clk,Q);
input clear,clk;
output [2:0]Q;
srff ff2(Q[2],(~Q[1]&~Q[0]),(~Q[1]&Q[0]),clear,clk);
srff ff1(Q[1],(~Q[2]&~Q[1]),( (Q[2]&~Q[0]) | (~Q[2]&Q[1]&Q[0]) ),clear,clk);
srff ff0(Q[0],~Q[0],( (~Q[2]&Q[0]) | (Q[1]&Q[0]) ),clear,clk);
endmodule

