#include "../include/FileNotOpenedException.h"

FileNotOpenedException::FileNotOpenedException(const std::string &message) : std::runtime_error{message} {}