#ifndef AGILNET_SUPPORT_LOG
#define AGILNET_SUPPORT_LOG

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <iostream>

namespace agilNet
{
namespace support
{

class Log
{
private :
    Log();
    static const long long FileSize;
    static Log* single;
    static bool isInit;
public :
    enum Level
    {
        trace,
        debug,
        info,
        warning,
        error,
        fatal
    };
    void write(Level level,const std::string& content);
    void write(Level level,const char* content)
    {
        std::string str(content);
        write(level,str);
    }

    Log& operator<<(const char* charPtr)
    {
        std::string str(charPtr);
        write(fatal,str);
        return getSingleRefer();
    }
    Log& operator<<(const int num)
    {
        std::stringstream stream;
        stream<<num;
        write(fatal,stream.str());
        return getSingleRefer();
    }
    Log& operator<<(const double num)
    {
        std::stringstream stream;
        stream<<num;
        write(fatal,stream.str());
        return getSingleRefer();
    }
    Log& operator<<(const std::string& str)
    {
        write(fatal,str);
        return getSingleRefer();
    }
    static Log* getSingle();
    static Log& getSingleRefer()
    {
        return *getSingle();
    }
};
}
}
#endif // AGILNET_SUPPORT_LOG
