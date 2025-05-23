#include "BankMovement.h"
#include <chrono>
using namespace std;

string BankMovement::lastId = "0000001";

string BankMovement::createId(void){
   string initialNumbers = "23230";
   string newId = initialNumbers + lastId;
   int lastIdNumber = stoi(lastId);
   lastIdNumber++;
   setLastId(to_string(lastIdNumber));
   return newId;
}

string BankMovement::getId(void)
{
   return id;
}

void BankMovement::setId(const string& newId)
{
   id = newId;
}

float BankMovement::getAmmount(void)
{
   return ammount;
}

void BankMovement::setAmmount(float newAmmount)
{
   ammount = newAmmount;
}

User BankMovement::getUser(void)
{
   return user;
}

void BankMovement::setUser(User newUser)
{
   user = newUser;
}

Date BankMovement::getDate(void)
{
   return date;
}

void BankMovement::setDate(Date newDate)
{
   date = newDate;
}

float BankMovement::calculateBalance(void)
{
   return 0.0f;
}

void BankMovement::printReceipt(void)
{
   // TODO : implement
}

string BankMovement::getLastId() {
    return lastId;
}

void BankMovement::setLastId(const string& newLastId) {
    lastId = newLastId;
}

BankMovement::BankMovement(float ammount, User user, Date date)
    : id(createId()), ammount(ammount), user(user), date(date)
{
}

BankMovement::BankMovement()
{
}