#include <iostream>
#include <locale>

using namespace std;

int valorMaximo(int vec[], int tam);

int main(){
setlocale(LC_ALL, "");

const int TAM=5;
int vec[TAM]={1,2,13,4,5};


cout<<"El valor maximo es: "<<valorMaximo(vec, TAM);

cout<<endl;
system("pause");
return 0;
}
int valorMaximo(int vec[],int tam){
    int maximo=vec[0];
    for(int i = 0; i < tam; i++){
        if(vec[i]>maximo){
            maximo=vec[i];
        }
    }
    return maximo;
}
