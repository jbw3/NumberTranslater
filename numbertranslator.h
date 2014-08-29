/**
 * @file numbertranslator.h
 * @author John Wilkes
 */

#ifndef NUMBER_TRANSLATOR_H
#define NUMBER_TRANSLATOR_H

#include <string>

const unsigned int MAX_PLACES = 51;

bool isNum(const std::string& str);

std::string stripLeadingZeros(const std::string& str);

void translate(const std::string& inStr, std::string& outStr);

#endif // NUMBER_TRANSLATOR_H
