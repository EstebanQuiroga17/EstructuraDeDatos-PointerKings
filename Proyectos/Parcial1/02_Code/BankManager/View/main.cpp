#include <iostream>
#include <cstdlib>
#include "..\Model\UserManager.h"
#include "..\Model\BackupManager.h"
#include "..\Model\MenuManager.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    UserManager gestor;
    MenuManager menu;
    gestor.loadUsers(); 

    bool salir = false;
    while (!salir) {
        system("cls");
        cout << "========== Menu Manager ==========\n\n";

        int seleccion = menu.mostrarMenuPrincipal();

        switch (seleccion) {
            case 0:
                gestor.crearUsuario();
                break;
            case 1: {
                char tipoCuenta; // 's' o 'c'
                User* usuario = gestor.login(tipoCuenta);
                if (usuario) {
                    menu.menuOperations(gestor, usuario, tipoCuenta);
                }
                break;
            }
            case 2:
                system("start \"\" \"Utils\\index.html\"");
                break;
            case 3:
                system("cls");
                gestor.mostrarUsuarios();
                gestor.debugMostrarTodosLosMovimientos();
                cout << "\nPresiona Enter para volver al menú...";
                cin.ignore();
                cin.get();
                break;
            case 4:
                menu.showMovementsQueryMenu(gestor);
                break;
            case 5: {
                std::string backupName = BackupManager::getTimestampedBackupName();
                if (BackupManager::makeBackup("users.dat", backupName)) {
                    std::cout << "Backup realizado: " << backupName << std::endl;
                } else {
                    std::cout << "Error al realizar el backup." << std::endl;
                }
                system("pause");
                break;
            }
            case 6: {
                std::string backupToRestore;
                std::cout << "Ingrese nombre del backup a restaurar: ";
                std::cin >> backupToRestore;
                if (BackupManager::restoreBackup(backupToRestore, "users.dat")) {
                    std::cout << "Backup restaurado.\n";
                    gestor.loadUsers();
                } else {
                    std::cout << "Error al restaurar backup.\n";
                }
                system("pause");
                break;
            }
            case 7:
                // NUEVO SUBMENÚ MODIFICAR/ELIMINAR USUARIO
                menu.showModifyUserMenu(gestor);
                break;
            case 8:
                salir = true;
                break;
        }
    }
    return 0;
}

