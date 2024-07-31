#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

void cargarCadena(char *pal, int tam);

///CLASE FECHA
class Fecha{
    private:
        int dia, mes, anio;
    public:
    //CONSTRUCTOR
    Fecha();
    //SETS
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    //GETS
    int getDia();
    int getMes();
    int getAnio();

    void Cargar();
    void Mostrar();
};
//CONSTRUCTOR
Fecha::Fecha(){
    dia=1;
    mes=1;
    anio=1900;
}
//SETS
void Fecha::setDia(int d){
    if(d>=1 && d<=31){
        dia=d;
    }
}
void Fecha::setMes(int m){
    if(m>=1 && m<=12){
        mes=m;
    }
}
void Fecha::setAnio(int a){
    if(anio>0){
        anio=a;
    }
}
//GETS
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}

void Fecha::Cargar(){
    int d, m, a;
    bool correcto=false;

    do{
        cout<<"DIA: ";
        cin>>d;
        cout<<"MES: ";
        cin>>m;
        cout<<"ANIO: ";
        cin>>a;

        if (d>=1 && d<=31 && m>=1 && m<=12 && a>0){
        dia = d;
        mes = m;
        anio = a;
        correcto = true;
        }else{
            cout<<"Fecha incorrecta."<<endl;
        }

    } while (!correcto);

}

void Fecha::Mostrar(){
    cout << "FECHA: " <<dia<< "/" <<mes<< "/" <<anio<<endl;
}

//CLASE COMPRA
class Compra{
    private:
        int numCompra;
        Fecha fechaCompra;
        char nomProductoC[25];
        int tipoProducto;
        int formaPago;
        int cantidad;
        float importe;
    public:
        //CONTADOR
        Compra();
        //SETS
        void setNumCompra(int com){numCompra=com;}
        void setFechaCompra(Fecha f){fechaCompra=f;}
        void *setNomProductoC(const char *n){strcpy(nomProductoC, n);}
        void setTipoProducto(int t){if(t>0 && t<16)tipoProducto=t;}
        void setFormaPago(int p){if(p>0 && p<6)formaPago=p;}
        void setCantidad(int can){cantidad=can;}
        void setImporte(float i){importe=i;}
};
Compra::Compra(){
    numCompra=0;
    tipoProducto=0;
    formaPago=0;
    cantidad=0;
    importe=0;
}



int main(){
setlocale(LC_ALL, "");





cout<<endl;
system("pause");
return 0;
}
void cargarCadena(char *pal, int tam){
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}
