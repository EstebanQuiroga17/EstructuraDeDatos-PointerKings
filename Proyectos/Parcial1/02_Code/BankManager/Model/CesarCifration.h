#ifndef __BankManagerProject_CesarCifration_h
#define __BankManagerProject_CesarCifration_h

#include <string>

class CesarCifration {
public:
    CesarCifration(int key = 3);

    bool encryptFile(const std::string& path);
    bool decryptFile(const std::string& path);

private:
    int key;
};

#endif
