#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

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

class Empresa{
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

void Empresa::Cargar(){
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

void Empresa::Mostrar(){
    if(estado==true){
        cout<<"NUMERO: "<<numero<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CANTIDAD DE EMPLEADOS: "<<cantidadEmpleados<<endl;
        cout<<"CATEGORIA: "<<categoria<<endl;
        cout<<"NUMERO DE MUNICIPIO: "<<numeroMunicipio<<endl;
    }
}

class ArchivoEmpresas{
    private:
        char _nombreEmp[20];
    public:
        ArchivoEmpresas(const char *nombreEmp="empresas.dat"){strcpy(_nombreEmp, nombreEmp);}
};

bool CargarDuno();
bool CargarVector();
bool mostrarArchivo();
void cantEmpresa();
void empleadoMasD();
void categoriaMasE();


int main(){
setlocale(LC_ALL, "");

char opc;

while(true){
    system("cls");
    cout<<"----------MENU------------"<<endl;
    cout<<"a). Con un registro solo."<<endl;
    cout<<"b). Con un vector de 5 registros."<<endl;
    cout<<"c). Mostrar archivo."<<endl;
    cout<<"d). Calcular e informar la cantidad de empresas de cada municipio."<<endl;
    cout<<"e). Informar los nombres de las empresas con más de 200 empleados."<<endl;
    cout<<"f). Calcular e informar la categoría de empresa con más empleados"<<endl;
    cout<<"s). SALIR"<<endl;
    cout<<"OPCION: ";
    cin>>opc;
        system("cls");
        switch(opc){
            case 'a':
                    CargarDuno();
                break;
            case 'b':
                    CargarVector();
                break;
            case 'c':
                    mostrarArchivo();
                break;
            case 'd':
                    cantEmpresa();
                break;
            case 'e':
                    empleadoMasD();
                break;
            case 'f':
                    categoriaMasE();
                break;
            case 's':
                return 0;
        }
        system("pause");
}


cout<<endl;
system("pause");
return 0;
}

bool CargarDuno(){
    Empresa reg;
    FILE *pEmpresa;

    pEmpresa=fopen("empresas.dat", "wb");
    if(pEmpresa==NULL){
       cout<<"No se pudo crear.";
       return false;
    }

    for(int i = 0; i < 5; i++){
        reg.Cargar();
        fwrite(&reg, sizeof (Empresa), 1, pEmpresa);
    }
    fclose(pEmpresa);
    return true;
}

bool CargarVector(){
    Empresa reg[5];
    FILE *pEmpresa;

    pEmpresa=fopen("empresas.dat", "ab");
    if(pEmpresa==NULL){
        cout<<"no se pudo crear el archivo";
        return false;
    }

    for(int i = 0; i < 5; i++){
        reg[i].Cargar();
        cout<<endl;
    }

    fwrite(reg, sizeof (Empresa), 5, pEmpresa);
    fclose(pEmpresa);
    return true;
}

bool mostrarArchivo(){
    Empresa reg;
    FILE *pEmpresa;

    pEmpresa=fopen("empresas.dat", "rb");
    if(pEmpresa==NULL){
        cout<<"no se pudo abrir el archivo";
        return false;
    }
    while(fread(&reg, sizeof (Empresa), 1, pEmpresa)==1){
        reg.Mostrar();
        cout<<endl;
    }

    fclose(pEmpresa);
    return true;
}

void cantEmpresa(){
    Empresa reg;
    const int TAM=5;
    int contadorE[TAM]={};

    FILE *pEmpresa;

    pEmpresa=fopen("empresas.dat", "rb");
    if(pEmpresa==NULL){
        cout<<"ERROR"<<endl;
    }

    while(fread(&reg, sizeof (Empresa), 1, pEmpresa)==1){
        contadorE[reg.getNumeroMunicipio()-1]++;
    }
    cout<<"Cantidad de empresas de cada municipio: "<<endl;
    for(int i = 0; i < TAM ; i++){
        cout<<"Municipio #"<<i+1<<": "<<contadorE[i]<<endl;
    }
    fclose(pEmpresa);
}

void empleadoMasD(){
    Empresa reg;

    FILE *pEmpresa;
    pEmpresa=fopen("empresas.dat", "rb");
    if(pEmpresa==NULL){
        cout<<"ERROR"<<endl;
    }

    cout<<"Empresas con más de 200 empleados: "<<endl;
    while(fread(&reg, sizeof (Empresa), 1, pEmpresa)==1){
        if(reg.getCantidadEmpleados()>200){
            cout<<reg.getNombre()<<endl;
        }
    }
    fclose(pEmpresa);
}

void categoriaMasE() {
	Empresa reg;
	int mayor = 0;
	int categoria=0;

	FILE* pEmpresa;
	pEmpresa = fopen("empresas.dat", "rb");
	if (pEmpresa == NULL) {
		cout << "ERROR" << endl;
	}

	while (fread(&reg, sizeof(Empresa), 1, pEmpresa) == 1) {
		if (reg.getCantidadEmpleados() > mayor) {
			mayor = reg.getCantidadEmpleados();
			categoria=reg.getCategoria();
		}
	}

	cout << "Categoria de empresa con más empleados: " <<categoria<< endl;

    fclose(pEmpresa);
}
