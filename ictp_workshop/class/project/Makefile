.PHONY : clean

CXX = g++

prog : parcel.o station.o main.o
	$(CXX) $^ -o $@

clean :
	rm -f *.o prog
