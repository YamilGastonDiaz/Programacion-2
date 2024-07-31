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


//CLASE INVESTIGADOR
class Investigador{
    private:
        int dni;
        char nombre[20];
        char apellido[20];
        Fecha fechaNacimiento;
        int unidadAcademica;
        int categoria;
        int especialidad;
    public:
        //CONSTRUCTOR
        Investigador(int, const char *, const char *, Fecha, int, int, int);
        //SETS
        void setDni(int d){dni=d;}
        void *setNombre(const char *n){strcpy(nombre, n);}
        void *setApellido(const char *a){strcpy(apellido, a);}
        void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
        void setUnidadAcademica(int u){if(u>0 && u<31)unidadAcademica=u;}
        void setCategoria(int c){if(c>0 && c<6)categoria=c;}
        void setEspecialidad(int e){if(e>0 && e<11)especialidad=e;}
        //GETS
        int getDni(){return dni;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        Fecha getFechaNacimiento(){return fechaNacimiento;}
        int getUnidadAcademica(){return unidadAcademica;}
        int getCategoria(){return categoria;}
        int getEspecialidad(){return especialidad;}
};

Investigador::Investigador(int d=0, const char *n="S/N", const char *a="S/A", Fecha f=Fecha(), int u=0, int c=0, int e=0){
    dni=d;
    strcpy(nombre, n);
    strcpy(apellido, a);
    fechaNacimiento=f;
    unidadAcademica=u;
    categoria=c;
    especialidad=e;
}


int main(){
setlocale(LC_ALL, "");

Investigador i;





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
