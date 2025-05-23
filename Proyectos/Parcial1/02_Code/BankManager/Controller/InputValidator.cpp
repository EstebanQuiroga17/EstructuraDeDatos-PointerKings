#include "../Model/InputValidator.h"
#include <stdexcept>
#include <regex>
using namespace std;


bool InputValidator::isInteger(string input) {
    try {
        regex pattern("^\\d+$");
        if (!regex_match(input, pattern)) {
            throw invalid_argument("No es entero válido.");
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool InputValidator::isFloat(string input) {
    try {
        regex pattern("^\\d*(\\.\\d+)?$");
        size_t dotCount = count(input.begin(), input.end(), '.');
        if (!regex_match(input, pattern) || dotCount > 1) {
            throw invalid_argument("No es float válido.");
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool InputValidator::isEmail(string input) {
    try {
        regex pattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.(com|net|org|gov|edu|edu\.ec|es|info|co|ec)$)");
        if (!regex_match(input, pattern)) {
            throw invalid_argument("No es email válido.");
        }
        return true;
    } catch (...) {
        return false;
    }
}
