import numpy as np
import matplotlib.pyplot as plt
import time as tm

plt.close()

def func(r,x):
  return r-x*x

def xnext(r,x0,N):
  n = 0
  X = np.zeros(r.size*N)
  A = np.zeros(r.size*N)

  for r_value in r:
    xinit = x0
    #transient
    for i in range(N):
      xinit = func(r_value,xinit)
    X[n] = xinit
    A[n] = r_value
    n += 1

    for j in range(1,N):
      X[n] = func(r_value,X[n-1])
      A[n]= r_value
      n += 1
  return A, X


x0 = 0.4
Num = 200
r_min = 0
r_max = 5
total_of_r = 500
r = np.linspace(r_min,r_max,total_of_r)

tic = tm.time()
A, X = xnext(r,x0,Num)
toc = tm.time()
print('elapsed time: %.4f seconds' % (toc-tic))

fig, ax = plt.subplots(figsize=(12,8))
ax.plot(A,X,".",markersize=1, color="green")
ax.set_xlim(r_min,r_max)
#ax.set_ylim(0,1)
ax.set_title(r'Bifurcation plot of function: $Y_{next} = r-Y_{prior}^2$')
ax.set_xlabel('r-value in equation')
ax.set_ylabel(r'$Y[r,Y_{prior}]$')
#ax.set_ax*.4is_off()
plt.gca().set_aspect('equal', adjustable='box')
plt.show()
# plt.savefig('Bifur_plot.png')
