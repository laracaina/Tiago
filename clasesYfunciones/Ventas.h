#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include <iostream>
#include "Fecha.h"
#include "Clientes.h"
using namespace std;

class Ventas{
    protected:
        int idProductos[100] , cantVendida[100] ,  idEmpleado , idCliente;
        float precioFinal=0;
        int lenghtProducto=0;
        Fecha fechaDeVenta;

    public:
        void Cargar();
        void Mostrar();
        bool leerEnDisco(int pos);
        bool grabarEnDisco();
        float getPrecioFinal(){return precioFinal;}
        Fecha getFechaDeVenta(){return fechaDeVenta;}
        int* getCantVendidas(){return cantVendida;}
        int getIdEmpleado(){return idEmpleado;}
};

void Ventas::Cargar()
{
    cout<<"Ingresar el id del cliente que realizo la compra: ";
    cin>>idCliente;
    Clientes cliente;
    cliente.leerEnDisco(idCliente-1);
    bool IsSocio = cliente.getSocio();
    cout<<"Ingresar el id del empleado que vendio: ";
    cin>>idEmpleado;


    cout<<"Ingresar id producto: ";
    cin>>idProductos[0];


    for(int i=0; i<100 && idProductos[i]!=0; i++){
        cout<<"Ingresar cantidad de productos vendidos: ";
        cin>>cantVendida[i];
        lenghtProducto++;
        cout<<"Ingresar id producto: ";
        cin>>idProductos[i+1];
    }

    cout<<"Ingresar la fecha de la venta: ";
    fechaDeVenta.Cargar();

    for(int i=0;i<lenghtProducto;i++){
    int id=idProductos[i];
	int cant=cantVendida[i];

	Productos prod;
	prod.leerEnDisco(id-1);

	if(IsSocio && prod.getTieneDescuento()== 1){
		precioFinal+=(prod.getPrecio()-(prod.getPrecio()*(prod.getDescuento()/100)))*cant;
	}
	else{
		precioFinal+=prod.getPrecio()*cant;
    }

}
}


void Ventas::Mostrar(){
    cout<<"Id del empleado que realizo la venta: "<<idEmpleado<<endl;
    cout<<"Id del cliente que realizo la compra: "<<idCliente<<endl;
    for(int i = 0; i<lenghtProducto; i++){
      cout<<"Se vendieron "<<cantVendida[i] <<" del producto numero "<<idProductos[i]<<endl;
    }

    cout<<"Precio final de compra: $"<<precioFinal<<endl;
    cout<<"Fecha: ";
    fechaDeVenta.Mostar();
}








bool Ventas::leerEnDisco(int pos){
    FILE *p;
    p=fopen("ventas.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos*sizeof *this,0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}

bool Ventas::grabarEnDisco(){
    FILE *p;
    p=fopen("ventas.dat","ab+");
    if(p==NULL) return false;
    bool grabo=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}


void listarVentas(){
Ventas obj;
    int pos=0;
    while(obj.leerEnDisco(pos++)){
        obj.Mostrar();
        cout<<endl<<endl;
    }
    system("pause");

}
void agregarVentas(){
Ventas obj;
obj.Cargar();
obj.grabarEnDisco();

}




/*void ventasPorMes(){
int pos=0 , v[12];
Ventas obj;

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






void backUpVentas(){
     FILE* p=fopen("ventas.dat","rb+");
    FILE* archivoBackup=fopen("backupVentas.dat","wb+");

    Ventas x;
    fread(&x,sizeof(Ventas),1,p);
    while(!feof(p)){
        fwrite(&x,sizeof(Ventas),1,archivoBackup);
        fread(&x,sizeof(Ventas),1,p);
    }

    fclose(archivoBackup);
    fclose(p);

    if(archivoBackup == NULL){
        cout<<"NO SE PUDO HACER EL BACKUP";
    }else{
    cout<<"SE REALIZO EL BACKUP EXITOSAMENTE";
    }

   system("pause");
}



bool validacionVentas(){
FILE *p;
    p=fopen("productos.dat","rb+");
    FILE *a;
    a=fopen("empleados.dat","rb+");
    FILE *c;
    c=fopen("clientes.dat" , "rb+");
    if(p==NULL || a==NULL || c==NULL){
        return false;
    }else{return true;}

}

#endif // VENTAS_H_INCLUDED
