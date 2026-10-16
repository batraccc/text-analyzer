#include "/Users/batraccc/C++/cpp-workout/Text Analyzer/include/FilepathNonExistantException.h"

FilepathNonExistantException::FilepathNonExistantException(const std::string &message) : std::runtime_error{message} {}
