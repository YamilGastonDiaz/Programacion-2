#include <iostream>
#include <locale>

using namespace std;
///STRUCT
struct Articulo{
char articulo[6];
char descripcion[30];
float precio;
int stock;
};

///DEFINICIONES
void cargarCadena(char *palabra, int tamano);
void cargarArticulo(Articulo &reg);///paso por referencia
void mostrarArticulo(Articulo reg);

int main(){
setlocale(LC_ALL, "");

Articulo reg;

cargarArticulo(reg);
mostrarArticulo(reg);

cout<<endl;
system("pause");
return 0;
}
///DECLARACIONES
void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}
void cargarArticulo(Articulo &reg){
    cout<<"Igresar codigo: ";
    cargarCadena(reg.articulo, 5);
    cout<<"Ingresar descripcion: ";
    cargarCadena(reg.descripcion, 29);
    cout<<"Ingresar precio: ";
    cin>>reg.precio;
    cout<<"Ingrese el stock: ";
    cin>>reg.stock;
    cout<<endl;
}
void mostrarArticulo(Articulo reg){
    cout<<"Codigo: "<<reg.articulo<<endl;
    cout<<"Descripcion: "<<reg.descripcion<<endl;
    cout<<"Precio: "<<reg.precio<<endl;
    cout<<"Stock: "<<reg.stock<<endl;
}
