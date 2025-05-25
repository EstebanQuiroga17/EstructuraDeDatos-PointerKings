#pragma once
#include <vector>
#include <string>
#include "../Model/UserManager.h"


class MenuManager {
public:
    static int mostrarMenuPrincipal();
    static char menuTipoCuenta();
    static void mostrarAyuda();
    void menuOperations(UserManager& gestor, User* usuario);
    int menuOperacionBancaria();
};
