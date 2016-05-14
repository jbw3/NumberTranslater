/**
 * @file main.cpp
 * @brief Translates numbers into words
 * @author John Wilkes
 */

#include <iostream>
#include <string>
#include "numbertranslator.h"

void testTranslation(const std::string& number, const std::string& words);

int main(int argc, char* argv[])
{

    std::string inStr, outStr;

    testTranslation("0", "zero");
    testTranslation("1", "one");
    testTranslation("2", "two");
    testTranslation("3", "three");
    testTranslation("4", "four");
    testTranslation("5", "five");
    testTranslation("6", "six");
    testTranslation("7", "seven");
    testTranslation("8", "eight");
    testTranslation("9", "nine");
    testTranslation("10", "ten");
    testTranslation("11", "eleven");
    testTranslation("12", "twelve");
    testTranslation("13", "thirteen");
    testTranslation("14", "fourteen");
    testTranslation("15", "fifteen");
    testTranslation("16", "sixteen");
    testTranslation("17", "seventeen");
    testTranslation("18", "eighteen");
    testTranslation("19", "nineteen");
    testTranslation("20", "twenty");
    testTranslation("21", "twenty-one");
    testTranslation("30", "thirty");
    testTranslation("33", "thirty-three");
    testTranslation("40", "forty");
    testTranslation("45", "forty-five");
    testTranslation("50", "fifty");
    testTranslation("59", "fifty-nine");
    testTranslation("60", "sixty");
    testTranslation("64", "sixty-four");
    testTranslation("70", "seventy");
    testTranslation("75", "seventy-five");
    testTranslation("80", "eighty");
    testTranslation("90", "ninety");
    testTranslation("100", "one hundred");
    testTranslation("256", "two hundred fifty-six");
    testTranslation("1024", "one thousand twenty-four");
    testTranslation("7000", "seven thousand");
    testTranslation("10000", "ten thousand");
    testTranslation("100000", "one hundred thousand");
    testTranslation("480354", "four hundred eighty thousand three hundred fifty-four");
    testTranslation("1000000", "one million");
    testTranslation("49219813", "forty-nine million two hundred nineteen thousand eight hundred thirteen");
    testTranslation("3000000000", "three billion");
    testTranslation("4000000001", "four billion one");
    testTranslation("4000000000000", "four trillion");
    testTranslation("5000000000000000", "five quadrillion");
    testTranslation("8000000000000000000", "eight quintillion");
    testTranslation("18446744073709551616", "eighteen quintillion four hundred forty-six quadrillion seven hundred forty-four trillion seventy-three billion seven hundred nine million five hundred fifty-one thousand six hundred sixteen");
    testTranslation("1000000000000000000000", "one sextillion");
    testTranslation("9000000000000000000000000", "nine septillion");
    testTranslation("545000000070000000000000022", "five hundred forty-five septillion seventy quadrillion twenty-two");
    testTranslation("14000000000000000000000000016", "fourteen octillion sixteen");
    testTranslation("112000000000000000000000000000000", "one hundred twelve nonillion");
    testTranslation("1000000000000000000000000086000000", "one decillion eighty-six million");
    testTranslation("340282366920938463463374607431768211456", "three hundred forty undecillion two hundred eighty-two decillion three hundred sixty-six nonillion nine hundred twenty octillion nine hundred thirty-eight septillion four hundred sixty-three sextillion four hundred sixty-three quintillion three hundred seventy-four quadrillion six hundred seven trillion four hundred thirty-one billion seven hundred sixty-eight million two hundred eleven thousand four hundred fifty-six");
    testTranslation("100000000000000000000000000000000000000000000000000", "one hundred quindecillion");

#if 0
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
#endif

    return 0;
}

void testTranslation(const std::string& number, const std::string& words)
{
    std::string outStr;
    translate(number, outStr);

    if (outStr != words)
    {
        std::cout << "ERROR: " << number << '\n'
                  << outStr << " != " << words << '\n';
    }
}
