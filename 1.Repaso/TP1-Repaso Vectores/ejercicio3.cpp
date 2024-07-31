#include <iostream>
#include <locale>

using namespace std;

int posicionMinimo(int vec[], int tam);

int main(){
setlocale(LC_ALL, "");

const int TAM=5;
int vec[TAM]={6,7,8,3,9};

cout<<"Posicion minima: "<<posicionMinimo(vec, TAM)+1;

cout<<endl;
system("pause");
return 0;
}
int posicionMinimo(int vec[],int tam){
    int posMin=0;
    for(int i = 1; i < tam; i++){
        if(vec[i]<vec[posMin]){
            posMin=i;
        }
    }
    return posMin;
}
