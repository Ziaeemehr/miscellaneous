#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>  
#include<stdlib.h> 

using namespace std;
int N = 10;

//--------------------------------------------------//
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

//--------------------------------------------------//
class Station {

public:
    
    Station();
    Station( vector<Parcel> parcel ){
        
        for(int i=0; i<N; i++){
            dest = parcel[i].get_dest();
            cout<< dest<<endl;
        }
    }
    
    
private:
    string dest;
};

//--------------------------------------------------//

class Train{
public:
    
//     Train(string, string);
//     
//     int add_parcel(Parcel);
//     int get_state();
// 
//     
// private:
//     string destination;
//     string name;
//     int number;
//     vector<Parcel> parcel_vec;
};
//--------------------------------------------------//




//--------------------------------------------------//

int main(int argc, char *argv[]){
    vector<string> dest_list{"B","C","D"};
    
    vector<Parcel> parcel(N);
    
    
    Station station_A(parcel), station_B, station_C,station_D;
//     
//     
//     //Reporting
//     printf("Station B has %d parcel \n" , station_B.get_state();
//     printf("Station C has %d parcel \n" , station_C.get_state();
//     printf("Station D has %d parcel \n" , station_D.get_state();
    
   return 0;   
}