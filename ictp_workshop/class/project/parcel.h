#ifndef PARCEL_H
#define PARCEL_H
using namespace std;
class Parcel{

    string destination;
    vector<string> labels{"B","C","D"};

public:

    Parcel(){
        destination = labels[rand() % 3];
    }
    string get_dest(){
        return destination;
    }
};

#endif
