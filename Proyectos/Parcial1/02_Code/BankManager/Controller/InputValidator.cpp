#include "../Model/InputValidator.h"
#include "../Model/DateValidator.h"
#include "../Model/Date.h"
#include <stdexcept>
#include <regex>
#include <conio.h>
#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

int InputValidator::isInteger(const std::string& mensaje) {
    int value = 0;
    bool ok = false;
    do {
        char c;
        int i = 0;
        char* fact = (char*)malloc(12 * sizeof(char)); 
        printf("%s", mensaje.c_str());
        while ((c = getch()) != 13) { 
            if (c >= '0' && c <= '9') {
                if (i < 11) { 
                    *(fact + i) = c;
                    printf("%c", c);
                    i++;
                }
            } else if (c == 8 && i > 0) {
                i--;
                printf("\b \b");
            }
            
        }
        *(fact + i) = '\0';
        printf("\n");
        try {
            value = std::stoi(fact);
            ok = true;
        } catch (...) {
            printf("Invalido\n");
        }
        free(fact);
    } while (!ok);
    return value;
}

float InputValidator::isFloat(const std::string& mensaje) {
    float value = 0.0f;
    bool ok = false;
    do {
        char c;
        int decimalCount = -1;
        bool dot = false;
        int i = 0;
        char* fact = (char*)malloc(15 * sizeof(char)); 
        printf("%s", mensaje.c_str());
        while ((c = getch()) != 13) { 
            if ((c >= '0' && c <= '9') || c == '.') {
                if (i == 0 && c == '.') continue;
                if (c == 8 && i > 0) {
                i--;
                printf("\b \b");
                continue;
                }
                if (c == '.') {
                    if (dot) continue;
                    dot = true;
                }
                if(dot == true){
                    decimalCount++;
                }
                if(decimalCount > 2) continue; 
                *(fact + i) = c;
                printf("%c", c);
                i++;
            }
        }
        *(fact + i) = '\0';
        printf("\n");
        try {
            value = std::stof(fact);
            ok = true;
        } catch (...) {
            printf("Valor no valido. Intente de nuevo.\n");
        }
        free(fact); 
    } while (!ok);
    return value;
}

string InputValidator::isEmail() {
    string input;
    char ch;
    int atCount = 0;
    int dotCount = 0;
    bool afterAt = false;

    cout << "Email: ";
    while (true) {
        ch = _getch();

        if (ch == 13) {
            size_t atPos = input.find('@');
            size_t dotPos = input.find('.', (atPos != string::npos) ? atPos : 0);
            bool formatoOK =
                atCount == 1 &&
                dotCount == 1 &&
                atPos != string::npos && atPos > 0 &&
                dotPos != string::npos && dotPos > atPos + 1 && dotPos < input.size() - 1;

            if (formatoOK) {
                cout << endl;
                break;
            } else {
                cout << "\nFormato invalido. Ejemplo: nombre@dominio.com\n";
                input.clear();
                atCount = 0;
                dotCount = 0;
                afterAt = false;
                cout << "Email: ";
                continue;
            }
        }
        else if (ch == 8 && !input.empty()) {
            if (input.back() == '@') { atCount--; afterAt = false; dotCount = 0; }
            if (input.back() == '.') { dotCount--; }
            input.pop_back();
            cout << "\b \b";
        }
        else if (ch >= 'a' && ch <= 'z') {
            input += ch;
            cout << ch;
        }
        else if (ch == '@' && atCount == 0 && !input.empty() && input.find('@') == string::npos) {
            input += ch;
            cout << ch;
            atCount = 1;
            afterAt = true;
        }
        else if (ch == '.' && atCount == 1 && dotCount == 0 && input.back() != '@' && input.find('@') != string::npos) {
            input += ch;
            cout << ch;
            dotCount = 1;
        }
        
    }
    return input;
}


string InputValidator::isLetter(const string& mensaje) {
    string input;
    char ch;
    cout << mensaje;
    while (true) {
        ch = _getch();
        if (ch == 13) {
            cout << endl;
            break;
        }
        else if (ch == 8 && !input.empty()) {
            input.pop_back();
            cout << "\b \b";
        }
        else if (
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch == ' ') ||
            (static_cast<unsigned char>(ch) == 165) || // Ñ
            (static_cast<unsigned char>(ch) == 164) || // ñ
            (static_cast<unsigned char>(ch) == 160) || // á
            (static_cast<unsigned char>(ch) == 130) || // é
            (static_cast<unsigned char>(ch) == 161) || // í
            (static_cast<unsigned char>(ch) == 162) || // ó
            (static_cast<unsigned char>(ch) == 163)    // ú
        ) {
            input += ch;
            cout << ch;
        }
    }
    return input;
}

string InputValidator::isDNI() {
    char* dni = (char*)malloc(11 * sizeof(char));
    bool valida = false;

    do {
        int i = 0;
        char c;
        printf("Cedula: ");
        while (true) {
            c = _getch();
            if (c == 13) { 
                if (i == 10) { 
                    break;
                } else {
                    continue;
                }
            } else if (c == 8 && i > 0) { 
                i--;
                printf("\b \b");
            } else if (c >= '0' && c <= '9') {
                if (i < 10) { 
                    *(dni + i) = c;
                    printf("%c", c);
                    i++;
                }
            }

        }
        *(dni + i) = '\0';
        printf("\n");

        regex onlyNumbers("^[0-9]{10}$");
        if (!regex_match(dni, onlyNumbers)) {
            cout << "La cedula debe 10 numeros." << endl;
            continue;
        }

        int add = 0;
        int* weight = (int*)malloc(9 * sizeof(int));
        *(weight + 0) = 2; *(weight + 1) = 1; *(weight + 2) = 2; *(weight + 3) = 1; *(weight + 4) = 2;
        *(weight + 5) = 1; *(weight + 6) = 2; *(weight + 7) = 1; *(weight + 8) = 2;

        int validatorDigit = *(dni + 9) - '0';

        for (int j = 0; j < 9; ++j) {
            int digit = *(dni + j) - '0';
            int mult = digit * (*(weight + j));
            if (mult >= 10) mult -= 9;
            add += mult;
        }

        int resto = add % 10;
        int calculateDigit = (resto == 0) ? 0 : 10 - resto;

        free(weight);

        if (validatorDigit == calculateDigit) {
            valida = true;
        } else {
            cout << "cedula invalida" << endl;
        }

    } while (!valida);

    string result(dni);
    free(dni);
    return result;
}

Date InputValidator::pedirFechaNacimiento() {
    int day, month, year;
    bool validatorDate = false;
    do {
        year = InputValidator::isInteger("Anio de nacimiento (ej: 2001): ");
        month = InputValidator::isInteger("Mes de nacimiento (1-12): ");
        int diasMes = DateValidator::monthDays(month, year);
        day = InputValidator::isInteger("Dia de nacimiento: ");
        validatorDate = DateValidator::validateDay(day, diasMes);

        if (!validatorDate) {
            cout << "Fecha invalida. Intente de nuevo." << endl;
            continue;
        }

        Date hoy = Date::localDate();

        int edad = hoy.getYear().getYear() - year;
        if (edad > 100) {
            cout << "La edad no puede ser mayor a 100 anios. Intente de nuevo." << endl;
            validatorDate = false;
            continue;
        }
        if (year > hoy.getYear().getYear() ||
            (year == hoy.getYear().getYear() && month > hoy.getMonth()) ||
            (year == hoy.getYear().getYear() && month == hoy.getMonth() && day > hoy.getDay())) {
            cout << "No puede ingresar una fecha futura. Intente de nuevo." << endl;
            validatorDate = false;
            continue;
        }
        edad = hoy.getYear().getYear() - year;
        if (hoy.getMonth() < month || (hoy.getMonth() == month && hoy.getDay() < day)) {
            edad--;
        }

        if (edad < 18) {
            cout << "Debe ser mayor de 18 anios" << endl;
            validatorDate = false;
            continue;
        }

        cout << "Su edad es: " << edad << " anios." << endl;

    } while (!validatorDate);

    return Date(day, month, year);
}
