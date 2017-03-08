#include <iostream>

#include "dog.h"
#include "cat.h"


using std::cout;
using std::endl;

void prettyprint(Animal & a) {
	cout << a.name() 
	     << " sounds like this: "
	     << a.sound() << endl;
}

int main() {
	Dog d1("Fido",30.0);

	Cat c1("Tom",8.0);

	//Animal a1("Monster", 13413414.0);

	prettyprint(c1);

	prettyprint(d1);

	//prettyprint(a1);

	return 0;
}











