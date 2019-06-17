#include <cassert>
#include <string>
#include <vector>
#include <iostream>

/// Perform the main task
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

        switch (i)
        {
            case 1: std::cout << "one\n"; break;
            case 2: std::cout << "two\n"; break;
            case 3: std::cout << "three\n"; break;
            case 4: std::cout << "four\n"; break;
            case 5: std::cout << "five\n"; break;
            case 6: std::cout << "six\n"; break;

            default: throw std::runtime_error("Input number must be in range [1, 6].");
        }
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

/// Program that converts a number into its word
int main(int argc, char * argv[])
{

    const std::vector<std::string> args(argv, argv + argc);

    const std::string programName(args[0]);

    assert(doMain( { programName } ) == 1);
    assert(doMain( { programName, "1" } ) == 0);
    assert(doMain( { programName, "2" } ) == 0);
    assert(doMain( { programName, "3" } ) == 0);
    assert(doMain( { programName, "4" } ) == 0);
    assert(doMain( { programName, "5" } ) == 0);
    assert(doMain( { programName, "6" } ) == 0);
    assert(doMain( { programName, "nonsense" } ) == 1);
    assert(doMain( { programName, "1", "2" } ) == 1);

    return doMain(args);

}