//4 bit ring counter 
module rc(clk,clear,set,Q);
	input set,clk,clear;
	output [3:0] Q;
	dff s0(Q[0],clk,clear,set,Q[3]);
	dff s1(Q[3],clk,clear,~set,Q[2]);
	dff s2(Q[2],clk,clear,~set,Q[1]);
	dff s3(Q[1],clk,clear,~set,Q[0]);
endmodule

module dff(D,clk,clear,set,Q);
	input D,clk,set,clear;
	output reg Q;
	always @(posedge clk)
	begin
	if(!clear && set)
		Q <= 1;
	else if(!clear)
		Q <= 0;
	else
		Q <= D;
	end
endmodule
