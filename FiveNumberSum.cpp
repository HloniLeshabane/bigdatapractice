#include "FiveNumberSum.h"

FiveNumberSum::FiveNumberSum()
{
    //ctor
}

void FiveNumberSum::range(vector<float>&v){
    this->v = v;
    start_ = v.begin();
    end_ = v.end();

}

tuple<float,float,float,float,float> FiveNumberSum::summary(){

    float min,q1,q2,q3,max;

auto median = [&](vector<float>::iterator start, vector<float>::iterator end)  {

        if((end-start) % 2 == 0) {
            auto n = (end - start) / 2;
            auto n_before = n - 1 + (start-v.begin());
            auto n_after = n + (start-v.begin());

            return (v[n_before] + v[n_after]) / 2.0f;
        } else {

            auto n = float(end-start) / 2.f;
            return v[floor(n)];
        }
    };

    std::sort(v.begin(), v.end());
    min = v[0];
    max = *(v.end()-1);

    if((end_-start_) % 2 == 0){
        q1 = median(v.begin(),v.begin() + v.size()/2  ); //q1 for even
        q3 = median(v.begin() + v.size()/2 ,v.end()); //q3 for even
    }
    else{
        q3 = median(v.begin() + v.size()/2 + 1,v.end()); //q3 for odd
        q1 = median(v.begin(),v.begin() + v.size()/2 ); //q1 for odd
    }
    q2 = median(v.begin(),v.end()); //q2

    return { min,q1,q2,q3,max };

}
