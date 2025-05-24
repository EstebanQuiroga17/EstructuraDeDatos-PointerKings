#include "../Model/PersonalData.h"
#include <iostream>

std::string PersonalData::getName(void)
{
   return name;
}

void PersonalData::setName(std::string newName)
{
   name = newName;
}

std::string PersonalData::getLastName(void)
{
   return lastName;
}

void PersonalData::setLastName(std::string newLastName)
{
   lastName = newLastName;
}

std::string PersonalData::getDNI(void)
{
   return DNI;
}

void PersonalData::setDNI(std::string newDNI)
{
   DNI = newDNI;
}

Date PersonalData::getBirthDate(void)
{
   return birthDate;
}

void PersonalData::setBirthDate(Date newBirthDate)
{
   birthDate = newBirthDate;
}

PersonalData::PersonalData()
{

}

PersonalData::PersonalData(std::string name, std::string lastName, std::string DNI, Date birthDate, std::string email)
    : name(name), lastName(lastName), DNI(DNI), birthDate(birthDate), email(email){}


PersonalData::~PersonalData()
{
   
}

std::string PersonalData::getEmail(void)
{
   return email;
}

void PersonalData::setEmail(std::string newEmail)
{
   email = newEmail;
}

void PersonalData::guardarBinario(std::ofstream& out) const {
    // Guardar name
    int len = name.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    const char* ptrName = name.c_str();
    out.write(ptrName, len);

    // Guardar lastName
    len = lastName.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    const char* ptrLastName = lastName.c_str();
    out.write(ptrLastName, len);

    // Guardar DNI
    len = DNI.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    const char* ptrDNI = DNI.c_str();
    out.write(ptrDNI, len);

    // Guardar birthDate
    birthDate.guardarBinario(out);

    // Guardar email
    len = email.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    const char* ptrEmail = email.c_str();
    out.write(ptrEmail, len);

    // Guardar country (si lo usas)
    len = country.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(int));
    const char* ptrCountry = country.c_str();
    out.write(ptrCountry, len);
}

bool PersonalData::cargarBinario(std::ifstream& in) {
    // Leer name
    int len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(int));
    char* buffer = new char[len + 1];
    in.read(buffer, len);
    *(buffer + len) = '\0';
    name = buffer;
    delete buffer;

    // Leer lastName
    in.read(reinterpret_cast<char*>(&len), sizeof(int));
    buffer = new char[len + 1];
    in.read(buffer, len);
    *(buffer + len) = '\0';
    lastName = buffer;
    delete buffer;

    // Leer DNI
    in.read(reinterpret_cast<char*>(&len), sizeof(int));
    buffer = new char[len + 1];
    in.read(buffer, len);
    *(buffer + len) = '\0';
    DNI = buffer;
    delete buffer;

    // Leer birthDate
    birthDate.cargarBinario(in);

    // Leer email
    in.read(reinterpret_cast<char*>(&len), sizeof(int));
    buffer = new char[len + 1];
    in.read(buffer, len);
    *(buffer + len) = '\0';
    email = buffer;
    delete buffer;

    // Leer country (si lo usas)
    in.read(reinterpret_cast<char*>(&len), sizeof(int));
    buffer = new char[len + 1];
    in.read(buffer, len);
    *(buffer + len) = '\0';
    country = buffer;
    delete buffer;

    return true;
}

void PersonalData::mostrar() const {
    std::cout << "Nombre: " << name << std::endl;
    std::cout << "Apellido: " << lastName << std::endl;
    std::cout << "DNI: " << DNI << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Pais: " << country << std::endl;
    std::cout << "[Fecha de nacimiento omitida]" << std::endl;
}