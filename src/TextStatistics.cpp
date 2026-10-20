#include "../include/TextStatistics.h"

TextStatistics::TextStatistics() {}

int TextStatistics::getCharacterCount() const
{
    return character_count;
}

int TextStatistics::getCharacterCountWihoutSpaces() const
{
    return character_count_without_spaces;
}

int TextStatistics::getWordCount() const
{
    return word_count;
}

int TextStatistics::getSentenceCount() const
{
    return sentence_count;
}

int TextStatistics::getLineCount() const
{
    return line_count;
}

int TextStatistics::getUniqueWordCount() const
{
    return unique_word_count;
}

double TextStatistics::getAverageWordLength() const
{
    return average_word_length;
}

const std::map<std::string, int> &TextStatistics::getWordFrequencies() const
{
    return word_frequencies;
}

const std::map<char, int> &TextStatistics::getLetterFrequncies() const
{
    return letter_frequencies;
}
const std::vector<std::string> &TextStatistics::getUniqueWords() const
{
    return unique_words;
}