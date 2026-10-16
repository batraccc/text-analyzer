#include "/Users/batraccc/C++/cpp-workout/Text Analyzer/include/TextAnalyzer.h"
#include "/Users/batraccc/C++/cpp-workout/Text Analyzer/include/FileNotOpenedException.h"
#include "/Users/batraccc/C++/cpp-workout/Text Analyzer/include/FilepathNonExistantException.h"
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

std::string &standardize_word(std::string &word)
{
    word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
    for (char &character : word)
    {
        tolower(character);
    }
    return word;
}

int count_characters(std::ifstream &input_stream)
{
    size_t characters{0};
    std::string line{};
    while (getline(input_stream, line))
    {
        characters += line.size();
    }
    return static_cast<int>(characters);
}

int count_characters_without_spaces(std::ifstream &input_stream)
{
    int characters_without_spaces{0};
    std::string line{};
    while (getline(input_stream, line))
    {
        for (const char &character : line)
        {
            if (!isspace(character))
                characters_without_spaces++;
        }
    }
    return characters_without_spaces;
}

int count_words(std::ifstream &input_stream)
{
    int words{0};
    std::string line{};
    while (getline(input_stream, line))
    {
        std::stringstream ss(line);
        std::string word{};
        while (ss >> word)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(std::ifstream &input_stream)
{
    int sentences{0};
    std::string line{};
    while (getline(input_stream, line))
    {
        bool previous_was_terminator = false;
        for (const char &character : line)
        {
            if (character == '.' || character == '!' || character == '?')
            {
                if (!previous_was_terminator)
                {
                    sentences++;
                }
                previous_was_terminator = true;
            }
            else
            {
                previous_was_terminator = false;
            }
        }
    }
    return sentences;
}

int count_lines(std::ifstream &input_stream)
{
    int lines{0};
    std::string line{};
    while (getline(input_stream, line))
    {
        lines++;
    }
    return lines;
}

std::vector<std::string> get_vector_of_unique_words(std::ifstream &input_stream)
{
    std::vector<std::string> unique_words{};
    std::string line{};
    while (getline(input_stream, line))
    {
        std::stringstream ss(line);
        std::string word{};
        while (ss >> word)
        {
            std::string standardized_word = standardize_word(word);
            if (std::find(unique_words.begin(), unique_words.end(), standardized_word) == unique_words.end())
                unique_words.push_back(standardized_word);
        }
    }
    return unique_words;
}

double calculate_average_word_length(std::vector<std::string> &words)
{
    double total_length{0.0};
    for (const std::string &word : words)
    {
        total_length += static_cast<double>(word.size());
    }
    return total_length / (static_cast<int>(words.size()));
}

TextAnalyzer::TextAnalyzer() {}

void TextAnalyzer::loadFile(std::string &filepath)
{
    this->filepath = filepath;
    std::cout << "File loaded successfully" << std::endl;
    std::cout << std::endl;
}

void TextAnalyzer::showStatistics() const
{
    if (filepath.size() != 0)
    {
        std::ifstream input_stream(filepath);
        if (input_stream.is_open())
        {
            int characters = count_characters(input_stream);
            input_stream.clear();
            input_stream.seekg(0, std::ios::beg);
            int characters_without_spaces = count_characters_without_spaces(input_stream);
            input_stream.clear();
            input_stream.seekg(0, std::ios::beg);
            int words = count_words(input_stream);
            input_stream.clear();
            input_stream.seekg(0, std::ios::beg);
            int sentences = count_sentences(input_stream);
            input_stream.clear();
            input_stream.seekg(0, std::ios::beg);
            int lines = count_lines(input_stream);
            input_stream.clear();
            input_stream.seekg(0, std::ios::beg);
            std::vector<std::string> unique_words = get_vector_of_unique_words(input_stream);
            double average_word_length = calculate_average_word_length(unique_words);
            std::cout << "===== TEXT STATISTICS =====" << std::endl;
            std::cout << "Characters: " << characters << std::endl;
            std::cout << "Characters without spaces: " << characters_without_spaces << std::endl;
            std::cout << "Words: " << words << std::endl;
            std::cout << "Sentances: " << sentences << std::endl;
            std::cout << "Lines:" << lines << std::endl;
            std::cout << "Unique words: " << unique_words.size() << std::endl;
            std::cout << "Average word length: " << average_word_length << std::endl;
            std::cout << std::endl;
            input_stream.close();
        }
        else
        {
            throw FileNotOpenedException("File could not be opened!");
        }
    }
    else
    {
        throw FilepathNonExistantException("Filepath has not been set!");
    }
}