

#if !defined(__BankManagerProject_BinaryCifration_h)
#define __BankManagerProject_BinaryCifration_h
#include "List.h"

class BinaryCifration
{
public:
template <typename T>
    static void saveObject(const T& obj, const std::string& ruta) {
        std::ofstream out(ruta.c_str(), std::ios::binary | std::ios::trunc);
        if (!out) return;
        obj.saveBinary(out);
        out.close();
    }

    template <typename T>
    static bool loadObject(T& obj, const std::string& ruta) {
        std::ifstream in(ruta.c_str(), std::ios::binary);
        if (!in) return false;
        obj.loadBinary(in);
        in.close();
        return true;
    }

    template <typename T>
    static void saveList(const List<T>& lista, const std::string& ruta) {
        std::ofstream out(ruta.c_str(), std::ios::binary | std::ios::trunc);
        if (!out) return;
        lista.saveBinary(out); 
        out.close();
    }

    template <typename T>
    static bool loadList(List<T>& lista, const std::string& ruta) {
        std::ifstream in(ruta.c_str(), std::ios::binary);
        if (!in) return false;
        lista.loadBinary(in); 
        in.close();
        return true;
    }

static bool saveInt(int value, const std::string& ruta) {
    std::ofstream out(ruta, std::ios::binary | std::ios::trunc);
    if (!out) return false;
    out.write(reinterpret_cast<const char*>(&value), sizeof(value));
    return true;
}

static bool loadInt(int& value, const std::string& ruta) {
    std::ifstream in(ruta, std::ios::binary);
    if (!in) return false;
    in.read(reinterpret_cast<char*>(&value), sizeof(value));
    return true;
}

static bool saveString(const std::string& value, const std::string& ruta) {
    std::ofstream out(ruta, std::ios::binary | std::ios::trunc);
    if (!out) return false;

    size_t len = value.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len)); // Guardar tamaño
    out.write(value.data(), len);
    return true;
}

static bool loadString(std::string& value, const std::string& ruta) {
    std::ifstream in(ruta, std::ios::binary);
    if (!in) return false;

    size_t lenght = 0;
    in.read(reinterpret_cast<char*>(&lenght), sizeof(lenght)); // Leer tamaño
    value.resize(lenght);
    in.read(&value[0], lenght);
    return true;
}

    
protected:
private:

};

#endif