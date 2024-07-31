#include <iostream>
#include <locale>

using namespace std;

void cargarDatos(int vecA[70], int vecB[15], int mat[][15]);
void puntoA(int vecA[70]);
void puntoB(int vecB[15]);
void puntoC(int mat[][15]);

int main(){
setlocale(LC_ALL, "");

const int TIPO=70;
const int TIPO1=15;


int vecA[TIPO]={};
int vecB[TIPO1]={};
int mat[TIPO][TIPO1]={};

cargarDatos(vecA, vecB, mat);
puntoA(vecA);
puntoB(vecB);
puntoC(mat);

cout<<endl;
system("pause");
return 0;
}
void cargarDatos(int vecA[70], int vecB[15], int mat[][15]){
int dia, engranaje, maquina, cantProducida;

cout<<"Ingrese el dia: ";
cin>>dia;

while(dia != 32){
    cout<<"Ingrese tipo de engranaje: ";
    cin>>engranaje;
    cout<<"Ingrese numero de maquina utilizada: ";
    cin>>maquina;
    cout<<"Cantidad producida: ";
    cin>>cantProducida;
    cout<<endl;

    //puto A
    vecA[engranaje-1]+=cantProducida;
    //Punto B
    vecB[maquina-1]+=cantProducida;
    //punto C
    mat[engranaje-1][maquina-1]+=cantProducida;

    cout<<"Ingrese el dia: ";
    cin>>dia;
}
}
void puntoA(int vecA[70]){
    int mayorE=0;
    for(int i = 0; i < 70; i++){
        if(vecA[i]>vecA[mayorE]){
            mayorE=i;
        }
    }
    cout<<"Tipo de engranage: "<<mayorE+1<<endl;
}
void puntoB(int vecB[15]){
    int menorM=0;
    for(int i = 0; i < 15; i++){
        if(vecB[i]<vecB[menorM]){
            menorM=i;
        }
    }
    cout<<"Numero de maquina: "<<menorM+1<<endl;
}
void puntoC(int mat[][15]){
    for(int f = 0; f < 70; f++){
        for(int c = 0; c < 15; c++){
            cout<<f+1<<"    "<<c+1<<"   "<<mat[f][c]<<endl;
        }
    }

}
