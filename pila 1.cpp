#include <iostream>
#include <windows.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void cargarPILA(Nodo *&, int);
void quitarPILA(Nodo *&, int &);

int main(){
    string op;
    int valor;
    Nodo *pila = NULL;
    do
    {
        cout<<"Cargar pila:"<<endl;
        cin>>valor;
        cargarPILA(pila, valor);

        cout<<"Desea cargar otro elemento ? (s/n):"<<endl;
        cin>>op;
        
    } while(op == "S" || op == "s");
    system("pause");
    cout<<"La pila cargada es:"<<endl;
    while (pila != NULL)
    {
        quitarPILA(pila, valor);
        if (pila != NULL)
        {
            cout<<valor<<endl;
        }else
        {
            cout<<valor<<endl;
            cout<<"Fin de la pila."<<endl;
        }
    }
    return 0;
}

void cargarPILA(Nodo *&pila, int v){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = v;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout<<"El valor" <<v<< "se cargo correctamente."<<endl;
}

void quitarPILA(Nodo *&pila, int &v){
    Nodo *aux = pila;
    v = aux->dato;
    pila = aux->siguiente;
    delete aux;
}

