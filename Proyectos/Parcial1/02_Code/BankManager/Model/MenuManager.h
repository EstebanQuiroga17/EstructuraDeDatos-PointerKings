#pragma once
#include <vector>
#include <string>
#include "../Model/UserManager.h"


class MenuManager {
public:
    static int mostrarMenuPrincipal();
    static char menuTipoCuenta();
    static char menuAgregarCuenta();
    void menuOperations(UserManager& gestor, User* usuario, char tipoCuenta);
    int menuOperacionBancariaLogin();
    static int menuQueryMovements();
    static void showMovementsQueryMenu(UserManager&);
    int menuUpdateUser();
    static void printMovementsResults(const std::vector<BankMovement*>& results);
};
