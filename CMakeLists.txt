
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
include_directories("${PROJECT_BINARY_DIR}/src/StateMachineCommon")

set (SRC_CRUISECONTROL_DIR "src/CruiseControlModule")
set (SRC_CRUISECONTROL_STATEMACHINE_DIR "${SRC_CRUISECONTROL_DIR}/CruiseControlStateMachine")

set (SRC_ADAPTIVECRUISECONTROL_DIR "src/AdaptiveCruiseControlModule")

#Cruise Control module
include_directories("${PROJECT_BINARY_DIR}/${SRC_CRUISECONTROL_DIR}")
include_directories("${PROJECT_BINARY_DIR}/${SRC_CRUISECONTROL_STATEMACHINE_DIR}")

#ACC module
include_directories("${PROJECT_BINARY_DIR}/${SRC_ADAPTIVECRUISECONTROL_DIR}")

add_subdirectory(${SRC_CRUISECONTROL_DIR})
add_subdirectory(${SRC_ADAPTIVECRUISECONTROL_DIR})

file(GLOB_RECURSE CruiseControlSourceFiles
                  ${SRC_CRUISECONTROL_STATEMACHINE_DIR}/*.cpp
                  ${SRC_CRUISECONTROL_DIR}/*.cpp
                  )
add_library(CruiseControl ${CruiseControlSourceFiles})

#Adaptive Cruise Control library
file(GLOB_RECURSE AdaptiveCruiseControlSourceFiles
                  ${SRC_ADAPTIVECRUISECONTROL_DIR}/*.cpp
                  )
               
add_library(AdaptiveCruiseControl ${AdaptiveCruiseControlSourceFiles})

#Cruise Control Executable         
add_executable(CruiseControl_test
               test/CommonTestFunctions.cpp
               test/CruiseControl_test.cpp)
target_link_libraries(CruiseControl_test CruiseControl)

#Adaptive Cruise Control Executable
add_executable(AdaptiveCruiseControl_test
               test/CommonTestFunctions.cpp
               test/AdaptiveCruiseControl_test.cpp)
target_link_libraries(AdaptiveCruiseControl_test  AdaptiveCruiseControl)

#define a macro to simplify adding tests
macro (do_test program arg1 arg2 arg3 result)
  add_test (${program}${arg1} ${program} ${arg2} ${arg3})
  set_tests_properties (${program}${arg1}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro (do_test)

set (TEST_RESOURCE_DIR "test/resource")

#define test for Cruise Control
do_test ("CruiseControl_test" 1 "${TEST_RESOURCE_DIR}/test1/Input1.txt" "${TEST_RESOURCE_DIR}/test1/ExpectedOutput1.txt" "True")
do_test ("CruiseControl_test" 2 "${TEST_RESOURCE_DIR}/test2/Input2.txt" "${TEST_RESOURCE_DIR}/test2/ExpectedOutput2.txt" "True")

#define test for Adaptive Cruise Control
do_test ("AdaptiveCruiseControl_test" 1 "${TEST_RESOURCE_DIR}/test3/Input3.txt" "${TEST_RESOURCE_DIR}/test3/ExpectedOutput3.txt" "True")

do_test ("AdaptiveCruiseControl_test" 2 "${TEST_RESOURCE_DIR}/test4/Input4.txt" "${TEST_RESOURCE_DIR}/test4/ExpectedOutput4.txt" "True")

do_test ("AdaptiveCruiseControl_test" 3 "${TEST_RESOURCE_DIR}/testReturnOff/testReturnOffInput.txt" "${TEST_RESOURCE_DIR}/testReturnOff/testReturnOffOutput.txt" "True")