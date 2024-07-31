#include <iostream>
#include <locale>

using namespace std;

int posicionMaximo(int vec[], int tam);

int main(){
setlocale(LC_ALL, "");

const int TAM=5;
int vec[TAM]={1,13,4,5,6};

cout<<"Posicion maxima: "<<posicionMaximo(vec, TAM)+1;

cout<<endl;
system("pause");
return 0;
}
int posicionMaximo(int vec[],int tam){
    int posMax=0;
    for(int i = 1; i < tam; i++){
        if(vec[i]>vec[posMax]){
            posMax=i;
        }
    }
    return posMax;
}
