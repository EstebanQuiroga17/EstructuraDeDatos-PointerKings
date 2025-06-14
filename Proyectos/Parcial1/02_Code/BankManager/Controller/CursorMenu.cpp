#include "../Model/List.h"
#include "../Model/CursorMenu.h"
#include <iostream>
#include <conio.h> // Para _getch()
using namespace std;

// Constructor
CursorMenu::CursorMenu() {
    cursor = nullptr;
}

void CursorMenu::loadOptions(const vector<string>& opciones) {
    for (const auto& op : opciones) {
        menuOptions.insert(op);
    }
    cursor = menuOptions.getHead();
}

void CursorMenu::printMenu() {
    Node<string>* current = menuOptions.getHead();
    if (!current) {
        cout << "Menu vacio" << endl;
        return;
    }
    do {
        if (current == cursor)
            cout << ">> ";
        else
            cout << "   ";
        cout << current->getValue() << endl;
        current = current->getNextNode();
    } while (current != menuOptions.getHead());
}

int CursorMenu::runMenuLoopReturnIndex() {
    bool running = true;
    int index = 0;
    Node<string>* current = menuOptions.getHead();
    int total = 0;
    do {
        total++;
        current = current->getNextNode();
    } while (current != menuOptions.getHead());

    cursor = menuOptions.getHead();
    index = 0;

    while (running) {
        system("cls");
        cout << " Usa flechas para navegar. Enter para seleccionar.\n\n";
        printMenu();

        char key = _getch();
        if (key == -32) {
            key = _getch();
            if (key == 72) { // Arriba
                cursor = cursor->getPreviousNode();
                index = (index - 1 + total) % total;
            } else if (key == 80) { // Abajo
                cursor = cursor->getNextNode();
                index = (index + 1) % total;
            }
        } else if (key == 13) {
            return index;
        }
    }
    return index;
}

