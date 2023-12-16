module comp3bit(A,B,eq,gt,lt);
input [2:0]A;
input [2:0]B;
output eq,gt,lt;
xnor(i2,A[2],B[2]);
xnor(i1,A[1],B[1]);
xnor(i0,A[0],B[0]);

and (eq,i2,i1,i0);
and (k1,A[2],~B[2]);
and (k2,i2,A[1],~B[1]);
and (k3,i2,i1,A[0],~B[0]);

or (gt,k1,k2,k3);
nor (lt,eq,gt);
endmodule


