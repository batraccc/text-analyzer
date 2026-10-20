#include <iostream>
#include "../include/TextAnalyzer.h"
#include "../include/FileNotOpenedException.h"
#include "../include/TextStatistics.h"
#include "../include/TextAnalysisOutput.h"

void displayMenu()
{
    std::cout << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "     TEXT ANALYZER     " << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Load file" << std::endl;
    std::cout << "2. Show statistics" << std::endl;
    std::cout << "3. Show most common words" << std::endl;
    std::cout << "4. Show letter frequency" << std::endl;
    std::cout << "5. Search word" << std::endl;
    std::cout << "6. Show longest words" << std::endl;
    std::cout << "7. Save analysis" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose option: ";
}

int main()
{
    TextAnalysisOutput output;
    TextStatistics statistics;
    int choice{};
    do
    {
        displayMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            try
            {
                std::cin.ignore();
                std::string filepath{};
                std::cout << "Enter filepath: ";
                std::getline(std::cin, filepath);
                TextAnalyzer analyzer(filepath);
                statistics = analyzer.analyze();
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 2:
        {
            try
            {
                output.showStatistics(statistics, std::cout);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 3:
        {
            try
            {
                std::cin.ignore();
                int number_of_words_to_display{};
                std::cout << "Enter number of words to display: ";
                std::cin >> number_of_words_to_display;
                output.showMostCommonWords(statistics, std::cout, number_of_words_to_display);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 4:
        {
            try
            {
                output.showLetterFrequency(statistics, std::cout);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 5:
        {
            try
            {
                std::cout << "Enter word to search: ";
                std::cin.ignore();
                std::string word{};
                std::getline(std::cin, word);
                output.showCountOfWord(statistics, word, std::cout);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 6:
        {
            try
            {
                std::cin.ignore();
                int number_of_words_to_display{};
                std::cout << "Enter number of words to display: ";
                std::cin >> number_of_words_to_display;
                output.showLongestWords(statistics, std::cout, number_of_words_to_display);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 7:
        {
            try
            {
                std::cin.ignore();
                std::string filepath{};
                std::cout << "Enter filepath: ";
                std::getline(std::cin, filepath);
                output.saveAnalysis(statistics, filepath);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }

            break;
        }
        default:
        {
            break;
        }
        }
    } while (choice != 8);
    return 0;
}