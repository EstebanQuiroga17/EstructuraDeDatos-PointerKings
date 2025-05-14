

#include "../Model/PotenciasDeDos.h"


int PotenciasDeDos::potenciar(int potencia, int base)
{
   int result = 1;
   for(int i = 0; i < potencia; i++){
        result = base*result;
   }
   return result;
}

int PotenciasDeDos::resolverSerie(int indiceFinal)
{
     if (indiceFinal == 0)
        return potenciar(0, 2);
    else
        return potenciar(indiceFinal, 2) + resolverSerie(indiceFinal - 1);
}
