#include "../Model/InputValidator.h"
#include "../Model/DateValidator.h"
#include "../Model/Date.h"
#include <stdexcept>
#include <regex>
#include <conio.h>
#include <iostream>
#include <string>
#include <cstdlib> // Para system("cls") y system("pause")
using namespace std;


int InputValidator::isInteger(const std::string& mensaje) {
    int value = 0;
    bool ok = false;
    do {
        value = 0;
        char c;
        int i = 0;
        char* fact = (char*)malloc(12 * sizeof(char)); 
        printf("%s", mensaje.c_str());
        while ((c = getch()) != 13) {
            if (c >= '0' && c <= '9') {
                *(fact + i) = c;
                printf("%c", c);
                i++;
            }
        }
        *(fact + i) = '\0';
        printf("\n");
        try {
            value = std::stoi(fact);
            ok = true;
        } catch (...) {
            printf("value no valido. Intente de nuevo.\n");
        }
        free(fact);
    } while (!ok);
    return value;
}

float InputValidator::isFloat(const std::string& mensaje) {
    float value = 0.0f;
    bool ok = false;
    do {
        value = 0.0f;
        char c;
        bool dot = false;
        int i = 0;
        char* fact = (char*)malloc(15 * sizeof(char)); 
        printf("%s", mensaje.c_str());
        while ((c = getch()) != 13) { 
            if ((c >= '0' && c <= '9') || c == '.') {
                if (i == 0 && c == '.') continue;
                if (c == '.') {
                    if (dot) continue;
                    dot = true;
                }
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
    string email;
    regex pattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.(com|net|org|gov|edu|edu\.ec|es|info|co|ec)$)");
    bool valido = false;
    do {
        cout << "Email: ";
        cin >> email;
        if (!regex_match(email, pattern)) {
            cout << "Email invalido. Intente de nuevo." << endl;
        } else {
            valido = true;
        }
    } while (!valido);
    return email;
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
    char* dni = (char*)malloc(11 * sizeof(char)); // 10 dígitos + '\0'
    bool valida = false;

    do {
        int i = 0;
        char c;
        printf("Cédula (10 dígitos): ");
        // Entrada caracter a caracter
        while (i < 10) {
            c = _getch();
            if (c >= '0' && c <= '9') {
                *(dni + i) = c;
                printf("%c", c); // Mostrar
                i++;
            } else if (c == 8 && i > 0) { // Backspace
                i--;
                printf("\b \b");
            }
            // Ignora todo lo que no sea número o backspace
        }
        *(dni + i) = '\0'; // Fin de cadena
        printf("\n");

        // Validación del formato con regex
        regex onlyNumbers("^[0-9]{10}$");
        if (!regex_match(dni, onlyNumbers)) {
            cout << "La cedula debe ser numerica y de 10 digitos." << endl;
            continue;
        }

        // Validación de dígito verificador (como tu función original)
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
            cout << "Cédula invalida." << endl;
        }

    } while (!valida);

    string result(dni);
    free(dni);
    return result;
}


// string InputValidator::isDNI() {
//     string dni;
//     regex onlyNumbers("^[0-9]{10}$");
//     bool valida = false;

//     do {
//         cout << "Cedula (10 digitos): ";
//         cin >> dni;

//         if (!regex_match(dni, onlyNumbers)) {
//             cout << "La cedula debe ser numerica y de 10 digitos." << endl;
//             continue;
//         }

//         int add = 0;
//         int* weight = (int*)malloc(9 * sizeof(int));
//         *(weight + 0) = 2; *(weight + 1) = 1; *(weight + 2) = 2; *(weight + 3) = 1; *(weight + 4) = 2;
//         *(weight + 5) = 1; *(weight + 6) = 2; *(weight + 7) = 1; *(weight + 8) = 2;

//         const char* ptr = dni.c_str();
//         int validatorDigit = *(ptr + 9) - '0';

//         for (int i = 0; i < 9; ++i) {
//             int digit = *(ptr + i) - '0';             
//             int mult = digit * (*(weight + i));
//             if (mult >= 10) mult -= 9;
//             add += mult;
//         }

//         int resto = add % 10;
//         int calculateDigit = (resto == 0) ? 0 : 10 - resto;

//         free(weight); 

//         if (validatorDigit == calculateDigit) {
//             valida = true;
//         } else {
//             cout << "Cedula ecuatoriana invalida (digito verificador incorrecto)." << endl;
//         }

//     } while (!valida);

//     return dni;
// }

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

        // Recalcula edad exacta
        edad = hoy.getYear().getYear() - year;
        if (hoy.getMonth() < month || (hoy.getMonth() == month && hoy.getDay() < day)) {
            edad--;
        }

        cout << "Su edad es: " << edad << " anios." << endl;

    } while (!validatorDate);

    return Date(day, month, year);
}
