/**
 * @file main.cpp
 * @brief Translates numbers into words
 * @author John Wilkes
 */

#include <iostream>
#include <string>

using namespace std;

// ----- Constants -----

const int MAX_PLACES = 3;
const string WORDS[2][10] = 
                           {{"zero", "one", "two", "three", "four", "five", "six", 
                             "seven", "eight", "nine"},
                            {"", "", "twenty", "thirty", "forty", "fifty", "sixty", 
                             "seventy", "eighty", "ninety"}};
const string TEENS[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

// ----- Function Prototypes ------
bool isNum(const string& str);

int charToInt(char ch);

string stripLeadingZeros(string str);

/**
 * @brief Translate a group of three numbers
 * @param [in] inStr a string of digits
 * @param [out] outStr a string of words representing the number passed in
 */
void translateGroup(const string& inStr, string& outStr);

string translate(const string&);

int main()
{
    string inStr, outStr;

    getline(cin, inStr);
    while (inStr != "")
    {
        if (!isNum(inStr))
        {
            cout << "You did not enter a valid number.\n";
        }
        else
        {
            inStr = stripLeadingZeros(inStr);
            if (inStr.length() > MAX_PLACES)
            {
                cout << "I don't know numbers that high!\n";
            }
            else
            {
                translateGroup(inStr, outStr);
                cout << outStr << '\n';
            }
        }

        getline(cin, inStr);
    }

    return 0;
}

bool isNum(const string& str)
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

string stripLeadingZeros(string str)
{
    int i = 0;
    while (i < str.length() - 1 && str[i] == '0')
    {
        ++i;
    }

    if (i < str.length())
    {
        str = str.substr(i);
    }

    return str;
}

void translateGroup(const string& inStr, string& outStr)
{
    char ch;
    bool isTeen = false;
    size_t len = inStr.length();

    outStr.clear();

    if (len == 0 || len > 3)
        return;

    if (len == 3)
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
        if (len == 1 || ch != '0')
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

string translate(const string& str)
{
    int len = str.length();

    string word;

    for (int i = 0; i < len; i++)
    {
        if (i == len - 2 && str[i] == '1')
        {
            word += TEENS[charToInt(str[i+1])];
            break;
        }
        else
        {
            if (str[i] != '0' || len == 1)
            {
                word += WORDS[len-i-1][charToInt(str[i])];
            }
        }
    }

    return word;
}
