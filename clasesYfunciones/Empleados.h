#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include <iostream>
using namespace std;

class Empleados{
    protected:
        int idEmpleado , genero , turno , sueldo;
        Fecha fechaDeNacimiento;
        char nombre[31] , apellido [31];
        bool estado;

    public:
        void Cargar();
        void Mostrar();
        bool leerEnDisco(int pos);
        bool grabarEnDisco();
        bool grabarEnDisco(int pos);
        void bajaEmpleados();
        void cambiarSueldo();
        int getTurno(){return turno;}
        int getGenero(){return genero;}
        bool setTurno(){
        if(turno>=1 && turno<=3){return true;}
        else{return false;}
        }
        bool setGenero(){
        if(genero>=1 && genero<=3){return true;}
        else{return false;}
        }
        int getId(){return idEmpleado;}
};

int autoIDEmpleados(){
    FILE *p;
    p=fopen("empleados.dat", "ab+");
    fseek(p,0,2);
    int tam=ftell(p)/sizeof(Empleados);
    fclose(p);
    return tam+1;
}

void Empleados::Cargar(){
    idEmpleado = autoIDEmpleados();

    cout<<"Ingresar nombre del empleado: ";
    cin>>nombre;
    cout<<"Ingresar apellido: ";
    cin>>apellido;
    cout<<"Ingresar fecha de nacimiento: ";
    fechaDeNacimiento.Cargar();
    cout<<"Ingresar genero (1=mujer/2=hombre/3=otro): ";
    cin>>genero;
    while(!setGenero()){
            cout<<"El genero es invalido"<<endl;
            cout<<"Ingresar genero (1=mujer/2=hombre/3=otro): ";
            cin>>genero;
    }
    cout<<"Ingresar turno (1=maniana/2=tarde/3=noche): ";
    cin>>turno;
    while(!setTurno()){
        cout<<"El turno es invalido"<<endl;
        cout<<"Ingresar turno (1=maniana/2=tarde/3=noche): ";
        cin>>turno;
    }
    cout<<"Ingresar sueldo: ";
    cin>>sueldo;
    estado = true;
}

void Empleados::Mostrar(){
    if(estado){
        cout<<"El id empleado es: "<<idEmpleado<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Apellido: "<<apellido<<endl;
        cout<<"Fecha de nacimiento: ";
        fechaDeNacimiento.Mostar();
        cout<<"Genero: ";
        if(genero == 1){cout<<"Mujer"<<endl;}
        else if(genero == 2){cout<<"Hombre"<<endl;}else{cout<<"Otro"<<endl;}
        cout<<"Turno: ";
        if(turno==1){cout<<"Maniana"<<endl;}
        else if(turno==2){cout<<"Tarde"<<endl;}else{cout<<"Noche"<<endl;}
        cout<<"Sueldo: $"<<sueldo<<endl;
    }
}

bool Empleados::leerEnDisco(int pos){
    FILE *p;
    p=fopen("empleados.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos*sizeof *this,0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}

bool Empleados::grabarEnDisco(){
    FILE *p;
    p=fopen("empleados.dat","ab+");
    if(p==NULL) return false;
    bool grabo=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}
bool Empleados::grabarEnDisco(int pos){
    FILE *p;
    p=fopen("empleados.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos*sizeof (this),SEEK_SET);
    bool grabo=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}
void Empleados::bajaEmpleados(){
estado = false;
}

void Empleados::cambiarSueldo(){
cin>>sueldo;
}


void listarEmpleados(){
Empleados obj;
    int pos=0;
    while(obj.leerEnDisco(pos++)){
        obj.Mostrar();
        cout<<endl<<endl;
    }
    system("pause");

}
void agregarEmpleados(){
Empleados obj;
obj.Cargar();
obj.grabarEnDisco();

}


void eliminarEmpleados(){
int id;
Empleados empleadoEliminar;
cout<<"Ingresar id: ";
cin>>id;
bool leyo = empleadoEliminar.leerEnDisco(id-1);
if(!leyo){
        cout<<"No existe el id.";
}else{
empleadoEliminar.bajaEmpleados();
empleadoEliminar.grabarEnDisco(id-1);

}
}
void empleadoTurno(){
Empleados obj;
int turno , pos=0;
cout<<"Ingresar turno a buscar: ";
cin>>turno;
while(obj.leerEnDisco(pos++)){
    if(obj.getTurno() == turno){
        obj.Mostrar();
    }
    else{cout<<"No hay empleados en ese turno"<<endl;

    }
}
}

void buscarEmpleadosID(){
Empleados obj;
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


void empleadoGenero(){
Empleados obj;
int genero , pos=0;
cout<<"Ingresar genero a buscar: ";
cin>>genero;
while(obj.leerEnDisco(pos++)){
    if(obj.getGenero() == genero){
        obj.Mostrar();
    }else{
    cout<<"No hay empleados de ese genero"<<endl;
    }
}
}

void cambiarSueldo(){
int id , sueldoNuevo;
Empleados reg;
cout<<"Ingresar id del empleado al cual se le cambia el sueldo: ";
cin>>id;
bool leyo = reg.leerEnDisco(id-1);
if(!leyo){

    cout<<"No existe el id."<<endl;
}
else{

    cout<<"Ingresar nuevo sueldo: ";
    reg.cambiarSueldo();
    reg.grabarEnDisco(id-1);
}

}

void empleadoVentas(){
int pos=0 , idEmpleado , cantVentas = 0;
Ventas obj;
cout<<"Ingresar id del empleado a buscar: ";
cin>>idEmpleado;
while(obj.leerEnDisco(pos++))
{
    if(idEmpleado == obj.getIdEmpleado()){
        cantVentas=cantVentas+ 1;
    }
}
cout<<"El empleado "<<idEmpleado<<"� tiene "<<cantVentas<<" ventas."<<endl;
}


void backUpEmpleados(){
     FILE* p=fopen("empleados.dat","rb+");
    FILE* archivoBackup=fopen("backupEmpleados.dat","wb+");

    Empleados x;
    fread(&x,sizeof(Empleados),1,p);
    while(!feof(p)){
        fwrite(&x,sizeof(Empleados),1,archivoBackup);
        fread(&x,sizeof(Empleados),1,p);
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

#endif // EMPLEADOS_H_INCLUDED