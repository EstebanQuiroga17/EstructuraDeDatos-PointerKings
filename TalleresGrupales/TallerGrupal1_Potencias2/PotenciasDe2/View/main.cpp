#include <iostream>
#include "../Model/PotenciasDeDos.h"
#include "../Model/ValidarDatos.h"


using namespace std;

int main()
{
    int indiceFinal = ValidarDatos::validarNumeros("Ingrese el indice final: ");
    int resultado = PotenciasDeDos::resolverSerie(indiceFinal);

    cout<<resultado;
}
