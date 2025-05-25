#include "..\Model\UserManager.h"
#include "..\Model\User.h"
#include "..\Model\BankAccount.h"
#include "..\Model\List.h"
#include "..\Model\Node.h"
#include "..\Model\BinaryCifration.h"
#include "..\Model\CesarCifration.h"
#include "..\Model\InputValidator.h"
#include "..\Model\PersonalData.h"
#include <iostream>


#include <string>
#include <vector>
#include <cstdlib> // Para system("cls") y system("pause")
using namespace std;

void UserManager::crearUsuario() {
    system("cls");
    cout << "=== Registro de nuevo usuario ===" << endl;

    InputValidator validator;

    // --- Datos personales ---
    string nombre   = validator.isLetter("Nombre: ");
    string apellido = validator.isLetter("Apellido: ");
    string cedula   = validator.isDNI();
    Date fechaNac   = validator.pedirFechaNacimiento();
    string email    = validator.isEmail();

    PersonalData datos;
    datos.setName(nombre);
    datos.setLastName(apellido);
    datos.setDNI(cedula);
    datos.setBirthDate(fechaNac);
    datos.setEmail(email);

    // --- Cuenta de Ahorros ---
    cout << "\n--- Datos de la cuenta de AHORROS ---" << endl;
    string numCuentaAhorros;
    regex soloNumeros("^[0-9]{10}$");
    do {
        cout << "Numero de cuenta de ahorros (10 dígitos): ";
        cin >> numCuentaAhorros;
        if (!regex_match(numCuentaAhorros, soloNumeros)) {
            cout << "Debe tener exactamente 10 dígitos numéricos.\n";
        }
    } while (!regex_match(numCuentaAhorros, soloNumeros));
    
    string tipoAhorros;
    do {
        cout << "Tipo de cuenta de ahorros (Ahorros): ";
        cin >> tipoAhorros;
        if (tipoAhorros != "Ahorros" && tipoAhorros != "ahorros") {
            cout << "Solo se permite 'Ahorros'.\n";
        }
    } while (tipoAhorros != "Ahorros" && tipoAhorros != "ahorros");

    float saldoAhorros = validator.isFloat("Saldo inicial de ahorros: ");

    BankAccount cuentaAhorros;
    cuentaAhorros.setAccountNumber(numCuentaAhorros);
    cuentaAhorros.setType(tipoAhorros);
    cuentaAhorros.setBalance(saldoAhorros);

    // --- Cuenta Corriente ---
    cout << "\n--- Datos de la cuenta CORRIENTE ---" << endl;
    string numCuentaCorriente;
    do {
        cout << "Numero de cuenta corriente (10 dígitos): ";
        cin >> numCuentaCorriente;
        if (!regex_match(numCuentaCorriente, soloNumeros)) {
            cout << "Debe tener exactamente 10 dígitos numéricos.\n";
        }
    } while (!regex_match(numCuentaCorriente, soloNumeros));
    
    string tipoCorriente;
    do {
        cout << "Tipo de cuenta corriente (Corriente): ";
        cin >> tipoCorriente;
        if (tipoCorriente != "Corriente" && tipoCorriente != "corriente") {
            cout << "Solo se permite 'Corriente'.\n";
        }
    } while (tipoCorriente != "Corriente" && tipoCorriente != "corriente");

    float saldoCorriente = validator.isFloat("Saldo inicial corriente: ");

    BankAccount cuentaCorriente;
    cuentaCorriente.setAccountNumber(numCuentaCorriente);
    cuentaCorriente.setType(tipoCorriente);
    cuentaCorriente.setBalance(saldoCorriente);

    // --- Usuario completo ---
    User usuario;
    usuario.setPersonalData(datos);
    usuario.setSavingsAccount(cuentaAhorros);
    usuario.setCheckingAccount(cuentaCorriente);

    usuarios.insert(usuario);

    saveUsers(); // Guarda después de insertar
    cout << "\nUsuario creado exitosamente!\n";
    system("pause");
}






// void UserManager::crearUsuario() {
//     string nombre, apellido, cedula, email;
//     string numCuentaAhorros, numCuentaCorriente, tipoAhorros, tipoCorriente;
//     float saldoAhorros = 0, saldoCorriente = 0;

//     system("cls");
//     cout << "=== Registro de nuevo usuario ===" << endl;
//     cout << "Nombre: ";      cin >> nombre;
//     cout << "Apellido: ";    cin >> apellido;
//     cout << "Cedula: ";      cin >> cedula;
//     cout << "Email: ";       cin >> email;

//     // Ahorros
//     cout << "Numero de cuenta de ahorros: ";   cin >> numCuentaAhorros;
//     cout << "Tipo de cuenta de ahorros: ";     cin >> tipoAhorros;
//     cout << "Saldo inicial de ahorros: ";      cin >> saldoAhorros;

//     // Corriente
//     cout << "Numero de cuenta corriente: ";    cin >> numCuentaCorriente;
//     cout << "Tipo de cuenta corriente: ";      cin >> tipoCorriente;
//     cout << "Saldo inicial corriente: ";       cin >> saldoCorriente;

//     // Crea los objetos de cuenta
//     BankAccount cuentaAhorros, cuentaCorriente;
//     cuentaAhorros.setAccountNumber(numCuentaAhorros);
//     cuentaAhorros.setType(tipoAhorros);
//     cuentaAhorros.setBalance(saldoAhorros);

//     cuentaCorriente.setAccountNumber(numCuentaCorriente);
//     cuentaCorriente.setType(tipoCorriente);
//     cuentaCorriente.setBalance(saldoCorriente);

//     // PersonalData
//     PersonalData datos;
//     datos.setName(nombre);
//     datos.setLastName(apellido);
//     datos.setDNI(cedula);
//     datos.setEmail(email);

//     // Usuario
//     User usuario;
//     usuario.setPersonalData(datos);
//     usuario.setSavingsAccount(cuentaAhorros);
//     usuario.setCheckingAccount(cuentaCorriente);

//     usuarios.insert(usuario);

//     saveUsers(); // Guarda después de insertar
//     cout << "Usuario creado exitosamente!\n";
//     system("pause");
// }

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

void UserManager::saveUsers() {
    BinaryCifration::saveList(usuarios, "users.dat");
    CesarCifration cesar(3); // Usa tu desplazamiento preferido
    cesar.encryptFile("users.dat");
}

void UserManager::loadUsers() {
    CesarCifration cesar(3); // Usa el mismo desplazamiento que arriba
    cesar.decryptFile("users.dat");
    BinaryCifration::loadList(usuarios, "users.dat");
    cesar.encryptFile("users.dat"); // Vuelve a cifrar inmediatamente después de leer
}

void UserManager::mostrarUsuarios() {
    Node<User>* actual = usuarios.getHead();
    if (!actual) {
        std::cout << "No hay usuarios.\n";
        return;
    }
    std::cout << "=== Lista de usuarios ===\n";
    int i = 1;
    do {
        User usuario = actual->getValue();
        PersonalData pd = usuario.getPersonalData();
        std::cout << "Usuario #" << i << ":\n";
        std::cout << "  Nombre: " << pd.getName() << " " << pd.getLastName() << "\n";
        std::cout << "  Cedula: " << pd.getDNI() << "\n";
        std::cout << "  Cuenta Ahorros: " << usuario.getSavingsAccount().getAccountNumber()
                  << " | Saldo: $" << usuario.getSavingsAccount().getBalance() << "\n";
        std::cout << "  Cuenta Corriente: " << usuario.getCheckingAccount().getAccountNumber()
                  << " | Saldo: $" << usuario.getCheckingAccount().getBalance() << "\n";
        std::cout << "------------------------------\n";
        actual = actual->getNextNode();
        ++i;
    } while (actual != usuarios.getHead());
}
