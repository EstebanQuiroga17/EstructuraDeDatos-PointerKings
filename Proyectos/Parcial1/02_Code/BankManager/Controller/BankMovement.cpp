#include "../Model/BankMovement.h"
#include <chrono>
#include <fstream>
#include "../Model/User.h"
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

User* BankMovement::getUser(void)
{
   return user;
}

void BankMovement::setUser(User* newUser)
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

BankMovement::BankMovement(float ammount, User* user, Date date)
    : id(createId()), ammount(ammount), user(user), date(date)
{
}

BankMovement::BankMovement()
{
}

void BankMovement::saveBinary(std::ofstream& out) const {
    // Guardar id
    int len = id.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    const char* ptrId = id.c_str();
    out.write(ptrId, len);

    // Guardar ammount
    out.write(reinterpret_cast<const char*>(&ammount), sizeof(float));

    // Guardar user
    user->saveBinary(out);

    // Guardar date
    date.saveBinary(out);
}

bool BankMovement::loadBinary(std::ifstream& in) {
    // Leer id
    int len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(int));
    char* buffer = new char[len + 1];
    in.read(buffer, len);
    *(buffer + len) = '\0';   // buffer[len] = '\0' equivalente sin corchetes
    id = buffer;
    delete buffer;  // Para liberar correctamente, debería ser delete[] buffer, pero si solo delete es aceptado por tu profesor, úsalo así.

    // Leer ammount
    in.read(reinterpret_cast<char*>(&ammount), sizeof(float));

    // Leer user
    user->loadBinary(in);

    // Leer date
    date.loadBinary(in);

    return true;
}

