// log.hpp
#pragma once

#include "common/utils/singleton.hpp"

#include <string>
#include <vector>
#include <memory>

#ifndef COMMON_LOG_DISABLE

#define LogT( ... ) { common::Log::Get().Print( common::LogLevel::Trace, __VA_ARGS__ ); }
#define LogI( ... ) { common::Log::Get().Print( common::LogLevel::Info, __VA_ARGS__ ); }
#define LogW( ... ) { common::Log::Get().Print( common::LogLevel::Warn, __VA_ARGS__ ); }
#define LogE( ... ) { common::Log::Get().Print( common::LogLevel::Error, __VA_ARGS__ ); }
#define LogF( ... ) { common::Log::Get().Print( common::LogLevel::Fatal, __VA_ARGS__ ); }

#else

#define LogT( ... )
#define LogI( ... )
#define LogW( ... )
#define LogE( ... )
#define LogF( ... )

#define LogLine()

#endif

namespace common {
//----------------------------------------------------------------

enum class LogLevel
{
    All,
    Trace,
    Info,
    Warn,
    Error,
    Fatal,
    Off,
};

std::string LogLevel_ToStr( LogLevel level ) noexcept;

//----------------------------------------------------------------

class ILogger
{
public:
    virtual ~ILogger() {}

    virtual void Print( LogLevel level, const std::string & message ) = 0;
};

//----------------------------------------------------------------

class Log : public Singleton<Log>
{
public:
    using LogChannel_t = std::unique_ptr<ILogger>;

public:
    Log( LogLevel level ) noexcept;

    void SetLevel( LogLevel level ) noexcept;
    bool CheckLevel( LogLevel level ) const noexcept;

    void AddChannel( LogChannel_t channel );

    template<typename ... TArgs>
    void Print( LogLevel level, TArgs... args );

private:
    template<typename T>
    void Print( const T & value );

private:
    LogLevel                    m_level;
    std::string                 m_str;
    std::string                 m_str2;
    std::vector<LogChannel_t>   m_channels;
};

//----------------------------------------------------------------

template<typename ...TArgs>
void Log::Print( LogLevel level, TArgs ...args )
{
    assert( level != LogLevel::All && level != LogLevel::Off );

    if ( !CheckLevel( level ) )
        return;

    m_str.clear();

    ( Print(args), ... );

    if ( m_str.empty() )
        return;

    if ( m_str.back() == ' ' )
        m_str.pop_back();

    for ( auto & channel : m_channels )
        channel->Print( level, m_str );
}

//----------------------------------------------------------------

template<typename T>
void Log::Print( const T & value )
{
    m_str2.clear();

         if constexpr ( std::is_same<T, std::string>::value )   m_str2 = value;
    else if constexpr ( std::is_same<T, const char *>::value )  m_str2 = value?value:"";
    else if constexpr ( std::is_same<T, char *>::value )        m_str2 = value?value:"";
    else if constexpr ( std::is_same<T, char>::value )          m_str2 = value;
    else if constexpr ( std::is_same<T, bool>::value )          m_str2 = value?"true":"false";
    else                                                        m_str2 = std::to_string( value );

    m_str += m_str2;
}

//----------------------------------------------------------------
} // namespace
