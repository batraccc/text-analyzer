#include "../include/TextAnalysisOutput.h"
#include "../include/FileNotOpenedException.h"
#include "../include/TextUtilities.h"

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

void TextAnalysisOutput::showStatistics(const TextStatistics &statistics, std::ostream &os) const
{
    if (statistics.getIsEmpty() == true)
    {
        throw std::runtime_error("No analysis exists");
    }
    else if (statistics.getCharacterCount() == 0)
    {
        throw std::runtime_error("Analysis exists, but the file contains zero characters");
    }
    os << "===== TEXT STATISTICS =====" << std::endl;
    os << "Characters: " << statistics.getCharacterCount() << std::endl;
    os << "Characters without spaces: " << statistics.getCharacterCountWihoutSpaces() << std::endl;
    os << "Words: " << statistics.getWordCount() << std::endl;
    os << "Sentances: " << statistics.getSentenceCount() << std::endl;
    os << "Lines:" << statistics.getLineCount() << std::endl;
    os << "Unique words: " << statistics.getUniqueWordCount() << std::endl;
    os << "Average word length: " << statistics.getAverageWordLength() << std::endl;
    os << std::endl;
}

void TextAnalysisOutput::showMostCommonWords(const TextStatistics &statistics, std::ostream &os, const int number_of_words_to_display) const
{
    if (statistics.getIsEmpty() == true)
    {
        throw std::runtime_error("No analysis exists");
    }
    else if (statistics.getCharacterCount() == 0)
    {
        throw std::runtime_error("Analysis exists, but the file contains zero characters");
    }
    const auto &word_frequencies = statistics.getWordFrequencies();
    std::vector<std::pair<std::string, int>> sorted_words(word_frequencies.begin(), word_frequencies.end());
    std::sort(sorted_words.begin(), sorted_words.end(), [](const auto &a, const auto &b)
              { return a.second > b.second; });
    if (sorted_words.size() > static_cast<unsigned long>(number_of_words_to_display))
    {
        for (auto it = sorted_words.begin(); it != sorted_words.begin() + number_of_words_to_display; it++)
        {
            os << it->first << ": " << it->second << std::endl;
        }
    }
    else
    {
        for (const auto &[word, count] : sorted_words)
        {
            os << word << ": " << count << std::endl;
        }
    }
}

void TextAnalysisOutput::showLetterFrequency(const TextStatistics &statistics, std::ostream &os) const
{
    if (statistics.getIsEmpty() == true)
    {
        throw std::runtime_error("No analysis exists");
    }
    else if (statistics.getCharacterCount() == 0)
    {
        throw std::runtime_error("Analysis exists, but the file contains zero characters");
    }
    const auto &letter_frequencies = statistics.getLetterFrequncies();
    std::vector<std::pair<char, int>> letters_sorted(letter_frequencies.begin(), letter_frequencies.end());
    std::sort(letters_sorted.begin(), letters_sorted.end(), [](const auto &a, const auto &b)
              { return a.second > b.second; });
    for (const auto &[letter, count] : letters_sorted)
    {
        os << letter << ": " << count << std::endl;
    }
}

void TextAnalysisOutput::showLongestWords(const TextStatistics &statistics, std::ostream &os, const int number_of_words_to_display) const
{
    if (statistics.getIsEmpty() == true)
    {
        throw std::runtime_error("No analysis exists");
    }
    else if (statistics.getCharacterCount() == 0)
    {
        throw std::runtime_error("Analysis exists, but the file contains zero characters");
    }
    const auto &unique_words = statistics.getUniqueWords();
    std::map<std::string, size_t> word_lengths{};
    for (const std::string &word : unique_words)
    {
        word_lengths[word] = word.size();
    }
    std::vector<std::pair<std::string, size_t>> sorted_word_lengths(word_lengths.begin(), word_lengths.end());
    std::sort(sorted_word_lengths.begin(), sorted_word_lengths.end(), [](const auto &a, const auto &b)
              { return a.second > b.second; });
    if (sorted_word_lengths.size() > static_cast<unsigned long>(number_of_words_to_display))
    {
        for (auto it = sorted_word_lengths.begin(); it != sorted_word_lengths.begin() + number_of_words_to_display; it++)
        {
            os << it->first << ": " << it->second << std::endl;
        }
    }
    else
    {
        for (const auto &[word, count] : sorted_word_lengths)
        {
            os << word << ": " << count << std::endl;
        }
    }
}

void TextAnalysisOutput::saveAnalysis(const TextStatistics &statistics, const std::string &filepath) const
{
    std::ofstream output_stream(filepath);
    if (output_stream.is_open())
    {
        showStatistics(statistics, output_stream);
        output_stream << std::endl;
        showMostCommonWords(statistics, output_stream, statistics.getWordFrequencies().size());
        output_stream << std::endl;
        showLetterFrequency(statistics, output_stream);
        output_stream << std::endl;
        showLongestWords(statistics, output_stream, statistics.getUniqueWords().size());
    }
    else
    {
        throw FileNotOpenedException("File could not be opened");
    }
}

void TextAnalysisOutput::showCountOfWord(const TextStatistics &statistics, std::string &word, std::ostream &os) const
{
    if (statistics.getIsEmpty() == true)
    {
        throw std::runtime_error("No analysis exists");
    }
    else if (statistics.getCharacterCount() == 0)
    {
        throw std::runtime_error("Analysis exists, but the file contains zero characters");
    }
    const auto &word_frequencies = statistics.getWordFrequencies();
    std::string standardized_word = standardize_word(word);
    auto it = word_frequencies.find(standardized_word);
    if (it != word_frequencies.end())
    {
        os << it->first << ": " << it->second << std::endl;
    }
    else
    {
        os << standardized_word << ": " << "0" << std::endl;
    }
}