// log_stdout.cpp
#include "log_stdout.hpp"

#include <iostream>

namespace common {
//----------------------------------------------------------------

void LoggerStdout::Print( LogLevel level, const std::string & message )
{
    std::cout << "[" << LogLevel_ToStr( level ) << "] " << message << std::endl;
}

//----------------------------------------------------------------
} // namespace
