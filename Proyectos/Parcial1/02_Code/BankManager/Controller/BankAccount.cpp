#include <fstream>
#include "../Model/BankAccount.h"
#include "../Model/BinaryCifration.h"
#include <cstdlib>
using namespace std;

int BankAccount::lastId = 0;

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

std::string BankAccount::generateAccountNumber() {
   if(!BinaryCifration::loadInt(lastId, "BankAccountIdConfig.dat"))
      lastId=1;
   string initialNumbers = "131415";
   string lastIdString = to_string(lastId);
   string id = initialNumbers + lastIdString;
   lastId++;
   BinaryCifration::saveInt(lastId, "BankAccountIdConfig.dat");
   return id;
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

BankAccount::BankAccount() : balance(0.0f), accountNumber(""), type("")
{
}


void BankAccount::saveBinary(std::ofstream& out) const {

    out.write(reinterpret_cast<const char*>(&balance), sizeof(float));

    int len = accountNumber.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    const char* ptrAccount = accountNumber.c_str();
    out.write(ptrAccount, len);

    len = type.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    const char* ptrType = type.c_str();
    out.write(ptrType, len);
}

bool BankAccount::loadBinary(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&balance), sizeof(float));

    int len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(int));
    char* buffer = new char[len + 1];
    in.read(buffer, len);
    *(buffer + len) = '\0';  
    accountNumber = buffer;
    delete buffer; 

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

int BankAccount::getLastId(){
    return lastId;
}

void BankAccount::setLastId(int newLastId){
    lastId = newLastId;
}