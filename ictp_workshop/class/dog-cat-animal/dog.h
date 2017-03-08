#ifndef DOG_H
#define DOG_H

#include <string>
using std::string;

#include "animal.h"

class Dog : public Animal {
public:

	Dog(string name, 
	    double weight);

	string sound() { return "Woof!"; }
};


#endif


