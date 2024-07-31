#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
    public:
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

class Tarjeta{
    private:
        int nroTarjeta;
        Fecha fechaAlta;
        int dni;
        float saldo;
        int estado;
    public:
        int getNroTarjeta(){return nroTarjeta;}
        Fecha getDiaFechaAlta(){return fechaAlta;}
        int getDNI(){return dni;}
        float getSaldo(){return saldo;}
        bool getEstado(){return estado;}
        void setNroTarjeta(int n){nroTarjeta=n;}
        void Mostrar(){};
};

class ArchivoTarjetas{
    private:
        char nombre[30];
    public:
        ArchivoTarjetas(const char *n="tarjetas.dat"){strcpy(nombre,n);}
        bool grabarRegistro(Tarjeta obj);
        Tarjeta leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        bool modificarRegistro(Tarjeta obj, int pos);
        bool listarRegistros();
};

bool ArchivoTarjetas::grabarRegistro(Tarjeta obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoTarjetas::listarRegistros(){
    FILE *p;
    Tarjeta obj;
    p=fopen(nombre, "rb");
    if(p==NULL) return false;
    while(fread(&obj, sizeof obj, 1, p)==1){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}

int ArchivoTarjetas::buscarRegistro(int num){
    FILE *p;
    Tarjeta obj;
    p=fopen(nombre, "rb");
    int pos=0;
    if(p==NULL) return -1;
    while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getNroTarjeta()==num){
        fclose(p);
        return pos;
        }
    pos++;
    }
    fclose(p);
    return -2;
}

Tarjeta ArchivoTarjetas::leerRegistro(int pos){
    FILE *p;
    Tarjeta obj;
    p=fopen(nombre, "rb");
    obj.setNroTarjeta(-5);
    if(p==NULL) return obj;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoTarjetas::modificarRegistro(Tarjeta obj, int pos){
    FILE *p;
    p=fopen(nombre, "rb+"); ///agrega al modo de apertura lo que le falta
    if(p==NULL) return false;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoTarjetas::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);///función que permite ubicarse dentro del archivo, en este caso lo ubiqué al final EOF
    int tam=ftell(p);///me devuelve la cantidad de bytes que hay desde el principio del archivo a la posición actual del indicador de pFILE.
    fclose(p);
    return tam/sizeof(Tarjeta);
}

class Viaje{
    private:
        int nroViaje;
        int nroTarjeta;
        int medio;
        Fecha fechaViaje;
        float importe;
    public:
        int getNroViaje(){return nroViaje;}
        int getNroTarjeta(){return nroTarjeta;}
        int getMedioTransporte(){return medio;}
        Fecha getFechaViaje(){return fechaViaje;}
        float getImporte(){return importe;}
        void setNroViaje(int n){nroViaje=n;}
        void setNroTarjeta(int n){nroTarjeta=n;}
        void Mostrar(){};
};

class ArchivoViajes{
    private:
        char nombre[30];
    public:
        ArchivoViajes(const char *n="Viajes.dat"){strcpy(nombre,n);}
        bool grabarRegistro(Viaje obj);
        Viaje leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        bool modificarRegistro(Viaje obj, int pos);
        bool listarRegistros();
};

bool ArchivoViajes::grabarRegistro(Viaje obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoViajes::listarRegistros(){
    FILE *p;
    Viaje obj;
    p=fopen(nombre, "rb");
    if(p==NULL) return false;
    while(fread(&obj, sizeof obj, 1, p)==1){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}

int ArchivoViajes::buscarRegistro(int num){
    FILE *p;
    Viaje obj;
    p=fopen(nombre, "rb");
    int pos=0;
    if(p==NULL) return -1;
    while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getNroTarjeta()==num){
            fclose(p);
            return pos;
        }
    pos++;
    }
    fclose(p);
    return -2;
}

Viaje ArchivoViajes::leerRegistro(int pos){
    FILE *p;
    Viaje obj;
    p=fopen(nombre, "rb");
    obj.setNroViaje(-5);
    if(p==NULL) return obj;
    fseek(p, pos*sizeof obj,0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoViajes::modificarRegistro(Viaje obj, int pos){
    FILE *p;
    p=fopen(nombre, "rb+"); ///agrega al modo de apertura lo que le falta
    if(p==NULL) return false;
    fseek(p, pos*sizeof obj,0);///función que permite ubicarse dentro del archivo
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoViajes::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);///función que permite ubicarse dentro del archivo, en este caso lo ubiqué al final EOF
    int tam=ftell(p);///me devuelve la cantidad de bytes que hay desde el principio del archivo a la posición actual del indicador de pFILE.
    fclose(p);
    return tam/sizeof(Viaje);
}

class TarjetaSinUso{
    private:
        int nroTarjeta;
        int DNI;
        Fecha fechaAlta;
    public:
        void setNroTarjeta(int nro){nroTarjeta=nro;}
        void setDNI(int dni){DNI=dni;}
        void setFechaAlta(Fecha a){fechaAlta=a;}
};

class ArchivoTarjetasSinUso{
    private:
        char nombre[30];
    public:
        ArchivoTarjetasSinUso(const char *n="sinuso.dat"){strcpy(nombre,n);}
        bool grabarRegistro(TarjetaSinUso obj);
};

bool ArchivoTarjetasSinUso::grabarRegistro(TarjetaSinUso obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}


void puntoA();
void mostrarPuntoA(int *v){}
void puntoB();
void puntoC();
int buscarMaximo(int *v, int tam){return 1;}
void puntoI();
void puntoL();
bool buscarViajes(int num);
void generarRegistroSinUso(Tarjeta reg);

int main(){
setlocale(LC_ALL, "");

puntoA();
puntoB();
puntoC();
puntoI();
puntoL();

cout<<endl;
system("pause");
return 0;
}

void puntoA(){
    Viaje reg;
    ArchivoViajes archiViaje;
    int num, cant, vMedios[3]={0};
    cant=archiViaje.contarRegistros();

    cout<<"INGRESE NUMERO DE TARJETA: ";
    cin>>num;

    for(int i=0;i<cant;i++){
        reg=archiViaje.leerRegistro(i);
        if(reg.getNroTarjeta()==num){
            vMedios[reg.getMedioTransporte()-1]++;
        }
    }
    mostrarPuntoA(vMedios);
}

void puntoB(){
    Viaje reg, aux;
    ArchivoViajes archiViaje;
    int cant;
    float minValor;
    cant=archiViaje.contarRegistros();

    for(int i=0;i<cant;i++){
        reg=archiViaje.leerRegistro(i);
        if(i==0){
        minValor=reg.getImporte();
        aux=reg;
        }else{
            if(reg.getImporte()<minValor){
                minValor=reg.getImporte();
                aux=reg;
            }
        }
    }
    cout<<"REGISTRO CON MENOR IMPORTE: ";
    aux.Mostrar();
}

void puntoC(){
    Viaje reg;
    ArchivoViajes archiViaje;
    int cant, vMeses[12]={0};
    cant=archiViaje.contarRegistros();

    for(int i=0;i<cant;i++){
        reg=archiViaje.leerRegistro(i);
        vMeses[reg.getFechaViaje().getMes()-1]++;
    }
    cout<<"MES DE MAYOR RECAUDACION: "<<buscarMaximo(vMeses,12)+1<<endl;
}

void puntoI(){
    Viaje reg, aux;
    ArchivoViajes archiViaje;
    int cant;
    float minValor;
    cant=archiViaje.contarRegistros();

    for(int i=0;i<cant;i++){
        reg=archiViaje.leerRegistro(i);
        if(i==0){
            minValor=reg.getImporte();
            aux=reg;
        }else{
            if(reg.getImporte()<minValor){
                minValor=reg.getImporte();
                aux=reg;
            }
        }
    }
    cout<<"TARJETA DEL REGISTRO CON MENOR IMPORTE: ";
    cout<<aux.getNroTarjeta()<<endl;
    ArchivoTarjetas archiSube;
    Tarjeta obj;
    int pos=archiSube.buscarRegistro(aux.getNroTarjeta());
    obj=archiSube.leerRegistro(pos);
    cout<<"DNI DEL DUEÑO: "<<obj.getDNI()<<endl;
}

bool buscarViajes(int num){
    Viaje obj;
    ArchivoViajes archi;
    int cant=archi.contarRegistros();

    for(int i=0;i<cant;i++){
        obj=archi.leerRegistro(i);
        if(obj.getNroTarjeta()==num && obj.getFechaViaje().getAnio()==2024)
        return true;
    }
    return false;
}


void generarRegistroSinUso(Tarjeta reg){
    TarjetaSinUso aux;
    ArchivoTarjetasSinUso archi;
    aux.setDNI(reg.getDNI());
    aux.setNroTarjeta(reg.getNroTarjeta());
    aux.setFechaAlta(reg.getDiaFechaAlta());
    archi.grabarRegistro(aux);
}

void puntoL(){
    Tarjeta reg;
    ArchivoTarjetas archiSube;
    int cant=archiSube.contarRegistros();

    for(int i=0;i<cant;i++){
        reg=archiSube.leerRegistro(i);
        if(reg.getEstado()){
            if(buscarViajes(reg.getNroTarjeta())==false){
                generarRegistroSinUso(reg);
            }
        }
    }
}
