:: Folder where the built objects are stored
mkdir build

:: Build main.cpp
:: We include the header from Activity 18, so we can reuse the types defined there
:: To do it, we created a symbolic link in the current folder to the header in Activity 18
:: so that it's easy to access the file while working from the folder for Activity 19
cl /EHsc /Fobuild/ /Febuild/ /W4 /I . main.cpp

:: You can not run the program at build\main.exe
