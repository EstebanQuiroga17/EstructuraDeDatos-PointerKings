#pragma once
#include "List.h"
#include "User.h"
#include <string>
#include <functional>
class BankAccount;

class UserManager {
private:
    List<User> usuarios;
public:
    UserManager();
    void crearUsuario();           // Pide datos y crea un usuario nuevo
    User* login(char &tipoCuenta);                 // Pide número de cuenta y retorna puntero al usuario si existe
    void mostrarUsuarios();        // Para debug (opcional)
    // Puedes agregar métodos como eliminar, modificar, etc.
    List<User>& getUsuarios();     // Acceso a la lista si la necesitas afuera
    void saveUsers();
    void loadUsers();
    BankAccount crearCuentaAhorros();
    BankAccount crearCuentaCorriente();
    void guardarUsuario(const PersonalData& datos, bool abrirAhorros, bool abrirCorriente);
    PersonalData capturarDatosPersonales();
    void deposit(User* usuario, float monto, char tipoCuenta, const Date& fecha);
    void withdraw(User* usuario, float monto, char tipoCuenta, const Date& fecha);
    void queryMovements( const std::function<bool( BankMovement&)>&);
    void eliminarUsuario();
    void modificarUsuario();

};
    