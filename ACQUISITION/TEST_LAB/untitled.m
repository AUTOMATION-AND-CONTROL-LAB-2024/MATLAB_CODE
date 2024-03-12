syms s z Ts
p = 75;
F = p/(s+p);
c = 1/Ts*(z-1)/(z+1);
Fz = subs(F,s,c);
Fz = subs(Fz,Ts,0.01);
simplify(Fz)