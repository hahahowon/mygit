#include "Ttime.h"
bool Time::operator<=(Time timeObj)
{
    this->CalSec();
    timeObj.CalSec();

    if(this->t_sec<=timeObj.t_sec)
        return true;
    else
        return false;
}
bool Time::operator>=(Time timeObj)
{
    this->CalSec();
    timeObj.CalSec();

    if(this->t_sec>=timeObj.t_sec)
        return true;
    else
        return false;
}
