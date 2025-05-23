#include "../Model/List.h"
#include "../Model/MenuManager.h"
#include <iostream>
#include <conio.h> // Para _getch()
using namespace std;

// Constructor
MenuManager::MenuManager() {
    cursor = nullptr;
}

// Carga las opciones al menú
void MenuManager::loadOptions(const vector<string>& opciones) {
    for (const auto& op : opciones) {
        menuOptions.insert(op);
    }
    cursor = menuOptions.getHead();
}

// Imprime el menú, resaltando la opción seleccionada
void MenuManager::printMenu() {
    Node<string>* current = menuOptions.getHead();
    if (!current) {
        cout << "Menú vacío" << endl;
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

// Ejecuta el menú interactivo
void MenuManager::runMenuLoop() {
    bool running = true;
    while (running) {
        system("cls");
        cout << " Usa ↑ y ↓ para navegar. Enter para seleccionar.\n\n";
        printMenu();

        char key = _getch();
        if (key == -32) { // Teclas especiales (flechas)
            key = _getch();
            if (key == 72) // Flecha arriba
                cursor = cursor->getPreviousNode();
            else if (key == 80) // Flecha abajo
                cursor = cursor->getNextNode();
        } else if (key == 13) { // Enter
            system("cls");
            cout << "Seleccionaste: " << cursor->getValue() << endl;
            if (cursor->getValue() == "Salir")
                running = false;
            system("pause");
        }
    }
}
