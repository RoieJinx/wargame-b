#pragma once
#include <cmath>

template <typename T,typename U>
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {
    return {l.first+r.first,l.second+r.second};
}
typedef std::pair<int, int> Position;

typedef unsigned int uint;
/*namespace warGameUtil
{
    double distance(std::pair<int,int> mySoldier , int x , int y)
    {
        double d = pow(mySoldier.first-x,2) + pow(mySoldier.second-y,2);
        d = sqrt(d);
        return d;
    }
}*/
