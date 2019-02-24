// log_stdout.hpp
#pragma once

#include "log.hpp"

namespace common {
//----------------------------------------------------------------

 class LoggerStdout final : public ILogger 
{
public:
    virtual void Print( LogLevel level, const std::string & message ) override;

private:
    int GetColor( LogLevel level ) const noexcept;
};

 //----------------------------------------------------------------
} // namespace
