#include "../Model/Name.h"
#include "../Model/NameValidator.h"
#include "../Model/QuickSort.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char* nameInput = NameValidator::validarNombre("Ingrese un nombre: ");
    cout << endl;
    Name name(nameInput);
    QuickSort::quickSort(name.getLowerCaseName(), 0, strlen(name.getLowerCaseName()) - 1);
    cout<<endl;
    name.printName();
    delete[] nameInput; 
}