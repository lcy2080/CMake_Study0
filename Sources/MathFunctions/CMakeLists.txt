cmake_minimum_required(VERSION 3.0)

add_library(MathFunctions mysqrt.cpp)

#add the install targets
install(TARGETS MathFunctions
        DESTINATION bin)
install(FILES MathFunctions.h
        DESTINATION include)