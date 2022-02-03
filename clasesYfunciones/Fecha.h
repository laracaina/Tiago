#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
using namespace std;

class Fecha{
    private:
        int dia , mes , anio;
    public:
        Fecha(int d=0 ,int m=0 , int a=0){
        dia=d;
        mes=m;
        anio=a;

        }

        bool setDia(int d){
            if(d>0 && d<32){dia=d;
            return true;
            }
            }
        bool setMes(int m){
            if(m>0 && m <13){mes=m;
            return true;
            }
            }
        bool setAnio(int a){
            if(a>0 && a<2022){anio=a;
            return true;
            }
            }
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        void Mostar();

        void Cargar(){
            int d,m,a;
    cout<<"Dia: ";
    cin>>d;

       while(!setDia(d)){cout<<"El dia no es valido."<<endl;
       cout<<"Dia: ";
    cin>>d;
       }


    cout<<"Mes: ";
    cin>>m;
    while(!setMes(m)){cout<<"El mes no es valido."<<endl;
    cout<<"Mes: ";
    cin>>m;
    }

    cout<<"Anio: ";
    cin>>a;
   while(!setAnio(a)){cout<<"El anio no es valido."<<endl;
   cout<<"Anio: ";
    cin>>a;
    }
}
};


void Fecha::Mostar(){

    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;

}

#endif // FECHA_H_INCLUDED