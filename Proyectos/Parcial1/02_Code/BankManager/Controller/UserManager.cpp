#include "..\Model\UserManager.h"
#include "..\Model\User.h"
#include "..\Model\BankAccount.h"
#include "..\Model\List.h"
#include "..\Model\Node.h"
#include <iostream>


#include <string>
#include <vector>
#include <cstdlib> // Para system("cls") y system("pause")
using namespace std;

UserManager::UserManager() {}

void UserManager::crearUsuario() {
    string nombre, apellido, cedula, email;
    string numCuentaAhorros, numCuentaCorriente, tipoAhorros, tipoCorriente;
    float saldoAhorros = 0, saldoCorriente = 0;

    system("cls");
    cout << "=== Registro de nuevo usuario ===" << endl;
    cout << "Nombre: ";      cin >> nombre;
    cout << "Apellido: ";    cin >> apellido;
    cout << "Cedula: ";      cin >> cedula;
    cout << "Email: ";       cin >> email;

    // Ahorros
    cout << "Numero de cuenta de ahorros: ";   cin >> numCuentaAhorros;
    cout << "Tipo de cuenta de ahorros: ";     cin >> tipoAhorros;
    cout << "Saldo inicial de ahorros: ";      cin >> saldoAhorros;

    // Corriente
    cout << "Numero de cuenta corriente: ";    cin >> numCuentaCorriente;
    cout << "Tipo de cuenta corriente: ";      cin >> tipoCorriente;
    cout << "Saldo inicial corriente: ";       cin >> saldoCorriente;

    // Crea los objetos de cuenta
    BankAccount cuentaAhorros, cuentaCorriente;
    cuentaAhorros.setAccountNumber(numCuentaAhorros);
    cuentaAhorros.setType(tipoAhorros);
    cuentaAhorros.setBalance(saldoAhorros);

    cuentaCorriente.setAccountNumber(numCuentaCorriente);
    cuentaCorriente.setType(tipoCorriente);
    cuentaCorriente.setBalance(saldoCorriente);

    // PersonalData
    PersonalData datos;
    datos.setName(nombre);
    datos.setLastName(apellido);
    datos.setDNI(cedula);
    datos.setEmail(email);

    // Usuario
    User usuario;
    usuario.setPersonalData(datos);
    usuario.setSavingsAccount(cuentaAhorros);
    usuario.setCheckingAccount(cuentaCorriente);

    usuarios.insert(usuario);

    cout << "Usuario creado exitosamente!\n";
    system("pause");
}

User* UserManager::login() {
    string cuentaIngresada;

    while (true) {
        system("cls");
        cout << "=== LOGIN ===" << endl;
        cout << "Ingrese número de cuenta (ahorros o corriente), o escriba 0 para salir: ";
        cin >> cuentaIngresada;

        // Permite salir escribiendo 0
        if (cuentaIngresada == "0") {
            cout << "Login cancelado.\n";
            system("pause");
            return nullptr;
        }

        Node<User>* actual = usuarios.getHead();
        if (!actual) {
            cout << "No hay usuarios registrados.\n";
            system("pause");
            return nullptr;
        }
        do {
            User usuario = actual->getValue(); //IMPORTANTE SI QUEREMOS MODIFICAR EL USUARIOS DEBEMOS CAMBIAR EL NOTO Y HACER POR REFERENCIA T& Node<T>::getValue()
            if (usuario.getSavingsAccount().getAccountNumber() == cuentaIngresada ||
                usuario.getCheckingAccount().getAccountNumber() == cuentaIngresada) {
                cout << "Login exitoso, bienvenido " << usuario.getPersonalData().getName() << "!\n";
                system("pause");
                return &usuario;
            }
            actual = actual->getNextNode();
        } while (actual != usuarios.getHead());

        cout << "Cuenta no encontrada. Intente de nuevo o escriba 0 para salir.\n";
        system("pause");
    }
}

// void UserManager::mostrarUsuarios() {
//     Node<User>* actual = usuarios.getHead();
//     if (!actual) {
//         cout << "No hay usuarios.\n";
//         return;
//     }
//     cout << "=== Lista de usuarios ===\n";
//     do {
//         const User& usuario = actual->getValue();
//         cout << "Nombre: " << usuario.getPersonalData().getName()
//              << " " << usuario.getPersonalData().getLastName()
//              << ", Cedula: " << usuario.getPersonalData().getDNI()
//              << ", Cuenta Ahorros: " << usuario.getSavingsAccount().getAccountNumber()
//              << ", Saldo Ahorros: " << usuario.getSavingsAccount().getBalance()
//              << ", Cuenta Corriente: " << usuario.getCheckingAccount().getAccountNumber()
//              << ", Saldo Corriente: " << usuario.getCheckingAccount().getBalance() << endl;
//         actual = actual->getNextNode();
//     } while (actual != usuarios.getHead());
// }