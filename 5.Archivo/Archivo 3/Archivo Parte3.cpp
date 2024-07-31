#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

const char *NOMBRE_ARCHIVO="empresaModificado.dat";

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
//CALSE CATEGORIA
class Categoria{
    private:
        int numero;
        char nombre[20];
        bool estado;
    public:
        Categoria(){estado=false;}

        void setNumero(int n){numero=n;}
        void *setNombre(const char *nom){strcpy(nombre, nom);}
        void setEstado(bool e){estado=e;}

        int getNumero(){return numero;}
        const char *getNombre(){return nombre;}
        bool getEstado(){return estado;}

        void Cargar();
        void Mostrar();
};

void Categoria::Cargar(){
    cout<<"NUMERO: ";
    cin>>numero;
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 19);
    estado=true;
}

void Categoria::Mostrar(){
    if(estado==true){
        cout<<"NUMERO: "<<numero<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
    }
}
//CLASE ARCHIVO CATEGORIA
class ArchivoCategoria{
    private:
        char nombre[30];
    public:
        ArchivoCategoria(const char *n="Categoria.dat"){strcpy(nombre, n);}

        Categoria leerRegistro(int pos);
        int contarRegistro();
};

Categoria ArchivoCategoria::leerRegistro(int pos){
    FILE *pFile;
    Categoria obj;

    pFile=fopen("Categoria.dat", "rb");
    if(pFile==NULL){
        return obj;
    }
    fseek(pFile, sizeof (Categoria)*pos, SEEK_SET);
    fread(&obj, sizeof (Categoria), 1, pFile);
    fclose(pFile);
    return obj;
}

int ArchivoCategoria::contarRegistro(){
    FILE *pFile;

    pFile=fopen("Categoria.dat", "rb");
    if(pFile==NULL){
        return -1;
    }

    fseek(pFile, 0, SEEK_END);
    int tam=ftell(pFile);
    fclose(pFile);
    return tam/sizeof(Categoria);
}

//CLASE EMPRESA
class Empresa
{
private:
    int numero;
    char nombre[30];
    int cantidadEmpleados;
    int categoria; //1 a 80
    int numeroMunicipio;  //1 a 135
    bool estado;///true si el registro está activo; false si está borrado
public:
    Empresa(){estado=false;}
    void setNumero(int n){numero = n;}
    void setNombre(const char *nomb){strcpy(nombre, nomb);}
    void setCategoria(int c){categoria = c;}
    void setNumeroMunicipio(int nm){numeroMunicipio=nm;}
    void setEstado(bool e){estado = e;}

    int getNumero(){return numero;}
    const char *getNombre(){return nombre;}
    int getCantidadEmpleados(){return cantidadEmpleados;}
    int getCategoria(){return categoria;}
    int getNumeroMunicipio(){return numeroMunicipio;}
    bool getEstado(){return estado;}

    void Cargar();
    void Mostrar();
};

void Empresa::Cargar()
{
    cout<<"NUMERO: ";
    cin>>numero;
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"CANTIDAD DE EMPLEADOS: ";
    cin>>cantidadEmpleados;
    cout<<"CATEGORIA: ";
    cin>>categoria;
    cout<<"NUMERO DE MUNICIPIO: ";
    cin>>numeroMunicipio;
    estado=true;
    cout<<endl;
}

void Empresa::Mostrar()
{
    if(estado==true)
    {
        cout<<"NUMERO: "<<numero<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CANTIDAD DE EMPLEADOS: "<<cantidadEmpleados<<endl;
        cout<<"CATEGORIA: "<<categoria<<endl;
        cout<<"NUMERO DE MUNICIPIO: "<<numeroMunicipio<<endl;
    }
}

//CLASE ARCHIVO EMPRESA
class ArchivoEmpresas{
    private:
        char _nombreEmp[20];
    public:
        ArchivoEmpresas(const char *nombreEmp="empresas modificado.dat"){strcpy(_nombreEmp, nombreEmp);}
    //ALTA REGISTRO
        bool grabarRegistro(Empresa obj);
    //PARA MODIFICAR Y BAJA DE ARCHIVO
        Empresa leerRegistro(int pos);
        bool listarRegistro();
        int contarRegistros();
};
//ALTA REGISTRO
bool ArchivoEmpresas::grabarRegistro(Empresa obj){
    FILE *pFile;
    bool escribir;

    pFile=fopen(NOMBRE_ARCHIVO, "ab");
    if(pFile==NULL){
        return false;
    }
    escribir=fwrite(&obj, sizeof (Empresa), 1, pFile);
    fclose(pFile);
    return escribir;
}


int ArchivoEmpresas::contarRegistros(){
    FILE *pFile;

    pFile=fopen(NOMBRE_ARCHIVO, "rb");
    if(pFile==NULL){
        return -1;
    }

    fseek(pFile, 0, SEEK_END);
    int tam=ftell(pFile);
    fclose(pFile);
    return tam/sizeof(Empresa);
}


Empresa ArchivoEmpresas::leerRegistro(int pos){
    Empresa obj;
    FILE *pFile;

    pFile=fopen(NOMBRE_ARCHIVO, "rb");
    if(pFile==NULL){
        return obj;
    }
    fseek(pFile, sizeof (Empresa)*pos, SEEK_SET);
    fread(&obj, sizeof (Empresa), 1, pFile);
    fclose(pFile);
    return obj;
}

//ALTA REGSITRO
void altaEmpresa(){
    Empresa obj;
    ArchivoEmpresas objA;
    obj.Cargar();
    objA.grabarRegistro(obj);
}

//LISTAR REGISTRO
bool ArchivoEmpresas::listarRegistro(){
    Empresa obj;
    FILE *pFile;

    pFile=fopen(NOMBRE_ARCHIVO, "rb");
    if(pFile==NULL){
        return false;
    }
    while(fread(&obj, sizeof (Empresa), 1, pFile)){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(pFile);
    return true;
}

void Listar(){
    ArchivoEmpresas objA;
    objA.listarRegistro();
}

void Punto2(){
    Empresa regE;
    ArchivoEmpresas archivoE;
    int cantidad=archivoE.contarRegistros();


    int vCategoria[80]={};

    for(int i = 0; i < cantidad; i++){
        regE=archivoE.leerRegistro(i);
        vCategoria[regE.getCategoria()-1]++;
    }

    int mayor=0;
    int pos=0;
    for(int i = 0; i < 80; i++){
        if(vCategoria[i]>mayor){
            mayor=vCategoria[i];
            pos=i;
        }
    }

    cout<<"categoria con mas empresas: "<<pos+1<<endl;
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
        cout<<"2). Informar la categoría con más empresas."<<endl;
        cout<<"3). Generar un archivo con las empresas de la categoría 15."<<endl;
        cout<<"4). Generar un archivo con la cantidad de empresas de categoría 1 para cada municipio."<<endl;
        cout<<"5). LISTADOS"<<endl;
        cout<<"0). SALIR"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
                altaEmpresa();
                system("pause");
            break;
        case 2:
                Punto2();
                system("pause");
            break;
        case 3:

                system("pause");
            break;
        case 4:

                system("pause");
            break;
        case 5:
                Listar();
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










