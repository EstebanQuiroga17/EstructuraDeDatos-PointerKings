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
    char tipoCuenta;
    InputValidator validator;
    std::cout << "=== Registro de nuevo usuario ===" << std::endl;

    PersonalData datos = capturarDatosPersonales();
    User* usuarioExistente = findUserByDNI(datos.getDNI());

    if (datos.getName().empty() || datos.getLastName().empty() ||
        datos.getDNI().empty() || datos.getEmail().empty()) {
        std::cout << "\nVolveras al menu principal.\n";
        system("pause");
        return;
    }

    if(usuarioExistente == nullptr){
        tipoCuenta = MenuManager::menuTipoCuenta();
    }else{
        tipoCuenta = MenuManager::menuAgregarCuenta();
    }
    

    bool abrirAhorros = false, abrirCorriente = false;

    if (usuarioExistente == nullptr) {
        if(tipoCuenta == 's') {
            abrirAhorros = true;
        } else if (tipoCuenta == 'c') {
            abrirCorriente = true;
        } else if (tipoCuenta == 'a') {
            abrirAhorros = true;
            abrirCorriente = true;
        }
    }else{
        addBankAccount(*usuarioExistente, tipoCuenta);
        return;
    }
    
    if (tipoCuenta == 'x') {
        std::cout << "\nRegistro cancelado por el usuario.\n";
        system("pause");
        return;
    }

    guardarUsuario(datos, abrirAhorros, abrirCorriente);
}

PersonalData UserManager::capturarDatosPersonales() {
    InputValidator validator;
    string cedula;
    cedula = validator.isDNI();

    if (cedula == "0") {
        cout << "Captura de datos cancelada.\n";
        system("pause");
        return PersonalData();
    }

    Node<User>* actual = usuarios.getHead();
    if (actual) {
        do {
            User& usuario = actual->getValue();
            if (usuario.getPersonalData().getDNI() == cedula) {
                cout << "Usuario encontrado: " << usuario.getPersonalData().getName() << " "
                     << usuario.getPersonalData().getLastName() << "\n";
                cout << "No es necesario capturar los datos nuevamente.\n";
                system("pause");
                return usuario.getPersonalData();  
            }
            actual = actual->getNextNode();
        } while (actual != usuarios.getHead());
    }

    cout << "Usuario no encontrado. Por favor, ingrese sus datos personales.\n";

    string nombre   = validator.isLetter("Nombre: ");
    string apellido = validator.isLetter("Apellido: ");
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

User* UserManager::findUserByDNI(const std::string& dni){
    Node<User>* actual = usuarios.getHead();
    if (!actual) return nullptr;

    do {
        User& usuario = actual->getValue();
        if (usuario.getPersonalData().getDNI() == dni) {
            return &usuario;
        }
        actual = actual->getNextNode();
    } while (actual != usuarios.getHead());

    return nullptr;
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
    std::string numCuenta = cuenta.generateAccountNumber("s");
    cout << "Numero de cuenta de ahorros generado: " << numCuenta << endl;

    float saldo;
    do {
        saldo = validator.isFloat("Saldo inicial de ahorros (minimo 10, maximo 250): ");
        if (saldo < 10)
            cout << "El saldo inicial debe ser al menos 10.\n";
        else if (saldo > 50000)
            cout << "El saldo inicial no puede exceder 50000.\n";
    } while (saldo < 10 || saldo > 50000);

    cuenta.setAccountNumber(numCuenta);
    cuenta.setType("Ahorros");
    cuenta.setBalance(saldo);
    return cuenta;
}


BankAccount UserManager::crearCuentaCorriente() {
    InputValidator validator;
    cout << "\n--- Datos de la cuenta CORRIENTE ---" << endl;

    BankAccount cuenta;
    std::string numCuenta = cuenta.generateAccountNumber("c");
    cout << "Numero de cuenta corriente generado: " << numCuenta << endl;

    float saldo;
    do {
        saldo = validator.isFloat("Saldo inicial corriente (minimo 250, maximo 50000): ");
        if (saldo < 250)
            cout << "El saldo inicial debe ser al menos 250.\n";
        else if (saldo > 50000)
            cout << "El saldo inicial no puede exceder 50000.\n";
    } while (saldo < 250 || saldo > 50000);

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
        cout << "Ingrese numero de cuenta (ahorros o corriente), o escriba 0 para salir: ";
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

void UserManager::modificarUsuarioLogeado(const std::string& cedulaLogeado) {
    system("cls");
    std::cout << "=== MODIFICAR MIS DATOS ===" << std::endl;

    Node<User>* head = usuarios.getHead();
    if (!head) {
        std::cout << "No hay usuarios registrados.\n";
        system("pause");
        return;
    }

    Node<User>* actual = head;
    User* usuarioPtr = nullptr;
    do {
        User& usuario = actual->getValue();
        if (usuario.getPersonalData().getDNI() == cedulaLogeado) {
            usuarioPtr = &usuario;
            break;
        }
        actual = actual->getNextNode();
    } while (actual != head);

    if (!usuarioPtr) {
        std::cout << "Usuario no encontrado.\n";
        system("pause");
        return;
    }

    bool volver = false;
    InputValidator validator;
    MenuManager menuMan;

    while (!volver) {
        system("cls");
        std::cout << "=== MODIFICANDO: "
                  << usuarioPtr->getPersonalData().getName() << " "
                  << usuarioPtr->getPersonalData().getLastName() << " ===\n";

        int seleccion = menuMan.menuUpdateUser();

        switch (seleccion) {
            case 0: { // Nombre y apellido
                std::string nombre = validator.isLetter("Nuevo nombre: ");
                std::string apellido = validator.isLetter("Nuevo apellido: ");
                usuarioPtr->getPersonalData().setName(nombre);
                usuarioPtr->getPersonalData().setLastName(apellido);
                std::cout << "Nombre y apellido modificados.\n";
                break;
            }
            case 1: { // DNI
                std::string nuevaCedula = validator.isDNI();
                usuarioPtr->getPersonalData().setDNI(nuevaCedula);
                std::cout << "Cedula modificada.\n";
                break;
            }
            case 2: { // Fecha nacimiento
                Date fechaNac = validator.pedirFechaNacimiento();
                usuarioPtr->getPersonalData().setBirthDate(fechaNac);
                std::cout << "Fecha de nacimiento modificada.\n";
                break;
            }
            case 3: { // Email
                std::string email = validator.isEmail();
                usuarioPtr->getPersonalData().setEmail(email);
                std::cout << "Email modificado.\n";
                break;
            }
            case 4: // Volver
                volver = true;
                break;
        }
        saveUsers();
        if (!volver) {
            std::cout << "Presiona Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    }
}


void UserManager::eliminarUsuario() {
    string cedula;
    system("cls");
    cout << "=== ELIMINAR USUARIO ===" << endl;
    cout << "Ingrese la cedula del usuario a eliminar: ";
    cin >> cedula;

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
        if (usuario.getPersonalData().getDNI() == cedula) {
            encontrado = true;
            break;
        }
        actual = actual->getNextNode();
    } while (actual != head);

    if (encontrado) {
        // Caso unico: solo hay un nodo
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
        // delete actual; // Si tu lista no gestiona memoria sola
        saveUsers();
        cout << "\nUsuario eliminado exitosamente.\n";
    } else {
        cout << "Usuario no encontrado.\n";
    }
    system("pause");
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
        std::cout << "  Email: " << pd.getEmail() << "\n";
        std::cout << "  Fecha Nacimiento: "<< pd.getBirthDate().getDay() << "/"
                  << pd.getBirthDate().getMonth() << "/"
                  << pd.getBirthDate().getYear().getYear() << "\n";
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
        std::cout << "Usuario invalido.\n";
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
        std::cout << "Tipo de cuenta invalido.\n";
        return;
    }
    Deposit deposito(monto, usuario, fecha);
    usuario->getBankMovements().insert(deposito);
    std::cout << "Deposito exitoso.\n";
    deposito.printReceipt(tipoCuenta); 
    saveUsers();
}

void UserManager::withdraw(User* usuario, float monto, char tipoCuenta, const Date& fecha) {
    if (!usuario) {
        std::cout << "Usuario invalido.\n";
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
        std::cout << "Tipo de cuenta invalido.\n";
        return;
    }
    WithDraw retiro(monto, usuario, fecha);
    usuario->getBankMovements().insert(retiro);
    std::cout << "Retiro exitoso.\n";
    retiro.printReceipt(tipoCuenta); 
    saveUsers();
}

void UserManager::queryMovements(
    const std::function<bool(BankMovement&)>& predicate,
    std::vector<BankMovement*>& results
) {
    Node<User>* userNode = usuarios.getHead();
    if (!userNode) return;
    do {
        User& user = userNode->getValue();
        List<BankMovement>& movements = user.getBankMovements();
        Node<BankMovement>* movNode = movements.getHead();
        if (movNode) {
            do {
                BankMovement& mov = movNode->getValue();
                if (predicate(mov)) {
                    results.push_back(&mov);
                }
                movNode = movNode->getNextNode();
            } while (movNode != movements.getHead());
        }
        userNode = userNode->getNextNode();
    } while (userNode != usuarios.getHead());
}

void UserManager::debugMostrarTodosLosMovimientos() {
    Node<User>* currentUser = usuarios.getHead();
    if (!currentUser) {
        std::cout << "No hay usuarios cargados.\n";
        return;
    }
    do {
        User& user = currentUser->getValue();
        std::cout << "Usuario: " << user.getPersonalData().getName() << " DNI: " << user.getPersonalData().getDNI() << std::endl;
        const List<BankMovement>& movements = user.getBankMovements();
        Node<BankMovement>* currentMov = movements.getHead();
        if (currentMov) {
            int n = 0;
            do {
                BankMovement& mov = currentMov->getValue();
                std::cout << "  Movimiento #" << (++n) << ": "
                          << "Monto: " << mov.getAmmount()
                          << ", DNI: " << mov.getUserDNI()
                          << ", Fecha: "; mov.getDate().print();
                currentMov = currentMov->getNextNode();
            } while (currentMov != movements.getHead());
        } else {
            std::cout << "  Sin movimientos." << std::endl;
        }
        currentUser = currentUser->getNextNode();
    } while (currentUser != usuarios.getHead());
}

void printMovementsResults(const std::vector<BankMovement*>& results) {
    if (results.empty()) {
        std::cout << "No movements found with that criteria.\n";
        return;
    }
    std::cout << "\n=== Resultados de la consulta ===\n";
    for (auto& mov : results) {
        mov->printReceipt('n'); // 'n' for no specific account type
        std::cout << "------------------------------\n";
    }
}

void UserManager::addBankAccount(User& user, char bankAccount){
    if (bankAccount == 's') {
        if (user.getSavingsAccount().getAccountNumber().empty()) {
            user.setSavingsAccount(crearCuentaAhorros());
            std::cout << "Cuenta de ahorros creada exitosamente.\n";
        } else {
            std::cout << "Ya existe una cuenta de ahorros para este usuario.\n";
            system("pause");
        }
    } else if (bankAccount == 'c') {
        if (user.getCheckingAccount().getAccountNumber().empty()) {
            user.setCheckingAccount(crearCuentaCorriente());
            std::cout << "Cuenta corriente creada exitosamente.\n";
        } else {
            std::cout << "Ya existe una cuenta corriente para este usuario.\n";
            system("pause");
        }
    } else {
        std::cout << "Tipo de cuenta no reconocido.\n";
    }
}

