#include <iostream>
#include <locale>

using namespace std;

int encontrarPosMaxF(int mat[][4], int numF);

int main(){
setlocale(LC_ALL, "");

const int FILA=4;
const int COLUM=4;

int mat[FILA][COLUM]={{2,6,5,9},{9,15,-6,8},{10,12,13,11},{-9,-6,-1,-4}};
int numF=1;

cout<<"Posicion del maximo: "<<encontrarPosMaxF(mat, numF)+1;

cout<<endl;
system("pause");
return 0;
}
int encontrarPosMaxF(int mat[][4], int numF){
    int posMax=0;
    for(int c = 1; c < 4; c++){
        if(mat[numF][c]>mat[numF][posMax]){
            posMax=c;
        }
    }
    return posMax;
}
