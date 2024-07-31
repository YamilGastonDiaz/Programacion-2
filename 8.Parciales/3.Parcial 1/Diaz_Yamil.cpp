#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

#include "parcial1l.h"

class JugadorNivelI{
    private:
        int DNI;
        char nombre[25];
        char apellido[30];
        Fecha inscripcion;
    public:

        void setDNI(int d){DNI=d;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setApellido(const char *a){strcpy(apellido, a);}
        void setInscripcion(Fecha f){inscripcion=f;}

        void Mostrar(){
            cout<<"DNI"<<DNI;
            cout<<"NOMBRE"<<nombre;
            cout<<"APELLIDO"<<apellido;
            cout<<"FECHA INSCRIPCION: ";
            inscripcion.Mostrar();
        }
};

class ArchivoJugadorNivelI{
    private:
        char nombre[30];
    public:
        ArchivoJugadorNivelI(const char *n){strcpy(nombre, n);}

        bool escribir(JugadorNivelI aux){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL)return false;
            bool escribio=fwrite(&aux, sizeof aux, 1, p);
            fclose(p);
            return escribio;
        }

        bool listarArchivo(){
            JugadorNivelI obj;
            FILE *pFile;

            pFile=fopen(nombre, "rb");
            if(pFile==NULL){
                cout<<"No se pudo abrir"<<endl;
                return false;
            }
            while(fread(&obj, sizeof (JugadorNivelI), 1, pFile)){
                obj.Mostrar();
                cout<<endl;
            }
            fclose(pFile);
            return true;
        }
};

void punto1(){
    ArchivoJugadores archivoJ("jugadores.dat");
    Jugador registroJ;
    int cantidadJ=archivoJ.contarRegistros();

    ArchivoEquipos archivoE("equipos.dat");
    Equipo registroE;
    int cantidad=archivoE.contarRegistros();

    ArchivoJugadorNivelI archivoJi("jugadoresNiveli.dat");
    JugadorNivelI registroJni;

    for(int i = 0; i < cantidadJ; i++){
        registroJ=archivoJ.leerRegistro(i);

        for(int j = 0; j < cantidad; j++){
            registroE=archivoE.leerRegistro(j);

            if(registroJ.getIdEquipo()==registroE.getIdEquipo()){

                if(registroE.getNivel()==1){
                    registroJni.setDNI(registroJ.getDNI());
                    registroJni.setNombre(registroJ.getNombre());
                    registroJni.setApellido(registroJ.getApellido());
                    registroJni.setInscripcion(registroJ.getFechaInscirpcion());

                    archivoJi.escribir(registroJni);
                }
            }
        }
    }
    archivoJi.listarArchivo();
}

int main(){
setlocale(LC_ALL, "");

punto1();

cout<<endl;
system("pause");
return 0;
}
