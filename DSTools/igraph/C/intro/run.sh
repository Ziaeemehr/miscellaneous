# gcc 01_test.c -I/usr/local/igraph -L/usr/local/lib -ligraph -o 01_test
export CPATH=/usr/local/include/igraph

g++ 01_test.c -I /usr/local/include/igraph -ligraph -o 01_test
