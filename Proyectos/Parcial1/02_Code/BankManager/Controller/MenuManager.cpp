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

//impresion del menú
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

//Función que retorna el índice seleccionado
int MenuManager::runMenuLoopReturnIndex() {
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
        cout << " Usa ↑ y ↓ para navegar. Enter para seleccionar.\n\n";
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

// // Método para ejecutar el menú visualizar (opcional)
// //Ejecutor del menú
// void MenuManager::runMenuLoop() {
//     bool running = true;
//     while (running) {
//         system("cls");
//         cout << " Usa ↑ y ↓ para navegar. Enter para seleccionar.\n\n";
//         printMenu();

//         char key = _getch();
//         if (key == -32) { // Teclas especiales (flechas)
//             key = _getch();
//             if (key == 72) // Flecha arriba
//                 cursor = cursor->getPreviousNode();
//             else if (key == 80) // Flecha abajo
//                 cursor = cursor->getNextNode();
//         } else if (key == 13) { // Enter
//             system("cls");
//             cout << "Seleccionaste: " << cursor->getValue() << endl;
//             if (cursor->getValue() == "Salir")
//                 running = false;
//             system("pause");
//         }
//     }
// }
