#include "../include/TextAnalyzer.h"
#include "../include/FileNotOpenedException.h"
#include "../include/TextUtilities.h"
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

TextAnalyzer::TextAnalyzer(const std::string &filepath) : filepath{filepath} {}

TextStatistics TextAnalyzer::analyze() const
{
    TextStatistics statistics;
    statistics.is_empty = false;
    std::ifstream input_stream(filepath);
    if (input_stream.is_open())
    {
        std::string line{};
        std::vector<std::string> words{};
        std::vector<std::string> unique_words{};
        std::map<std::string, int> word_count{};
        std::map<char, int> letter_frequency{};
        std::map<std::string, size_t> word_lengths{};
        while (getline(input_stream, line))
        {
            bool previous_was_terminator = false;
            statistics.character_count += static_cast<int>(line.size());
            for (const char &character : line)
            {
                if (!isspace(character))
                {
                    statistics.character_count_without_spaces++;
                }
                if (!isspace(character) && !ispunct(character))
                {
                    char altered_character = static_cast<char>(std::tolower(static_cast<unsigned char>(character)));
                    letter_frequency[altered_character]++;
                }
                if (character == '.' || character == '!' || character == '?')
                {
                    if (!previous_was_terminator)
                    {
                        statistics.sentence_count++;
                    }
                    previous_was_terminator = true;
                }
                else
                {
                    previous_was_terminator = false;
                }
            }
            std::stringstream ss(line);
            std::string word{};
            while (ss >> word)
            {
                statistics.word_count++;
                words.push_back(word);
                std::string standardized_word = standardize_word(word);
                if (std::find(unique_words.begin(), unique_words.end(), standardized_word) == unique_words.end())
                    unique_words.push_back(standardized_word);
                word_count[standardized_word]++;
            }
            statistics.line_count++;
            statistics.unique_word_count = static_cast<int>(unique_words.size());
            size_t length_of_all_words{0};
            for (const std::string &word : words)
            {
                length_of_all_words += word.size();
            }
            statistics.average_word_length = words.size() != 0 ? static_cast<double>(length_of_all_words) / words.size() : 0;
            statistics.word_frequencies = word_count;
            statistics.letter_frequencies = letter_frequency;
            for (const std::string &word : unique_words)
            {
                word_lengths[word] = word.size();
            }
            statistics.unique_words = unique_words;
        }
        input_stream.close();
        return statistics;
    }
    else
    {
        throw FileNotOpenedException("File could not be opened!");
    }
}