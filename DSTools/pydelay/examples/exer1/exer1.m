% Example 1 of K.W. Neves, Automatic integration of functional
% differential equations: an approach, ACM TOMS, 1 (1975) 357-368.

sol = dde23('exer1f',[1, 0.5],'exer1h',[0, 1]);

plot(sol.x,sol.y); %y is a 5 x N array

title('Exercise 1.  Example 1 of Neves.')
xlabel('time t');
ylabel('y(t)');
