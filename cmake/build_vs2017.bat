@echo off

rem ----------------------------------------------------------------
rem Input:
rem 1) build configuration (Debug / Release / RelWithDebInfo / MinSizeRel)
rem ----------------------------------------------------------------

call generate_vs2017.bat || (
    exit /b 1
)

call "%SCRIPT_PATH%\find_vs.bat" 2017
if "%VS_PATH%" == "" (
    echo "Error: VisualStudio 2017 is not installed on this machine"
    exit /b
)

echo "----------------------------------------------------------------"
echo "Info: Build VS2017"

set BUILD_CONFIGURATION=%1
if "%BUILD_CONFIGURATION%" == "" (
    set BUILD_CONFIGURATION=Debug
)

echo "Info: Build configuration is %BUILD_CONFIGURATION%"

echo "----------------------------------------------------------------"

cd %SOLUTION_PATH%

call "%VS_PATH%" prj_tests.sln /rebuild %BUILD_CONFIGURATION% || (
    cd %SCRIPT_PATH%
    echo "Error: failed to run solution build"
    exit /b 1
)

cd %SCRIPT_PATH%
