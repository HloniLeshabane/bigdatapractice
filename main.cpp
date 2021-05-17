#include <iostream>
#include <netcdf>
//if you are not getting the inteLlisence for netcdf
//#include </home//home/group15/netcdf/include/netcdf>
#include <omp.h>
#include <mpi/mpi.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include "FiveNumberSum.h"
#include "Day.h"
#include "Bins.h"
#include "MergeSort.h"
#include "OpenDataDaily.h"

using namespace std;
using namespace netCDF;
using namespace netCDF::exceptions;

static const int N_err = -1;
static const string filePath = "/data/full_data_daily_v2020/full_data_daily_v2020_10_2005.nc";
//this values are incorrect;
static const int nRec = 365;
static const int lat = 180;
static const int lon = 360;

void day_split(Day&,float dataIn[180][360]);
void bin_hemisphere(Bins&,Day&);
void print5num(tuple<float,float,float,float,float>);
void fulldatarange(vector<float>&,Bins&,HEMISPHERE);


int main(int argc, char **argv)
{

    float dataIn[lat][lon];
    Bins bins;
    int counter=0;

    MPI_Init(&argc, &argv);
    int rank, prosNum;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &prosNum);


    string first_year = "1985";
    string year_final = "2010";
    string product = "2020";
    int year_start=0,year_end=0;

    vector<float> full_data_set_north;
    vector<float> full_data_set_south;

    MergeSort merger;
    OpenDataDaily opendata;
    stringstream geek(first_year + " " + year_final);

    geek >> year_start;
    geek >> year_end;

    opendata.setDataDailyProduct(product);
    opendata.setYear(first_year);

    if(!opendata.setPath())
    {
        std::cout<<"Could not read in data\n";
        return EXIT_FAILURE;
    }

    Day day;

    for (int year = year_start+rank; year <= year_end ; year+=prosNum)
    {
        std::cout<<"I am rank"<<rank<<"I am Reading year: "<<to_string(year)<<"\n";
        opendata.setYear(to_string(year));
        for(int i=1; i<365; i+=1)
        {
            opendata.fetchDay(i,dataIn);
            day_split(day,dataIn);
        }
    }

    bin_hemisphere(bins,day);

    std::cout<<"Size of bin: "<<bins.sizeofBin()<<"\n";

    auto first = &bins.getBucketVect(HEMISPHERE::SOUTHERN)[5].getPrecipVals()[0];
    auto N = bins.getBucketVect(HEMISPHERE::SOUTHERN)[5].size();
    auto last = first;


    auto first2 = &bins.getBucketVect(HEMISPHERE::NORTHERN)[5].getPrecipVals()[0];
    auto N2 = bins.getBucketVect(HEMISPHERE::NORTHERN)[5].size();
    auto temp = new float[N2];

    //merger.mergeSort(first,N,last);

    #pragma omp parallel
    {
        #pragma omp single
        {
            merger.mergeSort(first2,N2,temp);
        }
    }

    FiveNumberSum fives;
    fulldatarange(full_data_set_north,bins,HEMISPHERE::NORTHERN);

    fives.range(full_data_set_north);
    print5num(fives.summary());

    delete []temp;
    counter++;

    /*if(rank !=0)
    {
        std::cout<<"hello world from other cluster/process"<<endl;
        counter++;
    }*/


    MPI_Finalize();
    return 0;
}

void day_split(Day & day,float dataIn[180][360])
{

    for(int i=0; i<lat; i++)
    {

        for(int j=0; j<lon; j++)
        {
            if(i<90)
            {
                if(dataIn[i][j] != -9999.0f)
                    day.add(dataIn[i][j],HEMISPHERE::NORTHERN);
            }
            else
            {
                if(dataIn[i][j] != -9999.0f)
                    day.add(dataIn[i][j],HEMISPHERE::SOUTHERN);
            }
        }
    }
}

void bin_hemisphere(Bins& bins,Day &day){
    for_each(day.getHemisphereVect(HEMISPHERE::SOUTHERN).begin(),day.getHemisphereVect(HEMISPHERE::SOUTHERN).end(),[&](float precip_val)
    {
        bins.add(precip_val,HEMISPHERE::SOUTHERN);
    });

    for_each(day.getHemisphereVect(HEMISPHERE::NORTHERN).begin(),day.getHemisphereVect(HEMISPHERE::NORTHERN).end(),[&](float precip_val)
    {
        bins.add(precip_val,HEMISPHERE::NORTHERN);
    });
}

void fulldatarange(vector<float>& fullDataSet,Bins& bins,HEMISPHERE hemisphere){
    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        auto begin = bins.getBucketVect(hemisphere)[i].getPrecipVals().begin();
        auto end = bins.getBucketVect(hemisphere)[i].getPrecipVals().end();
        fullDataSet.insert( fullDataSet.end(),begin, end );
    }
}

void print5num(tuple<float,float,float,float,float> summary){
auto [minimum,q1,q2,q3,maximum] = summary;

    std::cout<<"Northern min: "<<minimum<<"\n";
    std::cout<<"Northern Q1 : "<<q1<<"\n";
    std::cout<<"Northern Q2 : "<<q2<<"\n";
    std::cout<<"Northern Q3 : "<<q3<<"\n";
    std::cout<<"Northern max: "<<maximum<<"\n\n";
}
