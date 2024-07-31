#include <iostream>
#include <locale>

using namespace std;

void cargarDatos(float mat[][31]);
void gastoTotal(float mat[][31]);
void mayorGastoXmes(float mat[][31]);

int main(){
setlocale(LC_ALL, "");

const int MES=12;
const int DIA=31;


float mat[MES][DIA]={};

cargarDatos(mat);
gastoTotal(mat);
mayorGastoXmes(mat);


cout<<endl;
system("pause");
return 0;
}
void cargarDatos(float mat[][31]){
int mes, dia;
float gasto;

cout<<"Ingrese el mes: ";
cin>>mes;

while(mes != 0){
    cout<<"Ingrese el dia: ";
    cin>>dia;
    cout<<"ingrese el importe gastado: ";
    cin>>gasto;
    cout<<endl;

    mat[mes-1][dia-1]+=gasto;

    cout<<"Ingrese el mes: ";
    cin>>mes;
}

}
void gastoTotal(float mat[][31]){
    float gastoXmes;
    for(int f = 0; f < 12; f++){
            gastoXmes=0;
        for(int c = 0; c < 31; c++){
            gastoXmes+=mat[f][c];
        }
        cout<<"Mes "<<f+1<<" gasto total: "<<gastoXmes<<endl;
    }
}
void mayorGastoXmes(float mat[][31]){
    float mayorG;
    int diaMayorG;
    for(int f = 0; f < 12; f++){
            mayorG=0;
            diaMayorG=0;
        for(int c = 0; c < 31; c++){
            if(mat[f][c]>mayorG){
                mayorG=mat[f][c];
                diaMayorG=c;
            }
        }
        cout<<"Mes "<<f+1<<endl;
        cout<<"Dia "<<diaMayorG+1<<" monto: "<<mayorG<<endl;
    }

}
