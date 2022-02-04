#include <iostream>
#include <stdio.h>
#include "Producto.h"
using namespace std;

int autoIDProduct()
{
    FILE *p;
    p = fopen("productos.dat", "ab+");
    fseek(p, 0, 2);
    int tam = ftell(p) / sizeof(Producto);
    fclose(p);
    return tam + 1;
}

void Producto::Cargar()
{
    idProducto = autoIDProduct();

    cout << "Ingresar nombre del producto: ";
    cin >> nombreProducto;
    cout << "Ingresar si es vegano: ";
    cin >> esVegano;
    cout << "Ingresar si es sin Tacc: ";
    cin >> esSinTACC;
    cout << "Ingresar si hay stock: ";
    cin >> stock;
    cout << "Ingresar si tiene descuento para socios: ";
    cin >> tieneDescuento;
    if (tieneDescuento == 1)
    {
        cout << "Ingresar porcentaje de descuento: ";
        cin >> descuento;
    }

    cout << "Ingresar precio: ";
    cin >> precio;
    estado = true;
}

void Producto::Mostrar()
{
    if (estado)
    {
        cout << "Id del producto: " << idProducto << endl;
        cout << "Nombre del producto: " << nombreProducto << endl;
        cout << "Es vegano: ";
        if (esVegano == true)
        {
            cout << "si" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        cout << "Es SinTacc: ";
        if (esSinTACC == true)
        {
            cout << "si" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        cout << "Hay stock: ";
        if (stock == true)
        {
            cout << "si" << endl;
        }
        else
        {
            cout << "no" << endl;
        }

        cout << "Tiene descuento para socios: ";
        if (tieneDescuento == 1)
        {
            cout << "si" << endl;
            cout << "Porcentaje de descuento: " << descuento << "%" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        cout << "El precio es: $" << precio << endl;
    }
}

void Producto::listarProductos()
{
    Producto obj;
    int pos = 0;
    while (obj.leerEnDisco(pos++))
    {
        obj.Mostrar();
        cout << endl
             << endl;
    }
    system("pause");
}

void Producto::agregarProductos()
{
    Producto obj;
    obj.Cargar();
    obj.grabarEnDisco();
}

bool Producto::leerEnDisco(int pos)
{
    FILE *p;
    p = fopen("productos.dat", "rb+");
    if (p == NULL)
        return false;
    fseek(p, pos * sizeof *this, 0);
    bool leyo = fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}

bool Producto::grabarEnDisco()
{
    FILE *p;
    p = fopen("productos.dat", "ab+");
    if (p == NULL)
        return false;
    bool grabo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}

bool Producto::grabarEnDisco(int pos)
{
    FILE *p;
    p = fopen("productos.dat", "rb+");
    if (p == NULL)
        return false;
    fseek(p, pos * sizeof(this), SEEK_SET);
    bool grabo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}

void Producto::bajaProducto()
{
    estado = false;
}

void Producto::eliminarProducto()
{
    int id;
    Producto ProductoEliminar;
    cout << "Ingresar id: ";
    cin >> id;
    bool leyo = ProductoEliminar.leerEnDisco(id - 1);
    if (!leyo)
    {
        cout << "No existe el id.";
    }
    else
    {
        ProductoEliminar.bajaProducto();
        ProductoEliminar.grabarEnDisco(id - 1);
    }
}

void Producto::listarProductosVeganos()
{
    Producto obj;
    int pos = 0;
    while (obj.leerEnDisco(pos++))
    {
        if (obj.getEsVegano() == true)
        {
            obj.Mostrar();
        }
    }
}

void Producto::listarProductosSinTACC()
{
    Producto obj;
    int pos = 0;
    while (obj.leerEnDisco(pos++))
    {
        if (obj.getEsSinTacc() == true)
        {
            obj.Mostrar();
        }
    }
}
void Producto::listarProductosEnStock()
{
    Producto obj;
    int pos = 0;
    while (obj.leerEnDisco(pos++))
    {
        if (obj.getStock() == true)
        {
            obj.Mostrar();
        }
    }
}
void Producto::productosEconomicos()
{
    Producto obj;
    int pos = 0;
    while (obj.leerEnDisco(pos++))
    {

        if (obj.getPrecio() < 500)
        {
            obj.Mostrar();
        }
    }
}
void Producto::buscarProductoID()
{
    Producto obj;
    int id, pos = 0;
    cout << "Ingresar id a buscar: ";
    cin >> id;
    while (obj.leerEnDisco(pos++))
    {
        if (obj.getId() == id)
        {
            obj.Mostrar();
        }
        else
        {
            cout << "No existe ese ID" << endl;
        }
    }
}

void Producto::backUpProductos()
{
    FILE *p = fopen("productos.dat", "rb+");
    FILE *archivoBackup = fopen("backupProductos.dat", "wb+");

    Producto x;
    fread(&x, sizeof(Producto), 1, p);
    while (!feof(p))
    {
        fwrite(&x, sizeof(Producto), 1, archivoBackup);
        fread(&x, sizeof(Producto), 1, p);
    }

    fclose(archivoBackup);
    fclose(p);

    if (archivoBackup == NULL)
    {
        cout << "NO SE PUDO HACER EL BACKUP" << endl;
    }
    else
    {
        cout << "SE REALIZO EL BACKUP EXITOSAMENTE" << endl;
    }

    system("pause");
}

bool Producto::getEsVegano() { return esVegano; }
bool Producto::getEsSinTacc() { return esSinTACC; }
bool Producto::getStock() { return stock; }
float Producto::getPrecio() { return precio; }
bool Producto::getTieneDescuento() { return tieneDescuento; }
float Producto::getDescuento() { return descuento; }
int Producto::getId() { return idProducto; }