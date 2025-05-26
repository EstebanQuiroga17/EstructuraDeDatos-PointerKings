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
        while ((c = getch()) != 13) { // Enter para finalizar
            if (c >= '0' && c <= '9') {
                if (i < 11) { // Evita desbordamiento (máximo 11 dígitos más '\0')
                    *(fact + i) = c;
                    printf("%c", c);
                    i++;
                }
            } else if (c == 8 && i > 0) { // Backspace
                i--;
                printf("\b \b");
            }
            // Ignora cualquier otro carácter
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
    string input;
    char ch;
    int atCount = 0;
    int dotCount = 0;
    bool afterAt = false;

    cout << "Email: ";
    while (true) {
        ch = _getch();

        // ENTER: validar formato
        if (ch == 13) {
            // Validar: exactamente 1 arroba, 1 punto después del arroba, no al inicio/fin
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
                cout << "\nFormato inválido. Ejemplo: nombre@dominio.com\n";
                input.clear();
                atCount = 0;
                dotCount = 0;
                afterAt = false;
                cout << "Email: ";
                continue;
            }
        }
        // BACKSPACE
        else if (ch == 8 && !input.empty()) {
            if (input.back() == '@') { atCount--; afterAt = false; dotCount = 0; }
            if (input.back() == '.') { dotCount--; }
            input.pop_back();
            cout << "\b \b";
        }
        // Minúsculas
        else if (ch >= 'a' && ch <= 'z') {
            input += ch;
            cout << ch;
        }
        // Un solo @, no al inicio
        else if (ch == '@' && atCount == 0 && !input.empty() && input.find('@') == string::npos) {
            input += ch;
            cout << ch;
            atCount = 1;
            afterAt = true;
        }
        // Un solo punto, solo después de @, no inmediatamente después del @, no al final
        else if (ch == '.' && atCount == 1 && dotCount == 0 && input.back() != '@' && input.find('@') != string::npos) {
            input += ch;
            cout << ch;
            dotCount = 1;
        }
        // Todo lo demás se ignora
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
    char* dni = (char*)malloc(11 * sizeof(char)); // 10 dígitos + '\0'
    bool valida = false;

    do {
        int i = 0;
        char c;
        printf("Cedula: ");
        // Captura carácter a carácter
        while (true) {
            c = _getch();
            if (c == 13) { // Enter
                if (i == 10) { // Solo permite finalizar si hay 10 dígitos
                    break;
                } else {
                    // No hace nada si se presiona enter antes de los 10
                    continue;
                }
            } else if (c == 8 && i > 0) { // Backspace
                i--;
                printf("\b \b");
            } else if (c >= '0' && c <= '9') {
                if (i < 10) { // Solo permite hasta 10 dígitos
                    *(dni + i) = c;
                    printf("%c", c);
                    i++;
                }
                // Si son 10, ignora números extra
            }
            // Ignora otros caracteres
        }
        *(dni + i) = '\0'; // Fin de cadena
        printf("\n");

        // Validación del formato con regex
        regex onlyNumbers("^[0-9]{10}$");
        if (!regex_match(dni, onlyNumbers)) {
            cout << "La cedula debe 10 numeros." << endl;
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
            cout << "cedula invalida" << endl;
        }

    } while (!valida);

    string result(dni); // Convertir a std::string antes de liberar memoria
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

        // Recalcula edad exacta
        edad = hoy.getYear().getYear() - year;
        if (hoy.getMonth() < month || (hoy.getMonth() == month && hoy.getDay() < day)) {
            edad--;
        }

        cout << "Su edad es: " << edad << " anios." << endl;

    } while (!validatorDate);

    return Date(day, month, year);
}
