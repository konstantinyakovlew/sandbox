// log.cpp
#include "log.hpp"

namespace common {
//----------------------------------------------------------------

std::string LogLevel_ToStr( LogLevel level ) noexcept
{
    switch ( level )
    {
        case LogLevel::Trace:   return "TRACE";
        case LogLevel::Info:    return "INFO";
        case LogLevel::Warn:    return "WARN";
        case LogLevel::Error:   return "ERROR";
        case LogLevel::Fatal:   return "FATAL";
    }

    return "";
}

//----------------------------------------------------------------

Log::Log( LogLevel level ) noexcept
    : Singleton( this )
    , m_level( level )
{
}

//----------------------------------------------------------------

void Log::SetLevel( LogLevel level ) noexcept
{
    m_level = level;
}

//----------------------------------------------------------------

bool Log::CheckLevel( LogLevel level ) const noexcept
{
    return m_level <= level;
}

//----------------------------------------------------------------

void Log::AddChannel( LogChannel_t channel )
{
    m_channels.emplace_back( std::move(channel) );
}

//----------------------------------------------------------------
} // namespace
