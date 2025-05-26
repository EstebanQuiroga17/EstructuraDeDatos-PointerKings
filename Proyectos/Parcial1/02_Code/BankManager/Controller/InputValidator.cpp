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
        char* fact = (char*)malloc(12 * sizeof(char)); // Reserva dinámica, sin []
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
            printf("value no válido. Intente de nuevo.\n");
        }
        free(fact); // Libera memoria reservada
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
        char* fact = (char*)malloc(15 * sizeof(char)); // Solo punteros, sin []
        printf("%s", mensaje.c_str());
        while ((c = getch()) != 13) { // Mientras no se presione ENTER
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
            printf("Valor no válido. Intente de nuevo.\n");
        }
        free(fact); // Libera la memoria dinámica
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
            cout << "Email inválido. Intente de nuevo." << endl;
        } else {
            valido = true;
        }
    } while (!valido);
    return email;
}

string InputValidator::isLetter(const string& mensaje) {
    string input;
    regex onlyLetter("^[A-Za-záéíóúÁÉÍÓÚñÑ ]+$");
    do {
        cout << mensaje;
        getline(cin, input);
        if (!regex_match(input, onlyLetter)) {
            cout << "Solo se permiten letras. Intente de nuevo." << endl;
        }
    } while (!regex_match(input, onlyLetter));
    return input;
}

string InputValidator::isDNI() {
    string dni;
    regex onlyNumbers("^[0-9]{10}$");
    bool valida = false;

    do {
        cout << "Cédula (10 dígitos): ";
        cin >> dni;

        if (!regex_match(dni, onlyNumbers)) {
            cout << "La cédula debe ser numérica y de 10 dígitos." << endl;
            continue;
        }

        int add = 0;
        int* weight = (int*)malloc(9 * sizeof(int));
        *(weight + 0) = 2; *(weight + 1) = 1; *(weight + 2) = 2; *(weight + 3) = 1; *(weight + 4) = 2;
        *(weight + 5) = 1; *(weight + 6) = 2; *(weight + 7) = 1; *(weight + 8) = 2;

        const char* ptr = dni.c_str();
        int validatorDigit = *(ptr + 9) - '0';

        for (int i = 0; i < 9; ++i) {
            int digit = *(ptr + i) - '0';             
            int mult = digit * (*(weight + i));
            if (mult >= 10) mult -= 9;
            add += mult;
        }

        int resto = add % 10;
        int calculateDigit = (resto == 0) ? 0 : 10 - resto;

        free(weight); // Liberar memoria dinámica

        if (validatorDigit == calculateDigit) {
            valida = true;
        } else {
            cout << "Cédula ecuatoriana inválida (dígito verificador incorrecto)." << endl;
        }

    } while (!valida);

    return dni;
}

// Pide y valida fecha de nacimiento (usa DateValidator)
Date InputValidator::pedirFechaNacimiento() {
    int day, month, year;
    bool validatorDate = false;
    do {
        year = InputValidator::isInteger("Año de nacimiento (ej: 2001): ");
        month = InputValidator::isInteger("Mes de nacimiento (1-12): ");
        int diasMes = DateValidator::monthDays(month, year);
        day = InputValidator::isInteger("Día de nacimiento: ");
        validatorDate = DateValidator::validateDay(day, diasMes);

        // Validar fecha válida
        if (!validatorDate) {
            cout << "Fecha inválida. Intente de nuevo." << endl;
            continue;
        }

        // Obtener fecha actual
        Date hoy = Date::localDate();

        // Validar rango de años
        int edad = hoy.getYear().getYear() - year;
        if (edad > 100) {
            cout << "La edad no puede ser mayor a 100 años. Intente de nuevo." << endl;
            validatorDate = false;
            continue;
        }

        // Validar que la fecha de nacimiento no sea futura
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

        cout << "Su edad es: " << edad << " años." << endl;

    } while (!validatorDate);

    return Date(day, month, year);
}
