#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <regex>
#include "Date.h"

class InputValidator {
public:
    //static int isInteger(std::string input);
    //static float isFloat(std::string input);
    //static bool isEmail(std::string input);
    int isInteger(const std::string& mensaje);
    float isFloat(const std::string& mensaje);
    std::string isEmail();
    std::string isLetter(const std::string& mensaje);
    Date pedirFechaNacimiento();
    std::string isDNI(); 
};

#endif 

