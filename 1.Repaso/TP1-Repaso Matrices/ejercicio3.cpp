#include <iostream>
#include <locale>

using namespace std;

int sumarColumna(int mat[][4], int numCol);

int main(){
setlocale(LC_ALL, "");

const int FILA=4;
const int COLUM=4;

int mat[FILA][COLUM]={{2,6,5,9},{9,15,-6,8},{10,12,13,11},{-9,-6,-1,-4}};
int numCol=0;

cout<<"La suma de la columna indicada es: "<<sumarColumna(mat, numCol);

cout<<endl;
system("pause");
return 0;
}
int sumarColumna(int mat[][4], int numCol){
    int sumarC=0;
    for(int f = 0; f < 4; f++){
        sumarC+=mat[f][numCol];
    }
    return sumarC;
}
