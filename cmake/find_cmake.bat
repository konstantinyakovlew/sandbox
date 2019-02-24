@echo off

where /q cmake
if errorlevel 1 (
	for /f "tokens=1,2*" %%a in ('reg query "HKLM\Software\Kitware\CMake" /v "InstallDir" 2^>nul') do set "CMAKE_PATH=%%cbin\cmake.exe"
) else (
	set CMAKE_PATH=cmake
)

exit /b
