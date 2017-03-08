#ifndef CAT_H
#define CAT_H



#include <string>
using std::string;

#include "animal.h"

class Cat : public Animal {
public:

	Cat(string name, 
	    double weight);

	string sound() { return "Miaow!"; }
};



#endif



