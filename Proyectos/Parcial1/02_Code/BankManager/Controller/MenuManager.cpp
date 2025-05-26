#include "MenuManager.h"
#include "CursorMenu.h" // Cambia según dónde esté tu clase de menú con cursores
#include "InputValidator.h" // Cambia según dónde esté tu clase de menú con cursores
#include <iostream>
#include <cstdlib>
#include <conio.h>


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
        "Consultar movimientos",
        "Crear backup",
        "Restaurar backup",
        "Modificacion de usuarios",
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

int MenuManager::menuQueryMovements() {
    CursorMenu menu;
    menu.loadOptions({
        "Consultar por rango de fechas",
        "Consultar por nombre y DNI",
        "Consultar por monto mínimo",
        "Volver"
    });
    int seleccion = menu.runMenuLoopReturnIndex();
    return seleccion;
}

void MenuManager::showMovementsQueryMenu(UserManager& manager) {
    InputValidator validator;
    bool back = false;

    while (!back) {
        system("cls");
        std::cout << "==== CONSULTA DE MOVIMIENTOS ====" << std::endl;
        int option = MenuManager::menuQueryMovements();

        switch (option) {
            case 0: { // Rango de fechas
                int y1, m1, d1, y2, m2, d2;
                std::cout << "Fecha de inicio (AAAA MM DD): ";
                std::cin >> y1 >> m1 >> d1;
                std::cout << "Fecha de fin (AAAA MM DD): ";
                std::cin >> y2 >> m2 >> d2;
                Date from(y1, m1, d1), to(y2, m2, d2);

                manager.queryMovements([&]( BankMovement& mov) {
                    return mov.getDate() >= from && mov.getDate() <= to;
                });
                system("pause");
                break;
            }
            case 1: { // Nombre y DNI
                std::string name, dni;
                std::cout << "Ingrese el nombre: ";
                std::cin.ignore(); // Limpia el buffer
                std::getline(std::cin, name);
                std::cout << "Ingrese el DNI: ";
                std::getline(std::cin, dni);
                manager.queryMovements([&]( BankMovement& mov) {
                    return mov.getUser()->getPersonalData().getName() == name &&
                           mov.getUser()->getPersonalData().getDNI() == dni;
                });
                system("pause");
                break;
            }
            case 2: { // Monto mínimo
                float minAmount;
                std::cout << "Ingrese el monto mínimo: ";
                std::cin >> minAmount;
                manager.queryMovements([&]( BankMovement& mov) {
                    return mov.getAmmount() >= minAmount;
                });
                system("pause");
                break;
            }
            case 3: // Volver
                back = true;
                break;
        }
    }
}

int MenuManager::menuModifyUser() {
    CursorMenu menu;
    menu.loadOptions({
        "Modificar usuario",
        "Eliminar usuario",
        "Volver"
    });
    int seleccion = menu.runMenuLoopReturnIndex();
    return seleccion;
}

void MenuManager::showModifyUserMenu(UserManager& manager) {
    bool back = false;
    while (!back) {
        system("cls");
        std::cout << "==== MODIFICAR / ELIMINAR USUARIO ====" << std::endl;
        int option = MenuManager::menuModifyUser();

        switch (option) {
            case 0: // Modificar usuario
                //manager.modificarUsuario();
                system("pause");
                break;
            case 1: // Eliminar usuario
                manager.eliminarUsuario();
                system("pause");
                break;
            case 2: // Volver
                back = true;
                break;
        }
    }
}

