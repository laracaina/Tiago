#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <iostream>
#include "Ventas.h"
using namespace std;

class Clientes{
    protected:
        int idCliente , dni;
        bool esSocio , estado;
        char nombre[31] , apellido[31];


    public:
        void Cargar();
        void Mostrar();
        bool leerEnDisco(int pos);
        bool grabarEnDisco();
        bool grabarEnDisco(int pos);
        bool getSocio(){return esSocio;}
        void bajaCliente();
        int getId(){return idCliente;}

};

int autoIDClientes(){
    FILE *p;
    p=fopen("clientes.dat", "ab+");
    fseek(p,0,2);
    int tam=ftell(p)/sizeof(Clientes);
    fclose(p);
    return tam+1;
}

void Clientes::Cargar(){
     idCliente = autoIDClientes();
cout<<"Ingresar nombre del cliente: ";
cin>>nombre;
cout<<"Ingresar apellido del cliente: ";
cin>>apellido;
cout<<"Ingresar dni: ";
cin>>dni;
cout<<"Ingresar si es socio (1=si, 0=no): ";
cin>>esSocio;
estado = true;
}
void Clientes::Mostrar(){

    if(estado==true){
    cout<<"Id del cliente: "<<idCliente<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"Socio: ";
    if(esSocio){cout<<"Si"<<endl;}else{cout<<"No"<<endl;}
    }

}

bool Clientes::leerEnDisco(int pos){
    FILE *p;
    p=fopen("clientes.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos*sizeof *this,0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}

bool Clientes::grabarEnDisco(){
    FILE *p;
    p=fopen("clientes.dat","ab+");
    if(p==NULL) return false;
    bool grabo=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}
bool Clientes::grabarEnDisco(int pos){
    FILE *p;
    p=fopen("clientes.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos*sizeof (this),SEEK_SET);
    bool grabo=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}

void Clientes::bajaCliente(){
estado = false;
}
void listarClientes(){
Clientes obj;
    int pos=0;
    while(obj.leerEnDisco(pos++)){
        obj.Mostrar();
        cout<<endl<<endl;
    }
    system("pause");

}
void agregarClientes(){
Clientes obj;
obj.Cargar();
obj.grabarEnDisco();

}



void eliminarCliente(){
int id;
Clientes ClienteEliminar;
cout<<"Ingresar id: ";
cin>>id;
bool leyo = ClienteEliminar.leerEnDisco(id-1);
if(!leyo){
        cout<<"No existe el id.";
}else{
ClienteEliminar.bajaCliente();
ClienteEliminar.grabarEnDisco(id-1);
}
}



void buscarClienteID(){
Clientes obj;
int id , pos=0;
cout<<"Ingresar id a buscar: ";
cin>>id;
while(obj.leerEnDisco(pos++)){
    if(obj.getId()== id){
        obj.Mostrar();
    }
    else{cout<<"No existe ese ID"<<endl;}
}
}
void clientesSocios(){
Clientes obj;
int pos=0;

while(obj.leerEnDisco(pos++)){
    if(obj.getSocio()== true){
        obj.Mostrar();
    }
}
}

void backUpClientes(){
     FILE* p=fopen("clientes.dat","rb+");
    FILE* archivoBackup=fopen("backupClientes.dat","wb+");

    Ventas x;
    fread(&x,sizeof(Clientes),1,p);
    while(!feof(p)){
        fwrite(&x,sizeof(Clientes),1,archivoBackup);
        fread(&x,sizeof(Clientes),1,p);
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

#endif // CLIENTES_H_INCLUDED