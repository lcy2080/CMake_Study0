#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Tuto0Config.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif
#include <cmath>


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
#if defined(HAVE_LOG) && defined (HAVE_LOG)
    float OutputValue = exp(log(InputValue) * 0.5);
    fprintf(stdout, "exp log\n");
#elif defined(USE_MYMATH)
    float OutputValue = mysqrt(InputValue);
    //std::cout << "SQRT Out : " << mysqrt(InputValue) << std::endl;
#else
    float OutputValue = sqrt(InputValue);
    //std::cout << "SQRT Out : " << sqrt(InputValue) << std::endl;
#endif

    fprintf(stdout, "%g is %g", InputValue, OutputValue);

    return 0;
}