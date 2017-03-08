echo "-O0"
gfortran -O0 array.f90 
time ./a.out
g++ -std=c++11 -O0 main.cpp 
./a.out
rm a.out


echo "-O1"
gfortran -O1 array.f90 
time ./a.out
g++ -std=c++11 -O1 main.cpp 
./a.out
rm a.out

echo "-O2"
gfortran -O2 array.f90 
time ./a.out
g++ -std=c++11 -O2 main.cpp 
./a.out
rm a.out

echo "-O3"
gfortran -O3 array.f90 
time ./a.out
g++ -std=c++11 -O3 main.cpp 
./a.out
rm a.out





#TIMEING             -O0       -O1     -O2       -O3
#========================================================
#F90                 12.5s     3.8      3.8      3.8
#C++ NEW [i][j]      11.1      3.8      3.8      3.8
#C++ NEW [i*n+j]     13.1      3.8      3.9      3.8
#C++ VECTOR[i][j]    27.5      3.8      3.8      3.8
#C++ VECTOR[i*n+j]   15.9      3.7      3.7      3.7












#TIME	         |   20-times    |  500-times
#=======================================================
#F90             |   17.915s     |  7m32       col-wise
#C++ NEW         |   20.4747     |  8m32       row-wise
#C++ VECTOR      |   41.1594     |  17m26      row-wise
