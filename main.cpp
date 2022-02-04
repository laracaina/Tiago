#include <iostream>
#include "clasesYfunciones/rlutil.h"
#include "clasesYfunciones/Interfaz.h"
#include "clasesYfunciones/Venta.h"
#include "clasesYfunciones/Cliente.h"
#include "clasesYfunciones/Producto.h"
#include "clasesYfunciones/Empleado.h"
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
                Producto::listarProductos();
                break;
            case 2:
                Producto::agregarProductos();
                break;
            case 3:
                 Producto::listarProductosVeganos();
                break;
            case 4:
                Producto::listarProductosSinTACC();
                break;
            case 5:
                Producto::productosEconomicos();
                break;
            case 6:
                Producto::listarProductosEnStock();
                break;
            case 7:
                Producto::buscarProductoID();
                break;
            case 8:
                  Producto::eliminarProducto();
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
               Empleado::listarEmpleados();
                break;
            case 2:
               Empleado::agregarEmpleados();
                break;
            case 3:
              Empleado::empleadoTurno();
                break;
            case 4:
               Empleado::empleadoGenero();
                break;
            case 5:
                 Empleado::cambiarSueldo();
                break;
            case 6:
                Empleado::buscarEmpleadosID();
                break;
            case 7:
                 Empleado::eliminarEmpleados();
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
                Venta::listarVentas();
                break;
            case 2:
                if(Venta::validacionVentas() == false){
                    recuadroChico(30 , 12 , 13 , 16 , 89);
                gotoxy(33,14);
                rlutil::setColor(15);
                    cout<<"PRIMERO HAY QUE CAGRAR PRODUCTOS, EMPLEADOS Y CLIENTES"<<endl;
                }else{

                Venta::agregarVentas();
                }
                break;
            case 3:
                //ventasPorMes();
                break;
            case 4:
                Empleado::empleadoVentas();
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
                 Cliente::listarClientes();
                break;
            case 2:
                 Cliente::agregarClientes();
                break;
            case 3:
                 Cliente::clientesSocios();
                break;
            case 4:
                Cliente::buscarClienteID();
                break;
            case 5:
                 Cliente::eliminarCliente();
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
                 Producto::backUpProductos();
                break;
            case 2:
               Empleado::backUpEmpleados();
                break;
            case 3:
                Cliente::backUpClientes();
                break;
            case 4:
                 Venta::backUpVentas();
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
