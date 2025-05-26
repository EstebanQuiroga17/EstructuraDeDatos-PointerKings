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
    void crearUsuario();           
    User* login(char &tipoCuenta);                 
    void mostrarUsuarios();       
    List<User>& getUsuarios();     
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
    