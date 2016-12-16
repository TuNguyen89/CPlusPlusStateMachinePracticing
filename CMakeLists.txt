
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
include_directories("${PROJECT_BINARY_DIR}/test")
include_directories("${PROJECT_BINARY_DIR}/include")
include_directories("${PROJECT_BINARY_DIR}/src")


include_directories("${PROJECT_BINARY_DIR}/src/CruiseControlModule")
add_subdirectory(src/CruiseControlModule)

add_library(CruiseControl
               src/CruiseControlModule/CruiseControl.cpp
               src/CruiseControlModule/CruiseControlStateMachine/CruiseControlAccState.cpp
               src/CruiseControlModule/CruiseControlStateMachine/CruiseControlActiveState.cpp
               src/CruiseControlModule/CruiseControlStateMachine/CruiseControlOffState.cpp
               src/CruiseControlModule/CruiseControlStateMachine/CruiseControlReadyState.cpp
               src/CruiseControlModule/CruiseControlStateMachine/CruiseControlSetState.cpp
               src/CruiseControlModule/CruiseControlStateMachine/CruiseControlState.cpp
               src/CruiseControlModule/CruiseControlStateMachine/CruiseControlWaitState.cpp)

add_executable(CruiseControl_test
               test/CruiseControl_test.cpp)
              
target_link_libraries(CruiseControl_test CruiseControl)

