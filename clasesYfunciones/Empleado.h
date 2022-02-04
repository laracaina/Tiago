#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "Fecha.h"
class Empleado
{
protected:
    int idEmpleado, genero, turno, sueldo;
    Fecha fechaDeNacimiento;
    char nombre[31], apellido[31];
    bool estado;

public:
    void Cargar();
    void Mostrar();
    bool leerEnDisco(int pos);
    bool grabarEnDisco();
    bool grabarEnDisco(int pos);
    void bajaEmpleado();
    void cambiarSueldo2();
    int getTurno();
    int getGenero();
    bool setTurno();
    bool setGenero();
    int getId();
    static void listarEmpleados();
    static void agregarEmpleados();
    static void eliminarEmpleados();
    static void empleadoTurno();
    static void buscarEmpleadosID();
    static void empleadoGenero();
    static void cambiarSueldo();
    static void empleadoVentas();
    static void backUpEmpleados();
};

#endif // EMPLEADO_H_INCLUDED