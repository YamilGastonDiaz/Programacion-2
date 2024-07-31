#include <iostream>
#include <locale>

using namespace std;

int valorMinimo(int vec[], int tam);

int main(){
setlocale(LC_ALL, "");

const int TAM=5;
int vec[TAM]={3,2,1,4,5};

cout<<"El valor minimo es: "<<valorMinimo(vec, TAM);



cout<<endl;
system("pause");
return 0;
}
int valorMinimo(int vec[],int tam){
    int minimo=vec[0];
    for(int i = 0; i < tam; i++){
        if(vec[i]<minimo){
            minimo=vec[i];
        }
    }
    return minimo;
}
