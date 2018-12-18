:: Folder where the built objects are stored
mkdir build

:: Build log.cpp, but do not link
:: /c means compile only, do not link
:: /Fo specifies the folder where to put the output
cl /EHsc /c /Fobuild/ log.cpp

:: Build main.cpp, but do not link
:: /I adds a folder to the folders where to look for includes.
:: We add the current folder because we are including log.h
cl /EHsc /c /Fobuild/ /I . main.cpp

:: Link the two object files together
LINK build\log.obj build\main.obj /OUT:build\main.exe

:: You can not run the program at build\main.exe
