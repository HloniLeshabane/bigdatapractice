#include "Bucket.h"
#include <numeric>
#include <iostream>


Bucket::Bucket()
{
    //ctor
}

size_t Bucket::size(){
    return vals.size();
}

void print(vector<float> &v)
{
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

void Bucket::add(float precip_val){
    vals.push_back(precip_val);
}

void Bucket::add(vector<float>& precip_vals){
    vals.insert( vals.end(), precip_vals.begin(), precip_vals.end() );
}


vector<float> & Bucket::getPrecipVals(){
    return vals;
}

void Bucket::setUpperBound(float upper_bound_){
    upper_bound = upper_bound_;
}


void Bucket::setLowerBound(float lower_bound_){
    lower_bound = lower_bound_;
}


float Bucket::getAverage(){
    avg = std::accumulate(vals.begin(), vals.end(), 0.0) / vals.size();
    return avg;
}


void Bucket::setHemisphere(HEMISPHERE hemisphere){
    this->hemisphere = hemisphere;
}
