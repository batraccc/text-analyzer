#ifndef _TEXT_UTILITIES_H_
#define _TEXT_UTILITIES_H_

#include <string>
#include <algorithm>

inline std::string &standardize_word(std::string &word)
{
    word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
    for (char &character : word)
    {
        character = static_cast<char>(std::tolower(static_cast<unsigned char>(character)));
    }
    return word;
};

#endif