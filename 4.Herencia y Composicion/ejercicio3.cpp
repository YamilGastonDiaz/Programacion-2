#include <iostream>
#include <locale>
#include  <cstring>

using namespace std;

void cargarCadena(char *pal, int tam);
//CLASE DENOMINACION
class Denominacion{
    private:
        char nCientifico[20];
        char nComun[20];
        char nPuebloOrig[20];
    public:
        Denominacion();

        void setNcientifico(const char *nc){strcpy(nCientifico, nc);}
        void setNcomun(const char *ncm){strcpy(nComun, ncm);}
        void setNpuebloOrig(const char *npo){strcpy(nPuebloOrig, npo);}

        const char *getNcientifico(){return nCientifico;}
        const char *getNcomun(){return nComun;}
        const char *getNpuebloOrig(){return nPuebloOrig;}

        void Cargar();
        void Mostrar();
};

Denominacion::Denominacion(){
    strcpy(nCientifico, "S/Nc");
    strcpy(nComun, "S/Ncm");
    strcpy(nPuebloOrig, "S/Npo");
}

void Denominacion::Cargar(){
    cout<<"nombre cientifico: ";
    cargarCadena(nCientifico, 19);
    cout<<"nombre comun: ";
    cargarCadena(nComun, 19);
    cout<<"nombre dado por pueblos originarios: ";
    cargarCadena(nPuebloOrig, 19);
}

void Denominacion::Mostrar(){
    cout<<"nombre cientifico: "<<nCientifico<<endl;
    cout<<"nombre comun: "<<nComun<<endl;
    cout<<"nombre dado por pueblos originarios: "<<nPuebloOrig<<endl;
}
//CLASE DIMENSION
class Dimension{
    private:
        float largo, ancho, alto;
    public:
        Dimension();

        void setLargo(float lgo){largo=lgo;}
        void setAncho(float anc){ancho=anc;}
        void setAlto(float alt){alto=alt;}

        float getLargo(){return largo;}
        float getAncho(){return ancho;}
        float getAlto(){return alto;}

        void Cargar();
        void Mostrar();
};
Dimension::Dimension(){
    largo=0;
    ancho=0;
    alto=0;
}

void Dimension::Cargar(){
    cout<<"largo: ";
    cin>>largo;
    cout<<"ancho: ";
    cin>>ancho;
    cout<<"alto: ";
    cin>>alto;
}

void Dimension::Mostrar(){
    cout<<"largo: "<<largo<<endl;
    cout<<"ancho: "<<ancho<<endl;
    cout<<"alto: "<<alto<<endl;
}
//CLASE CLASEFICACION
class Especie{
    private:
        char tipoEspecie[15];
    public:
        Especie(){strcpy(tipoEspecie, "S/E");}

        void *setTipoEspecie(const char *te){strcpy(tipoEspecie, te);}

        const char *getTipoEspecie(){return tipoEspecie;}

        void Cargar();
        void Mostrar();
};
void Especie::Cargar(){
    cout<<"Clase de especie: ";
    cargarCadena(tipoEspecie, 14);
}
void Especie::Mostrar(){
    cout<<"Clase de especie: "<<tipoEspecie<<endl;
}

//CLASE ANIMAL BASE
class Animal{
    private:
        Denominacion especie;
        int tiempoVida;
        Dimension tamanio;
        float peso;
        char habitat[25];
        char alimentacion[20];
        int poblacionE;
    public:
        Animal();

        void setEspecie(Denominacion de){especie=de;}
        void setTiempoVida(int tv){tiempoVida=tv;}
        void setTamanio(Dimension dt){tamanio=dt;}
        void setPeso(float p){peso=p;}
        void *setHabitat(const char *h){strcpy(habitat, h);}
        void *setAlimentacion(const char *alm){strcpy(alimentacion, alm);}
        void setPoblacion(int pe){poblacionE=pe;}

        Denominacion getEspecie(){return especie;}
        int getTiempoVida(){return tiempoVida;}
        Dimension getTamanio(){return tamanio;}
        float getPeso(){return peso;}
        const char *getHabitat(){return habitat;}
        const char *getAlimentacion(){return alimentacion;}
        int getPoblacion(){return poblacionE;}

        void Cargar();
        void Mostrar();
};

Animal::Animal(){
    especie=Denominacion();
    tiempoVida=0;
    tamanio=Dimension();
    peso=0.0f;
    strcpy(habitat, "S/H");
    strcpy(alimentacion, "S/A");
    poblacionE=0;
}

void Animal::Cargar(){
    cout<<"Denominacion Especie: "<<endl;
    especie.Cargar();
    cout<<"Tiempo de Vida: "<<endl;
    cin>>tiempoVida;
    cout<<"Dimencion: "<<endl;
    tamanio.Cargar();
    cout<<"Peso: "<<endl;
    cin>>peso;
    cout<<"Habitat: "<<endl;
    cargarCadena(habitat, 24);
    cout<<"Alimentacion: "<<endl;
    cargarCadena(alimentacion, 19);
    cout<<"Poblacion Estimada: "<<endl;
    cin>>poblacionE;
}

void Animal::Mostrar(){
    cout<<"Denominacion Especie: "<<endl;
    especie.Mostrar();
    cout<<"Tiempo de Vida: "<<tiempoVida<<endl;
    cout<<"Dimencion: "<<endl;
    tamanio.Mostrar();
    cout<<"Peso: "<<peso<<endl;
    cout<<"Habitat: "<<habitat<<endl;
    cout<<"Alimentacion: "<<alimentacion<<endl;
    cout<<"Poblacion Estimada: "<<poblacionE<<endl;
}
//CLASES DERIVADAS DE ANIMAL
//CLASE PEZ
class Pez:public Animal{
    private:
        Especie clasePez;
    public:
        Pez(){clasePez=Especie();}

        void setClasePez(Especie cp){clasePez=cp;}

        Especie getClasePez(){return clasePez;}

        void Cargar();
        void Mostrar();
};
void Pez::Cargar(){
    Animal::Cargar();
    cout<<"Clasificacion: "<<endl;
    clasePez.Cargar();
    cout<<endl;
}

void Pez::Mostrar(){
    Animal::Mostrar();
    cout<<"Clasificacion: "<<endl;
    clasePez.Mostrar();
}
//CLASE ANFIBIO
class Anfibio:public Animal{
    private:
        Especie claseAnfibio;
    public:
        Anfibio(){claseAnfibio=Especie();}

        void setClaseAnfibio(Especie ca){claseAnfibio=ca;}

        Especie getClasificacionAnfibio(){return claseAnfibio;}

        void Cargar();
        void Mostrar();
};
void Anfibio::Cargar(){
    Animal::Cargar();
    cout<<"Clasificacion: "<<endl;
    claseAnfibio.Cargar();
}
void Anfibio::Mostrar(){
    Animal::Mostrar();
    cout<<"Clasificacion: "<<endl;
    claseAnfibio.Mostrar();
}
//CLASE REPTIL
class Reptil:public Animal{
    private:
        Especie claseReptil;
    public:
        Reptil(){claseReptil=Especie();}

        void setClaseReptil(Especie rpt){claseReptil=rpt;}

        Especie getClaseReptil(){return claseReptil;}

        void Cargar();
        void Mostrar();
};
void Reptil::Cargar(){
    Animal::Cargar();
    cout<<"Clasificacion: "<<endl;
    claseReptil.Cargar();
}
void Reptil::Mostrar(){
    Animal::Mostrar();
    cout<<"Clasificacion: "<<endl;
    claseReptil.Mostrar();
}
//CLASE AVE
class Ave:public Animal{
    private:
        Especie claseAve;
    public:
        Ave(){claseAve=Especie();}

        void setClaseAve(Especie cave){claseAve=cave;}

        Especie getClaseAve(){return claseAve;}

        void Cargar();
        void Mostrar();
};
void Ave::Cargar(){
    Animal::Cargar();
    cout<<"Clasificacion: "<<endl;
    claseAve.Cargar();
}
void Ave::Mostrar(){
    Animal::Mostrar();
    cout<<"Clasificacion: "<<endl;
    claseAve.Mostrar();
}
//CLASE MAMIFERO
class Mamifero:public Animal{
    private:
        Especie claseMamifero;
    public:
        Mamifero(){claseMamifero=Especie();}

        void setClaseMamifero(Especie cmm){claseMamifero=cmm;}

        Especie getClaseMamifero(){return claseMamifero;}

        void Cargar();
        void Mostrar();
};
void Mamifero::Cargar(){
    Animal::Cargar();
    cout<<"Clasificacion: "<<endl;
    claseMamifero.Cargar();
}
void Mamifero::Mostrar(){
    Animal::Mostrar();
    cout<<"Clasificacion: "<<endl;
    claseMamifero.Mostrar();
}
//CLASE DERIVADAS DE MAMIFERO
//CLASE MARINO
class Marino:public Mamifero{
    private:

    public:

};
//CLASE TERRESTRE
class Terrestre:public Mamifero{
    private:

    public:

};


int main(){
setlocale(LC_ALL, "");

Mamifero obj;
obj.Mostrar();


cout<<endl;
system("pause");
return 0;
}

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
