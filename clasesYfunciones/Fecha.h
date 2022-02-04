#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
private:
    int dia, mes, anio;

public:
    Fecha(int d = 0, int m = 0, int a = 0)
    {
        dia = d;
        mes = m;
        anio = a;
    }

    bool setDia(int d);
    bool setMes(int m);
    bool setAnio(int a);
    int getDia();
    int getMes();
    int getAnio();
    void Mostar();
    void Cargar();
};

#endif // FECHA_H_INCLUDED