function v = sysf(t,y,Z)
global c1 c2 c3 c4 IP aE aI thetaE thetaI rE rI tauE tauI eta kE kI a1

v=zeros(4,1);

E1 = y(1);
E2 = y(2);
I1 = y(3);
I2 = y(4);
E1_lag = Z(1,1);
E2_lag = Z(2,1);

v(1) = 1./tauE*(-E1+(kE-rE*E1)*SE(c1*E1-c2*I1+IP+eta*(a1*E2_lag)));  %dE1/dt
v(2) = 1./tauE*(-E2+(kE-rE*E2)*SE(c1*E2-c2*I2+IP+eta*(a1*E1_lag)));  %dE2/dt
v(3) = 1./tauI*(-I1+(kI-rI*I1)*SI(c3*E1-c4*I1));                     %dI1/dt
v(4) = 1./tauI*(-I2+(kI-rI*I2)*SI(c3*E2-c4*I2));                     %dI2/dt

%--------------------------------------------------------------------------

function s = SE(x)
global aE thetaE
s = 1./(1+ exp(-aE*(x-thetaE)))-1./(1.+exp(aE*thetaE));

function s = SI(x)
global aI thetaI
s = 1./(1+ exp(-aI*(x-thetaI)))-1./(1.+exp(aI*thetaI));






