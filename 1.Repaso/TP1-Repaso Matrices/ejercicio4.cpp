#include <iostream>
#include <locale>

using namespace std;

int cantidadNumPos(int mat[][4], int numCol);

int main(){
setlocale(LC_ALL, "");

const int FILA=4;
const int COLUM=4;

int mat[FILA][COLUM]={{2,6,5,9},{9,15,-6,8},{10,12,13,11},{-9,-6,-1,-4}};
int numCol=2;

cout<<"cantidad de positivos de la columna indicada es: "<<cantidadNumPos(mat, numCol);

cout<<endl;
system("pause");
return 0;
}
int cantidadNumPos(int mat[][4], int numCol){
    int numPositivos=0;
    for(int f = 0; f < 4; f++){
        if(mat[f][numCol]>0){
            numPositivos++;
        }
    }
    return numPositivos;
}
