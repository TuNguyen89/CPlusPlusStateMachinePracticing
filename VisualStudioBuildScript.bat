IF NOT EXIST build_vs mkdir build_vs
cd build_vs
del /Q *

cmake -G "Visual Studio 14 2015" ..
cmake --build .
