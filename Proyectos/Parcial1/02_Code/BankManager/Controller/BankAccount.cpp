#include <fstream>
#include "../Model/BankAccount.h"
#include <cstdlib>
#include <ctime>
using namespace std;

float BankAccount::getBalance(void)
{
   return balance;
}

void BankAccount::setBalance(float newBalance)
{
   balance = newBalance;
}

std::string BankAccount::getAccountNumber(void) const
{
   return accountNumber;
}

void BankAccount::setAccountNumber(std::string newAccountNumber)
{
   accountNumber = newAccountNumber;
}

std::string BankAccount::getType(void)
{
   return type;
}

void BankAccount::setType(std::string newType)
{
   type = newType;
}

string BankAccount::generateAccountNumber(int digits, std::string number) {
    if (digits == 0) {
        if (number[0] == '0') {
            return generateAccountNumber(10, "");
        }
        return number;
    }
    if (number.empty()) {
        number += '1' + rand() % 9;
    } else {
        number += '0' + rand() % 10;
    }
    return generateAccountNumber(digits - 1, number);
}

BankAccount::BankAccount(std::string type)
   : type(type)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    accountNumber = generateAccountNumber();
    setBalance(0.0f);
}

BankAccount::~BankAccount()
{
}

void BankAccount::guardarBinario(std::ofstream& out) const {
    // Guardar balance
    out.write(reinterpret_cast<const char*>(&balance), sizeof(float));

    // Guardar accountNumber
    int len = accountNumber.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    const char* ptrAccount = accountNumber.c_str();
    out.write(ptrAccount, len);

    // Guardar type
    len = type.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    const char* ptrType = type.c_str();
    out.write(ptrType, len);
}

bool BankAccount::cargarBinario(std::ifstream& in) {
    // Leer balance
    in.read(reinterpret_cast<char*>(&balance), sizeof(float));

    // Leer accountNumber
    int len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(int));
    char* buffer = new char[len + 1];
    in.read(buffer, len);
    *(buffer + len) = '\0';  // Fin de cadena sin corchetes
    accountNumber = buffer;
    delete buffer;  // Si la consigna es delete y no delete[], úsalo así

    // Leer type
    in.read(reinterpret_cast<char*>(&len), sizeof(int));
    buffer = new char[len + 1];
    in.read(buffer, len);
    *(buffer + len) = '\0';
    type = buffer;
    delete buffer;

    return true;
}

bool BankAccount::operator==(const BankAccount& account1) const{
    if(this->accountNumber == account1.accountNumber){
        return true;
    }else{
        return false;
    }
}
