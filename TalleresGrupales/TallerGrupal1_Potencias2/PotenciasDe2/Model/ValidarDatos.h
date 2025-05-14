#ifndef ValidarDatos_h
#define ValidarDatos_h

class ValidarDatos {
public:
    static int validarNumeros(char msj[20]);
    static bool validarAnioBisiesto(int anio);
    static int validarMes(int mes, int anio);
    static bool validarDia(int dia, int mes);
};
#endif
