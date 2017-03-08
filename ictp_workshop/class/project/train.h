#ifndef TRAIN_H
#define TRAIN_H

#include<string>
using std::string

class Train{
public:
    
    Train(string, string);
    
    int add_parcel(Parcel);
    int get_state();

    
private:
    string destination;
    string name;
    int number;
    vector<Parcel> parcel_vec;
};
#endif     