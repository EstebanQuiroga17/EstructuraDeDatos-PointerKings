#if !defined(__BankManagerProject_MenuManager_h)
#define __BankManagerProject_MenuManager_h

#pragma once
#include "List.h"
#include <vector>
#include <string>

class MenuManager {
private:
    List<std::string> menuOptions;
    Node<std::string>* cursor;
public:
    MenuManager();
    void loadOptions(const std::vector<std::string>& opciones);
    void printMenu();
    int runMenuLoopReturnIndex(); // <-- AGRÉGALO AQUÍ
    // void runMenuLoop(); // <-- Puedes borrar/comentar este si ya no lo usas
};

#endif
