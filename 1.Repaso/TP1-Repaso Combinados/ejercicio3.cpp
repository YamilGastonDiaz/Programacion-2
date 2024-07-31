#include <iostream>
#include <locale>

using namespace std;

void cargarDatos(float mat[][12]);
void totalMontoV(float mat[][12]);

int main(){
setlocale(LC_ALL, "");

const int VENDEDOR=5;
const int MES=12;

float mat[VENDEDOR][MES]={};

cargarDatos(mat);
totalMontoV(mat);


cout<<endl;
system("pause");
return 0;
}
void cargarDatos(float mat[][12]){
int dia, mes, numLetra;
float importe;
char codVendedor;

cout<<"Ingrese Dia: ";
cin>>dia;

while(dia != 0){
    cout<<"Ingrese Mes: ";
    cin>>mes;
    cout<<"Ingrese el importe: ";
    cin>>importe;
    cout<<"Codigo de vendedor: ";
    cin>>codVendedor;
    cout<<endl;

    numLetra=(int)codVendedor;

    mat[numLetra-97][mes-1]+=importe;

    cout<<"Ingrese Dia: ";
    cin>>dia;
}
}
void totalMontoV(float mat[][12]){
    for(int f = 0; f < 5; f++){
            char codigo=f+97;
            cout<<"Empleado "<<codigo<<endl;
        for(int c = 0; c < 12; c++){
            if(mat[f][c]>0){
                cout<<"Monto total del mes "<<c+1<<" :"<<mat[f][c]<<endl;
            }
        }
    }
}
