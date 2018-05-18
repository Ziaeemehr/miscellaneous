% This is example 3 of D.R. Wille' and C.T.H. Baker, DELSOL--a numerical 
% code for the solution of systems of delay-differential equations, Appl.
% Numer. Math., 9 (992) 223-234. 

sol = dde23('exam1f',[1, 0.2],ones(3,1),[0, 5]);

plot(sol.x,sol.y);
title('Figure 1. Example 3 of Wille'' and Baker.')
xlabel('time t');
ylabel('y(t)');
