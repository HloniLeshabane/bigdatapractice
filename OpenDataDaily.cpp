#include "OpenDataDaily.h"

OpenDataDaily::OpenDataDaily()
{
    //ctor
}


void OpenDataDaily::setDataDailyProduct(string product){
    full_data_daily_product = product;
}

void OpenDataDaily::setYear(string year_){
    year = year_;
}

bool OpenDataDaily::setPath(){

    auto [response,path] = getPath();


    return (response!=RESPONSE::SUCCESS)?false:true;
}

tuple<RESPONSE,string> OpenDataDaily::getPath(){


    if(full_data_daily_product == "2020" || full_data_daily_product == "2018"){
        if(full_data_daily_product=="2020"){

            string path_ = "/data/full_data_daily_v2020/full_data_daily_v2020_10_"+year+".nc";
            return {RESPONSE::SUCCESS,path_};
        }
        else if(full_data_daily_product=="2018"){
            string path_ = "/data/full_data_daily_V2018_05/full_data_daily_v2018_05_"+year+".nc";
            return {RESPONSE::SUCCESS,path_};
        }

    }else{
        return {RESPONSE::INVALID_PRODUCT,""};
    }
    return {RESPONSE::INVALID_YEAR,""};
}

bool OpenDataDaily::fetchDay(int day,float dataIn[180][360]){


    try
    {
       auto [response,path] = getPath();

            NcFile myFile(path, NcFile::FileMode::read);
             precipVar = myFile.getVar("precip");
            if(precipVar.isNull()) return false;
             lonVar = myFile.getVar("lon");
            if(lonVar.isNull()) return false;
             latVar = myFile.getVar("lat");
            if(latVar.isNull()) return false;
             timeVar = myFile.getVar("time");
            if(timeVar.isNull()) return false;

        vector<size_t> start, count;

            start.push_back(day);
            start.push_back(0);
            start.push_back(0);

            count.push_back(1);
            count.push_back(lati);
            count.push_back(longi);
            precipVar.getVar(start,count, dataIn);
            return true;
    }
    catch (NcException &e)
    {
            e.what();
            return -1;
    }
    return false;
}
