#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>
#include "parcel.h"
using namespace std;

class Station {

public:

    Station();
    Station( vector<class::Parcel> parcel ){

        for(int i=0; i<parcel.size(); i++){
            dest = parcel[i].get_dest();
            cout << dest<< endl;
        }
    }

private:
    string dest;
};

#endif
