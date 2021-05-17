#ifndef BINS_H
#define BINS_H
#include <vector>
#include "Bucket.h"
using namespace std;

class Bins
{
    public:
        Bins();
        void add(float,HEMISPHERE);
        void add(vector<float>&,HEMISPHERE);
        vector<Bucket> & getBucketVect(HEMISPHERE);
        long int sizeofBin();

    protected:

    private:
        vector<Bucket> northern_buckets;
        vector<Bucket> southern_buckets;
};

#endif // BINS_H
