#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
    public:
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        void setDia(int d){dia=d;}
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}

        void Cargar();
        void Mostrar();
        //SOBRECARGAS
        bool operator ==(Fecha &obj);
        bool operator>(Fecha &obj);
        bool operator==(const char *nombreMes);

};

void Fecha::Cargar(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
    cout<<endl;
}

void Fecha::Mostrar(){
    cout<<"DIA: ";
    cout<<dia<<"/";
    cout<<mes<<"/";
    cout<<anio;
}

bool Fecha::operator==(Fecha &obj){
    if(dia!=obj.dia)return false;
    if(mes!=obj.mes)return false;
    if(anio!=obj.anio)return false;
    return true;
}

bool Fecha::operator>(Fecha &obj){
  if(dia>obj.dia && mes>obj.mes && anio>obj.anio) return true;
}

bool Fecha::operator==(const char *nombreMes){
    char meses[12][12];
    strcpy(meses[0],"ENERO");
    strcpy(meses[1],"FEBRERO");
    strcpy(meses[2],"MARZO");
    strcpy(meses[3],"ABRIL");
    strcpy(meses[4],"MAYO");
    strcpy(meses[5],"JUNIO");
    strcpy(meses[6], "JULIO");
    strcpy(meses[7], "AGOSTO");
    strcpy(meses[8], "SEPTIEMBRE");
    strcpy(meses[9], "OCTUBRE");
    strcpy(meses[10], "NOVIEMBRE");
    strcpy(meses[11], "DICIEMBRE");
        if(strcmp(meses[mes-1],nombreMes)==0)
            return true;
    return false;
}

int main(){
setlocale(LC_ALL, "");

Fecha a;

a.Cargar();


if(a=="MAYO"){
    cout<<"IGUALES";
}else{
    cout<<"DISTINTOS";
}


cout<<endl;
system("pause");
return 0;
}
