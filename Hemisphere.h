#ifndef HEMISPHERE_H
#define HEMISPHERE_H
#include <vector>

using namespace std;

enum class HEMISPHERE{ NORTHERN, SOUTHERN};

class Hemisphere
{
    public:
        Hemisphere();
        Hemisphere(HEMISPHERE);
        void add(float);
        float getAverage();
        vector<float> & getVect();

    protected:

    private:
        HEMISPHERE hemisphere;
        float avg;
        vector<float> precip_vals;
};

#endif // HEMISPHERE_H
