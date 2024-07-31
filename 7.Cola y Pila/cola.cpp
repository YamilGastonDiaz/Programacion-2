///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

using namespace std;

class Cola{
private:
     int *pInfo;
     int inicio, fin, tam;

public:
    Cola(int cant){
        tam=cant;
        pInfo=new int[cant];
        if(pInfo==NULL)exit(1);
        fin=inicio=0;
    }
    ~Cola(){
        delete []pInfo;
    }
    bool Agregar(int info){
        if(fin==tam){///la Cola está llena
            return false;
        }
        pInfo[fin]=info;
        fin++;
        return true;
    }

    bool Sacar(int &valorQueSale){
        if(inicio==fin){///la Cola está vacía
            return false;
        }
        valorQueSale=pInfo[inicio];
        inicio++;
        return true;
    }
};


int main(){
    Cola primera(5);
    int ingreso, salida;
    for(int i=1;i<=3;i++){
            cout<<"INGRESE UN VALOR PARA LA COLA ";
            cin>>ingreso;
            primera.Agregar(ingreso);
    }
    cout<<"INGRESE UN VALOR PARA LA COLA ";
    cin>>ingreso;
    if(!primera.Agregar(ingreso)){
            cout<<"VALOR NO ACEPTADO. COLA LLENA"<<endl;
    }
    while(primera.Sacar(salida)){
        cout<<salida<<endl;
    }
	cout<<endl;
	system("pause");
	return 0;
}
