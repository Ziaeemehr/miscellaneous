#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using std::string;

class Animal {
public:

	Animal(string name, 
	       double weight);

	string name() { return name_; }

	double weight() { return weight_; }

	virtual string sound() = 0;

private:

	string name_;

	double weight_;

};

#endif
