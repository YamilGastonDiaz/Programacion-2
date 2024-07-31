#include <iostream>
#include <locale>

using namespace std;

bool encontrarNumero(int vec[10], int num);

int main(){
setlocale(LC_ALL, "");

const int TAM=10;
int vec[TAM]={1,1,1,1,1,1,1,1,1,1};
int num=13;

if(encontrarNumero(vec, num)){
    cout<<"TRUE";
}else{
    cout<<"FALSE";
}

cout<<endl;
system("pause");
return 0;
}
bool encontrarNumero(int vec[], int num){
    for(int i = 0; i < 10; i++){
        if(vec[i] == num){
            return true;
        }
    }
    return false;
}
