module upc(clk,clear,Q);
input clk,clear;
output [3:0]Q;
jkff s0(1'b1,1'b1,clk,clear,Q[0]);
jkff s1(1'b1,1'b1,Q[0],clear,Q[1]);
jkff s2(1'b1,1'b1,Q[1],clear,Q[2]);
jkff s3(1'b1,1'b1,Q[2],clear,Q[3]);
endmodule


module jkff(J,K,clk,resetn,Q);
input J,K,clk,resetn;
output reg Q;
always @(negedge clk)
begin
	if (resetn)
		Q<=0;
	else
		Q<=(J&~Q)|(~K&Q);
end
endmodule


