module PEn4to2(w,y,z);
input [3:0]w;
output reg [1:0]y;
output reg z;

always@(w)
begin
z=1;
y=2'bXX;
casex(w)
4'b1XXX : y=3;
4'b01XX : y=2;
4'b001X : y=1;
4'b0001 : y=0;
default z=0;
endcase
end

endmodule

