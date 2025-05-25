#include <iostream>
#include "..\Model\UserManager.h"
#include "..\Model\BackupManager.h"
#include "..\Model\MenuManager.h"

using namespace std;

int main() {
    UserManager gestor;

    bool salir = false;
    while (!salir) {
        system("cls");
        cout << "========== Menu Manager ==========\n\n";

        int seleccion = MenuManager::mostrarMenuPrincipal();

        switch (seleccion) {
            case 0:
                gestor.crearUsuario();
                break;
            case 1:
                // User* usuario = gestor.login();
                // if(usuario){
                //     menu.menuOperations(gestor, usuario);
                // }
                break;
            case 2:
                MenuManager::mostrarAyuda();
                break;
            case 3:
                system("cls");
                gestor.mostrarUsuarios();
                cout << "\nPresiona Enter para volver al menú...";
                cin.ignore();
                cin.get();
                break;
            case 4: {
                std::string backupName = BackupManager::getTimestampedBackupName();
                if (BackupManager::makeBackup("users.dat", backupName)) {
                    std::cout << "Backup realizado: " << backupName << std::endl;
                } else {
                    std::cout << "Error al realizar el backup." << std::endl;
                }
                system("pause");
                break;
            }
            case 5: {
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
            case 6:
                salir = true;
                break;
        }
    }
    return 0;
}

