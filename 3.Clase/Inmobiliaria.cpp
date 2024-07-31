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

//CLASE DIRECCION
class Direccion{
    private:
        char calle[25];
        int num;
        int codPostal;
        char localidad[30];
        int piso;
    public:
        //CONTRUCTOR
        Direccion(const char *, int, int, const char *, int);
        //SET
        void *setCalle(const char *c){strcpy(calle, c);}
        void setNum(int n){num = n;}
        void setCodPostal(int cp){codPostal = cp;}
        void *setLocalidad(const char *l){strcpy(localidad, l);}
        void setPiso(int p){piso = p;}
        //GET
        const char *getCalle(){return calle;}
        int getNum(){return num;}
        int getCodPostal(){return codPostal;}
        int getPiso(){return piso;}

        void Cargar();
        void Mostrar();
};

Direccion::Direccion(const char *c="S/C", int n=0, int cp=0, const char *l="S/L", int p=0){
    strcpy(calle, c);
    num=n;
    codPostal=cp;
    strcpy(localidad, l);
    piso=p;
}

void Direccion::Cargar(){
    cout<<"Calle: ";
    cargarCadena(calle, 24);
    cout<<"Numero de Calle: ";
    cin>>num;
    cout<<"Codigo Postal: ";
    cin>>codPostal;
    cout<<"Localidad: ";
    cargarCadena(localidad, 29);
    cout<<"Piso: ";
    cin>>piso;
}

void Direccion::Mostrar(){
    cout<<"Calle: "<<calle<<endl;
    cout<<"Numero de Calle: "<<num<<endl;
    cout<<"Codigo Postal: "<<codPostal<<endl;
    cout<<"Localidad: "<<localidad<<endl;
    cout<<"Piso: "<<piso<<endl;
}

//CLASE INMOBILIARIA BASE
class Inmobiliaria{
    private:
        Direccion inmueble;
        Fecha fIngreso;
        Fecha fOperacion;
        float superficie;
        int tipoOperacion;
    public:
        //CONSTRUCTOR
        Inmobiliaria(Direccion, Fecha, Fecha, float, int);
        //SETS
        void setInmueble(Direccion inm){inmueble=inm;}
        void setFingreso(Fecha ing){fIngreso=ing;}
        void setFoperacion(Fecha ope){fOperacion=ope;}
        void setSuperficie(float s){superficie=s;}
        void setTipoOperacion(int tope){tipoOperacion=tope;}
        //GETS
        Direccion getInmueble(){return inmueble;}
        Fecha getFingreso(){return fIngreso;}
        Fecha getFoperacion(){return fOperacion;}
        float getSuperficie(){return superficie;}
        int getTipoOperacion(){return tipoOperacion;}
        //debo hacer
        void Cargar();
        void Mostrar();
};

Inmobiliaria::Inmobiliaria(Direccion inm=Direccion(), Fecha fi=Fecha(), Fecha fo=Fecha(), float s=0, int to=0){
    inmueble=inm;
    fIngreso=fi;
    fOperacion=fo;
    superficie=s;
    tipoOperacion=to;
}
void Inmobiliaria::Cargar(){
    cout<<"Direccion inmueble: "<<endl;
    inmueble.Cargar();
    cout<<"Fecha ingreso: "<<endl;
    fIngreso.Cargar();
    cout<<"Fecha operacion: "<<endl;
    fOperacion.Cargar();
    cout<<"Superficie total: ";
    cin>>superficie;
    cout<<"Tipo de operacion: ";
    cin>>tipoOperacion;
    cout<<endl;
}

void Inmobiliaria::Mostrar(){
    cout<<"Direccion inmueble: "<<endl;
    inmueble.Mostrar();
    cout<<"Fecha ingreso: "<<endl;
    fIngreso.Mostrar();
    cout<<"Fecha operacion: "<<endl;
    fOperacion.Mostrar();
    cout<<"Superficie total: "<<superficie<<endl;
    cout<<"Tipo de operacion: "<<tipoOperacion<<endl;
}

//CLASE DERIVADAS

class Casa:public Inmobiliaria{
    private:
        int cantAmbiente;
        float supConstruida;
    public:
        Casa(int, float);

        void setCantAmbiente(int ca){cantAmbiente=ca;}
        void setSupConstruida(float supC){supConstruida=supC;}

        int getCantAmbiente(){return cantAmbiente;}
        float getSupConstruida(){return supConstruida;}
        //hacer
        void Cargar();
        void Mostrar();
};

Casa::Casa(int ca=0, float supC=0){
    cantAmbiente=ca;
    supConstruida=supC;
}

void Casa::Cargar(){
    Inmobiliaria::Cargar();
    cout<<"Cantidad de ambientes: ";
    cin>>cantAmbiente;
    cout<<"Superficie construida: ";
    cin>>supConstruida;
}

void Casa::Mostrar(){
    cout<<"Cantidad de ambientes: "<<cantAmbiente<<endl;
    cout<<"Superficie construida: "<<supConstruida<<endl;
}

class Departamento:public Inmobiliaria{
    private:
        int cantAmbiente;
        bool instalacionDisponible;
    public:
        Departamento(int, bool);

        void setCantAmbiente(int cantA){cantAmbiente=cantA;}
        void setInstalacionDisponible(bool id){instalacionDisponible=id;}

        int getCantAmbiente(){return cantAmbiente;}
        bool getInstalacionDisponible(){return instalacionDisponible;}
        //hacer
        void Cargar();
        void Mostrar();

};
Departamento::Departamento(int cantA=0, bool id=false){
    cantAmbiente=cantA;
    instalacionDisponible=id;
}

void Departamento::Cargar(){
    cout<<"Cantidad de ambiente: ";
    cin>>cantAmbiente;
    cout<<"Instalaciones complementaria: ";
    cin>>instalacionDisponible;
}

void Departamento::Mostrar(){
    cout<<"Cantidad de ambiente: "<<cantAmbiente<<endl;
    cout<<"Instalaciones complementaria: "<<instalacionDisponible<<endl;
}


class Local:public Inmobiliaria{
    private:
        int zona;
    public:
        Local(int z=0){zona=z;}

        void setZona(int z){zona=z;}

        int getZona(){return zona;}

        void Cargar();
        void Mostrar();
};

class Terreno:public Inmobiliaria{
    private:
        char mejoras;
    public:
        Terreno(char m){mejoras=m;}

        void setMejora(char m){mejoras=m;}

        char getMejora(){return mejoras;}

        void Cargar();
        void Mostrar();
};

void Terreno::Cargar(){
    cout<<"Registra mejoras: ";
    cin>>mejoras;
}

int main(){
setlocale(LC_ALL, "");

Casa obj;

obj.Cargar();


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
