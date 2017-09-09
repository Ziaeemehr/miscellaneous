function v = exam1f(t,y,Z)
ylag1 = Z(:,1);
ylag2 = Z(:,2);
v = zeros(3,1);

v(1) = ylag1(1);
v(2) = ylag1(1) + ylag2(2);
v(3) = y(2);



%  y1(t) = y1(t-1)
%  y2(t) = y1(t-1) + y2(t-0.2)
%  y3(t) = y2(t)