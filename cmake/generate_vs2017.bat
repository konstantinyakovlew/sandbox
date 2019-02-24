@echo off
set SCRIPT_PATH=%~d0%~p0

echo "----------------------------------------------------------------"
echo "Info: Generate VS2017 solution"
echo "----------------------------------------------------------------"

call %SCRIPT_PATH%\find_cmake.bat"
if "%CMAKE_PATH%" == "" (
    echo "Error: CMake is not installed on this machine"
    exit /b
)

set SOLUTION_PATH=%SCRIPT_PATH%\tmp_cmake_vs2017

if not exist %SOLUTION_PATH% (
    mkdir %SOLUTION_PATH%
)

cd %SOLUTION_PATH%

call "%CMAKE_PATH%" -G "Visual Studio 15" -DCMAKE_VERBOSE_MAKEFILE=ON %SCRIPT_PATH% || (
    cd %SCRIPT_PATH%
    echo "Error: CMake run failed"
    exit /b 1
)

cd %SCRIPT_PATH%
