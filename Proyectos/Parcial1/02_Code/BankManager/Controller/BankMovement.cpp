#include "../Model/BankMovement.h"
#include <chrono>
#include <fstream>
#include "../Model/User.h"
#include "../Model/BinaryCifration.h"
using namespace std;

int BankMovement::lastId = 0;

string BankMovement::createId(void){
   if(!BinaryCifration::loadInt(lastId, "BankMovementsIdConfig.dat"))
      lastId=1;
   string initialNumbers = "23230-";
   string lastIdString = to_string(lastId);
   string id = initialNumbers + lastIdString;
   lastId++;
   BinaryCifration::saveInt(lastId, "BankMovementsIdConfig.dat");
   return id; 
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

void BankMovement::printReceipt(char accountType) {
   std::cout << ">>> IMPRIMIENDO RECIBO <<<" << std::endl;
   std::cout << "[BankMovement] Monto: " << ammount << std::endl;
   std::cout << "DNI: " << userDNI << std::endl;
   std::cout << "Fecha: ";
   date.print(); 
   std::cout << "ID de Movimiento: " << id << std::endl;

}

int BankMovement::getLastId() {
    return lastId;
}

void BankMovement::setLastId(int newLastId) {
    lastId = newLastId;
}

BankMovement::BankMovement(float ammount, User* user, Date date, User* destinationUser)
    : id(createId()), ammount(ammount), date(date),user(user), destinationUser(destinationUser)
{
   userDNI = user->getPersonalData().getDNI();
}

BankMovement::BankMovement()
{
}

void BankMovement::saveBinary(std::ofstream& out) const {
    
    int len = id.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    out.write(id.c_str(), len);

    
    out.write(reinterpret_cast<const char*>(&ammount), sizeof(float));

    
    int dniLen = userDNI.size();
    out.write(reinterpret_cast<const char*>(&dniLen), sizeof(int));
    out.write(userDNI.c_str(), dniLen);

    
    date.saveBinary(out);
}


bool BankMovement::loadBinary(std::ifstream& in) {
    
    int len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(int));
    char* buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    id = buffer;
    delete[] buffer;

    
    in.read(reinterpret_cast<char*>(&ammount), sizeof(float));

    
    int dniLen = 0;
    in.read(reinterpret_cast<char*>(&dniLen), sizeof(int));
    char* bufferDNI = new char[dniLen + 1];
    in.read(bufferDNI, dniLen);
    bufferDNI[dniLen] = '\0';
    userDNI = bufferDNI;
    delete[] bufferDNI;

    
    date.loadBinary(in);

    return true;
}


