#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

#include "parcialm1.h"


class EnEjecucion{
private:
    char codigoObra[5];
    char direccion[30];
    int provincia;
public:
    void setCodigoObra(const char *co){strcpy(codigoObra,co);}
    void setDireccion(const char *d){strcpy(direccion,d);}
    void setProvincia(int p){provincia=p;}

    void Mostrar(){
        cout<<"Codigo de Obra: "<<codigoObra<<endl;
        cout<<"Direccion: "<<direccion<<endl;
        cout<<"Provincia: "<<provincia<<endl;
    }
};

class ArchivoEnEjecucion{
    private:
        char nombre[30];
    public:
        ArchivoEnEjecucion(const char *n){strcpy(nombre, n);}

        bool grabarEnEjecucion(EnEjecucion aux){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL)return false;
            bool escribio=fwrite(&aux, sizeof aux, 1, p);
            fclose(p);
            return escribio;
        }

        bool listarArchivo(){
            EnEjecucion obj;
            FILE *pFile;

            pFile=fopen(nombre, "rb");
            if(pFile==NULL){
                cout<<"No se pudo abrir"<<endl;
                return false;
            }
            while(fread(&obj, sizeof (EnEjecucion), 1, pFile)){
                obj.Mostrar();
                cout<<endl;
            }
            fclose(pFile);
            return true;
        }
};

///EJERCICIOS DE PREGUNTA CON MULTIPLE CHOIS
//Generar un archivo con el codigo de obra, la direccion y la provincia de las obras cuyo estado de ejecuccion sea en "ejecucion"

void punto1(){
    Obra regO;
    ArchivoObras archivoO("obras.dat");
    int cantidadRo=archivoO.contarRegistros();

    ArchivoEnEjecucion archivoE("obrasEjecucion.dat");
    EnEjecucion regEjecucion;

    for(int i = 0; i < cantidadRo; i++){
        regO=archivoO.leerRegistro(i);

        if(regO.getEstadoEjecucion()==3){
            regEjecucion.setCodigoObra(regO.getCodigoObra());
            regEjecucion.setDireccion(regO.getDireccion());
            regEjecucion.setProvincia(regO.getProvincia());

            archivoE.grabarEnEjecucion(regEjecucion);
        }
    }
    archivoE.listarArchivo();
}

void punto2(){
    ArchivoProveedores archivoP("proveedores.dat");
    Proveedor regP;
    int cantidadRp=archivoP.contarRegistros();

    int vProvincia[24]={};

    for(int i = 0; i < cantidadRp; i++){
        regP=archivoP.leerRegistro(i);
        vProvincia[regP.getProvincia()-1]++;
    }

    int menor=vProvincia[0];
    bool bandera=false;

    for(int i = 1; i < 24; i++){
        if(vProvincia[i]>0){
            if(!bandera){
                menor=vProvincia[i];
                bandera=true;
            }else{
                if(vProvincia[i]<menor){
                    menor=vProvincia[i];
                }
            }
        }
    }

    for(int i = 0; i < 24; i++){
        if(vProvincia[i]==menor){
            cout<<i+1<<endl;
        }
    }
}

///EJERCICIOS DEL PARCIAL
void puntoA1(){
    ArchivoMateriales archivoM("materiales.dat");
    Material regM;
    int cantidadRm=archivoM.contarRegistros();


    ArchivoCompras archivoC("compras.dat");
    Compra regC;
    int cantidadRc=archivoC.contarRegistros();

    int cantTotal;

    for(int i = 0; i < cantidadRm; i++){
        regM=archivoM.leerRegistro(i);

        cantTotal=0;
        for(int j = 0; j < cantidadRc; j++){
            regC=archivoC.leerRegistro(j);

            if(regM.getCodigoMaterial()==regC.getCodigoMaterial()){
                cantTotal++;
            }
        }
        cout<<"codigo material #"<<regM.getCodigoMaterial()<<" cantidad de compras: "<<cantTotal<<endl;
    }
}

void puntoA2(){

    ArchivoProveedores archivoP("proveedores.dat");
    Proveedor regP;


    ArchivoCompras archivoC("compras.dat");
    Compra regC;
    int cantidadRc=archivoC.contarRegistros();

    float vProveedor[60]={};

    for(int i = 0; i < cantidadRc; i++){
        regC=archivoC.leerRegistro(i);
        vProveedor[regC.getNumeroproveedor()-1]+=regC.getImporte();
    }


    int mayor = vProveedor[0];
    int posM = 0;

    for(int i = 1; i < 60; i++){

        if(vProveedor[i] > mayor){
            mayor=vProveedor[i];
            posM=i;
        }
    }

    regP=archivoP.leerRegistro(posM+1);
    cout<<regP.getNombre();

}

void puntoA3(){

    ArchivoCompras archivoC("compras.dat");
    Compra regC;
    int cantidadRc=archivoC.contarRegistros();

    bool vProveedor[60]={};

    for(int i = 0; i < cantidadRc; i++){
        regC=archivoC.leerRegistro(i);

        if(regC.getFechaCompra().getAnio()==2022){
            vProveedor[regC.getNumeroproveedor()-1]=true;
        }
    }

    cout<<"proveedores a los que no se les compró nada el año pasado"<<endl;
    for(int i = 0; i < 60; i++){

        if(!vProveedor[i]){
            cout<<i+1<<endl;
        }
    }
}

void puntoA4(){
    ArchivoObras archivoO("obras.dat");
    Obra regO;
    int cantidadO=archivoO.contarRegistros();

    ArchivoCompras archivoC("compras.dat");
    Compra regC;
    int cantidadC=archivoC.contarRegistros();

    ArchivoMateriales archivoM("materiales.dat");
    Material regM;
    int cantidadM=archivoM.contarRegistros();

    float gasto;
    for(int i = 0; i < cantidadO; i++){
        regO=archivoO.leerRegistro(i);

        gasto = 0;

        for(int j = 0; j < cantidadC; j++){
            regC=archivoC.leerRegistro(j);

            for(int x = 0; x < cantidadM; x++){
                regM=archivoM.leerRegistro(x);

                if(strcmp(regO.getCodigoObra(), regC.getCodigoObra())==0 && regM.getCodigoMaterial()==regC.getCodigoMaterial()){
                    if(regM.getTipo()==1){
                        gasto+=regC.getImporte();
                    }
                }
            }
        }
    cout<<regO.getCodigoObra()<<": "<< gasto<<endl;
    }
}

void puntoA5(){
    ArchivoProveedores archivoP("proveedores.dat");
    Proveedor regP;
    int cantidadRp=archivoP.contarRegistros();

    int vProvincia[24]={};

    for(int i = 0; i < cantidadRp; i++){
        regP=archivoP.leerRegistro(i);
        vProvincia[regP.getProvincia()-1]++;
    }

    for(int i = 0; i < 24; i++){
        if(vProvincia[i]>22){
            cout<<"Provincia: "<<i+1<<endl;
        }
    }
}

bool cambioA6(Compra regC, int pos){
    FILE *pFile;
    bool resultado;

    pFile=fopen("compras.dat", "rb+");
    if(pFile==NULL){
        return false;
    }

    fseek(pFile, sizeof(Compra)*pos, SEEK_SET);
    resultado=fwrite(&regC, sizeof(Compra), 1, pFile);
    fclose(pFile);
    return resultado;
}

void puntoA6(){
    ArchivoCompras archivoC("compras.dat");
    Compra regC;
    int cantidadRc=archivoC.contarRegistros();

    for(int i = 0; i < cantidadRc; i++){
       regC=archivoC.leerRegistro(i);

       if(regC.getFechaCompra().getAnio()==2020){
            regC.setActivo(false);
            cambioA6(regC, i);
       }

    }
}

void puntoA7(){
    ArchivoMateriales archivoM("materiales.dat");
    Material regM;
    int cantidadRm=archivoM.contarRegistros();

    float precioNuevo;

    for(int i = 0; i < cantidadRm; i++){
        regM=archivoM.leerRegistro(i);

        if(regM.getTipo()==3){
            precioNuevo=regM.getPU()*1.1;
            regM.setPU(precioNuevo);
        }
    }
}




int main(){
setlocale(LC_ALL, "");


punto1();


cout<<endl;
system("pause");
return 0;
}
