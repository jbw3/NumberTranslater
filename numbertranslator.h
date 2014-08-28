/**
 * @file numbertranslator.h
 * @author John Wilkes
 */

#ifndef NUMBER_TRANSLATOR_H
#define NUMBER_TRANSLATOR_H

#include <string>

const unsigned int MAX_PLACES = 51;

bool isNum(const std::string& str);

int charToInt(char ch);

std::string stripLeadingZeros(const std::string& str);

/**
 * @brief Translate a group of three numbers
 * @param [in] inStr a string of digits
 * @param [out] outStr a string of words representing the number passed in
 * @param [in] returnZero whether to return "zero" if inStr is 0
 */
void translateGroup(const std::string& inStr, std::string& outStr, bool returnZero);

void translate(const std::string& inStr, std::string& outStr);

#endif // NUMBER_TRANSLATOR_H
