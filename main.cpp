/**
 * @file main.cpp
 * @brief Translates numbers into words
 * @author John Wilkes
 */

#include <iostream>
#include <string>
#include "numbertranslator.h"

int main(int argc, char* argv[])
{
    std::string inStr, outStr;

    getline(std::cin, inStr);
    while (inStr != "")
    {
        if (!isNum(inStr))
        {
            std::cout << "You did not enter a valid number.\n";
        }
        else
        {
            inStr = stripLeadingZeros(inStr);
            if (inStr.length() > MAX_PLACES)
            {
                std::cout << "I don't know numbers that high!\n";
            }
            else
            {
                translate(inStr, outStr);
                std::cout << outStr << '\n';
            }
        }

        getline(std::cin, inStr);
    }

    return 0;
}
