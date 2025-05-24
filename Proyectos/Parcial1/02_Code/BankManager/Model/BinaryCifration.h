/***********************************************************************
 * Module:  BinaryCifration.h
 * Author:  TEVS
 * Modified: martes, 13 de mayo de 2025 20:02:07
 * Purpose: Declaration of the class BinaryCifration
 ***********************************************************************/

#if !defined(__BankManagerProject_BinaryCifration_h)
#define __BankManagerProject_BinaryCifration_h
#include "List.h"

class BinaryCifration
{
public:
template <typename T>
    static void guardarObjeto(const T& obj, const std::string& ruta) {
        std::ofstream out(ruta.c_str(), std::ios::binary | std::ios::trunc);
        if (!out) return;
        obj.guardarBinario(out);
        out.close();
    }

    template <typename T>
    static bool cargarObjeto(T& obj, const std::string& ruta) {
        std::ifstream in(ruta.c_str(), std::ios::binary);
        if (!in) return false;
        obj.cargarBinario(in);
        in.close();
        return true;
    }

    template <typename T>
    static void guardarLista(const List<T>& lista, const std::string& ruta) {
        std::ofstream out(ruta.c_str(), std::ios::binary | std::ios::trunc);
        if (!out) return;
        lista.guardarBinario(out); // Tu método de la lista
        out.close();
    }

    template <typename T>
    static bool cargarLista(List<T>& lista, const std::string& ruta) {
        std::ifstream in(ruta.c_str(), std::ios::binary);
        if (!in) return false;
        lista.cargarBinario(in); // Tu método de la lista
        in.close();
        return true;
    }
    
protected:
private:

};

#endif