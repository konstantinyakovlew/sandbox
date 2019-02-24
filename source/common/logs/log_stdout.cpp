// log_stdout.cpp
#include "log_stdout.hpp"

#include <iostream>
#include <windows.h>

namespace common {
//----------------------------------------------------------------

void LoggerStdout::Print( LogLevel level, const std::string & message )
{
#ifdef PLATFORM_WINDOWS
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( hstdout, &csbi );

    const int color = GetColor( level );
	SetConsoleTextAttribute( hstdout, color );
#endif

    std::cout << "[" << LogLevel_ToStr( level ) << "] " << message << std::endl;

#ifdef PLATFORM_WINDOWS
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
#endif
}

int LoggerStdout::GetColor( LogLevel level ) const noexcept
{
#ifdef PLATFORM_WINDOWS
    switch ( level )
    {
        case LogLevel::Warn:    return 240;
        case LogLevel::Error:   return 224;
        case LogLevel::Fatal:   return 192;
    }

    return 7;
#else
    return 0;
#endif
}

//----------------------------------------------------------------
} // namespace
