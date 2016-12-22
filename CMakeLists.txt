
project(CruiseControl)
cmake_minimum_required (VERSION 2.6)
include(CTest)
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

set (SRC_CRUISECONTROL_DIR "src/CruiseControlModule")
set (SRC_CRUISECONTROL_STATEMACHINE_DIR "${SRC_CRUISECONTROL_DIR}/CruiseControlStateMachine")

set (SRC_ADAPTIVECRUISECONTROL_DIR "src/AdaptiveCruiseControlModule")
set (SRC_ADAPTIVECRUISECONTROL_STATEMACHINE_DIR "${SRC_ADAPTIVECRUISECONTROL_DIR}/AdaptiveCruiseControlStateMachine")

#Cruise Control module
include_directories("${PROJECT_BINARY_DIR}/${SRC_CRUISECONTROL_DIR}")
include_directories("${PROJECT_BINARY_DIR}/${SRC_CRUISECONTROL_STATEMACHINE_DIR}")

#ACC module
include_directories("${PROJECT_BINARY_DIR}/${SRC_ADAPTIVECRUISECONTROL_DIR}")
include_directories("${PROJECT_BINARY_DIR}/${SRC_ADAPTIVECRUISECONTROL_STATEMACHINE_DIR}")

add_subdirectory(${SRC_CRUISECONTROL_DIR})
add_subdirectory(${SRC_ADAPTIVECRUISECONTROL_DIR})

file(GLOB_RECURSE CruiseControlSourceFiles
                  ${SRC_CRUISECONTROL_DIR}/*.cpp
                  ${SRC_CRUISECONTROL_STATEMACHINE_DIR}/*.cpp
                  )
add_library(CruiseControl ${CruiseControlSourceFiles})

#Adaptive Cruise Control library
file(GLOB_RECURSE AdaptiveCruiseControlSourceFiles
                  ${SRC_ADAPTIVECRUISECONTROL_DIR}/*.cpp
                  ${SRC_ADAPTIVECRUISECONTROL_STATEMACHINE_DIR}/*.cpp
                  )
               
add_library(AdaptiveCruiseControl ${AdaptiveCruiseControlSourceFiles})
               
add_executable(CruiseControl_test
               test/CruiseControl_test.cpp)
              
target_link_libraries(CruiseControl_test CruiseControl AdaptiveCruiseControl)

#define a macro to simplify adding tests
macro (do_test arg1 arg2 arg3 result)
  add_test (CruiseControl_test${arg1} CruiseControl_test ${arg2} ${arg3})
  set_tests_properties (CruiseControl_test${arg1}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro (do_test)

set (TEST_RESOURCE_DIR "test/resource")
do_test (1 "${TEST_RESOURCE_DIR}/test1/Input1.txt" "${TEST_RESOURCE_DIR}/test1/ExpectedOutput1.txt" "True")
do_test (2 "${TEST_RESOURCE_DIR}/test2/Input2.txt" "${TEST_RESOURCE_DIR}/test2/ExpectedOutput2.txt" "True")