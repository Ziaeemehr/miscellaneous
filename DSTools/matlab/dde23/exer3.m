% Wheldon's model of chronic granuloctic leukemia from N. MacDonald, 
% Time Lags in Biological Models, Springer-Verlag, Berlin, 1978.

alpha = 1.1e10;
beta = 1e-12;
gamma = 1.25;
delta = 1;
lambda = 10;
mu = 4e-8;
omega = 2.43; 

for tau = [7, 20]
   sol = dde23('exer3f',tau,[100; 100],[0, 200],[],...
               alpha,beta,gamma,delta,lambda,mu,omega);
   figure
   plot(sol.x,sol.y)
   title(['Leukemia model for \tau = ',num2str(tau),'.'])
   xlabel('time t')
   ylabel('y(t)')
end