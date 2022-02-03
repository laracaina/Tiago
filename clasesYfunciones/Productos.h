#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include <iostream>
using namespace std;

class Productos{
    protected:
        int idProducto;
        bool esVegano , esSinTACC , stock , estado;
        char nombreProducto[100];
        float precio;
        bool tieneDescuento;
        float descuento;

    public:
        void Cargar();
        void Mostrar();
        bool leerEnDisco(int pos);
        bool grabarEnDisco();
        bool grabarEnDisco(int pos);
        void bajaProducto();
        bool getEsVegano(){return esVegano;}
        bool getEsSinTacc(){return esSinTACC;}
        bool getStock(){return stock;}
        float getPrecio(){return precio;}
        bool getTieneDescuento(){return tieneDescuento;}
        float getDescuento(){return descuento;}
        int getId(){return idProducto;}

};

int autoIDProduct(){
    FILE *p;
    p=fopen("productos.dat", "ab+");
    fseek(p,0,2);
    int tam=ftell(p)/sizeof(Productos);
    fclose(p);
    return tam+1;
}

void Productos::Cargar(){
    idProducto = autoIDProduct();

    cout<<"Ingresar nombre del producto: ";
    cin>>nombreProducto;
    cout<<"Ingresar si es vegano: ";
    cin>>esVegano;
    cout<<"Ingresar si es sin Tacc: ";
    cin>>esSinTACC;
    cout<<"Ingresar si hay stock: ";
    cin>>stock;
    cout<<"Ingresar si tiene descuento para socios: ";
    cin>>tieneDescuento;
    if(tieneDescuento == 1){
        cout<<"Ingresar porcentaje de descuento: ";
        cin>>descuento;
    }

    cout<<"Ingresar precio: ";
    cin>>precio;
    estado = true;
}

void Productos::Mostrar(){
    if(estado){
        cout<<"Id del producto: "<<idProducto<<endl;
        cout<<"Nombre del producto: "<<nombreProducto<<endl;
        cout<<"Es vegano: ";
        if(esVegano == true){cout<<"si"<<endl;} else{cout<<"no"<<endl;}
        cout<<"Es SinTacc: ";
        if(esSinTACC == true){cout<<"si"<<endl;} else{cout<<"no"<<endl;}
        cout<<"Hay stock: ";
        if(stock == true){cout<<"si"<<endl;} else{cout<<"no"<<endl;}

    cout<<"Tiene descuento para socios: ";
    if(tieneDescuento == 1){cout<<"si"<<endl;
    cout<<"Porcentaje de descuento: "<<descuento<<"%"<<endl;
    }else{cout<<"no"<<endl;}
    cout<<"El precio es: $"<<precio<<endl;
}
}

void listarProductos(){
Productos obj;
    int pos=0;
    while(obj.leerEnDisco(pos++)){
        obj.Mostrar();
        cout<<endl<<endl;
    }
    system("pause");

}


void agregarProductos(){
Productos obj;
obj.Cargar();
obj.grabarEnDisco();

}

bool Productos::leerEnDisco(int pos){
    FILE *p;
    p=fopen("productos.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos*sizeof *this,0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}

bool Productos::grabarEnDisco(){
    FILE *p;
    p=fopen("productos.dat","ab+");
    if(p==NULL) return false;
    bool grabo=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}

bool Productos::grabarEnDisco(int pos){
    FILE *p;
    p=fopen("productos.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos*sizeof (this),SEEK_SET);
    bool grabo=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}

void Productos::bajaProducto(){
estado = false;
}


void eliminarProducto(){
int id;
Productos ProductoEliminar;
cout<<"Ingresar id: ";
cin>>id;
bool leyo = ProductoEliminar.leerEnDisco(id-1);
if(!leyo){
        cout<<"No existe el id.";
}else{
ProductoEliminar.bajaProducto();
ProductoEliminar.grabarEnDisco(id-1);
}
}

void listarProductosVeganos(){
Productos obj;
int pos = 0;
while(obj.leerEnDisco(pos++)){
if(obj.getEsVegano() == true){
    obj.Mostrar();
}
}
}

void listarProductosSinTACC(){
Productos obj;
int pos = 0;
while(obj.leerEnDisco(pos++)){
if(obj.getEsSinTacc() == true){
    obj.Mostrar();
}
}
}
void listarProductosEnStock(){
Productos obj;
int pos = 0;
while(obj.leerEnDisco(pos++)){
if(obj.getStock() == true){
    obj.Mostrar();
}
}
}
void productosEconomicos(){
Productos obj;
int pos=0;
while(obj.leerEnDisco(pos++)){

    if(obj.getPrecio() < 500){
        obj.Mostrar();
    }
}
}
void buscarProductoID(){
Productos obj;
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

void backUpProductos(){
     FILE* p=fopen("productos.dat","rb+");
    FILE* archivoBackup=fopen("backupProductos.dat","wb+");

    Productos x;
    fread(&x,sizeof(Productos),1,p);
    while(!feof(p)){
        fwrite(&x,sizeof(Productos),1,archivoBackup);
        fread(&x,sizeof(Productos),1,p);
    }

    fclose(archivoBackup);
    fclose(p);

    if(archivoBackup == NULL){
        cout<<"NO SE PUDO HACER EL BACKUP"<<endl;
    }else{
    cout<<"SE REALIZO EL BACKUP EXITOSAMENTE"<<endl;
    }

    system("pause");

}

#endif // PRODUCTOS_H_INCLUDED