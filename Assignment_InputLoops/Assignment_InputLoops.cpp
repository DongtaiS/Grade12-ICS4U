#include <iostream>

int main()
{
    int number;
    std::cout << "Please enter a number between 10 and 25. \n";
    std::cin >> number;
    while (number < 10 || number > 25)
    {
        std::cout << "Please enter a number between 10 and 25. \n";
        std::cin >> number;
    }
    char letter;
    std::cout << "Please enter 'Y', 'y', 'N', or 'n'. \n";
    std::cin >> letter;
    while (letter != 'Y' && letter != 'y' && letter != 'N' && letter != 'n')
    {
        std::cout << "Please enter 'Y', 'y', 'N', or 'n'. \n";
        std::cin >> letter;
    }
    std::string word;
    std::cout << "Please enter \"Yes\" or \"No\". \n";
    std::cin >> word;
    while (word != "Yes" && word != "No")
    {
        std::cout << "Please enter \"Yes\" or \"No\". \n";
        std::cin >> word;
    }
}
