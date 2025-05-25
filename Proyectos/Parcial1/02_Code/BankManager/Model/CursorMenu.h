#if !defined(__BankManagerProject_CursorMenu_h)
#define __BankManagerProject_CursorMenu_h

#pragma once
#include "List.h"
#include <vector>
#include <string>


class CursorMenu {
private:
    List<std::string> menuOptions;
    Node<std::string>* cursor;
public:
    CursorMenu();
    void loadOptions(const std::vector<std::string>& opciones);
    void printMenu();
    int runMenuLoopReturnIndex(); // <-- AGRÉGALO AQUÍ
};

#endif
