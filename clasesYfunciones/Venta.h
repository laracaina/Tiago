#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "Fecha.h"

class Venta
{
protected:
    int idProductos[100], cantVendida[100], idEmpleado, idCliente;
    float precioFinal = 0;
    int lenghtProducto = 0;
    Fecha fechaDeVenta;

public:
    void Cargar();
    void Mostrar();
    bool leerEnDisco(int pos);
    bool grabarEnDisco();
    float getPrecioFinal() { return precioFinal; }
    Fecha getFechaDeVenta() { return fechaDeVenta; }
    int *getCantVendidas() { return cantVendida; }
    int getIdEmpleado() { return idEmpleado; }
    static void listarVentas();
    static void agregarVentas();
    static void backUpVentas();
    static bool validacionVentas();
};

#endif // VENTAS_H_INCLUDED
