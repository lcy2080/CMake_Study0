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

option (USE_MYMATH "Use tutorial provided math implementation" OFF)

if (USE_MYMATH)
    INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

#does this system provide the log and exp functions?
INCLUDE(CheckFunctionExists)
CHECK_FUNCTION_EXISTS(log HAVE_LOG)
check_function_exists(exp HAVE_EXP)

#EXECUTABLE TARGET
ADD_EXECUTABLE(Tuto0.out main.cpp)
target_link_libraries(${EXTRA_LIBS})

#add the install targets
install(TARGETS Tuto0.out
        DESTINATION bin)
install(FILES ${PROJECT_BINARY_DIR}/Tuto0Config.h
        DESTINATION include)

include(CTest)

#does the application run
add_test(TutorialRuns Tuto0.out 25)
#does it sqrt of 25
add_test(TutorialComp25 Tuto0.out 25)
set_tests_properties(TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
#does it handle negative numbers
add_test(TutorialNegative Tuto0.out -25)
set_tests_properties(TutorialNegative PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0")
#dost it handle small numbers
add_test(TutorialSmall Tuto0.out 0.0001)
set_tests_properties(TutorialSmall PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01")
#does the usage message work?
add_test(TutorialUsage Tuto0.out)
set_tests_properties(TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* number")


