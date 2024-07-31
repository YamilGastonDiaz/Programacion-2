#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

class RecuLunes {
private:
	int legajo;
	char nombre[30];
	char apellido[30];
	int dni;
	//Fecha fechaNacimiento;
	float sueldo;
	int carrera;
	bool estado;
public:

	void setLegajo(int l) { legajo = l; }
	void setNombre(const char* n) { strcpy(nombre, n); }
	void setApellido(const char* a) { strcpy(apellido, a); }
	void setDni(int d) { dni = d; }
	//void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
	void setSueldo(float s) { sueldo = s; }
	void setCarrera(int c) { carrera = c; }
	void setEstado(bool e) { estado = e; }


	int getLegajo() { return legajo; }
	const char* getNombre() { return nombre; }
	const char* getApellido() { return apellido; }
	int getDni() { return dni; }
	//Fecha getFechaNacimiento(){return fechaNacimiento;}
	float getSueldo() { return sueldo; }
	int getCarrera() { return carrera; }
	bool getEstado() { return estado; }

	void cargar() {
		cout << "Legajo: ";
		cin >> legajo;
		cout << "DNI: ";
		cin >> dni;
		cout << "Sueldo: ";
		cin >> sueldo;
		cout << "Carrera: ";
		cin >> carrera;
		estado = true;
	}

	void mostrar() {
		if (estado == true) {
			cout << "Legajo: " << legajo<<endl;
			cout << "DNI: " << dni<<endl;
			cout << "Sueldo: " << sueldo<<endl;
			cout << "Carrera: " << carrera<<endl;
		}
	}
};




class ArchivoRec {
private:
	char nombre[30];
public:
	ArchivoRec(const char* n = "reclunes.dat") {///cambiar las comillas si no compila!!!!!
		strcpy(nombre, n);
	}
	RecuLunes leerRegistro(int pos) {
		RecuLunes reg;
		reg.setEstado(false);
		FILE* p;
		p = fopen(nombre, "rb");
		if (p == NULL) return reg;
		fseek(p, sizeof reg * pos, 0);
		fread(&reg, sizeof reg, 1, p);
		fclose(p);
		return reg;
	}
	int contarRegistros() {
		FILE* p;
		p = fopen(nombre, "rb");
		if (p == NULL) return -1;
		fseek(p, 0, 2);
		int tam = ftell(p);
		fclose(p);
		return tam / sizeof(RecuLunes);
	}
	bool grabarRegistro(RecuLunes reg) {
		FILE* p;
		p = fopen(nombre, "ab");
		if (p == NULL) return false;
		int escribio = fwrite(&reg, sizeof reg, 1, p);
		fclose(p);
		return escribio;
	}

	bool LegajoRepertido(int legajo) {
		RecuLunes reg;
		ArchivoRec arch;
		int cantidad = arch.contarRegistros();

		for (int i = 0; i < cantidad; i++)
		{
			reg = arch.leerRegistro(i);
			if (reg.getLegajo() == legajo) {
				return true;
			}
		}
		return false;
	}

	int BuscarLegajo(int legajo) {
		RecuLunes reg;
		ArchivoRec arch;
		int cantidad = arch.contarRegistros();

		for (int i = 0; i < cantidad; i++)
		{
			reg = arch.leerRegistro(i);
			if (reg.getLegajo() == legajo) {
				return i;
			}
		}
		return -1;
	}

	bool sobreEscribirRegistro(RecuLunes reg, int pos) {
		FILE* p;
		p = fopen(nombre, "rb+");
		if (p == NULL) return false;
		fseek(p, sizeof reg * pos, 0);
		fwrite(&reg, sizeof reg, 1, p);
		fclose(p);
		return true;
	}

};


/*
Hacer un menú con opciones para dar alta de registros y modificar el DNI de un registro.
Al dar el alta se debe validad que no se repita el legajo.

Comentario:
Nombre y apellido tenían que estar en la misma variable.
No realiza la clase Fecha()
Repite la solicitud del legajo.
*/

void altaRegistro() {
	RecuLunes reg;
	ArchivoRec arch;
	int legajo;
	cout << "Ingrese legajo: ";
	cin >> legajo;
	if (arch.LegajoRepertido(legajo)) {
		cout << "Legajo repetido"<<endl;
		return;
	}else{
        cout<<"El legajo valido: "<<endl;
        reg.cargar();
	arch.grabarRegistro(reg);
	}
}



void Modificar() {
	RecuLunes reg;
	ArchivoRec arch;
	int legajo, opcion;
	cout << "Ingrese legajo: ";
	cin >> legajo;

	int pos = arch.BuscarLegajo(legajo);

	if (pos != -1)
	{
		reg = arch.leerRegistro(pos);

		cout << "¿Desea editar el DNI de Ingreso? (1)Si - (2)No: ";
		cin >> opcion;

		if (opcion == 1)
		{
			int dni;
			cout << "Ingrese el nuevo DNI: ";
			cin >> dni;
			reg.setDni(dni);
			bool resultado=arch.sobreEscribirRegistro(reg, pos);

			if(resultado == true){
                cout<<"se modifico correctamente"<<endl;
			}


		}
		else
		{
			cout << "No se ha modificado el DNI\n"<<endl;
		}
	}
	else
	{
		cout << "No se encontro el legajo\n"<<endl;
	}
}

/*Mostrar el archivo del punto 1 utilizando un vector dinámico.
Comentario:
No elimina el vector después de utilizarlo
*/


void mostrarArchivo() {
	RecuLunes reg, *vec;
	ArchivoRec arch;
	int cantidad = arch.contarRegistros();

	if(cantidad < 0){
        cout<<"no hay regitros";
        return;
	}

	vec = new RecuLunes[cantidad];

    if (vec == NULL){
        return;
    }

	for (int i = 0; i < cantidad; i++)
	{
		reg = arch.leerRegistro(i);
		vec[i] = reg;
	}

	for (int i = 0; i < cantidad; i++)
	{
		vec[i].mostrar();
		cout<<endl;
	}

}


int menu() {
	int opc;
	while(true){
    system("cls");
	cout << "1. Alta de registro."<<endl;
	cout << "2. Modificar DNI."<<endl;
	cout << "3. Mostrar Archivo."<<endl;
	cout <<"0. SALIR"<<endl;
	cout << "OPCION: ";
	cin >> opc;
	system("cls");
	switch (opc)
	{
		case 1:
			altaRegistro();
			system("pause");
			break;
		case 2:
			Modificar();
			system("pause");
			break;
        case 3:
            mostrarArchivo();
            system("pause");
            break;
        case 0:
            exit(10);
	default:
		break;
	}
	}
}


//Sobrecargar un operador para la clase que genera el objeto de datos del punto 1.
/*
bool operator==(RecuLunes a, RecuLunes b) {
	if (a.getLegajo()==b.getLegajo())
	{
		return true;
	}
	return false;
}
*/


int main()
{
    setlocale(LC_ALL, "");


    menu();

    cout<<endl;
    system("pause");
    return 0;
}
