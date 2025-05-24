#include <iostream>
#include "..\Model\MenuManager.h"
#include "..\Model\UserManager.h"
using namespace std;

void mostrarAyuda() {
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

int main() {
    UserManager gestor;

    bool salir = false;
    while (!salir) {
        system("cls");
        cout << "========== Menu Manager ==========\n\n";

        MenuManager menu;
        menu.loadOptions({"Crear usuario", "Login", "Menú de ayuda", "Mostrar usuarios", "Salir"});
        int seleccion = menu.runMenuLoopReturnIndex();

        switch (seleccion) {
            case 0: // Crear usuario
                gestor.crearUsuario();
                break;
            case 1: // Login
                gestor.login();
                break;
            case 2: // Ayuda
                mostrarAyuda();
                break;
            case 3: // Mostrar usuarios
                system("cls");
                gestor.mostrarUsuarios();
                cout << "\nPresiona Enter para volver al menú...";
                cin.ignore();
                cin.get();
                break;
            case 4: // Salir
                salir = true;
                break;
        }
    }
    // Guarda los usuarios al salir (opcional, si no los guardas en crearUsuario)
    // gestor.saveUsers();
    return 0;
}
