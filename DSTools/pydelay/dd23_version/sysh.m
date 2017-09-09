function v = sysh(t)
global N
v=zeros(2*N,1);
for i=1:2*N
    v(i) = rand();
end
