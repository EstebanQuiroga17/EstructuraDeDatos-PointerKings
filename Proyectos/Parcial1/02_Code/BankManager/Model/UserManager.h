#pragma once
#include "List.h"
#include "User.h" // Usa el nombre real de tu clase Usuario
#include <string>

class UserManager {
private:
    List<User> usuarios;
public:
    UserManager();
    void crearUsuario();           // Pide datos y crea un usuario nuevo
    User* login();                 // Pide número de cuenta y retorna puntero al usuario si existe
    void mostrarUsuarios();        // Para debug (opcional)
    // Puedes agregar métodos como eliminar, modificar, etc.
    List<User>& getUsuarios();     // Acceso a la lista si la necesitas afuera
    void saveUsers();
    void loadUsers();
};
    