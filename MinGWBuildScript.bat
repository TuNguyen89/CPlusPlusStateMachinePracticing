@echo off


IF NOT EXIST build_MinGW mkdir build_MinGW
cd build_MinGW
del /Q *

rem CmakeList.txt locate at ".."
cmake -G "MinGW Makefiles" ..
cmake --build .

