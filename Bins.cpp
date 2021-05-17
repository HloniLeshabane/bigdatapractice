#include "Bins.h"

Bins::Bins()
{
    //ctor
    auto bucket =Bucket();
    bucket.setHemisphere(HEMISPHERE::NORTHERN);
    northern_buckets.push_back(bucket);
    northern_buckets.push_back(bucket);
    northern_buckets.push_back(bucket);
    northern_buckets.push_back(bucket);
    northern_buckets.push_back(bucket);
    northern_buckets.push_back(bucket);
    northern_buckets.push_back(bucket);
    northern_buckets.push_back(bucket);
    northern_buckets.push_back(bucket);
    northern_buckets.push_back(bucket);

    auto bucket2 =Bucket();
    bucket2.setHemisphere(HEMISPHERE::SOUTHERN);
    southern_buckets.push_back(bucket2);
    southern_buckets.push_back(bucket2);
    southern_buckets.push_back(bucket2);
    southern_buckets.push_back(bucket2);
    southern_buckets.push_back(bucket2);
    southern_buckets.push_back(bucket2);
    southern_buckets.push_back(bucket2);
    southern_buckets.push_back(bucket2);
    southern_buckets.push_back(bucket2);
    southern_buckets.push_back(bucket2);

    southern_buckets[0].setLowerBound(0.f);
    southern_buckets[0].setUpperBound(0.02f);
    northern_buckets[0].setLowerBound(0.f);
    northern_buckets[0].setUpperBound(0.02f);

    southern_buckets[1].setLowerBound(0.02f);
    southern_buckets[1].setUpperBound(0.05f);
    northern_buckets[1].setLowerBound(0.02f);
    northern_buckets[1].setUpperBound(0.05f);

    southern_buckets[2].setLowerBound(0.05f);
    southern_buckets[2].setUpperBound(0.09f);
    northern_buckets[2].setLowerBound(0.05f);
    northern_buckets[2].setUpperBound(0.09f);

    southern_buckets[3].setLowerBound(0.09f);
    southern_buckets[3].setUpperBound(0.15f);
    northern_buckets[3].setLowerBound(0.09f);
    northern_buckets[3].setUpperBound(0.15f);

    southern_buckets[4].setLowerBound(0.15f);
    southern_buckets[4].setUpperBound(0.5f);
    northern_buckets[4].setLowerBound(0.15f);
    northern_buckets[4].setUpperBound(0.5f);

    southern_buckets[5].setLowerBound(0.5f);
    southern_buckets[5].setUpperBound(1.f);
    northern_buckets[5].setLowerBound(0.5f);
    northern_buckets[5].setUpperBound(1.f);

    southern_buckets[6].setLowerBound(1.f);
    southern_buckets[6].setUpperBound(5.f);
    northern_buckets[6].setLowerBound(1.f);
    northern_buckets[6].setUpperBound(5.f);

    southern_buckets[7].setLowerBound(5.f);
    southern_buckets[7].setUpperBound(10.f);
    northern_buckets[7].setLowerBound(5.f);
    northern_buckets[7].setUpperBound(10.f);

    southern_buckets[8].setLowerBound(10.f);
    southern_buckets[8].setUpperBound(20.f);
    northern_buckets[8].setLowerBound(10.f);
    northern_buckets[8].setUpperBound(20.f);

    southern_buckets[9].setLowerBound(20.f);
    southern_buckets[9].setUpperBound(40.f);
    northern_buckets[9].setLowerBound(20.f);
    northern_buckets[9].setUpperBound(40.f);


}


void Bins::add(float precip_val,HEMISPHERE hemisphere)
{
    if (precip_val < 0.02)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[0].add(precip_val);
        }
        else
        {
            northern_buckets[0].add(precip_val);
        }

    }
    else if (precip_val < 0.05)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[1].add(precip_val);
        }
        else
        {
            northern_buckets[1].add(precip_val);
        }
    }
    else if (precip_val < 0.09)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[2].add(precip_val);
        }
        else
        {
            northern_buckets[2].add(precip_val);
        }
    }
    else if (precip_val < 0.15)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[3].add(precip_val);
        }
        else
        {
            northern_buckets[3].add(precip_val);
        }
    }
    else if (precip_val < 0.5)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[4].add(precip_val);
        }
        else
        {

            northern_buckets[4].add(precip_val);
        }
    }
    else if (precip_val < 1)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[5].add(precip_val);
        }
        else
        {
            northern_buckets[5].add(precip_val);
        }
    }
    else if (precip_val < 5)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[6].add(precip_val);
        }
        else
        {
            northern_buckets[6].add(precip_val);
        }
    }
    else if (precip_val < 10)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[7].add(precip_val);
        }
        else
        {
            northern_buckets[7].add(precip_val);
        }
    }
    else if (precip_val < 20)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[8].add(precip_val);
        }
        else
        {
            northern_buckets[8].add(precip_val);
        }
    }
    else if (precip_val >= 20)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[9].add(precip_val);
        }
        else
        {
            northern_buckets[9].add(precip_val);
        }
    }

}

vector<Bucket> & Bins::getBucketVect(HEMISPHERE hemisphere){
    return (hemisphere==HEMISPHERE::SOUTHERN)?southern_buckets:northern_buckets;
}


void Bins::add(vector<float>& precip_vals,HEMISPHERE hemisphere){
    auto precip_val = precip_vals[0];

     if (precip_val < 0.02)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[0].add(precip_vals);
        }
        else
        {
            northern_buckets[0].add(precip_vals);
        }

    }
    else if (precip_val < 0.05)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[1].add(precip_vals);
        }
        else
        {
            northern_buckets[1].add(precip_vals);
        }
    }
    else if (precip_val < 0.09)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[2].add(precip_vals);
        }
        else
        {
            northern_buckets[2].add(precip_vals);
        }
    }
    else if (precip_val < 0.15)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[3].add(precip_vals);
        }
        else
        {
            northern_buckets[3].add(precip_vals);
        }
    }
    else if (precip_val < 0.5)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[4].add(precip_vals);
        }
        else
        {

            northern_buckets[4].add(precip_vals);
        }
    }
    else if (precip_val < 1)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[5].add(precip_vals);
        }
        else
        {
            northern_buckets[5].add(precip_vals);
        }
    }
    else if (precip_val < 5)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[6].add(precip_vals);
        }
        else
        {
            northern_buckets[6].add(precip_vals);
        }
    }
    else if (precip_val < 10)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[7].add(precip_vals);
        }
        else
        {
            northern_buckets[7].add(precip_vals);
        }
    }
    else if (precip_val < 20)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[8].add(precip_vals);
        }
        else
        {
            northern_buckets[8].add(precip_vals);
        }
    }
    else if (precip_val >= 20)
    {
        if(hemisphere == HEMISPHERE::SOUTHERN)
        {
            southern_buckets[9].add(precip_vals);
        }
        else
        {
            northern_buckets[9].add(precip_vals);
        }
    }
}

long int Bins::sizeofBin(){
    long int bin_size=0;
    for(int i=0;i<northern_buckets.size();i++){
        bin_size += northern_buckets[i].size();
    }

    for(int i=0;i<southern_buckets.size();i++){
        bin_size += southern_buckets[i].size();
    }

    return bin_size;
}
