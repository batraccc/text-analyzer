#ifndef _TEXT_ANALYZER_H_
#define _TEXT_ANALYZER_H_

#include <string>

class TextAnalyzer
{
private:
    std::string filepath{};

public:
    TextAnalyzer();
    void loadFile(std::string &filepath);
    void showStatistics() const;
    void showMostCommonWords() const;
    void showLetterFrequency() const;
    int countGivenWord(std::string &word) const;
    void showLongestWords() const;
    void saveAnalysis() const;
};

#endif