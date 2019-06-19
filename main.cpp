#include <cassert>
#include <string>
#include <vector>
#include <iostream>


/// Function to check the number of arguments
int checkNumArguments(const size_t &argc)
{
    if (argc == 2u) {
        return 0;
    }
    else {
        throw std::runtime_error("Error: Incorrect number of arguments.");
    }
}


/// Function turn an integer into a word
void intToWord(const int &number, std::ostream &outstream = std::cout)
{
    switch (number)
    {
        case 1: outstream << "one\n"; break;
        case 2: outstream << "two\n"; break;
        case 3: outstream << "three\n"; break;
        case 4: outstream << "four\n"; break;
        case 5: outstream << "five\n"; break;
        case 6: outstream << "six\n"; break;

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
    catch (const std::runtime_error &err)
    {
        std::cout << err.what() << '\n';
        return 1;
    }
    catch (const std::invalid_argument&)
    {
        std::cout << "Error: Argument is not an integer.\n";
        return 1;
    }

    return 0;
}


/// Function to test task performing behavior of the program
void testUse()
{
    assert(checkNumArguments(2u) == 0);
    assert(doMain( { "int_to_word", "1" } ) == 0);
    assert(doMain( { "int_to_word", "2" } ) == 0);
    assert(doMain( { "int_to_word", "3" } ) == 0);
    assert(doMain( { "int_to_word", "4" } ) == 0);
    assert(doMain( { "int_to_word", "5" } ) == 0);
    assert(doMain( { "int_to_word", "6" } ) == 0);
}


/// Function to test error handling behavior of the program
void testAbuse()
{
    assert(doMain( { "int_to_word" } ) == 1);
    assert(doMain( { "int_to_word", "1", "2"} ) == 1);
    assert(doMain( { "int_to_word", "7" } ) == 1);
    assert(doMain( { "int_to_word", "nonsense" } ) == 1);
}


/// Function to test the program
void test()
{
    testUse();
    testAbuse();
}


/// Program to convert an integer into its word
int main(int argc, char * argv[])
{
    // Preparation
    const std::vector<std::string> args(argv, argv + argc);

    // Test the program
    test();

    // Run the program
    return doMain(args);

}