@echo off

call :vs%1
if "%n%" == "" (
    exit /b
)

for /f "tokens=1,2*" %%a in ('reg query "HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\VisualStudio\SxS\VS7" /v "%n%.0" 2^>nul') do set "VS_PATH=%%cCommon7\IDE\devenv"

exit /b

:vs2017
set /a "n=%n%+1"
:vs2015
set /a "n=%n%+2"
:vs2013
set /a "n=%n%+1"
:vs2012
set /a "n=%n%+1"
:vs2010
set /a "n=%n%+10"
exit /b
