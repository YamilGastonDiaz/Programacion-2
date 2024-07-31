#include <iostream>
#include <locale>

using namespace std;

int sumarMatriz(int mat[][4]);

int main(){
setlocale(LC_ALL, "");

const int FILA=4;
const int COLUM=4;

int mat[FILA][COLUM]={{2,6,5,9},{9,15,-6,8},{10,12,13,11},{-9,-6,-1,-4}};

cout<<"Suma de toda matriz: "<<sumarMatriz(mat);

cout<<endl;
system("pause");
return 0;
}
int sumarMatriz(int mat[][4]){
    int sumaM=0;
    for(int f = 0; f < 4; f++){
        for(int c = 0; c < 4; c++){
            sumaM+=mat[f][c];
        }
    }
    return sumaM;
}
