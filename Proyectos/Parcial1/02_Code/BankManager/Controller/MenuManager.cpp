#include "MenuManager.h"
#include "CursorMenu.h" // Cambia según dónde esté tu clase de menú con cursores
#include "InputValidator.h" // Cambia según dónde esté tu clase de menú con cursores
#include <iostream>
#include <cstdlib>


using std::string;
using std::vector;
using std::cout;
using std::cin;

int MenuManager::mostrarMenuPrincipal() {
    CursorMenu menu;
    menu.loadOptions({
        "Crear usuario",
        "Login",
        "Menu de ayuda",
        "Mostrar usuarios",
        "Crear backup",
        "Restaurar backup",
        "Salir"
    });
    return menu.runMenuLoopReturnIndex();
}

char MenuManager::menuTipoCuenta() {
    CursorMenu menu;
    menu.loadOptions({
        "Cuenta de Ahorros",
        "Cuenta Corriente",
        "Ambas cuentas (Ahorros y Corriente)",
        "Cancelar"
    });
    int seleccion = menu.runMenuLoopReturnIndex();
    switch (seleccion) {
        case 0: return 's'; // Solo ahorros
        case 1: return 'c'; // Solo corriente
        case 2: return 'a'; // Ambas cuentas
        default: return 'x'; // Cancelar
    }
}

int MenuManager::menuOperacionBancaria() {
    CursorMenu menu;
    menu.loadOptions({
        "Depósito",
        "Retiro",
        "Volver"
    });
    int seleccion = menu.runMenuLoopReturnIndex();
    return seleccion;
}

void MenuManager::menuOperations(UserManager& gestor, User* usuario, char tipoCuenta) {
    InputValidator validator;
    bool volver = false;

    // Puedes mostrar el tipo de cuenta al usuario, si quieres
    std::string tipoCuentaStr = (tipoCuenta == 's') ? "Ahorros" : "Corriente";

    while (!volver) {
        system("cls");
        std::cout << "=== Operaciones Bancarias (" << tipoCuentaStr << ") ===\n";
        int op = MenuManager::menuOperacionBancaria();

        switch (op) {
            case 0: { // Depósito
                float monto;
                do {
                    monto = validator.isFloat("\nIngrese monto a depositar: ");
                    if (monto <= 0) std::cout << "El monto debe ser mayor que 0.\n";
                } while (monto <= 0);

                Date fecha = Date::localDate();
                gestor.deposit(usuario, monto, tipoCuenta, fecha);
                system("pause");
                break;
            }
            case 1: { // Retiro
                float monto;
                do {
                    monto = validator.isFloat("\nIngrese monto a retirar: ");
                    if (monto <= 0) std::cout << "El monto debe ser mayor que 0.\n";
                } while (monto <= 0);

                Date fecha = Date::localDate();
                gestor.withdraw(usuario, monto, tipoCuenta, fecha);
                system("pause");
                break;
            }
            case 2:
                volver = true;
                break;
        }
    }
}

