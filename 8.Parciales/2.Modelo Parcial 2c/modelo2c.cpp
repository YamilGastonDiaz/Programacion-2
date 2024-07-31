#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

#include "parcial1l.h"

/// PUNTO 1

///Generar un archivo con los equipos que tengan al menos 10 jugadores inscriptos.
///Cada registro debe tener el ID de equipo, el nombre del equipo, y la categoría del deporte
///al que pertenece el equipo.

class Equipos10{
    private:
        int IDequipo, IDcategoria;
        char nombre[30];
        bool estado;
    public:
        void setEquipo(int e){IDequipo=e;}
        void setNombre(const char *nom){strcpy(nombre, nom);}
        void setCategoria(int cat){IDcategoria=cat;}
        void setEstado(bool e){estado=e;}
    void Mostrar(){
        cout<<"EQUIPO "<<IDequipo<<endl;
        cout<<"NOMBRE "<<nombre<<endl;
        cout<<"CATEGORIA "<<IDcategoria<<endl;
    }
};
class ArchivoEquipos10{
    private:
        char nombre[30];
    public:
        ArchivoEquipos10(const char *n){
            strcpy(nombre, n);
        }

        Equipos10 leerRegistro(int pos){
            Equipos10 reg;
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
            return tam/sizeof(Equipos10);
        }

        bool grabarRegistro(Equipos10 reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
};

int contarJugadores(int equipo){
    ArchivoJugadores archiJ("jugadores.dat");
    Jugador reg;
    int cantReg, cantJug=0;
    cantReg=archiJ.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiJ.leerRegistro(i);
        if(reg.getIdEquipo()==equipo) cantJug++;
    }
    return cantJug;
}

int buscarDeporte(int equipo){
    ArchivoJugadores archiJ("jugadores.dat");
    Jugador reg;
    int cantReg;
    cantReg=archiJ.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiJ.leerRegistro(i);
        if(reg.getIdEquipo()==equipo) return reg.getIdDeporte();
    }
    return -1;
}

int buscarCategoria(int deporte){
    ArchivoDeportes archiD("deportes.dat");
    Deporte reg;
    int cantReg;
    cantReg=archiD.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archiD.leerRegistro(i);
        if(reg.getIdDeporte()==deporte) return reg.getIdCtegoria();
    }
    return -1;
}

void puntoA1(){
    Equipos10 aux;
    ArchivoEquipos10 archiE10("equipos10.dat");

    Equipo reg;
    ArchivoEquipos archiE("equipos.dat");
    int cantReg, cantJug, categoria, deporte;
    cantReg=archiE.contarRegistros();

    for(int i=0;i<cantReg;i++){
        reg=archiE.leerRegistro(i);
        cantJug=contarJugadores(reg.getIdEquipo());

        if(cantJug>=10){
            deporte=buscarDeporte(reg.getIdEquipo());
            categoria=buscarCategoria(deporte);
            aux.setEquipo(reg.getIdEquipo());
            aux.setNombre(reg.getNombre());
            aux.setCategoria(categoria);
            archiE10.grabarRegistro(aux);
        }
    }
}

///Hacer un vector dinámico para listar el archivo del punto anterior.

void puntoB1(){
    Equipos10 *v;
    ArchivoEquipos10 archiE10("equipos10.dat");
    int cantReg;
    cantReg=archiE10.contarRegistros();

    if(cantReg==0){
        cout<<"NO HAY REGISTROS EN EL ARCHIVO"<<endl;
        return;
    }

    v=new Equipos10[cantReg];
    if(v==NULL) return;

    for(int i=0;i<cantReg;i++){
        v[i]=archiE10.leerRegistro(i);
    }

    for(int i=0;i<cantReg;i++){
        v[i].Mostrar();
    }
    delete  []v;
}

///Sobrecargar el operador == para comparar un objeto Jugador con un objeto Deporte.
/// Debe devolver verdadero cuando coinciden los Id de deporte.

///en la clase Jugador iría el código.

/*
bool operator==(const Deporte &obj){
if(idDeporte==obj.getIDdeporte()) return true;
return false;
}
*/
///PUNTO 2

///Hacer un archivo con los deportes que tengan jugadores de todos los claustros. Los
///registros del archivo nuevo deben tener el mismo formato que el archivo de deportes.

void puntoA2(){
    Deporte objD, objN;
    ArchivoDeportes archivoD("deportes.dat");
    ArchivoDeportes archivoNuevo("deporteNuevo.dat");

    int cantD=archivoD.contarRegistros();

    Jugador objJ;
    ArchivoJugadores archivoJ("Jugadores.dat");
    int cant=archivoJ.contarRegistros();

    bool vClaustro[4]={};

    for(int i = 0; i < cantD; i++){
        objD=archivoD.leerRegistro(i);

        for(int j = 0; j < cant; j++){
            if(objD.getIdDeporte()==objJ.getIdDeporte()){
                vClaustro[objJ.getClaustro()-1]=true;
            }
        }
        if(vClaustro[0] && vClaustro[1] && vClaustro[2] && vClaustro[3]){
            archivoNuevo.grabarRegistro(objN);
        }
    }
}

///Crear un vector dinámico con los equipos de nivel inicial. Listar el vector.

void PuntoB2(){
    Equipo *vec, obj;
    ArchivoEquipos archivoE("equipos.dat");
    int cantidad=archivoE.contarRegistros();

    int cont=0, pos=0;

    for(int i = 0; i < cantidad; i++){
        obj=archivoE.leerRegistro(i);
        if(obj.getNivel()==1){
            cont++;
        }
    }


    if(cont > 0){
        vec=new Equipo[cont];
        if(vec == NULL){
            return;
        }

        for(int i = 0; i < cantidad; i++){
        obj=archivoE.leerRegistro(i);
            if(obj.getNivel()==1){
                vec[pos]=obj;
                pos++;
            }
        }

        for(int i = 0; i < pos; i++){
            vec[i].Mostrar();
        }
    }

    delete []vec;
}

///PUNTO 3

///Generar un archivo con los jugadores que hayan pagado más de $10000 de matrícula y
///que se hayan inscripto este año. Cada registro del archivo debe tener el siguiente formato:
///DNI, nombre, apellido, claustro y nombre del deporte.

class JugadorN{
    public:
        void setDni(int d) { dni = d; }
        void setNombre(const char* n) { strcpy(nombre, n); }
        void setApellido(const char* a) { strcpy(apellido, a); }
        void setClaustro(int c) { claustro = c; }
        void setNombreDeporte(const char* nd) { strcpy(nombreDeporte, nd); }

        void Mostrar() {
            cout << dni << endl;
            cout << nombre << endl;
            cout << apellido << endl;
            cout << claustro << endl;
            cout << nombreDeporte << endl;
        }

    private:
        int dni;
        char nombre[30];
        char apellido[30];
        int claustro;
        char nombreDeporte[30];
};

class ArchivoJugadoresN{
private:
	char nombre[30];
public:
	ArchivoJugadoresN(const char* n) {
		strcpy(nombre, n);
	}

	bool grabarRegistro(JugadorN reg) {
		FILE* p;
		p = fopen(nombre, "ab");
		if (p == NULL) return false;
		bool escribio=fwrite(&reg, sizeof reg, 1, p);
		fclose(p);
		return escribio;
	}

	bool listarArchivo() {
		JugadorN reg;
		FILE* p;
		p = fopen(nombre, "rb");
		if (p == NULL) return false;
		while (fread(&reg, sizeof (JugadorN), 1, p))
		{
			reg.Mostrar();
		}
		fclose(p);
		return true;
	}
};



void Punto3A(){

    ArchivoJugadores aj("jugadores.dat");
    ArchivoJugadoresN ajn("jugadoresN.dat");
    Jugador reg;
    JugadorN regN;
    int cant = aj.contarRegistros();

    for (int i = 0; i < cant; i++){
        reg = aj.leerRegistro(i);
        if (reg.getMatricula() > 10000 && reg.getFechaInscirpcion().getAnio() == 2024){

            regN.setDni(reg.getDNI());
            regN.setNombre(reg.getNombre());
            regN.setApellido(reg.getApellido());
            regN.setClaustro(reg.getClaustro());
            regN.setNombreDeporte(reg.getNombre());
            ajn.grabarRegistro(regN);
        }
    }
}

///Crear un vector con los jugadores pertenecientes a un equipo cuyo número de equipo se
///ingresa por teclado. Listar el vector

void Punto3B(){
Jugador *vec, reg;
ArchivoJugadores archivoJ("jugadores.dat");

    //cuento registro
    int cantReg=archivoJ.contarRegistros();

    int cont=0, numEquipo, pos=0;
    //primero pido el ingreso del tipo de los materiales que se desea contar
    cout << "Ingrese el tipo para listar: ";
    cin >> numEquipo;

    for (int i=0; i<cantReg; i++){
        //leemos un registro de compras
        reg=archivoJ.leerRegistro(i);
        //en la posicion i me copio el registro
        if(reg.getIdEquipo()==numEquipo){
            cont++;
        }
    }

    //chequeo y luego pido memoria para hacer el vector
    if(cont>0){
        //generamos el vector dinamico
        vec= new Jugador[cont];
        if(vec==NULL) {
            return;
        }
        //ya validado hacemos nuevamente la lectura
        for (int i=0; i<cantReg; i++){
        //leemos un registro de compras
        reg=archivoJ.leerRegistro(i);
        //en la posicion i me copio el registro
            if(reg.getIdEquipo()==numEquipo){
                vec[pos]=reg;
                pos++;
            }
        }

        for(int i=0; i<pos; i++){
            vec[i].Mostrar();
        }
    }

    delete []vec;
}


int main(){
setlocale(LC_ALL, "");


puntoA2();


cout<<endl;
system("pause");
return 0;
}
