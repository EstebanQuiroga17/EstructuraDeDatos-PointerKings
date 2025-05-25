#include "..\Model\UserManager.h"
#include "..\Model\User.h"
#include "..\Model\BankAccount.h"
#include "..\Model\List.h"
#include "..\Model\Node.h"
#include "..\Model\BinaryCifration.h"
#include "..\Model\CesarCifration.h"
#include "..\Model\InputValidator.h"
#include "..\Model\PersonalData.h"
#include "..\Model\WithDraw.h"
#include "..\Model\Deposit.h"
#include "..\Model\MenuManager.h"
#include <iostream>


#include <string>
#include <vector>
#include <cstdlib> 
using namespace std;

UserManager::UserManager() {
}

void UserManager::crearUsuario() {
    system("cls");
    std::cout << "=== Registro de nuevo usuario ===" << std::endl;

    // 1. Capturar datos personales
    PersonalData datos = capturarDatosPersonales();

    // 2. Validar datos personales
    if (datos.getName().empty() || datos.getLastName().empty() ||
        datos.getDNI().empty() || datos.getEmail().empty()) {
        std::cout << "\nError: Todos los campos personales son obligatorios.\n";
        system("pause");
        return;
    }

    // 3. Menú de tipo de cuenta (con cursores)
    char tipoCuenta = MenuManager::menuTipoCuenta();
    //char tipoCuenta = menuTipoCuenta(); // Retorna 's', 'c', 'a' o 'x'

    // 4. Decidir qué cuentas crear
    bool abrirAhorros = false, abrirCorriente = false;
    if (tipoCuenta == 's') abrirAhorros = true;
    else if (tipoCuenta == 'c') abrirCorriente = true;
    else if (tipoCuenta == 'a') abrirAhorros = abrirCorriente = true;
    else {
        std::cout << "\nRegistro cancelado por el usuario.\n";
        system("pause");
        return;
    }

    // 5. Llamar a guardar usuario (esto pedirá los datos de cuentas según selección)
    guardarUsuario(datos, abrirAhorros, abrirCorriente);
}


PersonalData UserManager::capturarDatosPersonales() {
    InputValidator validator;

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

    return datos;
}

void UserManager::guardarUsuario(const PersonalData& datos, bool abrirAhorros, bool abrirCorriente) {
    BankAccount cuentaAhorros, cuentaCorriente;

    if (abrirAhorros)    cuentaAhorros = crearCuentaAhorros();
    if (abrirCorriente)  cuentaCorriente = crearCuentaCorriente();

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

    // Generar número automáticamente
    BankAccount cuenta;
    std::string numCuenta = cuenta.generateAccountNumber(10, "");
    cout << "Número de cuenta de ahorros generado: " << numCuenta << endl;

    float saldo = validator.isFloat("Saldo inicial de ahorros: ");
    cuenta.setAccountNumber(numCuenta);
    cuenta.setType("Ahorros");
    cuenta.setBalance(saldo);
    return cuenta;
}

BankAccount UserManager::crearCuentaCorriente() {
    InputValidator validator;
    cout << "\n--- Datos de la cuenta CORRIENTE ---" << endl;

    // Generar número automáticamente
    BankAccount cuenta;
    std::string numCuenta = cuenta.generateAccountNumber(10, "");
    cout << "Número de cuenta corriente generado: " << numCuenta << endl;

    float saldo = validator.isFloat("Saldo inicial corriente: ");
    cuenta.setAccountNumber(numCuenta);
    cuenta.setType("Corriente");
    cuenta.setBalance(saldo);
    return cuenta;
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
                return &(actual->getValue());
            }
            actual = actual->getNextNode();
        } while (actual != usuarios.getHead());

        cout << "Cuenta no encontrada. Intente de nuevo o escriba 0 para salir.\n";
        system("pause");
    }
}


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

void UserManager::deposit(User* usuario, float monto, char tipoCuenta, const Date& fecha) {
    if (!usuario) {
        std::cout << "Usuario inválido.\n";
        return;
    }
    if (monto <= 0) {
        std::cout << "El monto debe ser mayor que cero.\n";
        return;
    }
    if (tipoCuenta == 's') {
        usuario->getSavingsAccount().setBalance(usuario->getSavingsAccount().getBalance() + monto);
    } else if (tipoCuenta == 'c') {
        usuario->getCheckingAccount().setBalance(usuario->getCheckingAccount().getBalance() + monto);
    } else {
        std::cout << "Tipo de cuenta inválido.\n";
        return;
    }
    Deposit deposito(monto, usuario, fecha);
    usuario->getBankMovements().insert(deposito);
    std::cout << "Depósito exitoso.\n";
    deposito.printReceipt(1); 
}

void UserManager::withdraw(User* usuario, float monto, char tipoCuenta, const Date& fecha) {
    if (!usuario) {
        std::cout << "Usuario inválido.\n";
        return;
    }
    if (monto <= 0) {
        std::cout << "El monto debe ser mayor que cero.\n";
        return;
    }
    if (tipoCuenta == 's') {
        float saldo = usuario->getSavingsAccount().getBalance();
        if (saldo < monto) {
            std::cout << "Saldo insuficiente.\n";
            return;
        }
        usuario->getSavingsAccount().setBalance(saldo - monto);
    } else if (tipoCuenta == 'c') {
        // Si tu cuenta corriente permite sobregiro, ajusta aquí
        float saldo = usuario->getCheckingAccount().getBalance();
        if (saldo < monto) {
            std::cout << "Saldo insuficiente.\n";
            return;
        }
        usuario->getCheckingAccount().setBalance(saldo - monto);
    } else {
        std::cout << "Tipo de cuenta inválido.\n";
        return;
    }
    WithDraw retiro(monto, usuario, fecha);
    usuario->getBankMovements().insert(retiro);
    std::cout << "Retiro exitoso.\n";
    retiro.printReceipt(); 
}