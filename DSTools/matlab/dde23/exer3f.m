function v = exer3f(t,y,Z,alpha,beta,gamma,delta,lambda,mu,omega)
ylag = Z(:,1);
v = zeros(2,1);

v(1) = alpha/(1 + beta*ylag(1)^gamma) - lambda*y(1)/(1 + mu*y(2)^delta);
% v(1) = alpha/(1 + beta*Z(1,1)^gamma) - lambda*y(1)/(1 + mu*y(2)^delta);
v(2) = lambda*y(1)/(1 + mu*y(2)^delta) - omega*y(2);
