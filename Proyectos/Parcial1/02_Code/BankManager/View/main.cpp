#include <iostream>
<<<<<<< HEAD
#include "../Model/User.h"
#include "../Model/PersonalData.h"
#include "../Model/List.h"
#include "../Model/BinaryCifration.h"

using namespace std;

int main() {
    List<User> usuarios;
    string archivo = "usuarios.dat";

    int opcion;
    do {
        cout << "\n==== MENU DE PRUEBA ====\n";
        cout << "1. Agregar usuario\n";
        cout << "2. Mostrar usuarios\n";
        cout << "3. Guardar archivo binario\n";
        cout << "4. Cargar archivo binario\n";
        cout << "5. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            PersonalData pd;
            string input;

            cout << "\nNombre: ";
            getline(cin, input);
            pd.setName(input);

            cout << "Apellido: ";
            getline(cin, input);
            pd.setLastName(input);

            cout << "DNI: ";
            getline(cin, input);
            pd.setDNI(input);

            cout << "Email: ";
            getline(cin, input);
            pd.setEmail(input);

            // Fecha de nacimiento
            Date birth;
            int dia, mes, anio;
            cout << "Dia de nacimiento: ";
            cin >> dia;
            cout << "Mes de nacimiento: ";
            cin >> mes;
            cout << "Anio de nacimiento: ";
            cin >> anio;
            cin.ignore();

            birth.setDay(dia);
            birth.setMonth(mes);
            Year y;
            y.setYear(anio);
            birth.setYear(y);
            pd.setBirthDate(birth);

            User nuevoUsuario;
            nuevoUsuario.setPersonalData(pd);

            usuarios.insert(nuevoUsuario);
            cout << "[Usuario agregado]\n";
        }

        if (opcion == 2) {
            cout << "\n=== Usuarios almacenados ===\n";
            if (usuarios.getHead() == nullptr) {
                cout << "No hay usuarios registrados.\n";
            } else {
                Node<User>* actual = usuarios.getHead();
                int i = 1;
                do {
                    cout << "\nUsuario #" << i << ":\n";
                    actual->getValue().getPersonalData().mostrar(); // Ajusta si tienes método mostrar
                    actual = actual->getNextNode();
                    i++;
                } while (actual != usuarios.getHead());
            }
        }

        if (opcion == 3) {
            BinaryCifration::guardarLista(usuarios, archivo);
            cout << "[Usuarios guardados en archivo binario]\n";
        }

        if (opcion == 4) {
            BinaryCifration::cargarLista(usuarios, archivo);
            cout << "[Usuarios cargados desde archivo binario]\n";
        }

    } while (opcion != 5);

    cout << "Fin del programa.\n";
=======
#include "MenuManager.h"
#include "UserManager.h"
// #include <conio.h> // Para _getch()
// //                 index = (index - 1 + total) % total;
using namespace std;

void mostrarAyuda() {
    system("cls");
    cout << "===== AYUDA =====\n";
    cout << "1. Crear usuario: Registra un nuevo usuario con cuenta.\n";
    cout << "2. Login: Ingresa con tu número de cuenta registrado.\n";
    cout << "3. Menú de ayuda: Muestra esta ventana.\n";
    cout << "4. Salir: Termina el programa.\n";
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
        menu.loadOptions({"Crear usuario", "Login", "Menú de ayuda", "Salir"});
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
            case 3: // Salir
                salir = true;
                break;
        }
    }
>>>>>>> 9abf4de00e55df170fc2f1f7314b3f58915c2bb2
    return 0;
}
