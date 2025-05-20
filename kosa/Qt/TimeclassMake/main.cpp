#include <iostream>
#include "Ttime.h"


int main(void)
{
    Time t1(7, 30, 20);
    cout<<t1.ShowTime()<<endl;
    cout<<"시간 - 초단위: "<<t1.CalSec()<<endl;

    Time t2(4, 50, 23);
    if(t1>=t2){
        cout<<t1.ShowTime()<<">="<<t2.ShowTime()<<endl;
        cout<<endl;
    }else{
        cout<<t2.ShowTime()<<">="<<t1.ShowTime()<<endl;
        cout<<endl;
    }

    if (t1<=t2){
        cout<<t1.ShowTime()<<">="<<t2.ShowTime()<<endl;
        cout<<endl;
    }else{
        cout<<t2.ShowTime()<<">="<<t1.ShowTime()<<endl;
        cout<<endl;
    }
    return 0;

}
