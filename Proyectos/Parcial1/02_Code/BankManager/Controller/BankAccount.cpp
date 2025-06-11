#include <fstream>
#include "../Model/BankAccount.h"
#include "../Model/BinaryCifration.h"
#include "../Model/User.h"
#include <cstdlib>
using namespace std;

string BankAccount::lastId = "000001";

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

std::string BankAccount::generateAccountNumber(std::string type) {
   string accountNumber;
   string extraDigit = "0"; // Default extra digit
   bool isValid = false;
   int sum = 0;
   int integerExtraDigit = 0;
   if(!BinaryCifration::loadString(lastId, "BankAccountIdConfig.dat")){
      lastId="1";
   }
   string branchNumber = "88"; 
   string accountTypeNumber;
   if(type == "s"){
      accountTypeNumber = "1";
   }else if(type == "c"){
      accountTypeNumber = "2";
   }else{
      cout<< "Invalid account type." << endl;
      return "";
   }
   
   accountNumber = branchNumber + accountTypeNumber + lastId + extraDigit;
   do{
      for(int i = 0; i<accountNumber.size(); i++){
         sum += accountNumber[i] - '0';
      }
      if(sum % 10 == 0){
         isValid = true;
      }else{
         integerExtraDigit = 10 - (sum % 10);
         extraDigit = std::to_string(integerExtraDigit);
         accountNumber = branchNumber + accountTypeNumber + lastId + extraDigit;
         sum = 0;
      }
   } while(!isValid);

   lastId = std::to_string(std::stoi(lastId) + 1);
   for(int i = lastId.size(); i < 6; i++) {
      lastId = "0" + lastId;
   }
   BinaryCifration::saveString(lastId, "BankAccountIdConfig.dat");
   return accountNumber;
}


BankAccount::BankAccount(std::string type)
   : type(type)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    accountNumber = generateAccountNumber(type);
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

string BankAccount::getLastId(){
    return lastId;
}

void BankAccount::setLastId(string newLastId){
    lastId = newLastId;
}