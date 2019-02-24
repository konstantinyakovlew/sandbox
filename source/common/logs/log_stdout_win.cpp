// log_stdout_win.cpp
#include "log_stdout_win.hpp"

#include <iostream>
#include <windows.h>

namespace common {
//----------------------------------------------------------------

void LoggerStdout_Win::Print( LogLevel level, const std::string & message )
{
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );

    const int color = GetColor( level );
	SetConsoleTextAttribute( hstdout, color );

    LoggerStdout_Win::Print( level, message );

    std::cout << "[" << LogLevel_ToStr( level ) << "] " << message << std::endl;

	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
}

//----------------------------------------------------------------

int LoggerStdout_Win::GetColor( LogLevel level ) const noexcept
{
    switch ( level )
    {
        case LogLevel::Warn:    return 240;
        case LogLevel::Error:   return 224;
        case LogLevel::Fatal:   return 192;
    }

    return 7;
}

//----------------------------------------------------------------
} // namespace
