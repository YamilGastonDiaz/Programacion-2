#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

void cargarCadena(char *pal, int tam);

class Articulo{
    private:
        char codigo[5];
        char descripcion[30];
        float precio;
        int stock;
        bool estado;
    public:
        //CONSTRUCTORES
        Articulo();
        Articulo(const char*);
        //SETS
        void setCodigo(const char*);
        void setDescripcion(const char*);
        void setPrecio(float);
        void setStock(int);
        void setEstado(bool);
        //GETS
        const char *getCodigo(){return codigo;};
        const char *getDescripcion(){return descripcion;};
        float getPrecio();
        int getStock();
        bool getEstado();

        void Cargar();
        void Mostrar();
};
//CONSTRUCTORES
Articulo::Articulo(){
    strcpy(codigo, "null");
    strcpy(descripcion, "null");
    precio=0;
    stock=0;
    estado=false;
}

Articulo::Articulo(const char *d){
    strcpy(descripcion, d);
}
//SETS
void Articulo::setCodigo(const char *c){
    strcpy(codigo, c);
}

void Articulo::setDescripcion(const char *d){
    strcpy(descripcion, d);
}

void Articulo::setPrecio(float p){
    precio=p;
}

void Articulo::setStock(int s){
    stock=s;
}

void Articulo::setEstado(bool e){
    estado=e;
}
//GETS
float Articulo::getPrecio(){
    return precio;
}

bool Articulo::getEstado(){
    return estado;
}

int Articulo::getStock(){
    return stock;
}

void Articulo::Cargar(){
    cout<<"CODIGO: ";
    cargarCadena(codigo, 4);
    cout<<"DESCRIPCION: ";
    cargarCadena(descripcion, 29);
    cout<<"PRECIO: ";
    cin>>precio;
    cout<<"STOCK: ";
    cin>>stock;
    cout<<"ESTADO: ";
    cin>>estado;
    cout<<endl;
}

void Articulo::Mostrar(){
    cout<<"CODIGO: "<<codigo<<endl;
    cout<<"DESCRIPCION: "<<descripcion<<endl;
    cout<<"PRECIO: "<<precio<<endl;
    cout<<"STOCK: "<<stock<<endl;
    cout<<"ESTADO: "<<estado<<endl;
    cout<<endl;
}

void PuntoA(Articulo *art, int tam){
    for(int i = 0; i < tam; i++){
        art[i].Cargar();
    }
}

void PuntoB(Articulo *art, int tam){
    for(int i = 0; i < tam; i++){
        art[i].Mostrar();
    }
}

void PuntoC(Articulo *art, int tam){
    float precio;
    cout <<"PRECIO: ";
    cin>>precio;

    for(int i = 0; i < tam; i++){
        if(art[i].getPrecio()>precio){
            art[i].Mostrar();
        }
    }
}

int PuntoDb(Articulo *art, int tam, char *cod){
    for(int i = 0; i < tam; i++){
        if(strcmp(art[i].getCodigo(), cod)==0){
            return i;
        }
    }
    return -1;
}

void PuntoD(Articulo *art, int tam){
    char cod[5];
    cout<<"Ingresar codigo: ";
    cargarCadena(cod, 4);
    cout<<endl;

   cout<<"Posicion: "<<PuntoDb(art, tam, cod)<<endl;

}

Articulo PuntoEb(Articulo *art, int tam, char *cod){
    Articulo aux;
    for(int i = 0; i < tam; i++){
        if(strcmp(art[i].getCodigo(), cod)==0){
            return art[i];
        }
    }
    aux.setStock(-1);
    return aux;
}

void PuntoE(Articulo *art, int tam){
    Articulo aux;
    char cod[5];
    cout<<"Ingrese el codigo: ";
    cargarCadena(cod, 4);
    cout<<endl;
    aux=PuntoEb(art, tam, cod);
    if(aux.getStock()==-1){
        aux.Mostrar();
    }else{
        aux.Mostrar();
    }
}

int PuntoFb(Articulo *art, int tam, int numS){
    int contador=0;
    for(int i = 0; i < tam; i++){
        if(art[i].getStock()<numS){
           contador++;
        }
    }
    return contador;
}

void PuntoF(Articulo *art, int tam){
    int valorS;
    cout<<"Ingrese un valor de stock: ";
    cin>>valorS;
    cout<<endl;

    cout<<"CANTIDAD DE ARTICULOS: "<<PuntoFb(art, tam, valorS);
}

void PuntoGb(Articulo *art, int tam, float incremento){
    float aumento;
    for(int i = 0; i < tam; i++){
       aumento=art[i].getPrecio();
       aumento+=aumento*incremento/100;
       art[i].setPrecio(aumento);
    }
}

void PuntoG(Articulo *art, int tam){
    float incremento;
    cout<<"Ingrese el porcentaje de aumento: ";
    cin>>incremento;
    cout<<endl;

    PuntoGb(art, tam, incremento);
}

int main(){
setlocale(LC_ALL, "");

const int TAM=2;
Articulo art[TAM];


char opc;

while(true){
    system("cls");
    cout<<"----------MENU------------"<<endl;
    cout<<"a). Cargar un vector de 10 artículos."<<endl;
    cout<<"b). Listar todos los artículos del vector."<<endl;
    cout<<"c). Listar todos los artículos cuyo precio sea mayor a un valor que se ingresa por teclado."<<endl;
    cout<<"d). Devolver la posición del objeto que contiene ese código. De no encontrarlo devolver -1."<<endl;
    cout<<"e). Devolver el objeto completo que contiene el código. De no encontrarlo devolver un valor de -1 en el stock."<<endl;
    cout<<"f). Devolver la cantidad de artículos cuyo stock sea inferior a ese valor recibido."<<endl;
    cout<<"g). Dado un porcentaje de incremento,modificar el precio unitario de todos los objetos."<<endl;
    cout<<"s). SALIR"<<endl;
    cout<<"OPCION: ";
    cin>>opc;
        system("cls");
        switch(opc){
            case 'a':
                    PuntoA(art, TAM);
                break;
            case 'b':
                    PuntoB(art, TAM);
                break;
            case 'c':
                    PuntoC(art, TAM);
                break;
            case 'd':
                    PuntoD(art, TAM);
                break;
            case 'e':
                    PuntoE(art, TAM);
                break;
            case 'f':
                   PuntoF(art, TAM);
                break;
            case 'g':
                    PuntoG(art, TAM);
                break;
            case 's':
                return 0;
        }
        system("pause>null");
}
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
