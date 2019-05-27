
#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <cmath>

float mysqrt(float input)
{
    double value = input;
    if (value <= 0)
    {
        return 0;
    }
    return sqrt(value);
}

#endif //MATHFUNCTIONS_H