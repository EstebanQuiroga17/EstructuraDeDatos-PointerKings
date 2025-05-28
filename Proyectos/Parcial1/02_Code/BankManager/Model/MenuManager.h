#pragma once
#include <vector>
#include <string>
#include "../Model/UserManager.h"


class MenuManager {
public:
    static int mostrarMenuPrincipal();
    static char menuTipoCuenta();
    static char menuAgregarCuenta();
    static void mostrarAyuda();
    void menuOperations(UserManager& gestor, User* usuario, char tipoCuenta);
    int menuOperacionBancaria();
    static int menuQueryMovements();
    static void showMovementsQueryMenu(UserManager&);
    static int menuModifyUser();
    static void showModifyUserMenu(UserManager& manager);
    int menuUpdateUser();
    static void printMovementsResults(const std::vector<BankMovement*>& results);
};
