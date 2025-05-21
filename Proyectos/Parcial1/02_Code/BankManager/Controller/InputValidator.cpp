#include "../Model/InputValidator.h"
#include <stdexcept>
#include <algorithm>


bool InputValidator::isInteger(std::string input) {
    try {
        std::regex pattern("^\\d+$");
        if (!std::regex_match(input, pattern)) {
            throw std::invalid_argument("El valor ingresado no es un número entero válido.");
        }
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

bool InputValidator::isFloat(std::string input) {
    try {
        std::regex pattern("^\\d*(\\.\\d+)?$");
        size_t dotCount = std::count(input.begin(), input.end(), '.');
        if (!std::regex_match(input, pattern) || dotCount > 1) {
            throw std::invalid_argument("El valor ingresado no es un número flotante válido.");
        }
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

bool InputValidator::isEmail(std::string input) {
    try {
        std::regex pattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.(com|net|org|gov|edu|edu\.ec|es|info|co|ec)$)");
        if (!std::regex_match(input, pattern)) {
            throw std::invalid_argument("El valor ingresado no es un correo electrónico válido.");
        }
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}