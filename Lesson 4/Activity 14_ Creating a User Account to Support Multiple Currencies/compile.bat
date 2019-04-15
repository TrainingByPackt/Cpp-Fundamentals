:: Folder where the built objects are stored
mkdir build

:: Build main.cpp
:: currency.h only has templates, so it does not need to be compiled
cl /EHsc /Fobuild/ /Febuild/ /W4 /I . main.cpp

:: You can not run the program at build\main.exe
