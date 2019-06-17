#include <cassert>
#include <string>
#include <vector>
#include <iostream>

/// Perform the main task and output to screen
int doMain(const std::vector<std::string>& args)
{
    const size_t argc = args.size();
    try
    {
        if (argc != 2)
        {
            throw std::runtime_error("Exactly one argument must be provided.");
        }

        const int i{std::stoi(args[1])};

        std::string output;

        switch (i)
        {
            case 1: output = "one"; break;
            case 2: output = "two"; break;
            case 3: output = "three"; break;
            case 4: output = "four"; break;
            case 5: output = "five"; break;
            case 6: output = "six"; break;

            default: throw std::runtime_error("Input number must be in range [1, 6].");
        }

        std::cout << output << '\n';

    }
    catch (const std::runtime_error& err)
    {
        std::cout << err.what() << '\n';
        return 1;
    }
    catch (const std::invalid_argument& err)
    {
        std::cout << "Argument is not a number.\n";
        return 1;
    }

    return 0;
}

/// Perform the main task, test version without printed output
int doMainNoPrint(const std::vector<std::string>& args)
{
    const size_t argc = args.size();
    try
    {
        if (argc != 2)
        {
            throw std::runtime_error("Exactly one argument must be provided.");
        }

        const int i{std::stoi(args[1])};

        std::string output;

        switch (i)
        {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;

            default: throw std::runtime_error("Input number must be in range [1, 6].");
        }

    }
    catch (const std::exception&)
    {
        return 1;
    }

    return 0;
}

/// Function to test the program
void test(const std::vector<std::string> &args)
{

    const std::string programName(args[0]);

    assert(doMainNoPrint( { programName } ) == 1);
    assert(doMainNoPrint( { programName, "1" } ) == 0);
    assert(doMainNoPrint( { programName, "2" } ) == 0);
    assert(doMainNoPrint( { programName, "3" } ) == 0);
    assert(doMainNoPrint( { programName, "4" } ) == 0);
    assert(doMainNoPrint( { programName, "5" } ) == 0);
    assert(doMainNoPrint( { programName, "6" } ) == 0);
    assert(doMainNoPrint( { programName, "nonsense" } ) == 1);
    assert(doMainNoPrint( { programName, "1", "2" } ) == 1);
    assert(doMainNoPrint( { programName, "7" } ) == 1);
}

/// Program that converts a number into its word
int main(int argc, char * argv[])
{

    const std::vector<std::string> args(argv, argv + argc);

    // Test the program
    test(args);

    // Run the program
    return doMain(args);

}