#include <iostream>
#include <locale>

using namespace std;

int encontrarPos(int vec[10], int num);

int main(){
setlocale(LC_ALL, "");

const int TAM=10;
int vec[TAM]={1,1,1,1,1,1,1,1,1,1};
int num=13;

cout<<"Valor buscado: "<<num<<" se encuentra en la posicion: "<<encontrarPos(vec, num);

cout<<endl;
system("pause");
return 0;
}
int encontrarPos(int vec[10], int num){
    int pos=0;
    for(int i = 0; i < 10; i++){
        if(vec[i]==num){
            pos=i+1;
            return pos;
        }
    }
    return -1;
}
