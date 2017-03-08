.PHONY : clean

CXX = g++

testprog : animal.o cat.o dog.o main.o
	$(CXX) $^ -o $@

clean : 
	rm -f *.o testprog


