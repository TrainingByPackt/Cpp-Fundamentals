:: Folder where the built objects are stored
mkdir build

:: Build mathlib.cpp, but do not link
cl /EHsc /c /Fobuild/ /I . mathlib.cpp

:: Build main.cpp, but do not link
cl /EHsc /c /Fobuild/ /I . main.cpp

:: Link the two object files together
LINK build\mathlib.obj build\main.obj /OUT:build\main.exe

:: You can not run the program at build\main.exe
