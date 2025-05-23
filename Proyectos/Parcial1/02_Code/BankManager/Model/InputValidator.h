#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <regex>

class InputValidator {
public:
    static bool isInteger(std::string input);
    static bool isFloat(std::string input);
    static bool isEmail(std::string input);
};

#endif 

