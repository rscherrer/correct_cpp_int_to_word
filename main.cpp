#include <cassert>
#include <string>
#include <vector>
#include <iostream>


/// Function to check the number of arguments
void checkNumArguments(const size_t &argc)
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


/// Function to run the main task
int doMain(const std::vector<std::string> &args)
{
    try
    {
        // Check arguments
        checkNumArguments(args.size());

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


/// Function to test task performing behavior of the program
void testUse(const std::string &programName)
{
    assert(doMain( { programName, "1" } ) == 0);
    assert(doMain( { programName, "2" } ) == 0);
    assert(doMain( { programName, "3" } ) == 0);
    assert(doMain( { programName, "4" } ) == 0);
    assert(doMain( { programName, "5" } ) == 0);
    assert(doMain( { programName, "6" } ) == 0);
}


/// Function to test error handling behavior of the program
void testAbuse(const std::string &programName)
{
    assert(doMain( { programName } ) == 1);
    assert(doMain( { programName, "1", "2"} ) == 1);
    assert(doMain( { programName, "7" } ) == 1);
    assert(doMain( { programName, "nonsense" } ) == 1);
}


/// Function to test the program
void test(const std::string &programName)
{
    testUse(programName);
    testAbuse(programName);
}


/// Program to convert an integer into its word
int main(int argc, char * argv[])
{
    // Preparation
    const std::vector<std::string> args(argv, argv + argc);

    // Test the program
    test(args[0u]);

    // Run the program
    return doMain(args);

}