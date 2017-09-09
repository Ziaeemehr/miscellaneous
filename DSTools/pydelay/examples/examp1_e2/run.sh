
g++ -lm -o prog1 1.cpp
./prog1 > result1.txt
echo "plot 'result1.txt' u 1:2 w l title'y1' ,'' u 1:3 w l title'y3','' u 1:4 w l title'y2' " |gnuplot -persist
g++ -lm -o prog2 2.cpp
./prog2 > result2.txt
echo "plot 'result2.txt' u 1:2 w l title'y1' ,'' u 1:3 w l title'y3','' u 1:4 w l title'y2' " |gnuplot -persist

vimdiff result1.txt result2.txt

