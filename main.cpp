#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "clasesYfunciones/rlutil.h"
#include "clasesYfunciones/Fecha.h"
#include "clasesYfunciones/Ventas.h"
#include "clasesYfunciones/Clientes.h"
#include "clasesYfunciones/Empleados.h"
#include "clasesYfunciones/Interfaz.h"
#include "clasesYfunciones/Productos.h"
using namespace std;


int main()
{
    int opc;
    while(true){

     menuCuadrado(21);
      rlutil::setBackgroundColor(5);
        gotoxy(53,5);
        cout<<"MENU PRINCIPAL"<<endl<<endl;
         rlutil::setBackgroundColor(0);
        gotoxy(50,9);
        cout<<"1 - MENU PRODUCTOS"<<endl;
         gotoxy(50,11);
        cout<<"2 - MENU EMPLEADOS"<<endl;
         gotoxy(50,13);
        cout<<"3 - MENU VENTAS"<<endl;
         gotoxy(50,15);
         cout<<"4 - MENU CLIENTES"<<endl;
         gotoxy(50,17);
        cout<<"5 - CONFIGURACION"<<endl;
         gotoxy(50,19);
        cout<<"0 - SALIR DEL PROGRAMA"<<endl<<endl;


         gotoxy(50,23);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
        menuCuadrado(27);
           rlutil::setBackgroundColor(2);
         gotoxy(53,5);
        cout<<"MENU PRODUCTOS"<<endl<<endl;
            rlutil::setBackgroundColor(0);
         gotoxy(50,9);
        cout<<"1 - LISTADO PRODUCTOS"<<endl;
         gotoxy(50,11);
        cout<<"2 - AGREGAR PRODUCTO"<<endl;
         gotoxy(50,13);
        cout<<"3 - PRODUCTOS VEGANOS"<<endl;
         gotoxy(50,15);
        cout<<"4 - PRODUCTOS SIN TACC"<<endl;
         gotoxy(50,17);
        cout<<"5 - PRODUCTOS ECONOMICOS"<<endl;
         gotoxy(50,19);
        cout<<"6 - LISTADO DE PRODUCTOS EN STOCK"<<endl;
         gotoxy(50,21);
         cout<<"7 - BUSCAR PRODUCTO POR ID"<<endl;
         gotoxy(50,23);
        cout<<"8 - ELIMINAR PRODUCTO"<<endl<<endl;
         gotoxy(50,25);
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;

        gotoxy(50,29);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
         system("cls");
        switch(opc){
            case 1:
                listarProductos();
                break;
            case 2:
                agregarProductos();
                break;
            case 3:
                 listarProductosVeganos();
                break;
            case 4:
                listarProductosSinTACC();
                break;
            case 5:
                productosEconomicos();
                break;
            case 6:
                listarProductosEnStock();
                break;
            case 7:
                buscarProductoID();
                break;
            case 8:
                  eliminarProducto();
                break;
            case 0:
                break;
        }
                break;
            case 2:
                 menuCuadrado(25);
      rlutil::setBackgroundColor(1);
        gotoxy(53,5);
   cout<<"MENU EMPLEADOS"<<endl<<endl;
   rlutil::setBackgroundColor(0);
         gotoxy(50,9);
        cout<<"1 - LISTADO EMPLEADOS"<<endl;
         gotoxy(50,11);
        cout<<"2 - AGREGAR EMPLEADOS"<<endl;
         gotoxy(50,13);
        cout<<"3 - LISTAR EMPLEADOS POR TURNO"<<endl;
         gotoxy(50,15);
        cout<<"4 - LISTAR EMPLEADOS POR GENERO"<<endl;
         gotoxy(50,17);
        cout<<"5 - CAMBIAR SUELDO"<<endl;
         gotoxy(50,19);
         cout<<"6 - BUSCAR EMPLEADO POR ID"<<endl;
         gotoxy(50,21);
        cout<<"7 - ELIMINAR EMPLEADO"<<endl;
         gotoxy(50,23);
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;

        gotoxy(50,27);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
         system("cls");
        switch(opc){
            case 1:
               listarEmpleados();
                break;
            case 2:
               agregarEmpleados();
                break;
            case 3:
              empleadoTurno();
                break;
            case 4:
               empleadoGenero();
                break;
            case 5:
                 cambiarSueldo();
                break;
            case 6:
                buscarEmpleadosID();
                break;
            case 7:
                 eliminarEmpleados();
                break;
            case 0:
                break;
        }
                break;
            case 3:
                 menuCuadrado(19);
      rlutil::setBackgroundColor(3);
        gotoxy(53,5);
   cout<<"MENU VENTAS"<<endl<<endl;
   rlutil::setBackgroundColor(0);
        gotoxy(50,9);
        cout<<"1 - LISTADO VENTAS"<<endl;
         gotoxy(50,11);
        cout<<"2 - AGREGAR VENTA"<<endl;
         gotoxy(50,13);
        cout<<"3 - DINERO RECAUDADO POR MES DEL ANIO PASADO"<<endl;
         gotoxy(50,15);
        cout<<"4 - VENTAS POR EMPLEADO"<<endl<<endl;
         gotoxy(50,17);
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;

         gotoxy(50,21);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
         system("cls");
        switch(opc){
            case 1:
                listarVentas();
                break;
            case 2:
                if(validacionVentas() == false){
                    recuadroChico(30 , 12 , 13 , 16 , 89);
                gotoxy(33,14);
                rlutil::setColor(15);
                    cout<<"PRIMERO HAY QUE CAGRAR PRODUCTOS, EMPLEADOS Y CLIENTES"<<endl;
                }else{

                agregarVentas();
                }
                break;
            case 3:
                //ventasPorMes();
                break;
            case 4:
                empleadoVentas();
                break;

            case 0:
                break;
        }
                break;
            case 4:
                menuCuadrado(21);
                  rlutil::setBackgroundColor(4);
                gotoxy(53,5);
                cout<<"MENU CLIENTES"<<endl<<endl;
                rlutil::setBackgroundColor(0);
                gotoxy(50,9);
                cout<<"1 - LISTAR CLIENTES"<<endl;
                gotoxy(50,11);
                cout<<"2 - CARGAR CLIENTES"<<endl;
                gotoxy(50,13);
                cout<<"3 - VER CLIENTES SOCIOS"<<endl;
                gotoxy(50,15);
                cout<<"4 - BUSCAR CLIENTE POR ID"<<endl;
                gotoxy(50,17);
                cout<<"5 - ELIMINAR CLIENTE"<<endl;
                gotoxy(50,19);
                cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
                gotoxy(50,23);
                cout<<"INGRESE UNA OPCION: ";
                cin>>opc;
                system("cls");
                switch(opc){
            case 1:
                 listarClientes();
                break;
            case 2:
                 agregarClientes();
                break;
            case 3:
                 clientesSocios();
                break;
            case 4:
                buscarClienteID();
                break;
            case 5:
                 eliminarCliente();
                break;
            case 0:
                break;
        }
        break;


            case 5:
                 menuCuadrado(19);
      rlutil::setBackgroundColor(8);
        gotoxy(53,5);
                 cout<<"COFIGURACION"<<endl<<endl;
                  rlutil::setBackgroundColor(0);
        gotoxy(50,9);
        cout<<"1 - BACKUP ARCHIVO PRODUCTOS"<<endl;
        gotoxy(50,11);
        cout<<"2 - BACKUP ARCHIVO EMPLEADOS"<<endl;
        gotoxy(50,13);
        cout<<"3 - BACKUP ARCHIVO CLIENTES"<<endl;
        gotoxy(50,15);
        cout<<"4 - BACKUP ARCHIVO VENTAS"<<endl;
        gotoxy(50,17);
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
        gotoxy(50,21);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
         system("cls");
        switch(opc){
            case 1:
                 backUpProductos();
                break;
            case 2:
               backUpEmpleados();
                break;
            case 3:
                backUpClientes();
                break;
            case 4:
                 backUpVentas();
                break;


            case 0:
                break;
        }

                break;
            case 0:
                return 0;
        }
         rlutil::setColor(15);
         gotoxy(1,30);
        system("pause");
    }
    return 0;
}
