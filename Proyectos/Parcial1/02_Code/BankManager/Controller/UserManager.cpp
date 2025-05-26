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

    PersonalData datos = capturarDatosPersonales();

    if (datos.getName().empty() || datos.getLastName().empty() ||
        datos.getDNI().empty() || datos.getEmail().empty()) {
        std::cout << "\nError: Todos los campos personales son obligatorios.\n";
        system("pause");
        return;
    }

    char tipoCuenta = MenuManager::menuTipoCuenta();

    bool abrirAhorros = false, abrirCorriente = false;
    if (tipoCuenta == 's') abrirAhorros = true;
    else if (tipoCuenta == 'c') abrirCorriente = true;
    else if (tipoCuenta == 'a') abrirAhorros = abrirCorriente = true;
    else {
        std::cout << "\nRegistro cancelado por el usuario.\n";
        system("pause");
        return;
    }

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

    BankAccount cuenta;
    std::string numCuenta = cuenta.generateAccountNumber();
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

    BankAccount cuenta;
    std::string numCuenta = cuenta.generateAccountNumber();
    cout << "Número de cuenta corriente generado: " << numCuenta << endl;

    float saldo = validator.isFloat("Saldo inicial corriente: ");
    cuenta.setAccountNumber(numCuenta);
    cuenta.setType("Corriente");
    cuenta.setBalance(saldo);
    return cuenta;
}

User* UserManager::login(char &tipoCuenta) {
    string cuentaIngresada;

    while (true) {
        system("cls");
        cout << "=== LOGIN ===" << endl;
        cout << "Ingrese número de cuenta (ahorros o corriente), o escriba 0 para salir: ";
        cin >> cuentaIngresada;

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
            User& usuario = actual->getValue();
            if (usuario.getSavingsAccount().getAccountNumber() == cuentaIngresada) {
                tipoCuenta = 's';
                cout << "Login exitoso, bienvenido " << usuario.getPersonalData().getName() << " (Cuenta de Ahorros)!\n";
                system("pause");
                return &usuario;
            }
            if (usuario.getCheckingAccount().getAccountNumber() == cuentaIngresada) {
                tipoCuenta = 'c';
                cout << "Login exitoso, bienvenido " << usuario.getPersonalData().getName() << " (Cuenta Corriente)!\n";
                system("pause");
                return &usuario;
            }
            actual = actual->getNextNode();
        } while (actual != usuarios.getHead());

        cout << "Cuenta no encontrada. Intente de nuevo o escriba 0 para salir.\n";
        system("pause");
    }
}

void UserManager::saveUsers() {
    BinaryCifration::saveList(usuarios, "users.dat");
    CesarCifration cesar(3); 
    cesar.encryptFile("users.dat");
}

void UserManager::loadUsers() {
    CesarCifration cesar(3); 
    cesar.decryptFile("users.dat");
    BinaryCifration::loadList(usuarios, "users.dat");
    cesar.encryptFile("users.dat"); 
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

void UserManager::queryMovements( const std::function<bool( BankMovement&)>& predicate)  {
    bool found = false;
    Node<User>* currentUser = usuarios.getHead();
    if (!currentUser) {
        std::cout << "No users registered.\n";
        return;
    }
    do {
        User user = currentUser->getValue();
        List<BankMovement> movements = user.getBankMovements();
        Node<BankMovement>* currentMov = movements.getHead();
        if (currentMov) {
            do {
                BankMovement mov = currentMov->getValue();
                if (predicate(mov)) {
                    mov.printReceipt();
                    found = true;
                }
                currentMov = currentMov->getNextNode();
            } while (currentMov != movements.getHead());
        }
        currentUser = currentUser->getNextNode();
    } while (currentUser != usuarios.getHead());

    if (!found)
        std::cout << "No movements found with that criteria.\n";
}

void UserManager::eliminarUsuario() {
    string cuenta;
    system("cls");
    cout << "=== ELIMINAR USUARIO ===" << endl;
    cout << "Ingrese el número de cuenta de ahorros o corriente del usuario a eliminar: ";
    cin >> cuenta;

    Node<User>* head = usuarios.getHead();
    if (!head) {
        cout << "No hay usuarios registrados.\n";
        system("pause");
        return;
    }

    Node<User>* actual = head;
    bool encontrado = false;

    do {
        User& usuario = actual->getValue();
        if (usuario.getSavingsAccount().getAccountNumber() == cuenta ||
            usuario.getCheckingAccount().getAccountNumber() == cuenta) {
            encontrado = true;
            break;
        }
        actual = actual->getNextNode();
    } while (actual != head);

    if (encontrado) {
        // Caso único: solo hay un nodo
        if (actual == actual->getNextNode()) {
            usuarios.setHead(nullptr);
        } else {
            // Religa los nodos anterior y siguiente
            Node<User>* prev = actual->getPreviousNode();
            Node<User>* next = actual->getNextNode();
            prev->setNextNode(next);
            next->setPreviousNode(prev);
            if (actual == head) usuarios.setHead(next);
        }
        // Libera memoria si es necesario:
        // delete actual; // (solo si tu lista NO maneja destrucción automática)
        saveUsers();
        cout << "\nUsuario eliminado exitosamente.\n";
    } else {
        cout << "Usuario no encontrado.\n";
    }
    system("pause");
}

