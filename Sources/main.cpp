#include <iostream>
#include "Tuto0Config.h"

//#ifdef USE_MYMATH
//#include "MathFunctions.h"
//#else
//#include <math.h>
//#endif


int main()
{
    std::cout << "hello world " << TUTO0_VERSION_MAJOR << "." << TUTO0_VERSION_MINOR << std::endl;
//    std::cout << "SQRT Out : " << sqrt(3) << std::endl;
    return 0;
}