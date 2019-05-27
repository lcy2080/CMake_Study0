#Require version
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

#Project Setup
PROJECT(Tuto0 CXX)

SET(TUTO0_VERSION_MAJOR 0)
SET(TUTO0_VERSION_MINOR 1)

#configure a header file to pass some of the Cmake Settings to the Source code.
CONFIGURE_FILE(
    "${PROJECT_BINARY_DIR}/Tuto0Config.h.in"
    "${PROJECT_BINARY_DIR}/Tuto0Config.h"
)

#add the binary tree to the search path for include files
#so that we will find Tuto0Config.h
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

#EXECUTABLE TARGET
ADD_EXECUTABLE(../Tuto0.out ../main.cpp)