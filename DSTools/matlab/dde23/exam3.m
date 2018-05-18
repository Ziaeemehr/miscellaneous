% Example 4.2 of H.J. Oberle and H.J. Pesch, Numerical treatment of 
% delay differential equations by Hermite interpolation, Numer. Math.,
% 37 (1981) 235-255.  This problem is solved for four values of a
% parameter lambda.  Oberle and Pesch point out that the problem is
% numerically more sensitive for the larger values of lambda, so they
% are solved with more stringent tolerances.

%  sol = dde23(ddefile,lags,history,tspan,options);

sol1 = dde23('exam3f',1,'exam3h',[0, 20],[],1.5);

sol2 = dde23('exam3f',1,'exam3h',[0, 20],[],2);

opts = ddeset('RelTol',1e-5,'AbsTol',1e-8);
sol3 = dde23('exam3f',1,'exam3h',[0, 20],opts,2.5);

opts = ddeset('RelTol',1e-6,'AbsTol',1e-10);
sol4 = dde23('exam3f',1,'exam3h',[0, 20],opts,3);

plot(sol1.x,sol1.y,sol2.x,sol2.y,...
     sol3.x,sol3.y,sol4.x,sol4.y);
legend('\lambda = 1.5','\lambda = 2.0',...
       '\lambda = 2.5','\lambda = 3.0')
title('Figure 3. Example 4.2 of Oberle and Pesch.')
