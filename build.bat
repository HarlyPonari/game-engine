@echo off

REM Remove the build directory if it exists
if exist "build\" (
  rmdir /s /q "build"
)

REM Create the build directory and navigate into it
mkdir build

REM now we must cmake -S . -B build
cmake -S . -B build

REM now we can build the project
cmake --build build
