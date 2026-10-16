#ifndef _FILEPATH_NON_EXISTANT_EXCEPTION_H_
#define _FILEPATH_NON_EXISTANT_EXCEPTION_H_

#include <stdexcept>

class FilepathNonExistantException : public std::runtime_error
{
public:
    FilepathNonExistantException(const std::string &message);
};

#endif