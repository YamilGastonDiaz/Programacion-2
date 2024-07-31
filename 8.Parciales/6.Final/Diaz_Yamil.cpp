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

class Fecha{
    private:
        int dia, mes, anio;
    public:
    Fecha();

    void setDia(int);
    void setMes(int);
    void setAnio(int);

    int getDia();
    int getMes();
    int getAnio();

    void Cargar();
    void Mostrar();
};

Fecha::Fecha(){
    dia=1;
    mes=1;
    anio=1900;
}

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

class Final{
    private:
        int codigo;
        char nombre[30];
        char apellido[30];
        int dni;
        Fecha fechaNacimiento;
        float deuda;
        int categoria;
        bool estado;

    public:

        void setCodigo(int c){codigo = c;}
        void setNombre(const char* n){strcpy(nombre,n);}
        void setApellido(const char* a){strcpy(apellido,a);}
        void setDni(int d){dni = d;}
        void setFechaNacimiento(Fecha f){fechaNacimiento = f;}
        void setDeuda(float da){deuda = da;}
        void setCategoria(int cat){categoria = cat;}
        void setEstado(bool e){estado=e;}

        int getCodigo(){return codigo;}
        const char* getNombre(){return nombre;}
        const char* getApellido(){return apellido;}
        int getDni(){return dni;}
        Fecha getFechaDeNacimiento(){return fechaNacimiento;}
        float getDeuda(){return deuda;}
        int getCategoria(){return categoria;}
        bool getEstado(){return estado;}
};


class ArchivoFinal{
private:
	char nombre[30];
public:
	ArchivoFinal(const char *n="final.dat"){///cambiar las comillas si no compila!!!!!
		strcpy(nombre, n);
	}
	Final leerRegistro(int pos){
		Final reg;
		reg.setEstado(false);
		FILE *p;
		p=fopen(nombre, "rb");
		if(p==NULL) return reg;
		fseek(p, sizeof reg*pos,0);
		fread(&reg, sizeof reg,1, p);
		fclose(p);
		return reg;
	}
		int contarRegistros(){
			FILE *p;
			p=fopen(nombre, "rb");
			if(p==NULL) return -1;
			fseek(p, 0,2);
			int tam=ftell(p);
			fclose(p);
			return tam/sizeof(Final);
		}
			bool grabarRegistro(Final reg){
				FILE *p;
				p=fopen(nombre, "ab");
				if(p==NULL) return false;
				bool escribio=fwrite(&reg, sizeof reg,1, p);
				fclose(p);
				return escribio;
			}

			bool validarId(int codigo){
                Final reg;
                FILE *p;
                p = fopen(nombre,"rb");
                if (p == NULL) return false;
                while (fread(&reg, sizeof reg, 1, p)==1 ){
                    if (reg.getCodigo() == codigo)
                    {
                        return true;
                    }
                }
                fclose(p);
                return false;
            }

            int BuscarId(int indice) {
                Final reg;
                int pos = 0;
                FILE* pFile;

                pFile = fopen(nombre, "rb");
                if (pFile == nullptr) {
                    return -1;
                }

            while (fread(&reg, sizeof(Final), 1, pFile)) {
                if (reg.getCodigo() == indice) {
                    fclose(pFile);
                    return pos;
                }
            pos++;
            }

            fclose(pFile);
            return -1;
            }

            bool Sobreescribir(int pos, Final reg) {
                FILE* pFile;

                pFile = fopen(nombre, "rb+");
                if (pFile == nullptr) {
                    return false;
                }

                fseek(pFile, sizeof(Final) * pos, SEEK_SET);

                bool resultado = fwrite(&reg, sizeof(Final), 1, pFile);

                fclose(pFile);

                return resultado;
            }

};


void altaArchivo(){
	ArchivoFinal archiF;
	Final obj;
	Fecha objF;

	int codigo;
	char nombre[30];
	char apellido[30];
	int dni;
	float deuda;
	int categoria;
	bool estado;

	cout << "CODIGO: ";
	cin >> codigo;
	while (archiF.validarId(codigo))
	{
		cout << "El codigo ingresado ya existe, ingrese nuevamente: " << endl;
		cin >> codigo;
	}
    obj.setCodigo(codigo);

	cout << "NOMBRE: ";
	cargarCadena(nombre, 30);
	obj.setNombre(nombre);

	cout << "APELLIDO: ";
	cargarCadena(apellido, 30);
	obj.setApellido(apellido);

	cout << "DNI: ";
	cin >> dni;
	obj.setDni(dni);

	cout << "FECHA DE NACIMIENTO" << endl;
	objF.Cargar();

	cout << "DEUDA: ";
	cin >> deuda;
	obj.setDeuda(deuda);

	cout << "CATEGORIA: ";
	cin >> categoria;
	obj.setCategoria(categoria);

	estado = true;
    obj.setEstado(estado);

	if(archiF.grabarRegistro(obj)){
		cout << "El registro se guardo con exito." << endl;
	}else
	{
		cout << "Hubo un error al guardar el registro." << endl;
	}

}


void bajaRegistro(){
    int codigo, indice;
    Final obj;
    ArchivoFinal archivo;
    int opcion;

    cout<<"ingrese el codigo que desea eliminar: ";
    cin>> codigo;


    indice=archivo.BuscarId(codigo);

    if(indice != -1){
        obj=archivo.leerRegistro(indice);


        cout<< "Desea eliminar este vendedor? (1)Si - (2)No: " << endl;
        cin>>opcion;
        system("cls");

        if(opcion == 1){
            if(obj.getEstado()==true){
                obj.setEstado(false);

                if(archivo.Sobreescribir(indice, obj)){
                    cout<<"Se elimino con exito."<<endl;
                }else{
                    cout<<"No se pudo eliminar."<<endl;
                }
            }
        }else{
            cout<<"Cancelo el eliminado del vendedor."<<endl;
        }
    }else{
        cout<<"Numero de Legajo inexistente."<<endl;
    }
}

void menu() {
	int opc;
	while(true){
    system("cls");
	cout << "1. Alta de registro."<<endl;
	cout << "2. Baja de registro."<<endl;
	cout <<"0. SALIR"<<endl;
	cout << "OPCION: ";
	cin >> opc;
	system("cls");
	switch (opc)
	{
		case 1:
			altaArchivo();
			system("pause");
			break;
		case 2:
            bajaRegistro();
			system("pause");
			break;
        case 0:
            exit(10);
	default:
		break;
	}
	}
}


int main(){
setlocale(LC_ALL, "");


menu();


cout<<endl;
system("pause");
return 0;
}
