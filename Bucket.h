#ifndef BUCKET_H
#define BUCKET_H
#include <vector>
#include "Hemisphere.h"
using namespace std;

class Bucket
{
    public:
        Bucket();
        void setUpperBound(float);
        void setLowerBound(float);
        void setHemisphere(HEMISPHERE);
        void add(float);
        void add(vector<float>&);
        float getAverage();
        size_t size();
        vector<float> & getPrecipVals();

    protected:

    private:
        float avg;
        float lower_bound;
        float upper_bound;
        vector<float> vals;
        HEMISPHERE hemisphere;
};

#endif // BUCKET_H
