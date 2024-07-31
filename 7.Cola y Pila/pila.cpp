///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

class Pila{
private:
     int *pInfo;
     int tam, tope;

public:
    Pila(int cant){
        tam=cant;
        pInfo=new int[cant];
        if(pInfo==NULL)exit(1);
        tope=0;
    }
    ~Pila(){
        delete []pInfo;
    }
    bool Agregar(int info){
        if(tope==tam){///la Pila está llena
            return false;
        }
        pInfo[tope++]=info;
        return true;
    }

    bool Sacar(int &valorQueSale){
        if(tope==0){///la Pila está vacía
            return false;
        }
        valorQueSale=pInfo[--tope];
        ///--tope;
        ///valorQueSale=pInfo[tope];
        return true;
    }
};


int main(){
    Pila lifo(5);
    int ingreso, salida;
    for(int i=1;i<=5;i++){
            cout<<"INGRESE UN VALOR PARA LA PILA ";
            cin>>ingreso;
            lifo.Agregar(ingreso);
    }
    cout<<"INGRESE UN VALOR PARA LA PILA ";
    cin>>ingreso;
    if(!lifo.Agregar(ingreso)){
            cout<<"VALOR NO ACEPTADO. PILA LLENA"<<endl;
    }
    while(lifo.Sacar(salida)){
        cout<<salida<<endl;
    }
	cout<<endl;
    ///
    cout<<"INGRESE UN VALOR PARA LA PILA ";
	cin>>ingreso;
    if(!lifo.Agregar(ingreso)){
            cout<<"VALOR NO ACEPTADO. PILA LLENA"<<endl;
    }
    cout<<"INGRESE UN VALOR PARA LA PILA ";
	cin>>ingreso;
    if(!lifo.Agregar(ingreso)){
            cout<<"VALOR NO ACEPTADO. PILA LLENA"<<endl;
    }
    while(lifo.Sacar(salida)){
        cout<<salida<<endl;
    }
	cout<<endl;

	system("pause");
	return 0;
}
