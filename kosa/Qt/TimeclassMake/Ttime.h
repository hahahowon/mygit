#ifndef _TIME_
#define _TIME_
#include <string>
#define HOUR_SEC       3600
#define MIN_SEC        60
using namespace std;

class Time
{
private:
    int hour, min, sec;
    int t_sec;


public:
    Time();
    Time(const int hour, const int min, const int t_sec);
    void SetHour(const int hour);
    void SetMin(const int min);
    void SetSec(const int sec);
    int GetHour();
    int GetMin();
    int GetSec();
    int CalSec();
    string ShowTime();

    bool operator<=(Time timeObj);
    bool operator>=(Time timeObj);
};


#endif // TIME
