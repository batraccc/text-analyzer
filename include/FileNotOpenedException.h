#ifndef _FILE_NOT_OPENED_EXCEPTION_H_
#define _FILE_NOT_OPENED_EXCEPTION_H_

#include <stdexcept>

class FileNotOpenedException : public std::runtime_error
{
public:
    FileNotOpenedException(const std::string &message);
};

#endif