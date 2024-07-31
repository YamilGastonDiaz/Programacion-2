#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

#include "parcial2.h"

class SinCompra{
    private:
        int numeroProveedor;
        char nombre[30];
        int provincia;
    public:
        void setNumeroProveedor(int np){numeroProveedor=np;}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setProvincia(int p){provincia=p;}

        void Mostrar(){
            cout<<"Numero de Proveedor: "<<numeroProveedor<<endl;
            cout<<"Nombre: "<<nombre;
            cout<<"Provincia: "<<provincia;
        }
};

class ArchivoSinCompra {
    private:
        char nombreArchivo[30];
    public:
        ArchivoSinCompra(const char *na){strcpy(nombreArchivo, na);}

        bool grabar(SinCompra aux){
            FILE *p;
            p=fopen(nombreArchivo, "ab");
            if(p==NULL)return false;
            bool escribio=fwrite(&aux, sizeof aux, 1, p);
            fclose(p);
            return escribio;
        }

        bool listarArchivo(){
            SinCompra obj;
            FILE *pFile;

            pFile=fopen(nombreArchivo, "rb");
            if(pFile==NULL){
                cout<<"No se pudo abrir"<<endl;
                return false;
            }
            while(fread(&obj, sizeof (SinCompra), 1, pFile)){
                obj.Mostrar();
                cout<<endl;
            }
            fclose(pFile);
            return true;
        }
};

bool contarComprasProveedor(int np, int anio){
    Compra reg;
    ArchivoCompras arcC("compras.dat");

    //cuento registro
    int cantReg=arcC.contarRegistros();

    //recorro
    for (int i=0; i<cantReg; i++)
    {
        //leemos un registro de compras
        reg=arcC.leerRegistro(i);

        //pregunto
        if(reg.getNumeroproveedor()==np && reg.getFechaCompra().getAnio()== anio){
            return true;
        }

    }
    return false;
}

void PuntoA(){
    Proveedor objP;
    ArchivoProveedores archivoP("proveedores.dat");
    int cantidadP=archivoP.contarRegistros();

    SinCompra objS;
    ArchivoSinCompra archivoS("sincompras.dat");

    bool tuvoCompras;

    for(int i = 0; i < cantidadP; i++){
        objP=archivoP.leerRegistro(i);
            if(tuvoCompras == false){
                objS.setNumeroProveedor(objP.getNumeroProveedor());
                objS.setNombre(objP.getNombre());
                objS.setProvincia(objP.getProvincia());

                archivoS.grabar(objS);
            }
    }

}

void puntoB(){
    Material objM;
    ArchivoMateriales archivoM("materiales.dat");
    int cantidad=archivoM.contarRegistros();

    int vTipo[6]={};

    for(int i = 0; i < cantidad; i++){
        objM=archivoM.leerRegistro(i);
        vTipo[objM.getTipo()-1]++;
    }

    int menor=vTipo[0];
    bool bandera=false;

    for(int i = 1; i < 6; i++){
        if(vTipo[i]>0){
            if(!bandera){
                menor=vTipo[i];
                bandera=true;
            }else{
                if(vTipo[i]<menor){
                    menor=vTipo[i];
                }
            }
        }
    }

    for(int i = 0; i < 6; i++){
        if(vTipo[i]==menor){
            cout<<i+1<<endl;
        }
    }
}

void PuntoC(){
    Material obj;
    ArchivoMateriales archivoM("materiales.dat");
    int cantM=archivoM.contarRegistros();

    Material *vec;
    vec=new Material[cantM];
    if(vec == NULL){
        return;
    }

    for(int i = 0; i < cantM; i++){
        obj=archivoM.leerRegistro(i);

        vec[i]=obj;
    }

    int tipo;
    cout<<"Ingrese tipo de material: ";
    cin>>tipo;


    for(int i = 0; i < cantM; i++){
        if(vec[i].getTipo()==tipo){
            vec[i].Mostrar();
        }
    }

    delete vec;
}


int main(){
setlocale(LC_ALL, "");





cout<<endl;
system("pause");
return 0;
}
