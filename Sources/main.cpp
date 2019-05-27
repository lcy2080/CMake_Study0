#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Tuto0Config.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#else
#include <math.h>
#endif


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stdout, "%s Version %d.%d\n", argv[0]
                , TUTO0_VERSION_MAJOR
                , TUTO0_VERSION_MINOR);
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }

    float InputValue = atof(argv[1]);
#ifdef USE_MYMATH
    float OutputValue = mysqrt(InputValue);
    //std::cout << "SQRT Out : " << mysqrt(InputValue) << std::endl;
#else
    float OutputValue = sqrt(InputValue);
    //std::cout << "SQRT Out : " << sqrt(InputValue) << std::endl;
#endif

    fprintf(stdout, "%g is %g", InputValue, OutputValue);

    return 0;
}