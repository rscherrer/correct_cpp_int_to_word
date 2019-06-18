#include <cassert>
#include <string>
#include <vector>
#include <iostream>


/// Function to run the program
int doMain(const std::vector<std::string>& args, std::string &output)
{

    if (args.size() > 2u) {
        output = "Error: Too many arguments.";
        return 1;
    } else if (args.size() < 2u) {
        output = "Error: No arguments were provided.";
        return 1;
    }

    int number;

    try
    {
        number = std::stoi(args[1]);
    }
    catch (std::invalid_argument&)
    {
        output = "Error: The argument is not an integer.";
        return 1;
    }

    switch (number)
    {
        case 1: output = "one"; break;
        case 2: output = "two"; break;
        case 3: output = "three"; break;
        case 4: output = "four"; break;
        case 5: output = "five"; break;
        case 6: output = "six"; break;
        default: {
            output = "Error: Input number must be in range [1, 6].";
            return 1;
        };
    }

    return 0;

}


/// Function to test the task performing behavior of the program
void testUse(const std::vector<std::string> &args, std::string &output)
{
    assert(doMain( { args[0], "1" }, output) == 0);
    assert(output == "one");

    assert(doMain( { args[0], "2" }, output) == 0);
    assert(output == "two");

    assert(doMain( { args[0], "3" }, output) == 0);
    assert(output == "three");

    assert(doMain( { args[0], "4" }, output) == 0);
    assert(output == "four");

    assert(doMain( { args[0], "5" }, output) == 0);
    assert(output == "five");

    assert(doMain( { args[0], "6" }, output) == 0);
    assert(output == "six");
}


/// Function to test the error handling behavior of the program
void testAbuse(const std::vector<std::string> &args, std::string &output)
{
    assert(doMain( { args[0], "7" }, output) == 1);
    assert(output == "Error: Input number must be in range [1, 6].");

    assert(doMain( { args[0], "nonsense" }, output) == 1);
    assert(output == "Error: The argument is not an integer.");

    assert(doMain( { args[0], "1", "2" }, output) == 1);
    assert(output == "Error: Too many arguments.");

    assert(doMain( { args[0] }, output) == 1);
    assert(output == "Error: No arguments were provided.");
}


/// Function to test the program
void test(const std::vector<std::string> &args, std::string &output)
{
    testUse(args, output);
    testAbuse(args, output);
}


/// Program to convert an integer into its word
int main(int argc, char * argv[])
{
    // Preparation
    const std::vector<std::string> args(argv, argv + argc);
    std::string output;

    // Test the program
    test(args, output);

    // Run the program
    const int exitCode = doMain(args, output);
    std::cout << output << '\n';
    return exitCode;
}