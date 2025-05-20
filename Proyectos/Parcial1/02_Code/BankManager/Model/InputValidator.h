#pragma once
#include <string>
#include <regex>
using namespace std;

class InputValidator
{
public:
    static bool isInteger(string input);
    static bool isFloat(string input);
    static bool isEmail(string input);
};

