module example2(x1,x2,x3,x4,f);
input x1,x2,x3,x4;
output f;
and(i,x1,x3);
and(j,x2,x4);
or(g,i,j);
or(k,x1,~x3);
or(l,~x2,x4);
and(h,k,l);
or(f,g,h);
endmodule
