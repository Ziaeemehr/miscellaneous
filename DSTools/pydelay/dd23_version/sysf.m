function v = sysf(t,y,Z)
global c1 c2 c3 c4 IP aE aI thetaE thetaI rE rI tauE tauI eta kE kI N

v = zeros(2*N,1);
E = zeros(N,1);
I = zeros(N,1);


Cij = load('./data_txt/strength.txt');
dij = load('./data_txt/dij.txt');

for i = 1:N
   E(i) = y(i);
   I(i) = y(i+N);
end

E_lag = zeros(N,1);
E_lag = Z(:,1);

for i = 1,N
   sum1 = 0.;
   for j = 1:N
      if (i==j)
         continue
      else
%           sum1 = sum1+Cij(i,j)*E_lag(j,(j-1)*N+i)
            sum1 = sum1+Cij(i,j)*E_lag(j,1);
      end
   end
   v(i) = 1./tauE*(-E(i)+(kE-rE*E(i))*SE(c1*E(i)-c2*I(i)+IP+eta/N*sum1));  %dE/dt
   v(i+N) = 1./tauI*(-I(i)+(kI-rI*I(i))*SI(c3*E(i)-c4*I(i)));                      %dI/dt
end


%--------------------------------------------------------------------------

function s = SE(x)
global aE thetaE
s = 1./(1+ exp(-aE*(x-thetaE)))-1./(1.+exp(aE*thetaE));

function s = SI(x)
global aI thetaI
s = 1./(1+ exp(-aI*(x-thetaI)))-1./(1.+exp(aI*thetaI));






