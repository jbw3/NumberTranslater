/**
 * @file main.cpp
 * @brief Translates numbers into words
 * @author John Wilkes
 */

#include <iostream>
#include <string>

using namespace std;

const int MAX_PLACES = 2;
const string WORDS[MAX_PLACES][10] = 
                           {{"zero", "one", "two", "three", "four", "five", "six", 
                             "seven", "eight", "nine"},
                            {"", "", "twenty", "thirty", "forty", "fifty", "sixty", 
                             "seventy", "eighty", "ninety"}};
const string TEENS[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

// function prototypes
bool isNum(const string& str);
int charToInt(const char&);
string stripLeadingZeros(string str);
string translate(const string&);

int main()
{
    string str;

    getline(cin, str);
    while (str != "")
    {
        if (!isNum(str))
        {
            cout << "Not a number.\n";
        }
        else
        {
            if (str.length() > MAX_PLACES)
                cout << "I don't know numbers that high!\n";
            else
                cout << translate(str) << endl;
        }

        getline(cin, str);
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

int charToint(const char& ch)
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

/**
 * @brief Translate a group of three numbers
 * @param str a string of digits
 * @return a string of words representing the number passed in
 */
//string translateGroup(const string& str)
//{
//    if ()
//}

string translate(const string& str)
{
    int len = str.length();

    if (len > MAX_PLACES)
        return "I don't know numbers that high!";

    string word;

    for (int i = 0; i < len; i++)
    {
        if (i == len - 2 && str[i] == '1')
        {
            word += TEENS[charToint(str[i+1])];
            break;
        }
        else
        {
            if (str[i] != '0' || len == 1)
            {
                word += WORDS[len-i-1][charToint(str[i])];
            }
        }
    }

    return word;
}
