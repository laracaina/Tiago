#include <iostream>
#include <stdio.h>
#include "Fecha.h"
#include "Cliente.h"
#include "Producto.h"
#include "Venta.h"
using namespace std;

void Venta::Cargar()
{
    cout << "Ingresar el id del cliente que realizo la compra: ";
    cin >> idCliente;
    Cliente cliente;
    cliente.leerEnDisco(idCliente - 1);
    bool IsSocio = cliente.getSocio();
    cout << "Ingresar el id del empleado que vendio: ";
    cin >> idEmpleado;

    cout << "Ingresar id producto: ";
    cin >> idProductos[0];

    for (int i = 0; i < 100 && idProductos[i] != 0; i++)
    {
        cout << "Ingresar cantidad de productos vendidos: ";
        cin >> cantVendida[i];
        lenghtProducto++;
        cout << "Ingresar id producto: ";
        cin >> idProductos[i + 1];
    }

    cout << "Ingresar la fecha de la venta: ";
    fechaDeVenta.Cargar();

    for (int i = 0; i < lenghtProducto; i++)
    {
        int id = idProductos[i];
        int cant = cantVendida[i];

        Producto prod;
        prod.leerEnDisco(id - 1);

        if (IsSocio && prod.getTieneDescuento() == 1)
        {
            precioFinal += (prod.getPrecio() - (prod.getPrecio() * (prod.getDescuento() / 100))) * cant;
        }
        else
        {
            precioFinal += prod.getPrecio() * cant;
        }
    }
}

void Venta::Mostrar()
{
    cout << "Id del empleado que realizo la venta: " << idEmpleado << endl;
    cout << "Id del cliente que realizo la compra: " << idCliente << endl;
    for (int i = 0; i < lenghtProducto; i++)
    {
        cout << "Se vendieron " << cantVendida[i] << " del producto numero " << idProductos[i] << endl;
    }

    cout << "Precio final de compra: $" << precioFinal << endl;
    cout << "Fecha: ";
    fechaDeVenta.Mostar();
}

bool Venta::leerEnDisco(int pos)
{
    FILE *p;
    p = fopen("ventas.dat", "rb+");
    if (p == NULL)
        return false;
    fseek(p, pos * sizeof *this, 0);
    bool leyo = fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}

bool Venta::grabarEnDisco()
{
    FILE *p;
    p = fopen("ventas.dat", "ab+");
    if (p == NULL)
        return false;
    bool grabo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}

void Venta::listarVentas()
{
    Venta obj;
    int pos = 0;
    while (obj.leerEnDisco(pos++))
    {
        obj.Mostrar();
        cout << endl
             << endl;
    }
    system("pause");
}
void Venta::agregarVentas()
{
    Venta obj;
    obj.Cargar();
    obj.grabarEnDisco();
}

/*void ventasPorMes(){
int pos=0 , v[12];
Venta obj;

for(int i =0; i<12 ; i++){
    v[i]=0;
}

while(obj.leerEnDisco(pos++)){
        for(int i =0; i<12 ; i++){

           if(obj.getFechaDeVenta().getAnio()== 2021){
            if(obj.getFechaDeVenta().getMes() == i){
                v[i-1] = v[i-1]+(obj.getCantVendidas()*obj.getPrecioFinal());
            }
        }

}
}
for(int i=0; i<12 ; i++){

    cout<<"En el mes "<<i+1<<" de 2021 se recaudaron $"<<v[i]<<endl;
}
}
*/

void Venta::backUpVentas()
{
    FILE *p = fopen("ventas.dat", "rb+");
    FILE *archivoBackup = fopen("backupVentas.dat", "wb+");

    Venta x;
    fread(&x, sizeof(Venta), 1, p);
    while (!feof(p))
    {
        fwrite(&x, sizeof(Venta), 1, archivoBackup);
        fread(&x, sizeof(Venta), 1, p);
    }

    fclose(archivoBackup);
    fclose(p);

    if (archivoBackup == NULL)
    {
        cout << "NO SE PUDO HACER EL BACKUP";
    }
    else
    {
        cout << "SE REALIZO EL BACKUP EXITOSAMENTE";
    }

    system("pause");
}

bool Venta::validacionVentas()
{
    FILE *p;
    p = fopen("productos.dat", "rb+");
    FILE *a;
    a = fopen("empleados.dat", "rb+");
    FILE *c;
    c = fopen("clientes.dat", "rb+");
    if (p == NULL || a == NULL || c == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

float Venta::getPrecioFinal() { return precioFinal; }
Fecha Venta::getFechaDeVenta() { return fechaDeVenta; }
int *Venta::getCantVendidas() { return cantVendida; }
int Venta::getIdEmpleado() { return idEmpleado; }