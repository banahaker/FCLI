@echo off
echo Compiling...
ping -n 2 127.0.0.1>nul
echo building cpp file...
g++ .\src\main.cpp -o  .\build\main.exe
ping -n 2 127.0.0.1>nul
echo build finish
echo --------------- Run Result -----------------
.\build\main.exe
echo.
echo --------------------------------------------