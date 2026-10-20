#ifndef _TEXT_STATISTICS_H_
#define _TEXT_STATISTICS_H_

#include <string>
#include <vector>
#include <map>

class TextStatistics
{
private:
    friend class TextAnalyzer;
    int character_count{0};
    int character_count_without_spaces{0};
    int word_count{0};
    int sentence_count{0};
    int line_count{0};
    int unique_word_count{0};
    double average_word_length{0.0};
    std::map<std::string, int> word_frequencies{};
    std::map<char, int> letter_frequencies{};
    std::vector<std::string> unique_words{};

public:
    TextStatistics();
    int getCharacterCount() const;
    int getCharacterCountWihoutSpaces() const;
    int getWordCount() const;
    int getSentenceCount() const;
    int getLineCount() const;
    int getUniqueWordCount() const;
    double getAverageWordLength() const;
    const std::map<std::string, int> &getWordFrequencies() const;
    const std::map<char, int> &getLetterFrequncies() const;
    const std::vector<std::string> &getUniqueWords() const;
};

#endif