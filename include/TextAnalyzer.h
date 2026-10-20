#ifndef _TEXT_ANALYZER_H_
#define _TEXT_ANALYZER_H_

#include <string>
#include "TextStatistics.h"

class TextAnalyzer
{
private:
    std::string filepath{};

public:
    TextAnalyzer(const std::string &filepath);
    TextStatistics analyze() const;
};

#endif