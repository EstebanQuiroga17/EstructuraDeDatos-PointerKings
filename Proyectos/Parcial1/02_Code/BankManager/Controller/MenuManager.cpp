#include "MenuManager.h"
#include "CursorMenu.h" // Cambia según dónde esté tu clase de menú con cursores
#include <iostream>
#include <cstdlib>

using std::string;
using std::vector;
using std::cout;
using std::cin;

int MenuManager::mostrarMenuPrincipal() {
    CursorMenu menu;
    menu.loadOptions({
        "Crear usuario",
        "Login",
        "Menu de ayuda",
        "Mostrar usuarios",
        "Crear backup",
        "Restaurar backup",
        "Salir"
    });
    return menu.runMenuLoopReturnIndex();
}

char MenuManager::menuTipoCuenta() {
    CursorMenu menu;
    menu.loadOptions({
        "Cuenta de Ahorros",
        "Cuenta Corriente",
        "Ambas cuentas (Ahorros y Corriente)",
        "Cancelar"
    });
    int seleccion = menu.runMenuLoopReturnIndex();
    switch (seleccion) {
        case 0: return 's'; // Solo ahorros
        case 1: return 'c'; // Solo corriente
        case 2: return 'a'; // Ambas cuentas
        default: return 'x'; // Cancelar
    }
}

void MenuManager::mostrarAyuda() {
    system("cls");
    cout << "===== AYUDA =====\n";
    cout << "1. Crear usuario: Registra un nuevo usuario con cuenta.\n";
    cout << "2. Login: Ingresa con tu número de cuenta registrado.\n";
    cout << "3. Menú de ayuda: Muestra esta ventana.\n";
    cout << "4. Mostrar usuarios: Visualiza todos los usuarios cargados.\n";
    cout << "5. Salir: Termina el programa.\n";
    cout << "\nUsa las flechas ↑ y ↓ para moverte, Enter para seleccionar.\n";
    cout << "\nPresiona cualquier tecla para volver al menú...";
    cin.ignore();
    cin.get();
}
