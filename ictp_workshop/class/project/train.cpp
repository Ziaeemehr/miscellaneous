#include "train.h"


Train::Train(string na, string dest):name{na},destination {dest}{}

int Train::add_parcel(Parcel p) {
    parcel_vec.push_back(p);
}

int Train::get_state() {
    return parcel_vec.size(); 
}