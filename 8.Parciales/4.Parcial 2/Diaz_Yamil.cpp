#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

void cargarCadena(char* pal, int tam) {
	int i;
	fflush(stdin);
	for (i = 0; i < tam; i++)
	{
		pal[i] = cin.get();
		if (pal[i] == '\n') break;
	}
	pal[i] = '\0';
	fflush(stdin);
}

class Paises {
    private:
        char codigoPais[5];
        char nombre[30];
        int continente;
        int nivelIngreso;
        int cantHabitantes;
        float pbi;
        bool estado;

	public:
		const char* getCodigoPais() { return nombre; }
		const char* getNombre() { return nombre; }
		int getContinente() { return continente; }
		float getPbi() { return pbi; }
		bool getEstado() { return estado; }

		void setCodigoPais(const char* c) { strcpy(codigoPais, c); }
		void setNombre(const char* n) { strcpy(nombre, n); }
		void setContinente(int c) { continente = c; }
		void setPbi(float p) { pbi = p; }
		void setEstado(bool e) { estado = e; }

		void Cargar() {
			cout << "Codigo: ";
			cargarCadena(codigoPais, 5);
			cout << "Nombre: ";
			cargarCadena(nombre, 30);
			cout << "Continente: ";
			cin >> continente;
			cout << "PBI: ";
			cin >> pbi;
			estado = true;
		}

		void Mostrar() {
			cout << "Codigo: " << codigoPais << endl;
			cout << "Nombre: " << nombre << endl;
			cout << "Continente: " << continente << endl;
			cout << "PBI: " << pbi << endl;
		}
};

class ArchivoPaises {
    private:
		char nombreArchivo[30];
	public:
		ArchivoPaises(const char* n) { strcpy(nombreArchivo, n); }

		Paises leerRegistro(int pos) {
			Paises reg;
			FILE* p;
			p = fopen(nombreArchivo, "rb");
			if (p == NULL) {
				return reg;
			}
			fseek(p, pos * sizeof(Paises), 0);
			fread(&reg, sizeof(Paises), 1, p);
			fclose(p);
			return reg;
		}

		int contarRegistros() {
			FILE* p;
			p = fopen(nombreArchivo, "rb");
			if (p == NULL) {
				return -1;
			}
			fseek(p, 0, 2);
			int tam = ftell(p);
			fclose(p);
			return tam / sizeof(Paises);
		}

		bool grabarRegistro(Paises reg) {
			FILE* p;
			p = fopen(nombreArchivo, "ab");
			if (p == NULL) {
				return false;
			}
			bool escribio = fwrite(&reg, sizeof(Paises), 1, p);
			fclose(p);
			return escribio;
		}

};


class Continente {
    private:
        int continente;
        char nombre[30];

    public:
		int getContinente() { return continente; }
		const char* getNombre() { return nombre; }

		void setContinente(int c) { continente = c; }
		void setNombre(const char* n) { strcpy(nombre, n); }

		void Cargar() {
			cout << "Codigo: ";
			cin >> continente;
			cout << "Nombre: ";
			cargarCadena(nombre, 30);
		}

		void Mostrar() {
			cout << "Codigo: " << continente << endl;
			cout << "Nombre: " << nombre << endl;
		}
};

class ArchivoContinente {
	private:
        char nombreArchivo[30];
	public:
		ArchivoContinente(const char* n) { strcpy(nombreArchivo, n); }

		Continente leerRegistro(int pos) {
			Continente reg;
			FILE* p;
			p = fopen(nombreArchivo, "rb");
			if (p == NULL) {
				return reg;
			}
			fseek(p, pos * sizeof(Continente), 0);
			fread(&reg, sizeof(Continente), 1, p);
			fclose(p);
			return reg;
		}

		int contarRegistros() {
			FILE* p;
			p = fopen(nombreArchivo, "rb");
			if (p == NULL) {
				return -1;
			}
			fseek(p, 0, 2);
			int tam = ftell(p);
			fclose(p);
			return tam / sizeof(Continente);
		}

		bool grabarRegistro(Continente reg) {
			FILE* p;
			p = fopen(nombreArchivo, "ab");
			if (p == NULL) {
				return false;
			}
			bool escribio = fwrite(&reg, sizeof(Continente), 1, p);
			fclose(p);
			return escribio;
		}
};


/*
Calcular e informar la cantidad de países por cada continente.
*/

void PuntoA() {
	ArchivoPaises ap("paises.dat");
	Paises regP;

	int cantPaises=ap.contarRegistros();


	int vContinente[5] = {};

	for (int i = 0; i < cantPaises; i++) {
		regP=ap.leerRegistro(i);
		vContinente[regP.getContinente()-1]++;
	}

	for (int i = 0; i < 5; i++)
	{
	    if(vContinente[i]>0){
            cout << "Continente " << i + 1 << ": " << vContinente[i] << endl;
	    }
	}

}

/*
Generar un archivo con los continentes cuyos países integrados a la OCDE tengan un PBI total menor a 100.000.000.
El formato debe ser el mismo que el del archivo de continentes
*/

void PuntoB() {
	ArchivoContinente ac("continentes.dat");
	ArchivoPaises	ap("paises.dat");
	ArchivoContinente acNuevo("continentesNuevo.dat");

	Continente regC;
	Paises regP;
	Continente regCNuevo;

	int cantContinentes = ac.contarRegistros();
	int cantPaises = ap.contarRegistros();

	for (int i = 0; i < cantContinentes; i++) {
		regC = ac.leerRegistro(i);
		float pbiTotal = 0;
		for (int j = 0; j < cantPaises; j++) {
			regP = ap.leerRegistro(j);
			if (regC.getContinente()==regP.getContinente()) {
				pbiTotal += regP.getPbi();
			}
		}
		if (pbiTotal < 100000000) {
			acNuevo.grabarRegistro(regCNuevo);
		}
	}
}


/*
Listar el archivo nuevo creado usando asignación dinámica de memoria
*/

void PuntoC() {
	ArchivoContinente acNuevo("continentesNuevo.dat");
	Continente *regCNuevo;
	int cantContinentes = acNuevo.contarRegistros();

	if(cantContinentes < 0){
        cout<<"no hay regitros";
        return;
	}


	regCNuevo = new Continente[cantContinentes];
	if (regCNuevo==NULL)
	{
		return;
	}

	for (int i = 0; i < cantContinentes; i++) {
		regCNuevo[i] = acNuevo.leerRegistro(i);
	}

	for (int i = 0; i < cantContinentes; i++)
	{
		regCNuevo[i].Mostrar();
	}
	delete [] regCNuevo;

}

/*
Sobrecargar un operador para alguna de las clases de los ejercicios anteriores,
que sea de utilidad para la resolución de alguno de esos puntos.
*/

int main()
{
    PuntoA();
    PuntoB();
    PuntoC();

	return 0;
}
