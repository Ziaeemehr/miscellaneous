global c1 c2 c3 c4 IP aE aI thetaE thetaI rE rI tauE tauI eta kE kI a1
par = [16.0,            % c1        1
       12.0,            % c2        2
       15.0,            % c3        3
       3.0,             % c4        4
       1.7,             % IP        5
       0.0,             % IQ        6
       1.3,             % aE        7
       2.0,             % aI        8
       4.0,             % thetaE    9
       3.7,             % thetaI    10
       1.0,             % rE        11
       1.0,             % rI        12
       8.0,             % tauE      13
       8.0,             % tauI      14
       1.0,             % eta       15
       1.0              % a1        16
       ]';

c1 = par(1);
c2 = par(2);
c3 = par(3);
c4 = par(4);
IP = par(5);
IQ = par(6);
aE = par(7);
aI = par(8);
thetaE = par(9);
thetaI = par(10);
rE = par(11);
rI = par(12);
tauE = par(13);
tauI = par(14);
eta  = par(15);
a1 = par(16);
kE = 1.-1./(1.+exp(par(7)*par(9)));
kI = 1.-1./(1.+exp(par(8)*par(10)));

sol = dde23('sysf',10,'sysh',[0, 2000]);

plot(sol.x,sol.y);
xlabel('time(ms)');
ylabel('Activity E and I');



