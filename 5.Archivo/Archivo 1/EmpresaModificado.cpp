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
    Empresa()
    {
        estado=false;
    }
    void setNumero(int n)
    {
        numero = n;
    }
    void setNombre(const char *nomb)
    {
        strcpy(nombre, nomb);
    }
    void setCategoria(int c)
    {
        categoria = c;
    }
    void setNumeroMunicipio(int nm)
    {
        numeroMunicipio=nm;
    }
    void setEstado(bool e)
    {
        estado = e;
    }

    int getNumero()
    {
        return numero;
    }
    const char *getNombre()
    {
        return nombre;
    }
    int getCantidadEmpleados()
    {
        return cantidadEmpleados;
    }
    int getCategoria()
    {
        return categoria;
    }
    int getNumeroMunicipio()
    {
        return numeroMunicipio;
    }
    bool getEstado()
    {
        return estado;
    }
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

class ArchivoEmpresas
{
private:
    char _nombreEmp[20];
public:
    ArchivoEmpresas(const char *nombreEmp="empresas modificado.dat")
    {
        strcpy(_nombreEmp, nombreEmp);
    }
    //ALTA REGISTRO
    bool grabarRegistro(Empresa obj);
    //PARA MODIFICAR Y BAJA DE ARCHIVO
    Empresa leerRegistro(int pos);
    int buscarId(int pos);
    bool cambiarRegistro(Empresa obj, int pos);
    //LISTAR REGISTRO
    bool listarRegistro();
    //LISTAR REGISTRO POR INGRESO DE NUMERO
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
//NECESARIO PARA MODIFICAR Y BAJA DE ARCHIVO
int ArchivoEmpresas::buscarId(int num){
    Empresa obj;
    int pos=0;
    FILE *pFile;

    pFile=fopen(NOMBRE_ARCHIVO, "rb");
    if(pFile==NULL){
        return -1;
    }

    while(fread(&obj, sizeof(Empresa), 1, pFile)){
        if(obj.getNumero()==num){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -2;
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

bool ArchivoEmpresas::cambiarRegistro(Empresa obj, int pos){
    FILE *pFile;
    bool resultado;

    pFile=fopen(NOMBRE_ARCHIVO, "rb+");
    if(pFile==NULL){
        return false;
    }

    fseek(pFile, sizeof (Empresa)*pos, SEEK_SET);
    resultado=fwrite(&obj, sizeof (Empresa), 1, pFile);
    fclose(pFile);
    return resultado;
}

//ALTA REGSITRO
void altaEmpresa(){
    Empresa obj;
    ArchivoEmpresas objA;
    obj.Cargar();
    objA.grabarRegistro(obj);
}
//BAJA REGISTRO
void bajaLogica(){
    Empresa obj;
    ArchivoEmpresas objA;
    int num, pos;
    char eliminar;

    cout<<"Ingrese un numero de empresa a borrar: ";
    cin>>num;

    pos=objA.buscarId(num);
    if(pos == -2){
        cout<<"No se encontro el archivo"<<endl;
        return;
    }
    obj=objA.leerRegistro(pos);
    obj.Mostrar();
    cout<<"Esta seguro de eliminar el registro? (S/N): ";
    cin>>eliminar;

    if(eliminar == 's' || eliminar == 'S'){
            obj.setEstado(false);
            cout<<endl;
            if(objA.cambiarRegistro(obj, pos)){
                    cout<<"Eliminado"<<endl;
            }else{
                    cout<<"No se pudo eliminar"<<endl;
            }

    }
}
//MODIFICAR REGISTRO(categoria)
void ModificarRegistro(){
    Empresa obj;
    ArchivoEmpresas objA;
    int num, pos, categoria;
    char modificar;

    cout<<"Ingrese un numero de empresa a modificar: ";
    cin>>num;

    pos=objA.buscarId(num);
    if(pos == -2){
        cout<<"No se encontro el archivo"<<endl;
        return;
    }
    obj=objA.leerRegistro(pos);
    obj.Mostrar();
    cout<<"Esta seguro de modificar el registro? (S/N): ";
    cin>>modificar;

    if(modificar == 's' || modificar == 'S'){
        cout<<"ingrese la categoria: ";
        cin>>categoria;
        obj.setCategoria(categoria);
        cout<<endl;
        if(objA.cambiarRegistro(obj, pos)){
            cout<<"se modifico"<<endl;
        }else{
            cout<<"no se modifico"<<endl;
        }
    }
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
//LISTAR POR INGRESO DE NUMERO DE EMPRESA
int ArchivoEmpresas::contarRegistros(){
    FILE *pFile;
    int tam;

    pFile=fopen(NOMBRE_ARCHIVO, "rb");
    if(pFile==NULL){
        return -1;
    }
    fseek(pFile, 0, SEEK_END);
    tam=ftell(pFile);
    fclose(pFile);
    return tam/sizeof(Empresa);
}

void listarXnumero(){
    Empresa obj;
    ArchivoEmpresas objA;
    int numero, cantEmpresa;

    cantEmpresa=objA.contarRegistros();
    if(cantEmpresa<=0){
        cout<<"Problemas con el registro o registro inexistente"<<endl;
        return;
    }
    cout<<"Ingrese numero de empresa: ";
    cin>>numero;
    for(int i = 0; i < cantEmpresa; i++){
        obj=objA.leerRegistro(i);
        if(obj.getNumero()==numero){
            obj.Mostrar();
            cout<<endl;
        }else{
            cout<<"no se encuentra la empresa"<<endl;
        }
    }
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
        cout<<"2). BAJA EMPRESA"<<endl;
        cout<<"3). MODIFICAR CATEGORIA EMPRESA"<<endl;
        cout<<"4). LISTADOS"<<endl;
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
                bajaLogica();
                system("pause");
            break;
        case 3:
                ModificarRegistro();
                system("pause");
            break;
        case 4:
            char opc;
            while(true)
            {
                system("cls");
                cout<<"a). LISTAR EMPRESAS"<<endl;
                cout<<"b). LISTAR EMPRESA POR NUMERO"<<endl;
                cout<<"c). VOLVER AL MENU PRINCIPAL"<<endl;
                cout<<"OPCION: ";
                cin>>opc;
                system("cls");
                switch(opc)
                {
                case 'a':
                        Listar();
                    break;
                case 'b':
                        listarXnumero();
                    break;
                case 'c':
                    break;
                }
                if(opc=='c') // Salir del bucle del submenú si se elige la opción C
                {
                    break;
                }
                system("pause");
            }
            break;
        case 0:
            return 0;
        }
    }

    cout<<endl;
    system("pause");
    return 0;
}





