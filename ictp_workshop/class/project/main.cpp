#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>  
#include<stdlib.h> 

using namespace std;
int N = 10000;

//--------------------------------------------------//
class Manager{
public:
    Manager(string parcel_name, string train_list){
        bool check(string name, string dest,string train_list ){
            return True or False;
        }
        
    }
private:
    
};

//--------------------------------------------------//

int main(int argc, char *argv[]){
    vector<string> dest_list{"B","C","D"};
    
    vector<Parcel> parcel(N);
    
    
    Station station_A(parcel), station_B, station_C,station_D;
    
    
    //Reporting
    printf("Station B has %d parcel \n" , station_B.get_state();
    printf("Station C has %d parcel \n" , station_C.get_state();
    printf("Station D has %d parcel \n" , station_D.get_state();
    
   return 0;   
}