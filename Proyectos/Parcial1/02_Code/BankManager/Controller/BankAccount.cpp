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

std::string BankAccount::getAccountNumber(void)
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

string BankAccount::generateAccountNumber(int digits = 10, std::string number = "") {
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