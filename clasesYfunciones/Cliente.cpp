#include <iostream>
#include <stdio.h>
#include "Cliente.h"
#include "Venta.h"
using namespace std;

int autoIDClientes()
{
    FILE *p;
    p = fopen("clientes.dat", "ab+");
    fseek(p, 0, 2);
    int tam = ftell(p) / sizeof(Cliente);
    fclose(p);
    return tam + 1;
}

void Cliente::Cargar()
{
    idCliente = autoIDClientes();
    cout << "Ingresar nombre del cliente: ";
    cin >> nombre;
    cout << "Ingresar apellido del cliente: ";
    cin >> apellido;
    cout << "Ingresar dni: ";
    cin >> dni;
    cout << "Ingresar si es socio (1=si, 0=no): ";
    cin >> esSocio;
    estado = true;
}
void Cliente::Mostrar()
{

    if (estado == true)
    {
        cout << "Id del cliente: " << idCliente << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "DNI: " << dni << endl;
        cout << "Socio: ";
        if (esSocio)
        {
            cout << "Si" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

bool Cliente::leerEnDisco(int pos)
{
    FILE *p;
    p = fopen("clientes.dat", "rb+");
    if (p == NULL)
        return false;
    fseek(p, pos * sizeof *this, 0);
    bool leyo = fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}

bool Cliente::grabarEnDisco()
{
    FILE *p;
    p = fopen("clientes.dat", "ab+");
    if (p == NULL)
        return false;
    bool grabo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}
bool Cliente::grabarEnDisco(int pos)
{
    FILE *p;
    p = fopen("clientes.dat", "rb+");
    if (p == NULL)
        return false;
    fseek(p, pos * sizeof(this), SEEK_SET);
    bool grabo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}

void Cliente::bajaCliente()
{
    estado = false;
}
void Cliente::listarClientes()
{
    Cliente obj;
    int pos = 0;
    while (obj.leerEnDisco(pos++))
    {
        obj.Mostrar();
        cout << endl
             << endl;
    }
    system("pause");
}
void Cliente::agregarClientes()
{
    Cliente obj;
    obj.Cargar();
    obj.grabarEnDisco();
}

void Cliente::eliminarCliente()
{
    int id;
    Cliente ClienteEliminar;
    cout << "Ingresar id: ";
    cin >> id;
    bool leyo = ClienteEliminar.leerEnDisco(id - 1);
    if (!leyo)
    {
        cout << "No existe el id.";
    }
    else
    {
        ClienteEliminar.bajaCliente();
        ClienteEliminar.grabarEnDisco(id - 1);
    }
}

void Cliente::buscarClienteID()
{
    Cliente obj;
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
void Cliente::clientesSocios()
{
    Cliente obj;
    int pos = 0;

    while (obj.leerEnDisco(pos++))
    {
        if (obj.getSocio() == true)
        {
            obj.Mostrar();
        }
    }
}

void Cliente::backUpClientes()
{
    FILE *p = fopen("clientes.dat", "rb+");
    FILE *archivoBackup = fopen("backupClientes.dat", "wb+");

    Venta x;
    fread(&x, sizeof(Cliente), 1, p);
    while (!feof(p))
    {
        fwrite(&x, sizeof(Cliente), 1, archivoBackup);
        fread(&x, sizeof(Cliente), 1, p);
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

bool Cliente::getSocio() { return esSocio; }
int Cliente::getId() { return idCliente; }