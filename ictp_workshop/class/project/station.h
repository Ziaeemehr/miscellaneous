#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>

class Station {

public:
    
    Station( vector<Class::Parcel> parcel ){
        
        for(int i=0; i<N; i++){
            dest = parcel[i].destination;
        }
    }
    
    
private:
    string dest;
};

#endif