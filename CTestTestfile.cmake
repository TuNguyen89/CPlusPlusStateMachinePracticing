# CMake generated Testfile for 
# Source directory: D:/Shared/CruiseControlExam1
# Build directory: D:/Shared/CruiseControlExam1
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(CruiseControl_test1 "CruiseControl_test" "test/resource/test1/Input1.txt" "test/resource/test1/ExpectedOutput1.txt")
set_tests_properties(CruiseControl_test1 PROPERTIES  PASS_REGULAR_EXPRESSION "True")
add_test(CruiseControl_test2 "CruiseControl_test" "test/resource/test2/Input2.txt" "test/resource/test2/ExpectedOutput2.txt")
set_tests_properties(CruiseControl_test2 PROPERTIES  PASS_REGULAR_EXPRESSION "True")
subdirs("src/CruiseControlModule")
