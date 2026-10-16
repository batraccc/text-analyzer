#include <iostream>
#include "../include/TextAnalyzer.h"
#include "../include/FileNotOpenedException.h"
#include "../include/FilepathNonExistantException.h"

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
    TextAnalyzer text_analyzer;
    int choice{};
    do
    {
        displayMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cin.ignore();
            std::string filepath{};
            std::cout << "Enter filepath: ";
            std::getline(std::cin, filepath);
            text_analyzer.loadFile(filepath);
            break;
        }
        case 2:
        {
            try
            {
                text_analyzer.showStatistics();
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
                text_analyzer.showMostCommonWords();
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
                text_analyzer.showLetterFrequency();
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
                std::cin.ignore();
                std::string word{};
                std::cout << "Enter a word: ";
                getline(std::cin, word);
                int count = text_analyzer.countGivenWord(word);
                std::cout << "Word " << word << " appears " << count << " times!";
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
                text_analyzer.showLongestWords();
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 7:
        {
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