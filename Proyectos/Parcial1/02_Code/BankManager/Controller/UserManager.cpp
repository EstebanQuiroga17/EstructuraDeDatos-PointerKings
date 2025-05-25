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

UserManager::UserManager() {

}


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

    // --- Preguntar tipo de cuenta(s) ---
    char opcion;
    bool abrirAhorros = false, abrirCorriente = false;
    cout << "\n¿Desea crear cuenta de Ahorros? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') abrirAhorros = true;

    cout << "¿Desea crear cuenta Corriente? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') abrirCorriente = true;

    BankAccount cuentaAhorros, cuentaCorriente;
    if (abrirAhorros)    cuentaAhorros = crearCuentaAhorros();
    if (abrirCorriente)  cuentaCorriente = crearCuentaCorriente();

    // --- Crear usuario completo ---
    User usuario;
    usuario.setPersonalData(datos);

    if (abrirAhorros)    usuario.setSavingsAccount(cuentaAhorros);
    if (abrirCorriente)  usuario.setCheckingAccount(cuentaCorriente);

    usuarios.insert(usuario);

    saveUsers();
    cout << "\nUsuario creado exitosamente!\n";
    system("pause");
}



BankAccount UserManager::crearCuentaAhorros() {
    InputValidator validator;
    cout << "\n--- Datos de la cuenta de AHORROS ---" << endl;
    string numCuenta;
    regex soloNumeros("^[0-9]{10}$");
    do {
        cout << "Numero de cuenta de ahorros (10 dígitos): ";
        cin >> numCuenta;
        if (!regex_match(numCuenta, soloNumeros)) {
            cout << "Debe tener exactamente 10 dígitos numéricos.\n";
        }
    } while (!regex_match(numCuenta, soloNumeros));

    float saldo = validator.isFloat("Saldo inicial de ahorros: ");
    BankAccount cuenta;
    cuenta.setAccountNumber(numCuenta);
    cuenta.setType("Ahorros");
    cuenta.setBalance(saldo);
    return cuenta;
}

BankAccount UserManager::crearCuentaCorriente() {
    InputValidator validator;
    cout << "\n--- Datos de la cuenta CORRIENTE ---" << endl;
    string numCuenta;
    regex soloNumeros("^[0-9]{10}$");
    do {
        cout << "Numero de cuenta corriente (10 dígitos): ";
        cin >> numCuenta;
        if (!regex_match(numCuenta, soloNumeros)) {
            cout << "Debe tener exactamente 10 dígitos numéricos.\n";
        }
    } while (!regex_match(numCuenta, soloNumeros));

    float saldo = validator.isFloat("Saldo inicial corriente: ");
    BankAccount cuenta;
    cuenta.setAccountNumber(numCuenta);
    cuenta.setType("Corriente");
    cuenta.setBalance(saldo);
    return cuenta;
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
                return &(actual->getValue());
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
