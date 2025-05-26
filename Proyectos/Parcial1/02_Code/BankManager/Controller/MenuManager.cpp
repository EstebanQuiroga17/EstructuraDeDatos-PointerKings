#include "../Model/MenuManager.h"
#include "../Model/CursorMenu.h"  
#include "../Model/InputValidator.h" 
#include <iostream>
#include <cstdlib>
#include <conio.h>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int MenuManager::mostrarMenuPrincipal()
{
    CursorMenu menu;
    menu.loadOptions({"Crear usuario",
                      "Login",
                      "Menu de ayuda",
                      "Mostrar usuarios",
                      "Consultar movimientos",
                      "Crear backup",
                      "Restaurar backup",
                      "Modificacion de usuarios",
                      "Salir"});
    return menu.runMenuLoopReturnIndex();
}

char MenuManager::menuTipoCuenta()
{
    CursorMenu menu;
    menu.loadOptions({"Cuenta de Ahorros",
                      "Cuenta Corriente",
                      "Ambas cuentas (Ahorros y Corriente)",
                      "Cancelar"});
    int seleccion = menu.runMenuLoopReturnIndex();
    switch (seleccion)
    {
    case 0:
        return 's'; // Solo ahorros
    case 1:
        return 'c'; // Solo corriente
    case 2:
        return 'a'; // Ambas cuentas
    default:
        return 'x'; // Cancelar
    }
}

int MenuManager::menuUpdateUser()
{
    CursorMenu menu;
    menu.loadOptions({"Modificar nombre y apellido",
                      "Modificar cedula",
                      "Modificar fecha de nacimiento",
                      "Modificar email",
                      "Modificar tipos de cuentas",
                      "Volver"});
    int seleccion = menu.runMenuLoopReturnIndex();
    return seleccion;
}

int MenuManager::menuOperacionBancaria()
{
    CursorMenu menu;
    menu.loadOptions({"Deposito",
                      "Retiro",
                      "Volver"});
    int seleccion = menu.runMenuLoopReturnIndex();
    return seleccion;
}

void MenuManager::menuOperations(UserManager &gestor, User *usuario, char tipoCuenta)
{
    InputValidator validator;
    bool volver = false;

    std::string tipoCuentaStr = (tipoCuenta == 's') ? "Ahorros" : "Corriente";

    while (!volver)
    {
        system("cls");
        std::cout << "=== Operaciones Bancarias (" << tipoCuentaStr << ") ===\n";
        int op = MenuManager::menuOperacionBancaria();

        switch (op)
        {
        case 0:
        { // Depósito
            float monto;
            do
            {
                monto = validator.isFloat("\nIngrese monto a depositar: ");
                if (monto <= 0)
                    std::cout << "El monto debe ser mayor que 0.\n";
            } while (monto <= 0);

            Date fecha = Date::localDate();
            gestor.deposit(usuario, monto, tipoCuenta, fecha);
            gestor.saveUsers();
            system("pause");
            break;
        }
        case 1:
        { // Retiro
            float monto;
            do
            {
                monto = validator.isFloat("\nIngrese monto a retirar: ");
                if (monto <= 0)
                    std::cout << "El monto debe ser mayor que 0.\n";
            } while (monto <= 0);

            Date fecha = Date::localDate();
            gestor.withdraw(usuario, monto, tipoCuenta, fecha);
            gestor.saveUsers();
            system("pause");
            break;
        }
        case 2:
            volver = true;
            break;
        }
    }
}

void MenuManager::printMovementsResults(const std::vector<BankMovement*>& results) {
    if (results.empty()) {
        std::cout << "No movements found with that criteria.\n";
        return;
    }
    std::cout << "\n=== Resultados de la consulta ===\n";
    for (auto& mov : results) {
        mov->printReceipt();
        std::cout << "------------------------------\n";
    }
}


int MenuManager::menuQueryMovements()
{
    CursorMenu menu;
    menu.loadOptions({"Consultar por rango de fechas",
                      "Consultar por nombre y DNI",
                      "Consultar por monto minimo",
                      "Volver"});
    int seleccion = menu.runMenuLoopReturnIndex();
    return seleccion;
}

void MenuManager::showMovementsQueryMenu(UserManager &manager)
{
    InputValidator validator;
    bool back = false;

    while (!back)
    {
        system("cls");
        std::cout << "==== CONSULTA DE MOVIMIENTOS ====" << std::endl;
        int option = MenuManager::menuQueryMovements();

        switch (option)
        {
        case 0:
        { // Rango de fechas
            int y1, m1, d1, y2, m2, d2;
            std::cout << "Fecha de inicio (AAAA MM DD): ";
            std::cin >> y1 >> m1 >> d1;
            std::cout << "Fecha de fin (AAAA MM DD): ";
            std::cin >> y2 >> m2 >> d2;
            Date from(y1, m1, d1), to(y2, m2, d2);

            std::vector<BankMovement *> results; // <<< corregido
            manager.queryMovements([&](BankMovement &mov)
                                   { return mov.getDate() >= from && mov.getDate() <= to; }, results);

            printMovementsResults(results);

            std::cout << "Presione Enter para continuar . . .";
            std::cin.ignore();
            std::cin.get();
            break;
        }

        case 1:
        { // Nombre y DNI
            std::string name, dni;
            std::cout << "Ingrese el nombre: ";
            std::cin.ignore(); // Limpia el buffer
            std::getline(std::cin, name);
            std::cout << "Ingrese el DNI: ";
            std::getline(std::cin, dni);

            std::vector<BankMovement *> results; // <<< corregido
            manager.queryMovements([&](BankMovement &mov)
                                   {
                                       // Aquí tu filtro real:
                                       // return mov.getUserDNI() == dni; // ejemplo
                                       std::cout << "[DEBUG] Movimiento encontrado: DNI=" << mov.getUserDNI() << std::endl;
                                       return true;
                                   },
                                   results);

            printMovementsResults(results);

            std::cout << "Presione Enter para continuar . . .";
            std::cin.ignore();
            std::cin.get();
            break;
        }

        case 2:
        { // Monto mínimo
            float minAmount;
            std::cout << "Ingrese el monto minimo: ";
            std::cin >> minAmount;

            std::vector<BankMovement *> results; // <<< corregido
            manager.queryMovements([&](BankMovement &mov)
                                   { return mov.getAmmount() >= minAmount; }, results);

            printMovementsResults(results);

            std::cout << "Presione Enter para continuar . . .";
            std::cin.ignore();
            std::cin.get();
            break;
        }

        case 3: // Volver
            back = true;
            break;
        }
    }
}

int MenuManager::menuModifyUser()
{
    CursorMenu menu;
    menu.loadOptions({"Modificar usuario",
                      "Eliminar usuario",
                      "Volver"});
    int seleccion = menu.runMenuLoopReturnIndex();
    return seleccion;
}

void MenuManager::showModifyUserMenu(UserManager &manager)
{
    bool back = false;
    while (!back)
    {
        system("cls");
        std::cout << "==== MODIFICAR / ELIMINAR USUARIO ====" << std::endl;
        int option = MenuManager::menuModifyUser();

        switch (option)
        {
        case 0: // Modificar usuario
            manager.modificarUsuario();
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
