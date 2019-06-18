#include <cassert>
#include <string>
#include <vector>
#include <iostream>


/// Function to check the number of arguments
int checkNumArguments(const int &argc)
{
    if (argc != 2u) {
        throw std::runtime_error("Error: Incorrect number of arguments.");
    }
}


/// Function turn an integer into a word
void intToWord(const int &number, std::ostream &os = std::cout)
{
    switch (number)
    {
        case 1: os << "one\n"; break;
        case 2: os << "two\n"; break;
        case 3: os << "three\n"; break;
        case 4: os << "four\n"; break;
        case 5: os << "five\n"; break;
        case 6: os << "six\n"; break;

        default: throw std::runtime_error("Error: Input number must be in range [1, 6].");
    }
}



/// Program to convert an integer into its word
int main(int argc, char * argv[])
{
    // Preparation
    const std::vector<std::string> args(argv, argv + argc);

    try
    {
        // Check arguments
        checkNumArguments(argc);

        // Convert argument into number
        const int number = std::stoi(args[1u]);

        // Convert number into word
        intToWord(number);
    }
    catch (std::runtime_error &err)
    {
        std::cout << err.what() << '\n';
        return 1;
    }
    catch (std::invalid_argument&)
    {
        std::cout << "Error: Argument is not an integer.\n";
        return 1;
    }

    return 0;

}