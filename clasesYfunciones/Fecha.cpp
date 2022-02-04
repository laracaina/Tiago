#include <iostream>
#include "Fecha.h"
using namespace std;

bool Fecha::setDia(int d)
{
    if (d > 0 && d < 32)
    {
        dia = d;
        return true;
    }
}
bool Fecha::setMes(int m)
{
    if (m > 0 && m < 13)
    {
        mes = m;
        return true;
    }
}
bool Fecha::setAnio(int a)
{
    if (a > 0 && a < 2022)
    {
        anio = a;
        return true;
    }
}
int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return anio; }

void Fecha::Cargar()
{
    int d, m, a;
    cout << "Dia: ";
    cin >> d;

    while (!setDia(d))
    {
        cout << "El dia no es valido." << endl;
        cout << "Dia: ";
        cin >> d;
    }

    cout << "Mes: ";
    cin >> m;
    while (!setMes(m))
    {
        cout << "El mes no es valido." << endl;
        cout << "Mes: ";
        cin >> m;
    }

    cout << "Anio: ";
    cin >> a;
    while (!setAnio(a))
    {
        cout << "El anio no es valido." << endl;
        cout << "Anio: ";
        cin >> a;
    }
}

void Fecha::Mostar()
{

    cout << dia << "/" << mes << "/" << anio << endl;
}