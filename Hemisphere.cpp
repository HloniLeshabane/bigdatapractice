#include "Hemisphere.h"
#include <numeric>
Hemisphere::Hemisphere(HEMISPHERE hemisphere)
{
    //ctor
    this->hemisphere = hemisphere;
}

Hemisphere::Hemisphere()
{
    //ctor
}

void Hemisphere::add(float precip){
    precip_vals.push_back(precip);
}

float Hemisphere::getAverage(){
    avg = std::accumulate(precip_vals.begin(), precip_vals.end(), 0.0) / precip_vals.size();
    return avg;
}

vector<float> & Hemisphere::getVect(){
    return precip_vals;
}
