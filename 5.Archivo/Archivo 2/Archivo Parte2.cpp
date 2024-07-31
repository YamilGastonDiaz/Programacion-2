#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

const char *NOMBRE_ARCHIVOM="municipios.dat";

void cargarCadena(char *pal, int tam)
{
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}
//CLASE MUNICIPIO
class Municipio{
    private:
        int numero;
        char nombre[20];
        int seccion;
        int cantidadH;
        bool estado;
    public:
        Municipio(){estado=false;}
        //SET
        void setNumero(int nm){numero=nm;}
        void *setNombre(const char *nob){strcpy(nombre, nob);}
        void setSeccion(int sec){seccion=sec;}
        void setCantidadH(int ch){cantidadH=ch;}
        void setEstado(bool e){estado=e;}
        //GET
        int getNumero(){return numero;}
        const char *getNombre(){return nombre;}
        int getSeccion(){return seccion;}
        int getCantidadH(){return cantidadH;}
        bool getEstado(){return estado;}

        void Cargar();
        void Mostrar();
};

void Municipio::Cargar(){
    cout<<"NUMERO: ";
    cin>>numero;
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 19);
    cout<<"SECCION: ";
    cin>>seccion;
    cout<<"CANTIDAD DE HABITANTES: ";
    cin>>cantidadH;
    estado=true;
    cout<<endl;
}

void Municipio::Mostrar(){
    if(estado==true){
    cout<<"NUMERO: "<<numero<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"SECCION: "<<seccion<<endl;
    cout<<"CANTIDAD DE HABITANTES: "<<cantidadH<<endl;
    }
}
//CLASE ARCHIVO MUNICIPIO
class ArchivoMunicipios{
    private:
        char nombre[30];
    public:
        ArchivoMunicipios(const char *n="municipios.dat"){strcpy(nombre, n);}

        Municipio leerRegistro(int pos);
        int contarRegistros();
        bool grabarRegistro(Municipio obj);
        bool listarRegistro();
};

Municipio ArchivoMunicipios::leerRegistro(int pos){
    Municipio obj;
    FILE *pFile;

    pFile=fopen(NOMBRE_ARCHIVOM, "rb");
    if(pFile==NULL){
        return obj;
    }
    fseek(pFile, sizeof (Municipio)*pos, SEEK_SET);
    fread(&obj, sizeof (Municipio), 1, pFile);
    fclose(pFile);
    return obj;
}

int ArchivoMunicipios::contarRegistros(){
    FILE *pFile;
    int tam;

    pFile=fopen(NOMBRE_ARCHIVOM, "rb");
    if(pFile==NULL){
        return -1;
    }
    fseek(pFile, 0, SEEK_END);
    tam=ftell(pFile);
    fclose(pFile);
    return tam/sizeof(Municipio);
}

//ALTA REGISTRO
bool ArchivoMunicipios::grabarRegistro(Municipio obj){
    FILE *pFile;
    bool escribir;

    pFile=fopen(NOMBRE_ARCHIVOM, "ab");
    if(pFile==NULL){
        return false;
    }
    escribir=fwrite(&obj, sizeof (Municipio), 1, pFile);
    fclose(pFile);
    return escribir;
}

//ALTA REGISTRO
void altaMunicipio(){
    Municipio obj;
    ArchivoMunicipios objA;
    obj.Cargar();
    objA.grabarRegistro(obj);
}


//LISTAR REGISTRO
bool ArchivoMunicipios::listarRegistro(){
    Municipio obj;
    FILE *pFile;

    pFile=fopen(NOMBRE_ARCHIVOM, "rb");
    if(pFile==NULL){
        return false;
    }
    while(fread(&obj, sizeof (Municipio), 1, pFile)){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(pFile);
    return true;
}

void Listar(){
    ArchivoMunicipios objA;
    objA.listarRegistro();
}

void Punto3(){
    Municipio reg;
    ArchivoMunicipios archivoM;
    int cantidad=archivoM.contarRegistros();

    int vHabitante[135]={};

    for(int i = 0; i < cantidad; i++){
        reg=archivoM.leerRegistro(i);
        vHabitante[reg.getNumero()-1]+=reg.getCantidadH();
    }

    int contador=0;
    for(int i = 0; i < 135; i++){
        if(vHabitante[i]<200000){
            contador++;
        }
    }
    cout<<"cantidad de habitantes menor a 200000: "<<contador<<endl;
}

void punto4(){
    Municipio reg;
    ArchivoMunicipios archivoM;
    int cantidad=archivoM.contarRegistros();

    int vMayor[9]={};

    for(int i = 0; i < cantidad; i++){
        reg=archivoM.leerRegistro(i);
        vMayor[reg.getSeccion()-1]+=reg.getCantidadH();
    }

    int mayor=0;
    int pos=0;

    for(int i = 0; i < 135; i++){
        if(vMayor[i]>mayor){
            mayor=vMayor[i];
            pos=i;
        }
    }

    archivoM.leerRegistro(pos+1);
    cout<<"seccion con mayor habitantes: "<<reg.getSeccion()<<endl;

}

int main()
{
    setlocale(LC_ALL, "");

    int opc;

    while(true)
    {
        system("cls");
        cout<<"----------MENU------------"<<endl;
        cout<<"1). ALTA EMPRESA"<<endl;
        cout<<"2). LISTADOS"<<endl;
        cout<<"3). Calcular e informar la cantidad de municipios con menos de 200.000 habitantes."<<endl;
        cout<<"4). Calcular e informar la sección con mayor cantidad de habitantes."<<endl;
        cout<<"0). SALIR"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
                altaMunicipio();
                system("pause");
            break;
        case 2:
                Listar();
                system("pause");
            break;
        case 3:
                Punto3();
                system("pause");
            break;
        case 4:
                punto4();
                system("pause");
            break;
        case 0:
            return 0;
        }
    }

    cout<<endl;
    system("pause");
    return 0;
}










