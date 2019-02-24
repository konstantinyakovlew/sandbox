// log_stdout_win.hpp
#pragma once

#include "log_stdout.hpp"

namespace common {
//----------------------------------------------------------------

 class LoggerStdout_Win final : public LoggerStdout
{
public:
    virtual void Print( LogLevel level, const std::string & message ) override;

private:
    int GetColor( LogLevel level ) const noexcept;
};

 //----------------------------------------------------------------
} // namespace
