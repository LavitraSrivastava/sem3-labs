module Q4(w,f);
    input [2:0]w;
    output f;
    wire [0:7]y;
    dec2to4 stg0 (w[1:0], ~w[2], y[0:3]);
    dec2to4 stg1 (w[1:0], w[2], y[4:7]);
    assign f = (y[3] | y[5] | y[6] | y[7] );
endmodule


module dec2to4(w, en, y);
    input [1:0] w;
    input en;
    output reg [0:3]y;
    integer k;

    always @ (w or en)
        for (k=0;k<=3;k=k+1)
            if (w==k && en == 1)
                y[k] = 1;
            else
                y[k] = 0;
endmodule


