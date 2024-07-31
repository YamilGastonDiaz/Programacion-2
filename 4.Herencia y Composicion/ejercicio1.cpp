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
//CLASE PERSONA
class Persona{
    private:
        int dni;
        char nombre[20];
        char apellido[20];
        Fecha fechaNacimiento;
        char telefono[30];
        char email[30];
    public:
        Persona();

        void setDni(int d){dni=d;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setApellido(const char *a){strcpy(apellido, a);}
        void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
        void setTelefono(const char *t){strcpy(telefono, t);}
        void setEmail(const char *e){strcpy(email, e);}

        int getDni(){return dni;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        Fecha getFechaNacimiento(){return fechaNacimiento;}
        const char *getTelefono(){return telefono;}
        const char *getEmail(){return email;}

        void Cargar();
        void Mostrar();
};
Persona::Persona(){
    dni=0;
    strcpy(nombre, "S/N");
    strcpy(apellido, "S/A");
    fechaNacimiento=Fecha();
    strcpy(telefono, "S/T");
    strcpy(email, "S/E");
}

void Persona::Cargar(){
    cout<<"DNI: ";
    cin>>dni;
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 19);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 19);
    cout<<"FECHA DE NACIMIENTO: "<<endl;
    fechaNacimiento.Cargar();
    cout<<"TELEFNO: ";
    cargarCadena(telefono, 29);
    cout<<"EMAIL: ";
    cargarCadena(email, 29);
    cout<<endl;
}

void Persona::Mostrar(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO: "<<endl;
    fechaNacimiento.Mostrar();
    cout<<"TELEFNO: "<<telefono<<endl;
    cout<<"EMAIL: "<<email<<endl;
}
//CLASE EMPLEADO
class Empleado:public Persona{
    private:
        int categoria;
        float sueldo;
        Fecha fechaIngreso;
    public:
        Empleado();

        void setCategoria(int c){categoria=c;}
        void setSueldo(float s){sueldo=s;}
        void setFechaIngreso(Fecha fi){fechaIngreso=fi;}

        int getCategoria(){return categoria;}
        float getSueldo(){return sueldo;}
        Fecha getFechaIngreso(){return fechaIngreso;}

        void Cargar();
        void Mostrar();
};
Empleado::Empleado(){
    categoria=0;
    sueldo=0;
    fechaIngreso=Fecha();
}

void Empleado::Cargar(){
    Persona::Cargar();
    cout<<"CATEGORIA: ";
    cin>>categoria;
    cout<<"SUELDO: ";
    cin>>sueldo;
    cout<<"FECHA DE INGRESO: "<<endl;
    fechaIngreso.Cargar();
}

void Empleado::Mostrar(){
    Persona::Mostrar();
    cout<<"CATEGORIA: "<<categoria<<endl;
    cout<<"SUELDO: "<<sueldo<<endl;
    cout<<"FECHA DE INGRESO: "<<endl;
    fechaIngreso.Mostrar();
}
//CLASE PROVEEDOR
class Proveedor:public Persona{
    private:
        int cuil;
        int tipoProducto;
        char condionPago;
    public:
        Proveedor();

        void setCuil(int cl){cuil=cl;}
        void setTipoProducto(int tp){tipoProducto=tp;}
        void setCondicionPago(char cp){condionPago=cp;}

        int getCuil(){return cuil;}
        int getTipoProducto(){return tipoProducto;}
        char getCondicionpago(){return condionPago;}

        void Cargar();
        void Mostrar();
};
Proveedor::Proveedor(){
    cuil=0;
    tipoProducto=0;
    condionPago='x';
}

void Proveedor::Cargar(){
    Persona::Cargar();
    cout<<"CUIL: ";
    cin>>cuil;
    cout<<"TIPO PRODUCTO: ";
    cin>>tipoProducto;
    cout<<"CONDICION DE PAGO: ";
    cin>>condionPago;
}

void Proveedor::Mostrar(){
    Persona::Mostrar();
    cout<<"CUIL: "<<cuil<<endl;
    cout<<"TIPO PRODUCTO: "<<tipoProducto<<endl;
    cout<<"CONDICION DE PAGO: "<<condionPago<<endl;
}
//CLASE DOCENTE
class Docente:public Persona{
    private:
        int legajo;
        char cargo[15];
        Fecha fechaIngreso;
    public:
        Docente();

        void setLegajo(int lo){legajo=lo;}
        void *setCargo(const char *carg){strcpy(cargo, carg);}
        void *setFechaNacimiento(Fecha fi){fechaIngreso=fi;}

        int getLegajo(){return legajo;}
        char *getCargo(){return cargo;}
        Fecha getFechaNacimiento(){return fechaIngreso;}

        void Cargar();
        void Mostrar();
};
Docente::Docente(){
    legajo=0;
    strcpy(cargo, "S/C");
    fechaIngreso=Fecha();
}

void Docente::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO: ";
    cin>>legajo;
    cout<<"CARGO: ";
    cargarCadena(cargo, 14);
    cout<<"FECHA INGRESO: "<<endl;
    fechaIngreso.Cargar();
}

void Docente::Mostrar(){
    Persona::Mostrar();
    cout<<"LEGAJO: "<<legajo<<endl;
    cout<<"CARGO: "<<cargo<<endl;
    cout<<"FECHA INGRESO: "<<endl;
    fechaIngreso.Mostrar();
}


int main(){
setlocale(LC_ALL, "");

Docente doce;

doce.Mostrar();


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
