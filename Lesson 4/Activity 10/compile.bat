:: Folder where the built objects are stored
mkdir build

:: Build connection.cpp, but do not link
:: /W4 enables additional warnings from the compiler, to help us spot possible error we make
cl /EHsc /c /Fobuild/ /W4 /I . connection.cpp

:: Build useraccount.cpp, but do not link
cl /EHsc /c /Fobuild/ /W4 /I . useraccount.cpp

:: Build main.cpp, but do not link
cl /EHsc /c /Fobuild/ /W4 /I . main.cpp

:: Link the two object files together
LINK build\connection.obj build\useraccount.obj build\main.obj /OUT:build\main.exe

:: You can not run the program at build\main.exe
