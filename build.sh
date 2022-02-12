@echo off
echo Compiling...
sleep 0.5s
echo building cpp file...
g++ ./src/main.cpp -o  ./build/main.exe
sleep 1s
echo build finish
echo --------------- Run Result -----------------
echo -e "\n"
./build/main.exe
echo -e "\n"
echo --------------------------------------------
