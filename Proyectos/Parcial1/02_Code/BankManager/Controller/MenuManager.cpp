#include "../Model/MenuManager.h"
#include "../Model/CursorMenu.h"
#include "../Model/InputValidator.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <DateValidator.h>

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
                      "Generar archivo descifrado para demostracion",
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
        {// Deposito
            float monto;
            do
            {
                monto = validator.isFloat("\nIngrese monto a depositar: ");
                if (monto <= 0)
                    std::cout << "El monto debe ser mayor que 0\n";
                if(monto<=0.009)
                    std::cout << "El monto minimo es 0.01\n";
            } while (monto <= 0 || monto <= 0.009);

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
                    std::cout << "El monto debe ser mayor que 0\n";
                if(monto<=0.009)
                    std::cout << "El monto minimo es 0.01\n";
            } while (monto <= 0 || monto <= 0.009);

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

void MenuManager::printMovementsResults(const std::vector<BankMovement *> &results)
{
    if (results.empty())
    {
        std::cout << "No movements found with that criteria.\n";
        return;
    }
    std::cout << "\n=== Resultados de la consulta ===\n";
    for (auto &mov : results)
    {
        mov->printReceipt('n'); // 'n' for no specific account type
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
            std::cout << "Fecha de inicio:\n";
            int y1 = validator.isInteger("Anio: ");
            int m1 = validator.isInteger("Mes (1-12): ");
            int d1 = validator.isInteger("Dia: ");
            while (!DateValidator::validateDay(d1, DateValidator::monthDays(m1, y1)))
            {
                std::cout << "Fecha invalida. Intente de nuevo.\n";
                y1 = validator.isInteger("Anio: ");
                m1 = validator.isInteger("Mes (1-12): ");
                d1 = validator.isInteger("Día: ");
            }
            Date from(y1, m1, d1);

            std::cout << "Fecha de fin:\n";
            int y2 = validator.isInteger("Anio: ");
            int m2 = validator.isInteger("Mes (1-12): ");
            int d2 = validator.isInteger("Dia: ");
            while (!DateValidator::validateDay(d2, DateValidator::monthDays(m2, y2)))
            {
                std::cout << "Fecha invalida. Intente de nuevo.\n";
                y2 = validator.isInteger("Anio: ");
                m2 = validator.isInteger("Mes (1-12): ");
                d2 = validator.isInteger("Dia: ");
            }
            Date to(y2, m2, d2);

            std::vector<BankMovement *> results;
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
            std::string name = validator.isLetter("Ingrese el nombre: ");
            std::string dni = validator.isDNI();

            std::vector<BankMovement *> results;
            manager.queryMovements([&](BankMovement &mov)
                                   { return (mov.getUser()->getPersonalData().getName() == name &&
                                             mov.getUser()->getPersonalData().getDNI() == dni); }, results);

            printMovementsResults(results);

            std::cout << "Presione Enter para continuar . . .";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        case 2:
        { // Monto mínimo
            float minAmount = validator.isFloat("Ingrese el monto minimo: ");
            while (minAmount < 0)
            {
                std::cout << "El monto debe ser positivo.\n";
                minAmount = validator.isFloat("Ingrese el monto minimo: ");
            }

            std::vector<BankMovement *> results;
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
