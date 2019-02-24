// main.cpp
#include <iostream>

#include "common/logs/log.hpp"
#include "common/logs/log_stdout.hpp"

using namespace common;

//#include <filesystem>
//#include <chrono>

//void fn1()
//{
//    //int x = 1;
//    //++x;
//    //--x;
//}
//
//void fn2() noexcept
//{
//    //int x = 1;
//    //++x;
//    //--x;
//}
//
//void fn3()
//{
//    std::string s1 { "C:\\projects\\spooky\\cmake\\tmp_cmake" };
//    std::string s2 { "C:\\projects\\spooky\\cmake\\tmp_cmake\\cub" };
//    std::filesystem::current_path( std::move(s1) );
//    std::filesystem::current_path( std::move(s2) );
//}
//
//void fn4()
//{
//    std::string s1( "C:\\projects\\spooky\\cmake\\tmp_cmake" );
//    std::string s2( "C:\\projects\\spooky\\cmake\\tmp_cmake\\cub" );
//    std::filesystem::current_path( std::move(s1) );
//    std::filesystem::current_path( std::move(s2) );
//}
//
//template<typename T>
//void test( T fn, size_t count )
//{
//    auto begin = std::chrono::steady_clock::now();
//
//    for ( auto i {0u}; i < count; ++i )
//        fn();
//
//    auto end = std::chrono::steady_clock::now();
//
//    LogI( "Time difference = ", std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() );
//}

int main()
{
    //std::unique_ptr log = std::make_unique<prune::LoggerStdout>();

    
    //prune::Log l( prune::LogLevel::All );

    //prune::Log::Get().AddChannel( std::move(log) );


    //test( fn2, 10000000000 );
    //test( fn1, 10000000000 );

    //prune::Log::Get().Print( prune::LogLevel::Error, "test" );

    //LogW( "dsfsdf '    ", 123, " ' fefe", 42.0f, false );
    //LogE( "dsfsdf '    ", 123, " ' fefe", 42.0f, false );
    //LogF( "dsfsdf '    ", 123, " ' fefe", 42.0f, false );
    //LogI( "dsfsdf '    ", 123, " ' fefe", 42.0f, false );

    Log log( LogLevel::All );

    Log::Get().AddChannel(std::make_unique<LoggerStdout>());

    LogI("Number is ", 123, ", bool is '", true, "'");

    return 0;
}
