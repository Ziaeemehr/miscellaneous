echo no optimization ========================================
gcc -o exec_matmul.x  matmul_exercise.c -lblas
./exec_matmul.x
echo -O0         ============================================
gcc -O0 -o exec_matmul.x  matmul_exercise.c -lblas
./exec_matmul.x
echo -O1         ============================================
gcc -O1 -o exec_matmul.x  matmul_exercise.c -lblas
./exec_matmul.x
echo -O2         ============================================
gcc -O2 -o exec_matmul.x  matmul_exercise.c -lblas
./exec_matmul.x
echo -O3         ============================================
gcc -O3 -o exec_matmul.x  matmul_exercise.c -lblas
./exec_matmul.x
echo -mavx       ============================================
gcc -O3 -mavx -o exec_matmul.x  matmul_exercise.c -lblas
./exec_matmul.x
echo -icc mkl     ============================================
icc -o exec_matmul.x matmul_exercise.c -mkl
./exec_matmul.x
