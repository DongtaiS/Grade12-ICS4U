#include <iostream>
#include <string>
int main()
{
    std::cout << "The size of an int is: " << sizeof(int) << std::endl;
    std::cout << "The size of a float is: " << sizeof(float) << std::endl;
    std::cout << "The size of a double is: " << sizeof(double) << std::endl;
    std::cout << "The size of a bool is: " << sizeof(bool) << std::endl;
    std::cout << "The size of a string is: " << sizeof(std::string) << std::endl;
    std::cout << "The size of a char is: " << sizeof(char) << std::endl;
    std::cout << "The size of a wide char is: " << sizeof(wchar_t) << std::endl;
    std::cout << "The size of a char16 is: " << sizeof(char16_t) << std::endl;
    std::cout << "The size of a char32 is: " << sizeof(char32_t) << std::endl;
    std::cout << "The size of a long double is: " << sizeof(long double) << std::endl;
    std::cout << "The size of a long is: " << sizeof(long) << std::endl;
    std::cout << "The size of a long long is: " << sizeof(long long) << std::endl;
    std::cout << "The size of a short is: " << sizeof(short) << std::endl;
    std::cout << "The size of a uint16 is: " << sizeof(uint16_t) << std::endl;
    std::cout << "The size of an int16 is: " << sizeof(int16_t) << std::endl;
    std::cout << "The size of a uint32 is: " << sizeof(uint32_t) << std::endl;
    std::cout << "The size of an int32 is: " << sizeof(int32_t) << std::endl;
}