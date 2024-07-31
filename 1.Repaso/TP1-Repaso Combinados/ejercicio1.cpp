#include <iostream>
#include <locale>

using namespace std;

void cargarDatos(int mat [][3]);
void cantiadVenta(int mat[][3]);
void articuloMasV(int mat[][3]);

int main(){
setlocale(LC_ALL, "");

const int FILA=5;
const int COLUM=3;

int mat[FILA][COLUM]={};

cargarDatos(mat);
cantiadVenta(mat);
articuloMasV(mat);

cout<<endl;
system("pause");
return 0;
}
void cargarDatos(int mat[][3]){
int articulo, sucursal, venta;

cout<<"Ingrese numero de articulo: ";
cin>>articulo;

while(articulo != 0){
    cout<<"Ingrese numero de sucursal: ";
    cin>>sucursal;
    cout<<"Ingrese cantidad de venta: ";
    cin>>venta;
    cout<<endl;

    mat[articulo-1][sucursal-1]+=venta;

    cout<<"Ingrese numero de articulo: ";
    cin>>articulo;
}
}
void cantiadVenta(int mat[][3]){
    for(int f = 0; f < 5; f++){
        for(int c = 0; c < 3; c++){
            cout<<mat[f][c]<<"\t";
        }
        cout<<endl;
    }

}
void articuloMasV(int mat[][3]){
    int mayorA;
    int mayorP;
    for(int c = 0; c < 3; c++){
            mayorA=0;
            mayorP=0;
        for(int f = 0; f < 5; f++){
            if(mat[f][c]>mayorA){
                mayorA=mat[f][c];
                mayorP=f;
            }
        }
        cout<<"Sucursal #"<<c+1<<endl;
        cout<<"Art #"<<mayorP+1<<endl;
    }
}
