#include "CesarCifration.h"
#include <fstream>

CesarCifration::CesarCifration(int key) : key(key) {}

bool CesarCifration::encryptFile(const std::string& path) {
    std::ifstream in(path.c_str(), std::ios::binary | std::ios::ate);
    if (!in) return false;

    std::streamsize size = in.tellg();
    in.seekg(0, std::ios::beg);

    char* buffer = new char[size];
    if (!in.read(buffer, size)) {
        delete[] buffer;
        return false;
    }
    in.close();

    for (std::streamsize i = 0; i < size; ++i)
        buffer[i] += key;

    std::ofstream out(path.c_str(), std::ios::binary | std::ios::trunc);
    if (!out) {
        delete[] buffer;
        return false;
    }
    out.write(buffer, size);
    out.close();
    delete[] buffer;
    return true;
}

bool CesarCifration::decryptFile(const std::string& path) {
    std::ifstream in(path.c_str(), std::ios::binary | std::ios::ate);
    if (!in) return false;

    std::streamsize size = in.tellg();
    in.seekg(0, std::ios::beg);

    char* buffer = new char[size];
    if (!in.read(buffer, size)) {
        delete[] buffer;
        return false;
    }
    in.close();

    for (std::streamsize i = 0; i < size; ++i)
        buffer[i] -= key;

    std::ofstream out(path.c_str(), std::ios::binary | std::ios::trunc);
    if (!out) {
        delete[] buffer;
        return false;
    }
    out.write(buffer, size);
    out.close();
    delete[] buffer;
    return true;
}
