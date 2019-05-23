:: Folder where the built objects are stored
mkdir build

:: Build main.cpp
:: We copied some structures from Activity 25, so we can reuse the types defined there.
:: Since we put them in an header, we need to tell the compiler to look for the headers
:: in the current folder when including headers.
cl /EHsc /Fobuild/ /Febuild/ /W4 /I . main.cpp

:: You can not run the program at build\main.exe
