// log_stdout.hpp
#pragma once

#include "log.hpp"

namespace common {
//----------------------------------------------------------------

 class LoggerStdout : public ILogger 
{
public:
    virtual void Print( LogLevel level, const std::string & message ) override;
};

 //----------------------------------------------------------------
} // namespace
