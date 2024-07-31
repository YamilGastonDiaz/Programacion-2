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


//CALSE CLIENTE
class Cliente{
    private:
        int dni;
        Fecha fechaNacimiento;
        char nombre[20];
        char apellido[20];
        char email[30];
        char telefono[15];
    public:
        //CONSTRUCTOR
        Cliente(int d=0, Fecha f=Fecha(), const char *n="S/N", const char *a="S/A", const char *e="S/E", const char *t="S/T");
        //SET
        void setDni(int d){dni=d;}
        void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setApellido(const char *a){strcpy(apellido, a);}
        void setEmail(const char *e){strcpy(email, e);}
        void setTelefono(const char *t){strcpy(telefono, t);}
        //GETS
        int getDni(){return dni;}
        Fecha getFechaNacimiento(){return fechaNacimiento;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        const char *getEmail(){return email;}
        const char *getTelefono(){return telefono;}

        void Cargar();
        void Mostrar();
};

Cliente::Cliente(int d, Fecha f, const char *n, const char *a, const char *e, const char *t){
    dni=d;
    fechaNacimiento=f;
    strcpy(nombre, n);
    strcpy(apellido, a);
    strcpy(email, e);
    strcpy(telefono, t);
}

void Cliente::Cargar(){
    cout<<"DNI: ";
    cin>>dni;
    cout<<"FECHA DE NACIMIENTO: "<<endl;
    fechaNacimiento.Cargar();
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 19);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 19);
    cout<<"EMAIL: ";
    cargarCadena(email, 29);
    cout<<"TELEFONO: ";
    cargarCadena(telefono, 14);
    cout<<endl;
}

void Cliente::Mostrar(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"EMAIL: "<<email<<endl;
    cout<<"TELEFONO: "<<telefono<<endl;
    cout<<endl;
}

void PuntoA(Cliente *c, int tam){
    for(int i = 0; i < tam; i++){
        c[i].Cargar();
    }
}

void PuntoB(Cliente *c, int tam){
    for(int i = 0; i < tam; i++){
        c[i].Mostrar();
    }
}

void PuntoC(Cliente *c, int tam){
    int numDni;
    cout<<"Ingrese DNI: ";
    cin>>numDni;
    cout<<endl;

    for(int i = 0; i < tam; i++){
        if(c[i].getDni()>numDni){
            c[i].Mostrar();
        }
    }
}

int PuntoDb(Cliente *c, int tam, int numDni){
    for(int i = 0; i < tam; i++){
        if(c[i].getDni()==numDni){
            return i;
        }
    }
    return -1;
}

void PuntoD(Cliente *c, int tam){
    int numDni;
    cout<<"Ingrese DNI: ";
    cin>>numDni;
    cout<<endl;

    cout<<"Posicion: "<<PuntoDb(c, tam, numDni)<<endl;

}

Cliente PuntoEb(Cliente *c, int tam, int numDni){
    Cliente aux;
    for(int i = 0; i < tam; i++){
        if(c[i].getDni()==numDni){
            return c[i];
        }
    }
    aux.setDni(-1);
    return aux;
}

void PuntoE(Cliente *c, int tam){
    Cliente aux;
    int numDni;
    cout<<"Ingrese DNI: ";
    cin>>numDni;
    aux=PuntoEb(c, tam, numDni);
    if(aux.getDni()==-1){
        aux.Mostrar();
    }else{
        aux.Mostrar();
    }
}

int PuntoFb(Cliente *c, int tam, Fecha f_ingreso){
    int contador=0;
    for(int i = 0; i < tam; i++){
        if(c[i].getFechaNacimiento().getAnio() < f_ingreso.getAnio()){
            contador++;
        }else{
            if(c[i].getFechaNacimiento().getAnio() == f_ingreso.getAnio() && c[i].getFechaNacimiento().getMes() < f_ingreso.getMes()){
                contador++;
            }else{
                if(c[i].getFechaNacimiento().getMes() == f_ingreso.getMes() && c[i].getFechaNacimiento().getDia() < f_ingreso.getDia()){
                    contador++;
                }
            }
        }
    }
    return contador;
}

void PuntoF(Cliente *c, int tam){
    Fecha f_ingreso;
    cout<<"Ingrese FECHA: "<<endl;
    f_ingreso.Cargar();

    cout<<"Cantida de clientes: "<<PuntoFb(c, tam, f_ingreso);

}

int main(){
setlocale(LC_ALL, "");

const int TAM=2;
Cliente c[TAM];

char opc;

while(true){
    system("cls");
    cout<<"----------MENU------------"<<endl;
    cout<<"a). Cargar un vector de 10 clientes."<<endl;
    cout<<"b). Listar todos los clientes del vector."<<endl;
    cout<<"c). Listar todos los clientes cuyo DNI sea mayor a un valor que se ingresa por teclado."<<endl;
    cout<<"d). Devolver la posición del objeto que contiene ese DNI. De no encontrarlo devolver -1."<<endl;
    cout<<"e). Devolver el objeto completo que contiene el DNI. De no encontrarlo devolver un valor de -1 en el DNI."<<endl;
    cout<<"f). Devolver la cantidad la cantidad de clientes cuyo nacimiento sea anterior a ese valor recibido."<<endl;
    cout<<"s). SALIR"<<endl;
    cout<<"OPCION: ";
    cin>>opc;
        system("cls");
        switch(opc){
            case 'a':
                    PuntoA(c, TAM);
                break;
            case 'b':
                    PuntoB(c, TAM);
                break;
            case 'c':
                    PuntoC(c, TAM);
                break;
            case 'd':
                    PuntoD(c, TAM);
                break;
            case 'e':
                    PuntoE(c, TAM);
                break;
            case 'f':
                    PuntoF(c, TAM);
                break;
            case 's':
                return 0;
        }
        system("pause>nul");
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
