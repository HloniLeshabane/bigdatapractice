#ifndef FIVENUMBERSUM_H
#define FIVENUMBERSUM_H
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>
#include <tuple>

using namespace std;

class FiveNumberSum
{
    public:
        FiveNumberSum();
        void range(vector<float>&);
        tuple<float,float,float,float,float> summary();

    protected:

    private:
    vector<float> v;
    vector<float>::iterator start_;
    vector<float>::iterator end_;

};

#endif // FIVENUMBERSUM_H
