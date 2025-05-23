#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <regex>

class InputValidator {
public:
    static int isInteger(std::string input);
    static float isFloat(std::string input);
    static bool isEmail(std::string input);
};

#endif 

