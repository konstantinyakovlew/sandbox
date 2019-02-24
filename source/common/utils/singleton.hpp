// singleton.hpp
#pragma once

#include <assert.h>

namespace common {
//----------------------------------------------------------------

template<typename T>
class Singleton
{
public:
    Singleton( T *pInstance )
    {
        assert(!m_pInstance);
        m_pInstance = pInstance;
    }

    Singleton ( const Singleton & )             = delete;
    Singleton ( Singleton && )                  = delete;
    Singleton & operator=( const Singleton & )  = delete;

    ~Singleton()
    {
        assert(m_pInstance);
        m_pInstance = nullptr;
    }

public:
    static T & Get() noexcept
    {
        assert(m_pInstance);
        return *m_pInstance;
    }

private:
    inline static T *m_pInstance = nullptr;
};

//----------------------------------------------------------------
}
