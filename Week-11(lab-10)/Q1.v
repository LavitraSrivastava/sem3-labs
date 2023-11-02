module jkff(Q,j,k,clear,clk);
input j,k,clear,clk;
output reg Q;
always@(posedge clk)
begin
	if(clear==1)
		Q<=0;
	else
		Q<=(j&~Q)|(~k&Q);
end
endmodule


//A=Q[2],B=Q[1],C=Q[0]
module Q1(clear,clk,Q);
input clear,clk;
output [2:0]Q;
jkff ff2(Q[2],Q[1],(Q[1]&Q[0]),clear,clk);
jkff ff1(Q[1],Q[0],(~Q[2]|Q[0]),clear,clk);
jkff ff0(Q[0],(Q[2]|~Q[1]),1'b1,clear,clk);
endmodule
