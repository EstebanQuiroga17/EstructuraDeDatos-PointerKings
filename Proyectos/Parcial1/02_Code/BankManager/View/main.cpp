#include <iostream>
#include "../Model/InputValidator.h"



using namespace std;

int main(){
    std::string input;
    std::cout << "Ingrese un número para validar si es float: ";
    std::cin >> input;

    bool esFloat = InputValidator::isFloat(input);
    std::cout << "Es float válido? " << (esFloat ? "Sí" : "No") << std::endl;

    return 0;
}