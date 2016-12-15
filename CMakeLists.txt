
project(CruiseControl)
cmake_minimum_required (VERSION 2.6)

#set the version
set (CruiseControl_VERSION_MAJOR 0)
set (CruiseControl_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/CruiseControlConfig.h.in"
    "${PROJECT_BINARY_DIR}/CruiseControlConfig.h"
    )
    
# add the binary tree to the search path for include files
# so that we will find CruiseControl.h
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_BINARY_DIR}/src")

add_executable(CruiseControl
               src/CruiseControl.cpp
               src/CruiseControlAccState.cpp
               src/CruiseControlActiveState.cpp
               src/CruiseControlOffState.cpp
               src/CruiseControlReadyState.cpp
               src/CruiseControlSetState.cpp
               src/CruiseControlState.cpp
               src/CruiseControlWaitState.cpp
               src/Vehicle.cpp
               test/CruiseControl_test.cpp)