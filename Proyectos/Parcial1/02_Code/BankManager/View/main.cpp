#include <iostream>
#include <cstdlib>
#include "..\Model\MenuManager.h"
#include "..\Model\UserManager.h"
#include "..\Model\BackupManager.h"
using namespace std;

int main() {
    UserManager gestor;

    bool salir = false;
    while (!salir) {
        system("cls");
        cout << "========== Menu Manager ==========\n\n";

        MenuManager menu;
        menu.loadOptions({"Crear usuario", "Login", "Menu de ayuda", "Mostrar usuarios","Crear backup", "Restaurar backup", "Salir"});
        int seleccion = menu.runMenuLoopReturnIndex();

        switch (seleccion) {
            case 0:
                gestor.crearUsuario();
                break;
            case 1:
                gestor.login();
                break;
            case 2:
               system("start \"\" \"Utils\\index.html\"");
                break;
            case 3:
                system("cls");
                gestor.mostrarUsuarios();
                cout << "\nPresiona Enter para volver al menú...";
                cin.ignore();
                cin.get();
                break;
            case 4:
                {
                    std::string backupName = BackupManager::getTimestampedBackupName();
                    if (BackupManager::makeBackup("users.dat", backupName)) {
                        std::cout << "Backup realizado: " << backupName << std::endl;
                    } else {
                        std::cout << "Error al realizar el backup." << std::endl;
                    }
                    system("pause");
                }
                break;
            case 5:
                {
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
                }
                break;
            case 6:
                salir = true;
                break;
        }
    }
    return 0;
}
