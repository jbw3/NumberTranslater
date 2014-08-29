/**
 * @file numbertranslator.cpp
 * @author John Wilkes
 */

#include "numbertranslator.h"

const std::string WORDS[2][10] = 
                                {{"zero", "one", "two", "three", "four", "five", "six", 
                                  "seven", "eight", "nine"},
                                 {"", "", "twenty", "thirty", "forty", "fifty", "sixty", 
                                  "seventy", "eighty", "ninety"}};
const std::string TEENS[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                             "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const std::string ORDERS[] = {"", "thousand", "million", "billion", "trillion", "quadrillion",
                              "quintillion", "sextillion", "septillion", "octillion", "nonillion",
                              "decillion", "undecillion", "duodecillion", "tredecillion",
                              "quattuordecillion", "quindecillion"};

bool isNum(const std::string& str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (str.at(i) < '0' || str.at(i) > '9')
        {
            return false;
        }
    }

    return true;
}

int charToInt(char ch)
{
    return int(ch - '0');
}

std::string stripLeadingZeros(const std::string& str)
{
    int i = 0;
    while (i < str.length() - 1 && str[i] == '0')
    {
        ++i;
    }

    std::string newStr;
    if (i < str.length())
    {
        newStr = str.substr(i);
    }

    return newStr;
}

/**
 * @todo outStr should be appended to
 *
 * @brief Translate a group of three numbers
 * @param [in] inStr a string of digits
 * @param [out] outStr a string of words representing the number passed in
 * @param [in] returnZero whether to return "zero" if inStr is 0
 */
void translateGroup(const std::string& inStr, std::string& outStr, bool returnZero)
{
    char ch;
    bool isTeen = false;
    size_t len = inStr.length();

    outStr.clear();

    if (len == 0 || len > 3)
        return;

    if (len == 3 && inStr.at(len-3) != '0')
    {
        outStr.append(WORDS[0][charToInt(inStr.at(len-3))]);
        outStr.append(" hundred");
    }
    if (len >= 2)
    {
        ch = inStr.at(len-2);
        if (ch == '1')
        {
            isTeen = true;
            if (!outStr.empty())
                outStr.append(" ");
            outStr.append(TEENS[charToInt(inStr.at(len-1))]);
        }
        else if (ch != '0')
        {
            if (!outStr.empty())
                outStr.append(" ");
            outStr.append(WORDS[1][charToInt(ch)]);
        }
    }
    if (len >= 1 && !isTeen)
    {
        ch = inStr.at(len-1);
        if ((len == 1 && returnZero) || ch != '0')
        {
            if (!outStr.empty())
            {
                if (inStr.at(len-2) == '0')
                    outStr.append(" ");
                else
                    outStr.append("-");
            }
            outStr.append(WORDS[0][charToInt(ch)]);
        }
    }
}

void translate(const std::string& inStr, std::string& outStr)
{
    size_t len = inStr.length();
    size_t orderIdx = 0;
    bool displayZero = true;
    std::string temp;

    if (len == 0)
        return;

    size_t idx, sel;
    if (len <= 3)
    {
        idx = 0;
        sel = len;
    }
    else
    {
        idx = len - 3;
        sel = 3;
    }

    outStr.clear();

    bool done = (len == 0);
    while (!done)
    {
        translateGroup(inStr.substr(idx, sel), temp, displayZero);
        if (!temp.empty())
        {
            if (orderIdx > 0)
            {
                temp.append(" ");
                temp.append(ORDERS[orderIdx]);
            }
            if (!outStr.empty())
                temp.append(" ");
            outStr = temp + outStr;
        }

        displayZero = false;
        ++orderIdx;
        if (idx == 0)
        {
            done = true;
        }
        else if (idx < 3)
        {
            sel = idx;
            idx = 0;
        }
        else
        {
            idx -= 3;
        }
    }
}
