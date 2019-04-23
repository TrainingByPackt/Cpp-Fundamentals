:: Folder where the built objects are stored
mkdir build

:: Build main.cpp
cl /EHsc /Fobuild/ /Febuild/ /W4 main.cpp
