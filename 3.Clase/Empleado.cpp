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

//CLASE EMPLEADO
class Empleado{
    private:
        int dni;
        char nombre[20];
        char apellido[20];
        char domicilio[30];
        char email[15];
        Fecha fechaNacimiento;
        int cargo;
    public:
        //CONTRUCTOR
        Empleado(int, const char *, const char *, const char *, const char *, Fecha, int);
        //SETS
        void setDni(int d){dni=d;}
        void *setNombre(const char *n){strcpy(nombre, n);}
        void *setApellido(const char *a){strcpy(apellido, a);}
        void *setDomicilio(const char *r){strcpy(domicilio, r);}
        void *setEmail(const char *e){strcpy(email, e);}
        void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
        void setCargo(int c){if(c>0 && c<11)cargo=c;}
        //GETS
        int getDni(){return dni;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        const char *getDomicilio(){return domicilio;}
        const char *getEmail(){return email;}
        Fecha getFechaNacimiento(){return fechaNacimiento;}
        int getCargo(){return cargo;}

        void Cargar();
        void Mostrar();
};
Empleado::Empleado(int d=0, const char *n="S/N", const char *a="S/A", const char *dir="S/D", const char *e="S/E", Fecha f=Fecha(), int c=0){
    dni=d;
    strcpy(nombre, n);
    strcpy(apellido, a);
    strcpy(domicilio, dir);
    strcpy(email, e);
    fechaNacimiento=f;
    cargo=c;
}

void Empleado::Cargar(){
    int c;
    bool correcto=false;


    cout<<"DNI: ";
    cin>>dni;
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 19);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 19);
    cout<<"DOMICILIO: ";
    cargarCadena(domicilio, 29);
    cout<<"EMAIL: ";
    cargarCadena(email, 14);
    cout<<"FECHA DE NACIMIENTO: "<<endl;
    fechaNacimiento.Cargar();
    do{
        cout<<"CARGO: ";
        cin>>c;

        if(c>0 && c<11){
            cargo=c;
            correcto=true;
        }else{
            cout<<"Cargo incorrecto."<<endl;
        }

    } while (!correcto);
}

void Empleado::Mostrar(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"DOMICILIO: "<<domicilio<<endl;
    cout<<"EMAIL: "<<email<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<"CARGO: "<<cargo<<endl;
    cout<<endl;
}


int main(){
setlocale(LC_ALL, "");

Empleado e;

e.Mostrar();



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
