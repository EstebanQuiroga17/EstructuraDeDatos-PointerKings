#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <regex>

class InputValidator {
public:
    //static int isInteger(std::string input);
    //static float isFloat(std::string input);
    //static bool isEmail(std::string input);
    int InputValidator::isInteger(const std::string& mensaje);
    float InputValidator::isFloat(const std::string& mensaje);
    string InputValidator::isEmail();
    string InputValidator::isLetter(const string& mensaje);
    Date InputValidator::pedirFechaNacimiento();
    string InputValidator::isDNI();
};

#endif 

