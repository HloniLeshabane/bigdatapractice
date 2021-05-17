#ifndef DAY_H
#define DAY_H
#include <vector>
#include "Hemisphere.h"


using namespace std;

class Day
{
    public:
        Day();
        void setDayofYear(int);
        void add(float,HEMISPHERE);
        float getAvg(HEMISPHERE);
        vector<float> & getHemisphereVect(HEMISPHERE);

    protected:

    private:
        int day;
        Hemisphere south;
        Hemisphere north;
};

#endif // DAY_H
