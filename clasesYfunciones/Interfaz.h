#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED
#include <iostream>
using namespace std;

void menuCuadrado(int pos){
rlutil::cls();
        gotoxy(25,2);
        rlutil::setColor(15);
        for(int i=1;i<70;i++)cout<<(char)205;
        gotoxy(25,2);
        cout<<(char)201;
        gotoxy(94,2);
        cout<<(char)187;

        for(int i=3;i<pos;i++){
            gotoxy(25,i);
            cout<<(char)186;

        }
        gotoxy(26,7);
        for(int i=1;i<69;i++)cout<<(char)205;
        gotoxy(25,7);
        cout<<(char)204;
        gotoxy(94,7);
        cout<<(char)185;
        for(int i=3;i<pos;i++){
            gotoxy(94,i);
            cout<<(char)186;
        }
          gotoxy(25,pos);
          for(int i=1;i<70;i++)cout<<(char)205;
        gotoxy(25,pos);
        cout<<(char)200;
        gotoxy(94,pos);
        cout<<(char)188;


}

void recuadroChico(int pos , int pos1 , int pos2 , int pos3 , int pos4){ ///pos 30 / pos1 12 / pos2 13 / pos3 16 / pos4 89
    int i;
    rlutil::setColor(12);
    gotoxy(pos,pos1);
    for(i=1;i<60;i++)cout<<(char)205;
    gotoxy(pos,pos1);
    cout<<(char)201;
    gotoxy(pos,pos2);
    for(i=pos2;i<pos3;i++){
    gotoxy(pos,i);
    cout<<(char)186;}
        gotoxy(pos,pos3);
    for(i=1;i<60;i++)cout<<(char)205;
    gotoxy(pos,pos3);
    cout<<(char)200;
    gotoxy(pos,pos2);
    for(i=pos2;i<pos3;i++){
    gotoxy(pos4,i);
    cout<<(char)186;}
    gotoxy(pos4,pos1);
    cout<<(char)187;
    gotoxy(pos4,pos3);
    cout<<(char)188;
}

#endif // INTERFAZ_H_INCLUDED
