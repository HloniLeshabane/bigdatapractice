#include "Day.h"

Day::Day()
{
    //ctor
    north = HEMISPHERE::NORTHERN;
    south = HEMISPHERE::SOUTHERN;
}

void Day::setDayofYear(int day_){
    day = day_;
}

float Day::getAvg(HEMISPHERE hemisphere){
    if(hemisphere ==HEMISPHERE::NORTHERN)
    return north.getAverage();
    else
    return south.getAverage();
}


void Day::add(float precip_val,HEMISPHERE hemisphere){

    if(hemisphere == HEMISPHERE::NORTHERN){
        north.add(precip_val);
    }
    else{
        south.add(precip_val);
    }
}

vector<float> & Day::getHemisphereVect(HEMISPHERE hemisphere){
    return (hemisphere==HEMISPHERE::SOUTHERN)? south.getVect(): north.getVect();
}
