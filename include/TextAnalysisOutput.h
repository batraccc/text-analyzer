#ifndef _TEXT_ANALYSIS_OUTPUT_H_
#define _TEXT_ANALYSIS_OUTPUT_H_

#include "TextStatistics.h"

class TextAnalysisOutput
{
public:
    void showStatistics(const TextStatistics &statistics, std::ostream &os) const;
    void showMostCommonWords(const TextStatistics &statistics, std::ostream &os) const;
    void showLetterFrequency(const TextStatistics &statistics, std::ostream &os) const;
    void showLongestWords(const TextStatistics &statistics, std::ostream &os) const;
    void saveAnalysis(const TextStatistics &statistics, const std::string &filepath) const;
    void showCountOfWord(const TextStatistics &statistics, std::string &word, std::ostream &os) const;
};

#endif