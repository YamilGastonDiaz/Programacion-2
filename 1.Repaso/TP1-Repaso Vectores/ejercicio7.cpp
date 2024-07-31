#include <iostream>
#include <locale>

using namespace std;

int contarNumero(int vec[10], int num);

int main(){
setlocale(LC_ALL, "");

const int TAM=10;
int vec[TAM]={13,1,1,13,13,1,1,13,1,13};
int num=13;

cout<<"cantidad repetida del numero recibido: "<<contarNumero(vec, num);

cout<<endl;
system("pause");
return 0;
}
int contarNumero(int vec[10], int num){
    int contar=0;
    for(int i = 0; i < 10; i++){
        if(vec[i]==num){
            contar++;
        }
    }
    return contar;
}
