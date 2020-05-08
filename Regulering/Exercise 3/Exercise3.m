syms b1 b2 b3 J m r



A = [0 1 0 0;
     0 -b1/J 0 -b2/J;
     0 0 0 1;
     0 0 0 -b3/m]
 
B = [0 0;
     -r/J r/J;
     0 0;
     1/m 1/m]
 
 C = [B A*B A*A*B A*A*A*B]
 
 