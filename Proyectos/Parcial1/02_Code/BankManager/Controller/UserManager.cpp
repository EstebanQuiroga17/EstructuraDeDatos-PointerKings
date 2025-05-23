#include "UserManager.h"
#include <iostream>
#include "User.h"
#include "BankAccount.h"
#include "List.h"
#include "Node.h"
#include <string>
#include <vector>
#include <cstdlib> // Para system("cls") y system("pause")
using namespace std;

UserManager::UserManager() {}

void UserManager::crearUsuario() {
    string nombre, cedula, numCuenta, tipo;
    float saldo;

    system("cls");
    cout << "=== Registro de nuevo usuario ===" << endl;
    cout << "Nombre: ";      cin >> nombre;
    cout << "Cedula: ";      cin >> cedula;
    cout << "Numero de cuenta: "; cin >> numCuenta;
    cout << "Tipo de cuenta: ";   cin >> tipo;
    cout << "Saldo inicial: ";    cin >> saldo;

    BankAccount cuenta;
    cuenta.setAccountNumber(numCuenta);
    cuenta.setBalance(saldo);
    cuenta.setType(tipo);

    User usuario;
    usuario.setNombre(nombre);
    usuario.setCedula(cedula);
    usuario.setCuenta(cuenta);

    usuarios.insert(usuario);

    cout << "Usuario creado exitosamente!\n";
    system("pause");
}

User* UserManager::login() {
    string cuentaIngresada;
    while (true) {
        system("cls");
        cout << "=== LOGIN ===" << endl;
        cout << "Ingrese numero de cuenta: ";
        cin >> cuentaIngresada;

        Node<User>* actual = usuarios.getHead();
        if (!actual) {
            cout << "No hay usuarios registrados.\n";
            system("pause");
            return nullptr;
        }
        do {
            User& usuario = actual->getValue();
            if (usuario.getCuenta().getAccountNumber() == cuentaIngresada) {
                cout << "Login exitoso, bienvenido " << usuario.getNombre() << "!\n";
                system("pause");
                return &usuario;
            }
            actual = actual->getNextNode();
        } while (actual != usuarios.getHead());

        cout << "Cuenta no encontrada. Intente de nuevo.\n";
        system("pause");
    }
}

void UserManager::mostrarUsuarios() {
    Node<User>* actual = usuarios.getHead();
    if (!actual) {
        cout << "No hay usuarios.\n";
        return;
    }
    cout << "=== Lista de usuarios ===\n";
    do {
        User& usuario = actual->getValue();
        cout << "Nombre: " << usuario.getNombre()
             << ", Cedula: " << usuario.getCedula()
             << ", Cuenta: " << usuario.getCuenta().getAccountNumber()
             << ", Saldo: " << usuario.getCuenta().getBalance() << endl;
        actual = actual->getNextNode();
    } while (actual != usuarios.getHead());
}

List<User>& UserManager::getUsuarios() {
    return usuarios;
}