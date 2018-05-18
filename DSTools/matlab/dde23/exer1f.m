function v = exer1f(t,y,Z)
% ylag1 = Z(:,1);
% ylag2 = Z(:,2);
v = zeros(5,1);

% v(1) = ylag1(5) + ylag1(3);
% v(2) = ylag1(1) + ylag2(2);
% v(3) = ylag1(3) + ylag2(1);
% v(4) = ylag1(5) * ylag1(4);
% v(5) = ylag1(1);


 v(1) = Z(5,1) + Z(3,1);
 v(2) = Z(1,1) + Z(2,2);
 v(3) = Z(3,1) + Z(1,2);
 v(4) = Z(5,1) * Z(4,1);
 v(5) = Z(1,1);
