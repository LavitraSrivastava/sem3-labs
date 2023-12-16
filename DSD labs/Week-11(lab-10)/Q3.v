module tff(Q,T,clear,clk);
input T,clear,clk;
output reg Q;
always@(posedge clk)
begin
	if(clear==1)
		Q<=0;
	else
		Q<=Q^T;
end
endmodule

module Q3(clear,clk,Q);
input clear,clk;
output [2:0]Q;
tff ff2(Q[2],(Q[2]^Q[1]),clear,clk);
tff ff1(Q[1],(Q[1]^Q[0]),clear,clk);
tff ff0(Q[0],~(Q[2]^Q[0]),clear,clk);
endmodule

